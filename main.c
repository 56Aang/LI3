#include "headers/clientes.h"
#include "headers/produtos.h"
#include "headers/faturacao.h"
#include <time.h>


//Função de comparação entre duas strings
int cstring_cmp(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
    /* strcmp functions works exactly as expected from
    comparison function */
}

//Função que lê o ficheiro de vendas fornecido e atribui às variáveis
//da estrutura criada o conteúdo do ficheiro após validação da venda
int readVendas (){
    FILE *f;
    f = fopen("dados/Vendas_1M.txt","r");
    FILE *vendasValidas;
    vendasValidas = fopen("dados/vendasValidas.txt", "w");
    if (f==NULL) printf("não encontrou ficheiro");
    else {
        char token[64];
        int i = 0;
        int count = 0;
        char *p; // Código do produto
        float preco; //Preço da venda
        int qt; //Quantidade da venda
        char *tipo_compra; //Tipo da compra, Normal(N) ou Promoção(P)
        char *c; //Código do cliente
        int mes; //Mês da venda
        int filial; //Filial responsável pela venda
        char *string; //Guarda a linha da venda





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

            //Validação das vendas, caso encontre o código de cliente e o código de produto
            //insere na estrutura todas as informações na linha da venda previamente copiadas
            if(encontra_cliente(c)!=-1 && encontra_produto(p)!=-1){
                //Conta o número total de vendas válidas
                count ++;
                //Função de inserção numa hashtable
                insere_faturacao(p,preco,qt,tipo_compra[0],c,mes,filial);
                //Escreve no ficheiro todas as vendas válidas
                fprintf(vendasValidas,"%s", token);
            }

            i++;
        }
        //Fecho dos ficheiro previamente lido
        fclose(f);
        //Fecho do ficheiro onde se estava a escrever
        fclose(vendasValidas);
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

    //Inicialização dos clientes
    init_client();
    //Inicialização dos produtos
    init_product();

    //Alocação de memória para clientes e produtos
    char **lista_clientes = calloc(clientsize,sizeof(char[5]));
    int *indice_cliente_ordenado = calloc(clientsize,sizeof(int));
    char **lista_produtos = calloc(productsize,sizeof(char[6]));
    int *indice_produto_ordenado = calloc(productsize,sizeof(int));




    //Clientes

    total_clientes = readClientes_lista(lista_clientes); // ficheiro -> array de strings / total_clientes
    //Ordena o array de clientes
    qsort(lista_clientes,total_clientes,sizeof(lista_clientes[0]),cstring_cmp); // ordenar array de strings por ordem crescente
    //Preenche o array com os indices hash ordenados, uma vez que o array já vem ordenado
    readClientes(lista_clientes,indice_cliente_ordenado);
    while(lista_clientes[i]) {
        //printf("%s\n",lista_clientes[i]);
        free(lista_clientes[i++]);
    }


    //Produtos

    total_produtos = readProdutos_lista(lista_produtos);
    i=0;
    //Ordena o array de produtos
    qsort(lista_produtos,total_produtos,sizeof(lista_produtos[0]),cstring_cmp);
    //Preenche o array com os indices hash ordenados, uma vez que o array já vem ordenado
    readProdutos(lista_produtos, indice_produto_ordenado);
    while(lista_produtos[i]){
        //printf("%s\n",lista_produtos[i]);
        free(lista_produtos[i++]);
    }


    clock_t t2;
    t2 = clock();

    //Inicialização da estrutura referente ás vendas
    init_faturacao();
    //Leitura do ficho das vendas e atribuição dos valores às variáveis da estrutura
    readVendas();

    int f2 = contaVendasFilial(1);
    printf("%d vendas da filial 1\n",f2);
    double total = faturacaoTotal();
    printf("%f de faturacao total\n", total);

    t2 = clock() - t2;
    printf("%f segundos - vendas\n",((double)t2)/CLOCKS_PER_SEC);


    //free (client_hash);
    //free (product_hash);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f segundos\n",time_taken );

    return 0;
}
