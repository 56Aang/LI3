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
        char *tipo_compra;
        char *c;
        int mes;
        int filial;
        
        int count = 0;
        char *string;
        int hash_code_c;

        


        while (fgets(token, 64, f)) {
            string = strdup(token);
        
            p = strsep(&string," "); // Produto
            //printf("%s\n",p);

            preco = strsep(&string," "); // preço
            //printf("%s\n",preco);
 
            qt = atoi(strsep(&string," ")); // quantidade
            //printf("%d\n",qt);

            tipo_compra = strsep(&string," "); // Normal ou Promoção (N,P)
            //printf("%s\n",cena);

            c = strsep(&string," "); // Cliente
            //printf("%s\n",c);

            mes = atoi(strsep(&string," ")); // mês da compra
            //printf("%d\n",cena1);

            filial = atoi(strsep(&string,"\n")); // filial, onde a venda foi realizada
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