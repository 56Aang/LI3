
#include <stdio.h>
#include "clientes.h"
#include <stdlib.h>
#include <string.h>

int readClientes(char *clientes[1000000]){
    FILE *f;
    f = fopen("/home/joao/Desktop/LI3/dados/Clientes.txt","r");
    char* token;
    int i=0;
    char cli_code[8];

    while (fgets(cli_code, 8, f)) {
        token = strtok(cli_code,"\r\n");
        printf("%s\n", token);
        clientes[i] = malloc(sizeof(token));
        strcpy(clientes[i],token);
        i++;
    }
    fclose(f);
    return 0;
}