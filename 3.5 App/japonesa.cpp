#include "japonesa.hpp"

std::string Japonesa::descricao() const {

  std::string desc = std::to_string(this->getQtd()) + "X Comida japonesa - " + this->combinado + ", "
            + std::to_string(this->sushis) + " sushis, "
            + std::to_string(this->temakis) + " temakis e "
            + std::to_string(this->hots) + " hots.";
  return desc;
}


Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  
                    this->combinado = combinado;
                    this->sushis = sushis;
                    this->temakis = temakis;
                    this->hots = hots;
                    m_qtd = qtd;
                    m_valor_unitario = valor_unitario;
}
