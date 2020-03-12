#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define productsize 500000

typedef char *produto; // o produto é uma string

//Função de inicialização e alocação de memória da estrutura
void init_product();
//Função de cálculo do índice de hash
int hash_p(produto p);
//Função de inserção de um produto na estrutura
int insere_product(produto p);

//Função de inserção dos índices hash ordenados num array
int readProdutos(char *lista_produtos[productsize],int indice_produto_ordenado[productsize]);
//Função de leitura do ficheiro de produtos e inserção dos mesmos num array
int readProdutos_lista(char *lista_produtos[productsize]);

//Função que verifica se existe certo produto
int encontra_produto(produto p);
//Função que retorna no número de produtos começados por uma letra específica
int getProductsStartedByLetter(char p);
