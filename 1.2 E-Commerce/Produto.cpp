#include "Produto.h"

Produto::Produto(int id, float valor_unitario){
    this->_id = id;
    this->_valor_unitario = valor_unitario;
}

float Produto::getValor(){
    return this->_valor_unitario;
}
