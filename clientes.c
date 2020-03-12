
#include <stdio.h>
#include "headers/clientes.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_cliente{
    int validade;
    char n_cliente[5];
}*clients;

//Array de estruturas para os clientes
clients *client_hash;

//Função de inicialização do array e alocação de memória
void init_client(){
    client_hash = calloc(clientsize , sizeof(struct s_cliente)); // inicialização da hash_table de clientes
}

//Função de cálculo do índice de hash para os clientes
int hash_c(cliente c){
    unsigned long int sum = 5381;
    for(int i = 0; c[i]; i++) sum = ((sum << 5) + sum) + c[i];
    return (sum%clientsize);
}

//Função de inserção dos clientes na estrutura
int insere_client(cliente c){
    //Cálculo do índice de hash
    int hash_code = hash_c(c);
    //Procura pela próxima posição livre no array
    while(client_hash[hash_code]) hash_code = (hash_code+1)%clientsize;
    //Alocação de memória dentro do array e atribuição do valor às variáveis
    client_hash[hash_code] = malloc(sizeof(struct s_cliente));
    client_hash[hash_code]->validade=1;
    strcpy(client_hash[hash_code]->n_cliente,c);
    return hash_code;
}

//Função que coloca num array os indices de hash dos clientes previamente ordenados
int readClientes(char *lista_clientes[clientsize],int indice_cliente_ordenado[]){
    int i,indice;
    for(i=0;lista_clientes[i];i++){
      indice = insere_client(lista_clientes[i]);
      indice_cliente_ordenado[i] = indice;
      //printf("%s\n",client_hash[indice_cliente_ordenado[i]]->n_cliente);
    }
    return i;
}

//Função que verifica se existe um cliente
int encontra_cliente(cliente c){
    int hash_code = hash_c(c);
    while(client_hash[hash_code])
        if (client_hash[hash_code]->validade == 1 && !strcmp(client_hash[hash_code]->n_cliente,c)) return hash_code;
        else hash_code = (hash_code+1)%clientsize;

    return -1;
}

//Função que lẽ o ficheiro dos clientes e os coloca num array
int readClientes_lista(char *lista_clientes[clientsize]){
    FILE *f;
    int i = 0;
    f = fopen("dados/Clientes.txt","r");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char *token;
        char cli_code[8]; // Código cliente

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
