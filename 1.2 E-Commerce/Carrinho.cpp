#include "Carrinho.h"

void Carrinho::adicionar_pedido(Produto* produto, int quantidade){
    _pedidos.push_back(new Pedido(produto, quantidade));
    totalpedidos++;
}
void Carrinho::imprimir_resumo(){
    int i = 0;
    float total = 0;
    while(totalpedidos>=0) {
        std::cout<< "Qtde: " << _pedidos[i]->getQuant() << "Total Produto: " << _pedidos[i]->get_valor_total() << std::endl;
        totalpedidos -= 1;
        total += _pedidos[i]->get_valor_total()*_pedidos[i]->getQuant();
        i++;
    }
    std::cout << "Total Carrinho: " << total << std::endl;

}
