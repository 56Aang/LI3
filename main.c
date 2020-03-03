#include "clientes.h"
#include "produtos.h"
#include "vendas.h"
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

int main() {
    clock_t t;
    t = clock();
    //int t1;
    int i = 0;
    int total_clientes;
    int total_produtos;


    char *lista_clientes[clientsize];// = calloc(5,sizeof(char));
    int indice_cliente_ordenado[clientsize];
    char *lista_produtos[clientsize];
    int indice_produto_ordenado[productsize];
    clients *client_hash = calloc(clientsize , sizeof(struct s_cliente)); // inicialização da hash_table de clientes
    products *product_hash = calloc(productsize , sizeof(struct s_produto));


    //Clientes
    total_clientes = readClientes_lista(lista_clientes); // ficheiro -> array de strings / total_clientes
    qsort(lista_clientes,total_clientes,sizeof(lista_clientes[0]),cstring_cmp); // ordenar array de strings por ordem crescente
    readClientes(client_hash,lista_clientes,indice_cliente_ordenado);
    while(lista_clientes[i]) {
        //printf("%s\n",lista_clientes[i]);
        free(lista_clientes[i++]);
    }


    //Produtos
    total_produtos = readProdutos_lista(lista_produtos);
    i=0;
    qsort(lista_produtos,total_produtos,sizeof(lista_produtos[0]),cstring_cmp);
    readProdutos(product_hash,lista_produtos, indice_produto_ordenado);
    while(lista_produtos[i]){
        printf("%s\n",lista_produtos[i]);
        free(lista_produtos[i++]);
    }



    clock_t t2;
    t2 = clock();



    //printf("%d\n",getProductsStartedByLetter('F', product_hash) );

   // insereVendas(client_hash,product_hash,arrvendas);

    //readVendas(client_hash,product_hash);








    t2 = clock() - t2;
    printf("%f segundos - vendas\n",((double)t2)/CLOCKS_PER_SEC);


    //free (client_hash);
    //free (product_hash);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f segundos\n",time_taken );

    return 0;
}
