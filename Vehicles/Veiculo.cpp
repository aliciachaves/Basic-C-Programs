#include "veiculo.hpp"
#include <iostream>

using namespace std;

int Veiculo::next_id = 0;

Veiculo::Veiculo(string subtipo, int velo_max, int n_passageiros){
    this->_subtipo = subtipo;
    this->_velo_max = velo_max;
    this->_n_passageiros = n_passageiros;

    next_id++;
    this->id = next_id;

}

int Veiculo::get_id(){
    return this->id;
}


void Veiculo::print_info(){
    cout << "Info: Veiculo " << this->get_id() << "\nPreco estimado: RS " << this->estima_preco() << ",00\n\tSubtipo: "
    << this->_subtipo << "\n\tVelocidade maxima: " << this->_velo_max << "km/h\n\tCapacidade de passageiros: "
    << this->_n_passageiros << endl;
}
