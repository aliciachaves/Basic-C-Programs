#include "pizza.hpp"

std::string Pizza::descricao() const {

  std::string borda;
  if(this->borda_recheada==1){
    borda = "borda recheada.";
  } else{
    borda = "sem borda recheada.";
  }

  std::string desc = std::to_string(this->getQtd()) + "X Pizza " + this->sabor + ", "
            + std::to_string(this->pedacos) + " pedacos e " + borda;
  return desc;
  }

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {

                this->pedacos = pedacos;
                this->borda_recheada = borda_recheada;
                this->sabor = sabor;
                m_qtd = qtd;
                m_valor_unitario = valor_unitario;
                 

}
