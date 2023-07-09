#ifndef JAPONESA_H
#define JAPONESA_H

#include "produto.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um produto do tipo Comida Japonesa.
 *
 */
class Japonesa : public Produto {
 public:

  Japonesa(const std::string& combinado,
           int sushis,
           int temakis,
           int hots,
           int qtd,
           float valor_unitario);
  std::string descricao() const override;

 private:
  std::string combinado;
  int sushis;
  int temakis;
  int hots;
};
#endif
