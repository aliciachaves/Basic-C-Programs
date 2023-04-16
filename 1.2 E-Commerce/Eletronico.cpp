#include "Eletronico.h"

Eletronico::Eletronico(int id, float valor, std::string marca, std::string modelo):Produto(id, valor){
    this->_marca = marca;
    this->_modelo = modelo;
}
void Eletronico::imprimir_info(){
    std::cout << this->_id << "Eletronico " << this->_marca << " " << this->_modelo << " " << this->_valor_unitario << std::endl;
}
