//
// Created by joao on 12/02/20.
//

#ifndef LI3_VENDAS_H
#define LI3_VENDAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "produtos.h"
#include <omp.h>
int readVendas (clients client_hash[clientsize], products product_hash[productsize]);
void readVendas2(char * arrvendas[]);
int insereVendas (clients client_hash[clientsize], products product_hash[productsize],char *arrvendas[]);

#endif //LI3_VENDAS_H
