//
// Created by Pedro Miguel De Soveral Pacheco Barbosa on 17/02/2020.
//

#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_client(clients client_hash[clientsize]){
#pragma omp parallel for num_threads(2)
    for(int i = 0; i< clientsize; i++){
        client_hash[i] = malloc(sizeof(struct s_cliente));
        client_hash[i]->validade = 0;
    }
}

int hash_c(cliente c){
    unsigned long int sum = 5381;
    for (int i = 0; c[i]; i++) sum = ((sum << 5) + sum) + c[i];
    return (sum%clientsize);
}

int insere_client(clients client_hash[clientsize],cliente c){
    int hash_code = hash_c(c);
    while(client_hash[hash_code]) hash_code = (hash_code+1)%clientsize;
    client_hash[hash_code] = malloc (sizeof (struct s_cliente));
    client_hash[hash_code]->validade=1;
    strcpy(client_hash[hash_code]->n_cliente,c);
    return hash_code;
}


int readClientes(clients client_hash[clientsize]){
    FILE *f;
    f = fopen("dados/Clientes.txt","r");
    int i = 0;
    char *token;
    char cli_code[8];
    while (fgets(cli_code, 8, f)) {
        token = strtok(cli_code, "\r\n");
        insere_client(client_hash, token);
        i++;
    }
    fclose(f);
    return i;
}

int encontra_Cliente (cliente c, clients client_hash[clientsize]) {
    int hash_code = hash_c(c);
    while(client_hash[hash_code]) {
        if (client_hash[hash_code]->validade && strcmp(client_hash[hash_code]->n_cliente, c) == 0) return 1;
        hash_code = (hash_code+1)%clientsize;
    }
    return 0;
}