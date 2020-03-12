#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define faturacaosize 1500000

//Função de inicialização da estrutura e alocação de memória
void init_faturacao();
//Função que calcula o índice de hash da venda
int hash_F(char *p, char *c);
//Função que insere na hashtable a venda
int insere_faturacao(char* p,float preco,int qt,char tipo_compra,char* c,int mes,int filial);
