//
// Created by Pedro Miguel De Soveral Pacheco Barbosa on 17/02/2020.
//

#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_product(products product_hash[productsize]){
#pragma omp parallel for num_threads(2)
    for(int i = 0; i< productsize; i++){
        product_hash[i] = malloc(sizeof(struct s_product));
        product_hash[i]->validade = 0;
    }
}

int hash_p(product c){
    unsigned long int sum = 5381;
    for (int i = 0; c[i]; i++) sum = ((sum << 5) + sum) + c[i];
    return (sum%productsize);
}

int insere_product(products product_hash[productsize],product p){
    int hash_code = hash_p(p);
    while(product_hash[hash_code]) hash_code = (hash_code+1)%productsize;
    product_hash[hash_code] = malloc (sizeof (struct s_product));
    product_hash[hash_code]->validade=1;
    strcpy(product_hash[hash_code]->n_product,p);
    return hash_code;
}

int readProducts(products product_hash[productsize]){
    FILE *f;
    f = fopen("dados/Produtos.txt","r");
    int i = 0;
    char *token;
    char cli_code[8];
    while (fgets(cli_code, 8, f)) {
        token = strtok(cli_code, "\r\n");
        insere_product(product_hash, token);
        i++;
    }
    fclose(f);
    return i;
}

int encontra_Product(product p, products product_hash[productsize]) {
    int hash_code = hash_p(p);
    while(product_hash[hash_code]) {
        if (product_hash[hash_code]->validade && strcmp(product_hash[hash_code]->n_product, p) == 0) return 1;
        hash_code = (hash_code+1)%productsize;
    }
    return 0;
}