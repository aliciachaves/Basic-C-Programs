#include "peixe.h"
using namespace std;

Peixe::Peixe(double peso, char sexo) : Criatura("Peixe") {
    this->_peso = peso;
    this->_sexo = sexo;
    std::cout << "Peixe:" << this->_subtipo << std::endl;
}

Peixe::~Peixe(){
    std::cout << "~Peixe:" << this->_subtipo << std::endl;
}

double Peixe::get_peso(){
    return this->_peso;
}

char Peixe::get_sexo(){
    return this->_sexo;
}

void Peixe::print_info(){
    Criatura::print_info();
    std::cout << "\tPeso:" << this->get_peso() << " kg\n\tSexo: " << this->get_sexo() << std::endl;
}

list<unique_ptr<Criatura>> Peixe::acasalar(shared_ptr<Criatura> c){
    list<unique_ptr<Criatura>> lst;
    shared_ptr<Peixe> outropeixe = dynamic_pointer_cast<Peixe>(c);
    if((c->get_subtipo()=="Peixe")&&(outropeixe->get_sexo()!=this->get_sexo())){
        double mediapeso = ((this->get_peso())+(outropeixe->get_peso()));
        lst.push_back(unique_ptr<Peixe> (new Peixe(mediapeso/2, 'F')));
        lst.push_back(unique_ptr<Peixe> (new Peixe(mediapeso/2, 'M')));

        return lst;
    }
}
