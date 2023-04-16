#include "Catalogo.h"

void Catalogo::adicionar_produto(std::string nome, int idade_minima, float valor){
    this->_id++;
    _produtos.push_back(new Brinquedo(this->_id, valor, nome, idade_minima));
}
void Catalogo::adicionar_produto(std::string titulo, std::string autor, int ano, float valor){
    this->_id++;
    _produtos.push_back(new Livro(this->_id, valor, titulo, autor, ano));
}
void Catalogo::adicionar_produto(std::string marca, std::string modelo, float valor){
    this->_id++;
    _produtos.push_back(new Eletronico(this->_id, valor, marca, modelo));
}
Produto* Catalogo::buscar_produto(int id){
    int n = this->_id;
    int i = 0;
    while(n>=0){
        if(_produtos[i]->id )

        n--;
        i++;
    }
}
void Catalogo::imprimir(){

}
