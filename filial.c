#include "headers/filial.h"


typedef struct s_filial{
    char n_produto[7]; //Código produto
    float preco; //Preço produto
    int qt; //Quantidade vendida
    char tipo_compra; //Tipo de compra: Normal(N) ou Promoção(P)
    char n_cliente[6]; //Código cliente
    int mes; //Mẽs da venda
}*filial;
