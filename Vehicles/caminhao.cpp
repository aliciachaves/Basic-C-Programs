#include "caminhao.hpp"
#include "veiculo.hpp"
#include <iostream>
using namespace std;

Caminhao::Caminhao(string subtipo, int velo_max, int n_passageiros, int carga_max):Veiculo(subtipo, velo_max, n_passageiros) {
    this->_carga_max = carga_max;
}

int Caminhao::estima_preco(){
    return (50000 + (100*(this->_carga_max)) + (10*(this->_velo_max)));
}

void Caminhao::print_info(){
    Veiculo::print_info();
    cout << "\n\tCarga maxima: " << this->_carga_max << "kg\n";
}
