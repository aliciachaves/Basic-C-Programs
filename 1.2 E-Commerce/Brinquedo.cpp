#include "Brinquedo.h"

Brinquedo::Brinquedo(int id, float valor, std::string nome, int idade_minima):Produto(id, valor){
    this->_nome = nome;
    this->_idade_minima = idade_minima;
}
void Brinquedo::imprimir_info() {
    std::cout << this->_id << "Brinquedo " << this->_nome << " " << this->_idade_minima << " " << this->_valor_unitario << std::endl;
}
