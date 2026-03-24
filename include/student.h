/***************************************************** PUBLIC INTERFACE *******************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include "book.h"

typedef struct _student Student;

/**
 * @brief Cria os estudantes
 * 
 * @param name Nome do aluno
 * @param age Idade do aluno
 * @param registration Matrícula do aluno
 * @param favorityBook Livro favorito do aluno
 * @return Student* 
 */
Student *StudentCreate(char *name, size_t age, size_t registration, const Book *favorityBook);

/**
 * @brief Retorna o nome do aluno
 * 
 * @param student O aluno
 */
char *StudentGetName(const Student *student);

/**
 * @brief Retorna a idade do aluno
 * 
 * @param student O aluno
 */
size_t StudentGetAge(const Student *student);

/**
 * @brief Retorna a matrícula do aluno
 * 
 * @param student O aluno
 */
size_t StudentGetRegistration(const Student *student);

/**
 * @brief Retorna o livro favorito do aluno
 * 
 * @param student O aluno
 */
Book *StudentGetFavorityBook(const Student *student);

/**
 * @brief Retorna o aluno anterior
 * 
 * @param student O aluno
 */
Student *StudentGetPrev(Student *student);

/**
 * @brief Retorna o próximo aluno
 * 
 * @param student O aluno
 */
Student *StudentGetNext(Student *student);

/**
 * @brief Atribui nome do aluno
 * 
 * @param student O aluno
 * @param name O título do livro
 */
void StudentSetName(Student *student, char *name);

/**
 * @brief Atribui a idade do aluno
 * 
 * @param student O aluno
 * @param age A idade do aluno
 */
void StudentSetAge(Student *student, size_t age); 

/**
 * @brief Atribui a matrícula do aluno
 * 
 * @param student O aluno
 * @param registration A matrícula do aluno
 */
void StudentSetRegistration(Student *student, size_t registration);

/**
 * @brief Atribui o aluno anterior
 * 
 * @param student O aluno
 * @param prev O aluno anterior
 */
void StudentSetPrev(Student *student, Student *prev);

/**
 * @brief Atribui próximo aluno
 * 
 * @param student O aluno
 * @param next O próximo aluno
 */
void StudentSetNext(Student *student, Student *next);

/**
 * @brief Atribui o livro favorito do aluno
 * 
 * @param student O aluno
 * @param favorityBook O livro favorito do aluno
 */
void StudentSetFavorityBook(Student *student, const Book *favorityBook);;

/**
 * @brief Destrói um aluno
 * 
 * @param studentReferency A referência para o aluno
 */
void StudentDestroy(Student **studentReferency);

/**
 * @brief Imprime os dados de um aluno
 * 
 * @param student O aluno
 */
void StudentPrint(const Student *student);

#endif

/******************************************************************************************************************************/
