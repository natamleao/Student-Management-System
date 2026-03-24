#include "../include/book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************** PRIVATE INTERFACE ******************************************************/

struct _book{
    char *_title;
    size_t _pagesNumber;
    float _price;
};

/***************************************************** PUBLIC INTERFACE *******************************************************/

Book *BookCreate(char *title, size_t pagesNumber, float price){
    Book *newBook = (Book*)malloc(sizeof(Book));

    if(!newBook){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    newBook->_title = NULL;

    BookSetTitle(newBook, title);
    BookSetPagesNumber(newBook, pagesNumber);
    BookSetPrice(newBook, price);
    
    return newBook;
}

char *BookGetTitle(const Book *book){return book->_title;}
size_t BookGetPagesNumber(const Book *book){return book->_pagesNumber;}
float BookGetPrice(const Book *book){return book->_price;}

void BookSetTitle(Book *book, char *title){
    if(title){
        free(book->_title); 
        
        book->_title = strdup(title);
        if(!book->_title){
            perror("strdup");
            exit(EXIT_FAILURE);
        }
    }
}

void BookSetPagesNumber(Book *book, size_t pagesNumber){
    if(pagesNumber > 0)
        book->_pagesNumber = pagesNumber;
}

void BookSetPrice(Book *book, float price){
    if(price > 0.0)
        book->_price = price;
}

Book *BookCopy(const Book *book){
    return BookCreate(BookGetTitle(book), BookGetPagesNumber(book), BookGetPrice(book));
}

void BookDestroy(Book **bookReferency){
    Book *copyBook = *bookReferency;

    if(copyBook){
        free(copyBook->_title);
        free(copyBook);          
    }

    *bookReferency = NULL;
}

void BookPrint(const Book *book){
    if(book){
        printf("+ LIVRO FAVORITO -----------------------------------------------------------+\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("+ TÍTULO: %s | NÚMERO DE PÁGINAS: %zu | PREÇO: %.2f\n", BookGetTitle(book), BookGetPagesNumber(book), BookGetPrice(book));
        printf("+---------------------------------------------------------------------------+\n");
    }

    else
        printf("+ Livro não registrado\n");
}

/******************************************************************************************************************************/