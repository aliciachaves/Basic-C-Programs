#include "aquario.h"
#include "peixe.h"
#include "polvo.h"
#include <memory>

Aquario::Aquario()= default;

Aquario::Aquario(const Aquario &orig){
    for(auto it=orig._criaturas.begin(); it!=orig._criaturas.end(); it++) {
        if(it->get()->get_subtipo()=="Peixe"){
            auto peixe = dynamic_pointer_cast<Peixe>(*it);
            auto copy = make_shared<Peixe>(*peixe);
            this->_criaturas.push_back(copy);
        } else if(it->get()->get_subtipo()=="Polvo"){
            auto polvo = dynamic_pointer_cast<Peixe>(*it);
            auto copy = make_shared<Peixe>(*polvo);
            this->_criaturas.push_back(copy);
        }
    }
}

void Aquario::add_peixe(double peso, char sexo){

    std::shared_ptr<Peixe> px(new Peixe(peso, sexo));
    _criaturas.push_back(px);
}


void Aquario::add_polvo(double qi){
    std::shared_ptr<Polvo> pv(new Polvo(qi));
    _criaturas.push_back(pv);

}

void Aquario::acasalamento(int id1, int id2){
    if(id1>=_criaturas.size()||id2>=_criaturas.size()) {return;}
    if(id1<_criaturas.size()||id2<_criaturas.size()) {
        shared_ptr<Criatura> a = _criaturas.at(id1);
        shared_ptr<Criatura> b = _criaturas.at(id2);
        auto r = a->acasalar(b);
        list<unique_ptr<Criatura>>::iterator it;
        for (it = r.begin(); it != r.end(); it++) {
            _criaturas.push_back(move(*it));
        }
    }
}

void Aquario::print(){
    std::cout << "=============\nAquario Info: " << std::endl;
    vector<shared_ptr<Criatura>>::iterator it;
    for(it=_criaturas.begin(); it!=_criaturas.end(); it++) {
        it->get()->print_info();
    }
    std::cout << "=============" << std::endl;
}
