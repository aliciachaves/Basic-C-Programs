#include "criatura.h"

#include <utility>

Criatura::Criatura(string subtipo){
    _subtipo = std::move(subtipo);
    std::cout << "Criatura:" << this->_subtipo << std::endl;
}

Criatura::~Criatura(){
    std::cout << "~Criatura:" << this->_subtipo << std::endl;
}

string Criatura::get_subtipo(){
    return this->_subtipo;
}

void Criatura::print_info(){
    std::cout << "Info:" << this->get_subtipo() << std::endl;
}
