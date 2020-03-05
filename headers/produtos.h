

#ifndef LI3_PRODUTOS_H
#define LI3_PRODUTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define productsize 500000

typedef char *produto; // o cliente é uma string



void init_product();
int hash_p(produto p);
int insere_product(produto p);

int readProdutos(char *lista_produtos[productsize],int indice_produto_ordenado[productsize]);
int readProdutos_lista(char *lista_produtos[productsize]);

int encontra_produto(produto p);
int getProductsStartedByLetter(char p);




#endif //LI3_PRODUTOS_H
