/***************************************************** PUBLIC INTERFACE *******************************************************/

#ifndef LIST_H
#define LIST_H

#include "student.h"
#include <stddef.h>

typedef struct _list List;

/**
 * @brief Cria a lista 
 * 
 * @param capacity A capacidade da lista
 * 
 * @return List* 
 */
List *ListCreate(size_t capacity);

/**
 * @brief Retorna o íncio da lista 
 * 
 * @param list A lista 
 */
Student *ListGetBegin(List *list);

/**
 * @brief Retorna o fim da lista 
 * 
 * @param list A lista 
 */
Student *ListGetEnd(List *list);

/**
 * @brief Retorna o tamanho da lista
 * 
 * @param list A lista 
 */
size_t ListGetSize(List *list);

/**
 * @brief Retorna a capacidade da lista
 * 
 * @param list A lista 
 */
size_t ListGetCapacity(List *list);

/**
 * @brief Atribui o início da lista
 * 
 * @param list A lista 
 * @param begin O início da lista
 */
void ListSetBegin(List *list, Student *begin);

/**
 * @brief Atribui o fim da lista
 * 
 * @param list A lista 
 * @param end O fim da lista
 */
void ListSetEnd(List *list, Student *end);

/**
 * @brief Atribui o tamanho da lista
 * 
 * @param list A lista 
 * @param size O tamanho da lista
 */
void ListSetSize(List *list, size_t size);

/**
 * @brief Atribui a capacidade da lista
 * 
 * @param list A lista 
 * @param size A capacidade da lista
 */
void ListSetCapacity(List *list, size_t capacity);

/**
 * @brief Busca um item na lista
 * 
 * @param list A lista 
 * @param registration A matrícula do aluno
 * @param f Flag para informar se o item pertence ou não a lista
 */
Student *ListSearch(List *list, size_t registration, int *f);

/**
 * @brief Ordena a lista
 * 
 * @param list A lista 
 */
void autoSortList(List *list);

/**
 * @brief Adiciona o ovo de páscoa a lista 
 * 
 * @param list A lista 
 * @param name Nome do aluno
 * @param registration Matrícula do aluno
 * @param age Idade do aluno
 * @param pagesNumber Número de páginas do livro
 * @param price Preço do livro
 */
void ListAdd(List *list, char *name, size_t registration, size_t age, char *title, size_t pagesNumber, float price, size_t pos, int *f);
 
/**
 * @brief Remove um item da lista
 * 
 * @param list Lista 
 * @param registration A matrícula do aluno
 */
void ListRemove(List *list, size_t registration, int *f);

/**
 * @brief Ler um arquivo contendo dados de entrada e adicionar os dados a lista
 * 
 * @param list A lista
 * @param fileName O nome do arquivo
 */
void ListLoad(List *list, const char *filename);

/**
 * @brief Salva toda a lista em um arquivo binário
 * 
 * @param list A lista
 * @param fileName O nome do arquivo
 */
void ListSave(List *list, const char *filename);

/**
 * @brief Imprime a lista  mostrando o identificador e o preço
 * 
 * @param list Lista 
 */
void ListPrint(List *list);

/**
 * @brief Desaloca toda a lista 
 * 
 * @param list Lista 
 */
void ListDestroy(List **list);

#endif

/******************************************************************************************************************************/