#include "headers/faturacao.h"

typedef struct s_vendas{
    char *n_produto;
    float preco;
    int qt;
    char tipo_compra;
    char *n_cliente;
    int mes;
    int filial;
}*faturacao;

faturacao *faturacao_hash;

int hash_F(char *p, char *c){
    unsigned long int sum = 5381;
    for(int i = 0; p[i]; i++) sum = ((sum << 5) + sum) + p[i];
    for(int i = 0; c[i]; i++) sum = ((sum << 5) + sum) + c[i];
    return (sum%faturacaosize);
}

void init_faturacao(){
    faturacao_hash = calloc(1500000,sizeof(struct s_vendas));
}


int insere_faturacao(char* p,float preco,int qt,char tipo_compra,char* c,int mes,int filial){
    int hash_code = hash_F(p,c);
    while(!faturacao_hash[hash_code]) hash_code++;
    printf("teste\n");
    faturacao_hash[hash_code]->n_produto = malloc(sizeof(char[6]));
    printf("teste\n");
    strcpy(faturacao_hash[hash_code]->n_produto,p);
    faturacao_hash[hash_code]->preco = preco;

    faturacao_hash[hash_code]->qt = qt;
    faturacao_hash[hash_code]->tipo_compra = tipo_compra;
    faturacao_hash[hash_code]->n_cliente = malloc(sizeof(char[5]));
    strcpy(faturacao_hash[hash_code]->n_cliente,c);
    faturacao_hash[hash_code]->mes = mes;
    faturacao_hash[hash_code]->filial = filial;
    
    return 0;
}