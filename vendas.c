#include "vendas.h"
int readVendas (clients client_hash[clientsize], products product_hash[productsize]){
    FILE *f;
    f = fopen("dados/Vendas_1M.txt","r");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char token[30];
        int i = 0;
        char *p;
        char *preco;
        int qt;
        char *cena;
        char *c;
        int cena1;
        int cena2;
        
        int count = 0;
        char *string;
        int hash_code_c;

        


        while (fgets(token, 64, f)) {
            string = strdup(token);
        
            p = strsep(&string," "); // produto
            //printf("%s\n",p);

            preco = strsep(&string," "); // preço
            //printf("%s\n",preco);
 
            qt = atoi(strsep(&string," ")); // quantidade ??
            //printf("%d\n",qt);

            cena = strsep(&string," "); // cena ??
            //printf("%s\n",cena);

            c = strsep(&string," "); // S ou N
            //printf("%s\n",c);

            cena1 = atoi(strsep(&string," ")); // um int qualquer
            //printf("%d\n",cena1);

            cena2 = atoi(strsep(&string,"\n")); // outro int qualquer
            //printf("%d\n",cena2);
        }
    fclose(f);
    }
    return 0;
}
/*
verificar vendas:
    verificar se existe cliente c
    verificar se existe produto p
    fazer um contador com quantas vendas válidas existem

diverte-te

*/