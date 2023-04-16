#include "Pedido.h"

Pedido::Pedido(Produto* produto, int quantidade){
    this->_produto = produto;
    this->_quantidade = quantidade;
}
double Pedido::get_valor_total(){
    return ((this->_produto->getValor())*this->_quantidade);
}

int Pedido::getQuant(){
    return this->_quantidade;
}
