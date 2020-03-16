#include "headers/faturacao.h"

typedef struct s_vendas{
    char n_produto[7]; //Código produto
    float preco; //Preço produto
    int qt; //Quantidade vendida
    char tipo_compra; //Tipo de compra: Normal(N) ou Promoção(P)
    char n_cliente[6]; //Código cliente
    int mes; //Mẽs da venda
    int filial; //Filial responsável pela venda
}*faturacao;

//Array de estruturas para as vendas
faturacao *faturacao_hash;

//Função que calcula o índice de hash de cada venda
int hash_F(char *p, char *c){
    unsigned long int sum = 5381;
    for(int i = 0; p[i]; i++) sum = ((sum << 5) + sum) + p[i];
    for(int i = 0; c[i]; i++) sum = ((sum << 5) + sum) + c[i];
    return (sum%faturacaosize);
}

//Função de inicialização da estrutura com respetiva alocação de memória
void init_faturacao(){
    faturacao_hash = calloc(1500000,sizeof(struct s_vendas));
}

//Função de inserção da venda validada na estrutura construída
int insere_faturacao(char* p,float preco,int qt,char tipo_compra,char* c,int mes,int filial){
    int hash_code = hash_F(p,c);
    //Procura por uma posição válida no array
    while(faturacao_hash[hash_code]) hash_code++;
    //Alocação de memória dentro da posição do array
    faturacao_hash[hash_code] = malloc(sizeof(struct s_vendas));
    //Atribuição dos valores a cada variável
    strcpy(faturacao_hash[hash_code]->n_produto,p);
    faturacao_hash[hash_code]->preco = preco;
    faturacao_hash[hash_code]->qt = qt;
    faturacao_hash[hash_code]->tipo_compra = tipo_compra;
    strcpy(faturacao_hash[hash_code]->n_cliente,c);
    faturacao_hash[hash_code]->mes = mes;
    faturacao_hash[hash_code]->filial = filial;

    return 0;
}

//Função que conta o numero de vendas de uma filial
int contaVendasFilial(int f){
  int i;
  int count = 0;
  for(i=0;i<faturacaosize;i++){
    if(faturacao_hash[i])
      if((faturacao_hash[i]->filial) == f) count++;
  }
  return count;
}


//Função que calcula o valor total de faturação total
double faturacaoTotal(){
  int i;
  double total=0;
  for(i=0;i<faturacaosize;i++)
    if(faturacao_hash[i]) total += faturacao_hash[i]->preco * faturacao_hash[i]->qt;
  return total;
}

//Função de comparação entre duas strings
int cstring_cmp2(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
    /* strcmp functions works exactly as expected from
    comparison function */
}

//Função que retorna um array com os clientes, ordenados, de uma certa filial
int clientesOrdenadosFilial(char **c_f_o, int f){
  int i,pArray=0;
  for(i=0;i<faturacaosize;i++)
    if (faturacao_hash[i])
      if(faturacao_hash[i]->filial == f){
        c_f_o[pArray] = calloc(6,sizeof(char));
        strcpy(c_f_o[pArray++],faturacao_hash[i]->n_cliente);
      }
  qsort(c_f_o,pArray,sizeof(char),cstring_cmp2);
  return pArray;
}
