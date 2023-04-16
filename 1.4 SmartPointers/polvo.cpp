#include "polvo.h"
#include <iostream>
#include <memory>

using namespace std;

Polvo::Polvo(double qi) : Criatura("Polvo") {
    this->_qi = qi;
    std::cout << "Polvo:" << this->_subtipo << std::endl;
}

Polvo::~Polvo(){
    std::cout << "~Polvo:" << this->_subtipo << std::endl;
}

double Polvo::get_qi(){
    return this->_qi;
}

void Polvo::print_info(){
    Criatura::print_info();
    std::cout << "\tQI: " << this->get_qi() << std::endl;
}


list<unique_ptr<Criatura>> Polvo::acasalar(shared_ptr<Criatura> c){

    list<unique_ptr<Criatura>> lst;
    shared_ptr<Polvo> outropolvo = dynamic_pointer_cast<Polvo>(c);

    if(c->get_subtipo()=="Polvo"){

        double qi = ((this->get_qi() + outropolvo->get_qi())/2);
        lst.push_back(unique_ptr<Polvo> (new Polvo(qi)));

        return lst;
    }
}
