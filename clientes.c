
#include <stdio.h>
#include "headers/clientes.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_cliente{
    int validade;
    char n_cliente[5];
}*clients;

clients *client_hash;
void init_client(){
    client_hash = calloc(clientsize , sizeof(struct s_cliente)); // inicialização da hash_table de clientes
}


int hash_c(cliente c){
    unsigned long int sum = 5381;
    for(int i = 0; c[i]; i++) sum = ((sum << 5) + sum) + c[i];
    return (sum%clientsize);
}

int insere_client(cliente c){
    int hash_code = hash_c(c);
    while(client_hash[hash_code]) hash_code = (hash_code+1)%clientsize;
    if (client_hash[hash_code] == NULL) client_hash[hash_code] = malloc(sizeof(struct s_cliente));
    client_hash[hash_code]->validade=1;
    strcpy(client_hash[hash_code]->n_cliente,c);
    return hash_code;
}


int readClientes(char *lista_clientes[clientsize],int indice_cliente_ordenado[]){
    int i,indice;
    for(i=0;lista_clientes[i];i++){
      indice = insere_client(lista_clientes[i]);
      indice_cliente_ordenado[i] = indice;
      //printf("%s\n",client_hash[indice_cliente_ordenado[i]]->n_cliente);
    }
    return i;
}

int encontra_cliente(cliente c){
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
