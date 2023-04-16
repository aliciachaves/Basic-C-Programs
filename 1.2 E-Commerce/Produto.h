
#ifndef E_COMMERCE_PRODUTO_H
#define E_COMMERCE_PRODUTO_H
#include <string>
#include <iostream>

class Produto{
protected:
    int _id;
    float _valor_unitario;
public:
    Produto(int id, float valor_unitario);
    virtual void imprimir_info() = 0;
    float getValor();
};

#endif
