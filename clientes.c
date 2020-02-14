
#include <stdio.h>
#include "clientes.h"
#include <stdlib.h>
#include <string.h>

int readClientes(char *clientes[clientsize]){
    FILE *f;
    f = fopen("dados/Clientes.txt","r");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char *token;
        int i = 0;
        char cli_code[8];

        while (fgets(cli_code, 8, f)) {
            token = strtok(cli_code, "\r\n");
            printf("%s\n", token);
            clientes[i] = malloc(sizeof(token));
            strcpy(clientes[i], token);
            i++;
        }
        fclose(f);
    }
    return 0;
}
