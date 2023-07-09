#ifndef PIZZA_H
#define PIZZA_H

#include "produto.hpp"
#include <string>

class Pizza : public Produto {
 public:

  Pizza(const std::string& sabor,
        int pedacos,
        bool borda_recheada,
        int qtd,
        float valor_unitario);

  std::string descricao() const override;

 private:
  int pedacos;
  bool borda_recheada;
  std::string sabor;
};

#endif
