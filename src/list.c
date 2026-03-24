#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/***************************************************** PRIVATE INTERFACE ******************************************************/

struct _list{
    Student *_begin, *_end;
    size_t _size, _capcity;
};

typedef struct _studentFile{
    char _name[100];
    size_t _registration, _age, _pagesNumber;
    char _title[100];
    float _price;
}StudentFile;

void ListIncrementSize(List *list){list->_size++;}
void ListDecrementSize(List *list){list->_size--;}

void ListAddBegin(List *list, Student *student){
    StudentSetPrev(student, NULL);
    StudentSetNext(student, ListGetBegin(list));

    if (ListGetBegin(list) != NULL)
        StudentSetPrev(ListGetBegin(list), student);
    else
        ListSetEnd(list, student);

    ListSetBegin(list, student);
}

void ListAddOtherPosition(List *list, Student *student, size_t pos){
    Student *current = ListGetBegin(list);

    for(size_t i = 0; i < pos - 1; i++)
        current = StudentGetNext(current);

    Student *next = StudentGetNext(current);

    StudentSetNext(current, student);
    StudentSetPrev(student, current);

    StudentSetNext(student, next);
    if(next)
        StudentSetPrev(next, student);
    else
        ListSetEnd(list, student);
}

void ListSaveStudent(FILE *f, Student *s){
    size_t len;

    // nome
    len = strlen(StudentGetName(s)) + 1;
    fwrite(&len, sizeof(size_t), 1, f);
    fwrite(StudentGetName(s), sizeof(char), len, f);

    // dados básicos
    size_t registration = StudentGetRegistration(s);
    size_t age = StudentGetAge(s);
    fwrite(&registration, sizeof(size_t), 1, f);
    fwrite(&age, sizeof(size_t), 1, f);

    // livro
    Book *b = StudentGetFavorityBook(s);

    len = strlen(BookGetTitle(b)) + 1;
    fwrite(&len, sizeof(size_t), 1, f);
    fwrite(BookGetTitle(b), sizeof(char), len, f);

    size_t pagesNumber = BookGetPagesNumber(b);
    float price = BookGetPrice(b);
    fwrite(&pagesNumber, sizeof(size_t), 1, f);
    fwrite(&price, sizeof(float), 1, f);
}

/***************************************************** PUBLIC INTERFACE *******************************************************/

