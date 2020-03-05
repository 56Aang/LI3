
#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_produto{
    int validade;
    char n_produto[6];
}*products;

products *product_hash;
void init_product(){
    product_hash = calloc(productsize , sizeof(struct s_produto));
}

int hash_p(produto p){
    unsigned long int sum = 5381;
    for(int i = 0; p[i]; i++) sum = ((sum << 5) + sum) + p[i];
    return (sum%productsize);
}

int insere_product(produto p){
    int hash_code = hash_p(p);
    while(product_hash[hash_code]) hash_code = (hash_code+1)%productsize;
    if (product_hash[hash_code] == NULL) product_hash[hash_code] = malloc(sizeof(struct s_produto));
    product_hash[hash_code]->validade=1;
    strcpy(product_hash[hash_code]->n_produto,p);
    return hash_code;
}


int readProdutos(char *lista_produtos[productsize] ,int indice_produto_ordenado[]){
  int i,indice;
  for(i=0;lista_produtos[i];i++){
    indice = insere_product(lista_produtos[i]);
    indice_produto_ordenado[i] = indice;
  }
  return i;
}

int encontra_produto(produto p){
    int hash_code = hash_p(p);
    int r = 0;
    while(product_hash[hash_code])
        if (product_hash[hash_code]->validade == 1 && strcmp(product_hash[hash_code]->n_produto,p) == 0) return 1;
        else hash_code = (hash_code+1)%productsize;

    return r;
}


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
