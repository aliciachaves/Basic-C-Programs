
#ifndef E_COMMERCE_LIVRO_H
#define E_COMMERCE_LIVRO_H

#include "Produto.h"


class Livro : public Produto{

private:
    std::string _titulo;
    std::string _autor;
    int _ano;
public:
    Livro(int id, float valor, std::string titulo, std::string autor, int ano);
    void imprimir_info() override;
};

#endif
