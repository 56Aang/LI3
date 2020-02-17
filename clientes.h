//
// Created by Pedro Miguel De Soveral Pacheco Barbosa on 17/02/2020.
//

#ifndef LI3_CLIENTES_H
#define LI3_CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define clientsize 500000
typedef char *cliente; // o cliente é uma string

typedef struct s_cliente{
    int validade;
    char n_cliente[5];
    //char * produto;
}*clients;

void init_client(clients client_hash[clientsize]);
int insere_client(clients client_hash[clientsize],cliente c);
int readClientes(clients client_hash[clientsize]);
int hash_c(cliente c);
int encontra_Cliente (cliente c, clients client_hash[clientsize]);

#endif //LI3_CLIENTES_H
