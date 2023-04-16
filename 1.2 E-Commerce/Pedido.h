#ifndef E_COMMERCE_PEDIDO_H
#define E_COMMERCE_PEDIDO_H

#include "Produto.h"

class Pedido{
private:
    Produto* _produto;
    int _quantidade;
public:
    Pedido(Produto* produto, int quantidade);
    double get_valor_total();
    int getQuant();


};

#endif //E_COMMERCE_PEDIDO_H
