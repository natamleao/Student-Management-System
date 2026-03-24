#include "../include/student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************** PRIVATE INTERFACE ******************************************************/

struct _student{
    char *_name;
    size_t _registration, _age;
    Book *_favorityBook;
    struct _student *_prev, *_next;
};

/***************************************************** PUBLIC INTERFACE *******************************************************/

Student *StudentCreate(char *name, size_t age, size_t registration, const Book *favorityBook){
    Student *newStudent = (Student*)malloc(sizeof(Student));

    if(!newStudent){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    newStudent->_name = NULL;
    newStudent->_favorityBook = NULL;

    StudentSetName(newStudent, name);
    StudentSetAge(newStudent, age);
    StudentSetRegistration(newStudent, registration);
    StudentSetPrev(newStudent, NULL);
    StudentSetNext(newStudent, NULL);
    StudentSetFavorityBook(newStudent, favorityBook);

    return newStudent;
}

char *StudentGetName(const Student *student){return student->_name;}
size_t StudentGetAge(const Student *student){return student->_age;}
size_t StudentGetRegistration(const Student *student){return student->_registration;}
Book *StudentGetFavorityBook(const Student *student){return student->_favorityBook;}
Student *StudentGetPrev(Student *student){return student->_prev;}
Student *StudentGetNext(Student *student){return student->_next;}

void StudentSetName(Student *student, char *name){
    if(name){
        free(student->_name); 

        student->_name = strdup(name);
        if(!student->_name){
            perror("strdup");
            exit(EXIT_FAILURE);
        }
    }
}

void StudentSetAge(Student *student, size_t age){
    if(age > 0)
        student->_age = age;
}

void StudentSetRegistration(Student *student, size_t registration){
    if(registration > 0)
        student->_registration = registration;
}

void StudentSetPrev(Student *student, Student *prev){
    student->_prev = prev;
}

void StudentSetNext(Student *student, Student *next){
    student->_next = next;
}

void StudentSetFavorityBook(Student *student, const Book *favorityBook){
    if(favorityBook)
        student->_favorityBook = BookCopy(favorityBook);
}

void StudentDestroy(Student **studentReferency){
    Student *copyStudent = *studentReferency;

    if(copyStudent){
        free(StudentGetName(copyStudent));
        BookDestroy(&copyStudent->_favorityBook); 
        free(copyStudent);
    }

    *studentReferency = NULL;
}

void StudentPrint(const Student *student){
    if(student){
        printf("+ DADOS DO ALUNO(A) --------------------------------------------------------+\n");
        puts("+---------------------------------------------------------------------------+");
        printf("+ NOME: %s | MATRÍCULA: %zu | IDADE: %zu\n", StudentGetName(student), StudentGetRegistration(student), StudentGetAge(student));
        puts("+---------------------------------------------------------------------------+");
        BookPrint(StudentGetFavorityBook(student));
    }

    else
        printf("+ Aluno não registrado\n");
}

/******************************************************************************************************************************/