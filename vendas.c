#include "vendas.h"
/*
int readVendas (char *vendas){
    FILE *f;
    f = fopen("dados/Vendas_1M.txt","r");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char *token;
        int i = 0;
        char cli_code[64];

        while (fgets(cli_code, 64, f)) {
            token = strtok(cli_code, " ");
            printf("%s\n", token);
            vendas[i] = malloc(sizeof(token));
            strcpy(clientes[i], token);
            i++;
        }
        fclose(f);
    }
    return 0;
}*/