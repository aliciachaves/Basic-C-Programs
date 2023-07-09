#include <string>

#include "Estoque.h"

bool Estoque::pertence(const std::string& s){
    if(this->estoque.size()==0){
        return false;
    } else{
    for(auto it=this->estoque.begin(); it!=this->estoque.end(); it++){
        if(it->first==s){
            return true;
        }
    }
    }
    return false;
}

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if(!pertence(mercadoria)){
    this->estoque.insert(std::pair<std::string, int>(mercadoria, qtd));
  } else {
    for(auto it=this->estoque.begin(); it!=this->estoque.end(); it++){
        if(it->first==mercadoria){
            it->second += qtd;
        }
    }
  }
}


void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
    if(pertence(mercadoria)){
        for(auto it=this->estoque.begin(); it!=this->estoque.end(); it++){
            if(it->first==mercadoria){
                if(it->second>=qtd){
                    it->second -= qtd;
                }else{
                    throw ExcecaoMercadoriaInsuficiente {mercadoria};
                }
            }
        }

    } else{
        throw ExcecaoMercadoriaInexistente {mercadoria};
    }
}



unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  for(auto it=this->estoque.begin(); it!=this->estoque.end(); it++){
    if(it->first==mercadoria){
        return it->second;
    }
  }
  return 0;
}


void Estoque::imprime_estoque() const {
    for(auto it=this->estoque.begin(); it!=this->estoque.end(); it++){
        std::cout << it->first << ", " << it->second << std::endl;
    }
}


Estoque& Estoque::operator += (const Estoque& rhs) {
  for(auto it = rhs.estoque.begin(); it!=rhs.estoque.end(); it++){
            this->add_mercadoria(it->first, it->second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for(auto it = rhs.estoque.begin(); it!=rhs.estoque.end(); it++){
            this->sub_mercadoria(it->first, it->second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
        for(const auto l : lhs.estoque){
            if(!rhs.pertence(l.first)){
                return false;
                }
            else{
                for(const auto r : rhs.estoque){
                    for(const auto l : lhs.estoque){
                        if(r.first==l.first){
                            if(r.second<=l.second){
                                return false;
                            }
                        }
            }
                }
        }

}
    return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
    for(const auto r : rhs.estoque){
            if(!lhs.pertence(r.first)){
                return false;
                }
            else{
                for(const auto l : lhs.estoque){
                    for(const auto r : rhs.estoque){
                        if(r.first==l.first){
                            if(l.second<=r.second){
                                return false;
                            }
                        }
            }
                }
        }

}
    return true;
}
