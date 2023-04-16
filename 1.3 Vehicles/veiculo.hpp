#ifndef VEICULOS_H
#define VEICULOS_H
#include <string>
#include <iostream>
using namespace std;

class Veiculo{

    private:
    int id=0; 
    string _subtipo;
    static int next_id;
    
    protected:
    int _velo_max;
    int _n_passageiros;

    public:
    Veiculo(string subtipo, int velo_max, int n_passageiros);
 
    virtual ~Veiculo(){
    cout << "Destrutor Veiculo" << endl;
}

    int get_id();

    virtual int estima_preco()=0;
    
    virtual void print_info()=0;

};

#endif
