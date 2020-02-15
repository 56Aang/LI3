#include "clientes.h"
#include "produtos.h"
#include <time.h>
int main() {
    clock_t t;
    t = clock();
    
 

    clients client_hash[clientsize];
    init_client(client_hash);

  //  char *clientes[clientsize];

    char *produtos[productsize];
   // char *vendas[clientsize];

   
    readClientes(client_hash);
    readProdutos(produtos);

   

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f\n segundos",time_taken );
    return 0;
}
