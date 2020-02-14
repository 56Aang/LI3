
#include "produtos.h"
int readProdutos(char *produtos[productsize]){
    FILE *f;
    f = fopen("dados/Produtos.txt","r");
    char* token;
    int i=0;
    char cli_code[9];

    while (fgets(cli_code, 9, f)) {
        token = strtok(cli_code,"\r\n");
        printf("%s\n", token);
        produtos[i] = malloc(sizeof(token));
        strcpy(produtos[i],token);
        i++;
    }
    fclose(f);
    return 0;
}
