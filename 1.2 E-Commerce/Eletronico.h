#ifndef E_COMMERCE_ELETRONICO_H
#define E_COMMERCE_ELETRONICO_H

#include "Produto.h"


class Eletronico : public Produto{
private:
    std::string _marca;
    std::string _modelo;
public:
    Eletronico(int id, float valor, std::string marca, std::string modelo);
    void imprimir_info() override;

};


#endif
