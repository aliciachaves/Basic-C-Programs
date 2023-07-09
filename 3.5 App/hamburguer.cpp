#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  
  std::string categoria;
  if(this->artesanal==1){
    categoria = " artesanal.";
  } else{
    categoria = " simples.";
  }

  std::string desc = std::to_string(this->getQtd()) + "X Hamburguer " + this->tipo + categoria;
    
  return desc;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {

                        this->tipo = tipo;
                        this->artesanal = artesanal;
                        m_qtd = qtd;
                        m_valor_unitario = valor_unitario;
}
