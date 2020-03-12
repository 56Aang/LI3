
#include "headers/produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_produto{
    int validade;
    char n_produto[6]; //Código produto
}*products;

//Array de estrutura
products *product_hash;

//Função de inicialização e alocação de memória para a estrutura
void init_product(){
    product_hash = calloc(productsize , sizeof(struct s_produto));
}

//Função de cálculo do índice de hash
int hash_p(produto p){
    unsigned long int sum = 5381;
    for(int i = 0; p[i]; i++) sum = ((sum << 5) + sum) + p[i];
    return (sum%productsize);
}

//Função de inserção numa posição do array
int insere_product(produto p){
    //Calcula o índice de hash
    int hash_code = hash_p(p);
    //Procura a posição seguinte que esteja livre
    while(product_hash[hash_code]) hash_code = (hash_code+1)%productsize;
    //Alocação de memória na posição do array e atribuição das variáveis
    product_hash[hash_code] = malloc(sizeof(struct s_produto));
    product_hash[hash_code]->validade=1;
    strcpy(product_hash[hash_code]->n_produto,p);
    return hash_code;
}

//Função que coloca num array os indices de hash dos produtos previamente ordenados
int readProdutos(char *lista_produtos[productsize] ,int indice_produto_ordenado[]){
  int i,indice;
  for(i=0;lista_produtos[i];i++){
    indice = insere_product(lista_produtos[i]);
    indice_produto_ordenado[i] = indice;
  }
  return i;
}

//Função que verifica se existe um produto
int encontra_produto(produto p){
    int hash_code = hash_p(p);
    while(product_hash[hash_code])
        if (product_hash[hash_code]->validade == 1 && strcmp(product_hash[hash_code]->n_produto,p) == 0) return hash_code;
        else hash_code = (hash_code+1)%productsize;

    return -1;
}

//Função que retorna o número de produtos começados por uma certa letra
int getProductsStartedByLetter(char p){
    int i;
    int k = 0;
    for(i=0;i<productsize;i++)
        if(product_hash[i] && product_hash[i]->n_produto[0] == p) {
            //printf("%s\n",product_hash[i]->n_produto );
            k++;
        }

    return k;
}

//Função que lê o ficheiro dos produtos e os coloca num array
int readProdutos_lista(char *lista_produtos[productsize]){
    FILE *f;
    int i = 0;
    f = fopen("dados/Produtos.txt","r");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char *token;
        char cli_code[9];

        while (fgets(cli_code, 9, f)) {
            token = strtok(cli_code, "\r\n");
            //printf("%s\n", token);
            lista_produtos[i] = malloc(sizeof(token));
            strcpy(lista_produtos[i], token);
            i++;
        }
        fclose(f);
    }
    return i;
}
