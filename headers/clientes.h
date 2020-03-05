
#ifndef LI3_CLIENTES_H
#define LI3_CLIENTES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define clientsize 500000
typedef char *cliente; // o cliente é uma string

void init_client();
int insere_client(cliente c);

int readClientes(char *lista_clientes[clientsize],int indice_cliente_ordenado[]);
int readClientes_lista();

int hash_c(cliente c);
int encontra_cliente(cliente c);

#endif //LI3_CLIENTES_H