List *ListCreate(size_t capacity){
    List *newList = (List*)malloc(sizeof(List));

    if(!newList){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    ListSetBegin(newList, NULL);
    ListSetEnd(newList, NULL);
    ListSetSize(newList, 0);
    ListSetCapacity(newList, capacity);

    return newList;
}

Student *ListGetBegin(List *list){return list->_begin;}
Student *ListGetEnd(List *list){return list->_end;}
size_t ListGetSize(List *list){return list->_size;}
size_t ListGetCapacity(List *list){return list->_capcity;}

void ListSetBegin(List *list, Student *begin){
    list->_begin = begin;
}

void ListSetEnd(List *list, Student *end){
    list->_end = end;
}

void ListSetSize(List *list, size_t size){
    list->_size = size;
}

void ListSetCapacity(List *list, size_t capacity){
    if(capacity > 0)
        list->_capcity = capacity;
}


Student *ListSearch(List *list, size_t registration, int *f){
    Student *aux = ListGetBegin(list);

    while(aux){
        if(StudentGetRegistration(aux) == registration){
            (*f) = 1;

            return aux;
        }
        aux = StudentGetNext(aux);
    } 

    (*f) = 0;
    return NULL;
}

void autoSortList(List *list){
    if (!list|| !ListGetBegin(list)) return;

    int swapped;

    do{
        swapped = 0;
        Student *current = ListGetBegin(list);

        while(current && StudentGetNext(current)){
            Student *a = current;
            Student *b = StudentGetNext(a);

            if(StudentGetRegistration(a) > StudentGetRegistration(b)){
                Student* prev = StudentGetPrev(a);
                Student* next = StudentGetNext(b);

                if(prev != NULL)
                    StudentSetNext(prev, b);
                else
                    ListSetBegin(list, b);

                StudentSetPrev(b, prev);

                StudentSetNext(b, a);
                StudentSetPrev(a, b);

                StudentSetNext(a, next);

                if (next != NULL)
                    StudentSetPrev(next, a);

                else
                    ListSetEnd(list, a);

                swapped = 1;
                current = b; 
            } 

            else
                current = StudentGetNext(current);
        }
    }while(swapped);
}

void ListAdd(List *list, char *name, size_t registration, size_t age, char *title, size_t pagesNumber, float price, size_t pos, int *f){
    Book *newBook = BookCreate(title, pagesNumber, price);
    Student *newStudent = StudentCreate(name, age, registration, newBook);

    if(pos > ListGetCapacity(list) || ListGetSize(list) == ListGetCapacity(list)){
        BookDestroy(&newBook);
        (*f) = 0;
        return;
    } 

    if(pos == 0)
        ListAddBegin(list, newStudent);

    else
        ListAddOtherPosition(list, newStudent, pos);

    ListIncrementSize(list);

    autoSortList(list);

    (*f) = 1;
}

void ListRemove(List *list, size_t registration, int *f){
    if(!list) return;

    Student *remove = ListSearch(list, registration, f);

    if(*f == 1){
        if(ListGetBegin(list) == remove && ListGetEnd(list) == remove){
            ListSetBegin(list, NULL);
            ListSetEnd(list, NULL);
        }

        else if(remove == ListGetBegin(list)){
            ListSetBegin(list, StudentGetNext(remove));
            if(ListGetBegin(list) != NULL)
                StudentSetPrev(ListGetBegin(list), NULL);
        }

        else if(remove == ListGetEnd(list)){
            ListSetEnd(list, StudentGetPrev(remove));
            if(ListGetEnd(list) != NULL)
                StudentSetNext(ListGetEnd(list), NULL);
        }

        else {
            StudentSetNext(StudentGetPrev(remove), StudentGetNext(remove));
            StudentSetPrev(StudentGetNext(remove), StudentGetPrev(remove));
        }

        ListDecrementSize(list);
        StudentDestroy(&remove);
    }

    else
        printf("+ O aluno não está registrado\n");
}

void ListLoad(List *list, const char *filename){
    int f;
    FILE *file = fopen(filename, "rb");
    if(!file) return;

    StudentFile sf;


    while(fread(&sf, sizeof(StudentFile), 1, file))
        ListAdd(list, sf._name, sf._registration, sf._age, sf._title, sf._pagesNumber, sf._price, 0, &f);

    fclose(file);
}

void ListSave(List *list, const char *filename){
    FILE *file = fopen(filename, "wb");
    if(!file) return;

    Student *act = ListGetBegin(list);

    while(act){
        StudentFile sf;

        strcpy(sf._name, StudentGetName(act));
        sf._registration = StudentGetRegistration(act);
        sf._age = StudentGetAge(act);

        Book *b = StudentGetFavorityBook(act);
        strcpy(sf._title, BookGetTitle(b));
        sf._pagesNumber = BookGetPagesNumber(b);
        sf._price = BookGetPrice(b);

        fwrite(&sf, sizeof(StudentFile), 1, file);

        act = StudentGetNext(act);
    }

    fclose(file);
}

void ListPrint(List *list){
    Student *aux = ListGetBegin(list);

    while(aux){
        StudentPrint(aux);

        aux = StudentGetNext(aux);
    }
}

void ListDestroy(List **list){
    Student *prev = NULL, *act = ListGetBegin(*list);

    while(act){
        prev = act;
        act = StudentGetNext(act);
        StudentDestroy(&prev);
    }

    free(*list);
    *list = NULL;
}

/******************************************************************************************************************************/