/***************************************************** PUBLIC INTERFACE *******************************************************/

#ifndef BOOK_H
#define BOOK_H

#include <stddef.h>

typedef struct _book Book;

/**
 * @brief Cria os livros
 * 
 * @param title Título do livro
 * @param pagesNumber Número de páginas do livro
 * @param price Preço do livro
 * @return Book* 
 */
Book *BookCreate(char *title, size_t pagesNumber, float price);

/**
 * @brief Retorna o identificador o título do livro
 * 
 * @param book O livro
 */
char *BookGetTitle(const Book *book);

/**
 * @brief Retorna número de páginas do livro
 * 
 * @param book O livro
 */
size_t BookGetPagesNumber(const Book *book);

/**
 * @brief Retorna valor do livro
 * 
 * @param book O livro
 */
float BookGetPrice(const Book *book);

/**
 * @brief Atribui um título ao livro
 * 
 * @param book O livro
 * @param title O título do livro
 */
void BookSetTitle(Book *book, char *title);

/**
 * @brief Atribui o número de páginas ao livro
 * 
 * @param book O livro
 * @param pagesNumber O número de páginas do livro
 */
void BookSetPagesNumber(Book *book, size_t pagesNumber);

/**
 * @brief Atribui o ovo de pasco seguinte na lista
 * 
 * @param book O livro
 * @param price O preço do livro
 */
void BookSetPrice(Book *book, float price);

/**
 * @brief Cria uma cópia de um livro
 * 
 * @param book O livro
 */
Book *BookCopy(const Book *book);

/**
 * @brief Destrói um livro
 * 
 * @param bookReferency A referência para o livro
 */
void BookDestroy(Book **bookReferency);

/**
 * @brief Imprime os dados de um livro
 * 
 * @param book O livro
 */
void BookPrint(const Book *book);

#endif

/******************************************************************************************************************************/
