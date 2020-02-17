//
// Created by Pedro Miguel De Soveral Pacheco Barbosa on 17/02/2020.
//

#ifndef LI3_PRODUTOS_H
#define LI3_PRODUTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define productsize 500000
typedef char *product; // o cliente é uma string

typedef struct s_product{
    int validade;
    char n_product[6];
    //char * produto;
}*products;

void init_product(products product_hash[productsize]);
int insere_product(products product_hash[productsize],product c);
int readProducts(products product_hash[productsize]);
int hash_p(product c);
int encontra_Product(product p, products product_hash[productsize])

#endif //LI3_PRODUTOS_H
