#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "caminhao.hpp"
#include "veiculo.hpp"
#include <iostream>
using namespace std;


class Caminhao : public Veiculo{

    protected:
    int _carga_max;

    public:
    Caminhao(string subtipo, int velo_max, int n_passageiros, int carga_max);

    Caminhao(int velo_max, int n_passageiros, int carga_max);

    virtual ~Caminhao(){
    cout << "Destrutor Caminhao" << endl;
}

    int estima_preco() override;

    void print_info() override;
   
};

#endif
