#include "headers/clientes.h"
#include "headers/produtos.h"
#include "headers/faturacao.h"
#include <time.h>
#include <omp.h>



int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
    /* strcmp functions works exactly as expected from
    comparison function */
}


int readVendas (){
    FILE *f;
    f = fopen("dados/Vendas_1M.txt","r");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char token[64];
        int i = 0;
        int count = 0;
        char *p;
        float preco;
        int qt;
        char *tipo_compra;
        char *c;
        int mes;
        int filial;
        char *string;


        


        while (fgets(token, 64, f)) {
            string = strdup(token);
        
            p = strsep(&string," ");
            //printf("%s\n",p);

            preco = (float)atoll(strsep(&string," "));
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
           

            if(encontra_cliente(c)!=-1 && encontra_produto(p)!=-1){
                count ++;
                insere_faturacao(p,preco,qt,tipo_compra[0],c,mes,filial);
            }
            
            i++;
        }
        fclose(f);
        printf("%d\n",count );
    }
    return 0;
}














int main() {
    clock_t t;
    t = clock();
    //int t1;
    int i = 0;
    int total_clientes;
    int total_produtos;

    init_client();
    init_product();

    char **lista_clientes = calloc(clientsize,sizeof(char[5]));
    int *indice_cliente_ordenado = calloc(clientsize,sizeof(int));
    char **lista_produtos = calloc(productsize,sizeof(char[6]));
    int *indice_produto_ordenado = calloc(productsize,sizeof(int));

    


    //Clientes
    total_clientes = readClientes_lista(lista_clientes); // ficheiro -> array de strings / total_clientes
    qsort(lista_clientes,total_clientes,sizeof(lista_clientes[0]),cstring_cmp); // ordenar array de strings por ordem crescente
    readClientes(lista_clientes,indice_cliente_ordenado);
    while(lista_clientes[i]) {
        //printf("%s\n",lista_clientes[i]);
        free(lista_clientes[i++]);
    }


    //Produtos
    total_produtos = readProdutos_lista(lista_produtos);
    i=0;
    qsort(lista_produtos,total_produtos,sizeof(lista_produtos[0]),cstring_cmp);
    readProdutos(lista_produtos, indice_produto_ordenado);
    while(lista_produtos[i]){
        //printf("%s\n",lista_produtos[i]);
        free(lista_produtos[i++]);
    }


    clock_t t2;
    t2 = clock();

    init_faturacao();
    readVendas();




    t2 = clock() - t2;
    printf("%f segundos - vendas\n",((double)t2)/CLOCKS_PER_SEC);


    //free (client_hash);
    //free (product_hash);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f segundos\n",time_taken );

    return 0;
}
