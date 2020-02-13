#include "clientes.h"


int main() {
    //FILE *f;

    //f = fopen("/home/joao/Desktop/LI3/dados/Clientes.txt","r");
    char *clientes[1000000];
   // char cli_code[8];
   // int i = 0;
   // char* token;


/*
    while (fgets(cli_code, 8, f)) {
        token = strtok(cli_code,"\r\n");
        printf("%s\n", token);
        clientes[i] = malloc(sizeof(token));
        strcpy(clientes[i],token);
        i++;
    }

*/
    readClientes(clientes);


    /*    char cliente;
    int ncliente;
    fscanf(f,"%c%d\n",&cliente, &ncliente);
    printf("%c , %d", cliente , ncliente);
 */
    //fclose(f);
    return 0;
}
