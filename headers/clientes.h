#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define clientsize 500000
typedef char *cliente; // o cliente é uma string

//Função de inicialização e alocação de memória para a estrutura
void init_client();
//Função de inserção de um cliente na estrutura
int insere_client(cliente c);

//Função de inserção dos indices hash ordenados num array
int readClientes(char *lista_clientes[clientsize],int indice_cliente_ordenado[]);
//Função de leitura de um ficheiro e inserção dos clientes num array
int readClientes_lista(char *lista_clientes[clientsize]);

//Função de cálculo do índice hash
int hash_c(cliente c);
//Função que verifica se existe certo cliente
int encontra_cliente(cliente c);
