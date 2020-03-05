#ifndef LI3_VENDAS_H
#define LI3_VENDAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define faturacaosize 1500000
void init_faturacao();
int hash_F(char *p, char *c);
int insere_faturacao(char* p,float preco,int qt,char tipo_compra,char* c,int mes,int filial);

#endif //LI3_VENDAS_H
