#ifndef E_COMMERCE_CARRINHO_H
#define E_COMMERCE_CARRINHO_H

#include <vector>
#include "Pedido.h"
#include "Produto.h"

class Carrinho{
private:
    std::vector<Pedido*> _pedidos;
public:
    void adicionar_pedido(Produto* produto, int quantidade);
    void imprimir_resumo();
    float totalpedidos = 0;
};

#endif
