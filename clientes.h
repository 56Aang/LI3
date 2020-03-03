
#ifndef LI3_CLIENTES_H
#define LI3_CLIENTES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define clientsize 500000
typedef char *cliente; // o cliente é uma string

typedef struct s_cliente{
    int validade;
    char n_cliente[5];
    product_bought p;
}*clients;

void init_client(clients client_hash[clientsize]);
int insere_client(clients client_hash[clientsize],cliente c);

int readClientes(clients client_hash[clientsize], char *lista_clientes[clientsize],int indice_cliente_ordenado[]);
int readClientes_lista(char *lista_clientes[clientsize]);

int hash_c(cliente c);
int encontra_cliente(cliente c,clients client_hash[clientsize]);

#endif //LI3_CLIENTES_H
