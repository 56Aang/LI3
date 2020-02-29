

#ifndef LI3_PRODUTOS_H
#define LI3_PRODUTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define productsize 500000

typedef char *produto; // o cliente é uma string

typedef struct s_produto{
    int validade;
    char n_produto[6];
}*products;


typedef struct s_product_bought{
	char n_produto[6];
	char *preco;
	int quantidade;
	char tipo_compra;
	int mes;
	int filial;
	struct s_product_bought * next;
}*product_bought;


void init_product(products product_hash[productsize]);
int hash_p(produto p);
int insere_product(products product_hash[productsize],produto p);

int readProdutos(products product_hash[productsize],int indice_produto_ordenado[productsize]);
int readProdutos_lista(char *lista_produtos[productsize]);

int encontra_produto(produto p,products product_hash[productsize]);
int getProductsStartedByLetter(char p,products product_hash[productsize]);




#endif //LI3_PRODUTOS_H
