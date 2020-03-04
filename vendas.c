#include "vendas.h"


int readVendas (clients client_hash[clientsize], products product_hash[productsize]){
    FILE *f;
    f = fopen("dados/Vendas_1M.txt","r");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char token[64];
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
        
            p = strsep(&string," ");
            //printf("%s\n",p);

            preco = strsep(&string," ");
            //printf("%s\n",preco);

            qt = atoi(strsep(&string," "));
            //printf("%d\n",qt);

            tipo_compra = strsep(&string," ");
            //printf("%s\n",tipo_compra);

            c = strsep(&string," ");
            //printf("%s\n",c);

            mes = atoi(strsep(&string," "));
            //printf("%d\n",mes);

            filial = atoi(strsep(&string,"\n"));
            //printf("%d\n",filial);
           

            hash_code_c = encontra_cliente(c,client_hash);
            product_bought guia;
            product_bought guia2;

            if(hash_code_c != -1 && encontra_produto(p, product_hash)){
                count ++;
                product_bought aux_prod = malloc(sizeof(struct s_product_bought));
                strcpy(aux_prod->n_produto,p);
                aux_prod->next = NULL;
                aux_prod->preco = malloc(8 * sizeof(char)); // é preciso verificar/arranjar melhor maneira
                strcpy(aux_prod->preco, preco);
                aux_prod->quantidade = qt;
                aux_prod->tipo_compra = tipo_compra[0];
                aux_prod->mes = mes;
                aux_prod->filial = filial;

                

                if (client_hash[hash_code_c]->p){
                    guia2 = client_hash[hash_code_c]->p;
                    guia = client_hash[hash_code_c]->p->next;
                    
                    while(guia) {
                        guia2 = guia;
                        guia = guia->next;
                    }
                    guia2->next = aux_prod;
                }
                else client_hash[hash_code_c]->p = aux_prod;
            }
        
            
            i++;
        }
        fclose(f);
        printf("%d\n",count );
    }
    return 0;
}

/*

int insereVendas (clients client_hash[clientsize], products product_hash[productsize],char *arrvendas[]){
    char *p;
    char *preco;
    int i;
    int qt;
    char *tipo_compra;
    char *c;
    int mes;
    int filial;
        
    int count = 0;
    char *string;
    int hash_code_c;




#pragma omp parallel for
for(i=0;i<1000000;i++){
            
        string = strdup(arrvendas[i]);
        p = strsep(&string," ");
        printf("%s\n",p);
        preco = strsep(&string," ");
        printf("%s\n",preco);
        qt = atoi(strsep(&string," "));
        printf("%d\n",qt);
        tipo_compra = strsep(&string," ");
        printf("%s\n",tipo_compra);
        c = strsep(&string," ");
        printf("%s\n",c);
        mes = atoi(strsep(&string," "));
        printf("%d\n",mes);
        filial = atoi(strsep(&string,"\n"));
        printf("%d\n",filial);
    }
    
        
    
    return 0;
}




void readVendas2(char * arrvendas[]){
    FILE *f;
    f = fopen("dados/Vendas_1M.txt","r");
    int i = 0;
    if (f==NULL) printf("não encontrou ficheiro");
    else {

        char token[64];

        while (fgets(token, 64, f)){
            arrvendas[i] = malloc(sizeof(char [64]));
            strcpy(arrvendas[i],token);
            //printf("%s\n",arrvendas[i] );
            i++;
        }
    }
    fclose(f);
}
*/