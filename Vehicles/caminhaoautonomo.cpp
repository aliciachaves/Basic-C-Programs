#include "caminhao_autonomo.hpp"
#include <iostream>
#include "veiculo.hpp"
#include "caminhao.hpp"
using namespace std;

    CaminhaoAutonomo::CaminhaoAutonomo(int velo_max, int n_passageiros, int carga_max, string fabricante):Caminhao("CaminhaoAutonomo",velo_max, n_passageiros, carga_max){
        this->_fabricante = fabricante;
    }

    int CaminhaoAutonomo::estima_preco(){

        if(this->_fabricante == "Tesla"){

            return (500000 + (100*(this->_carga_max)) + (10*(this->_velo_max)));

        } else if(this->_fabricante == "Waymo"){

            return (400000 + (100*(this->_carga_max)) + (10*(this->_velo_max)));

        }
    }
    

    void CaminhaoAutonomo::print_info(){
        Caminhao::print_info();
        cout  << "\n\tFabricante: " << this->_fabricante << endl;
    }
