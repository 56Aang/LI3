#include "faturaçao.h"

typedef struct s_vendas{
    char n_produto[6];
    float preco;
    int qt;
    char tipo_compra;
    char n_cliente[5];
    int mes;
    int filial;
}*vendas;
