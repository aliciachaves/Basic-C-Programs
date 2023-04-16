#ifndef CAMINHAOAUTONOMO_H
#define CAMINHAOAUTONOMO_H

#include "veiculo.hpp"
#include "caminhao.hpp"
#include <iostream>
#include <string>
using namespace std;


class CaminhaoAutonomo : public Caminhao{

    protected:
    string _fabricante;

    public:
    CaminhaoAutonomo(int velo_max, int n_passageiros, int carga_max, string fabricante);

    virtual ~CaminhaoAutonomo(){
        cout << "Destrutor CaminhaoAutonomo" << endl;
    }


    int estima_preco() override;
    

    void print_info() override;

};

#endif
