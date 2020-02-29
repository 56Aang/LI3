
#include <stdio.h>
#include "clientes.h"
#include <stdlib.h>
#include <string.h>

void init_client(clients client_hash[clientsize]){
//    #pragma omp parallel for num_threads(2)
        for(int i = 0; i< clientsize; i++){
            client_hash[i] = malloc(sizeof(struct s_cliente));
            client_hash[i]->validade = 0;
        }

    
}


int hash_c(cliente c){
    unsigned long int sum = 5381;
    for(int i = 0; c[i]; i++) sum = ((sum << 5) + sum) + c[i];
    return (sum%clientsize);
}

int insere_client(clients client_hash[clientsize],cliente c){
    int hash_code = hash_c(c);
    while(client_hash[hash_code]) hash_code = (hash_code+1)%clientsize;
    if (client_hash[hash_code] == NULL) client_hash[hash_code] = malloc(sizeof(struct s_cliente));
    client_hash[hash_code]->validade=1;
    strcpy(client_hash[hash_code]->n_cliente,c);
    client_hash[hash_code]->p = NULL;
    return hash_code;
}


int readClientes(clients client_hash[clientsize],int indice_cliente_ordenado[]){
    FILE *f;
    f = fopen("dados/Clientes.txt","r");
    int i = 0;
    char *token;
    char cli_code[8];
    int hash_code;

    while (fgets(cli_code, 8, f)) {
        token = strtok(cli_code, "\r\n");
        hash_code = insere_client(client_hash, token);
        indice_cliente_ordenado[i] = hash_code;
        i++;
    }
    fclose(f);
    return i;
}

int encontra_cliente(cliente c,clients client_hash[clientsize]){
    int hash_code = hash_c(c);
    while(client_hash[hash_code])
        if (client_hash[hash_code]->validade == 1 && !strcmp(client_hash[hash_code]->n_cliente,c)) return hash_code;
        else hash_code = (hash_code+1)%clientsize;
    
    return -1;
}

int readClientes_lista(char *lista_clientes[clientsize]){
    FILE *f;
    int i = 0;
    f = fopen("dados/Clientes.txt","r");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char *token;
        char cli_code[8];

        while (fgets(cli_code, 8, f)) {
            token = strtok(cli_code, "\r\n");
            //printf("%s\n", token);
            lista_clientes[i] = malloc(sizeof(token));
            strcpy(lista_clientes[i], token);
            i++;
        }
        fclose(f);
    }
    return i;
}