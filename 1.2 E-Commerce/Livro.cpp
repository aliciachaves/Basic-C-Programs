#include "Livro.h"

Livro::Livro(int id, float valor, std::string titulo, std::string autor, int ano):Produto(id, valor){
    this->_titulo = titulo;
    this->_autor = autor;
    this->_ano = ano;
}
void Livro::imprimir_info() {
    std::cout << this->_id << "Livro " << this->_titulo << " " << this->_autor << " " << this->_ano << " " << this->_valor_unitario << std::endl;

}
