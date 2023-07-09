#ifndef HAMBURGUER_H
#define HAMBURGUER_H

#include "produto.hpp"
#include <string>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um produto do tipo Hamburguer.
 *
 */
class Hamburguer : public Produto {
 public:

  Hamburguer(const std::string& tipo,
             bool artesanal,
             int qtd,
             float valor_unitario);

  std::string descricao() const override;

 private:
  std::string tipo;
  bool artesanal;
};
#endif
