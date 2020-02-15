
#include <stdio.h>
#include "clientes.h"
#include <stdlib.h>
#include <string.h>

void init_client(clients client_hash[clientsize]){
    #pragma omp parallel for num_threads(2)
        for(int i = 0; i< clientsize; i++){
            client_hash[i] = malloc(sizeof(struct s_cliente));
            client_hash[i]->validade = 0;
        }

    
}

int hash(cliente c){
    int r=0;
    for(int i = 0; c[i] != '\0' ; i++) r+= c[i];
    return r;
}

int insere_client(clients client_hash[clientsize],cliente c){
    int hash_code = hash(c);
    while(client_hash[hash_code]->validade) hash_code = (hash_code+1)%clientsize;

    client_hash[hash_code]->validade=1;
    strcpy(client_hash[hash_code]->n_cliente,c);
    return hash_code;
}


int readClientes(clients client_hash[clientsize]){
    FILE *f;
    f = fopen("dados/Clientes.txt","r");
    //int hash_code;
    int i = 0;
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char *token;
        //int i = 0;
        char cli_code[8];

        while (fgets(cli_code, 8, f)) {
            token = strtok(cli_code, "\r\n");
            //printf("%s\n", token);
            insere_client(client_hash, token);
            i++;
            //clientes[i] = malloc(sizeof(token));
            //strcpy(clientes[i], token);
   //         printf("%s\n",client_hash[hash_code]->n_cliente);
            //i++;
        }
        fclose(f);
    }
    return i;
}

