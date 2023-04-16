#ifndef E_COMMERCE_CATALOGO_H
#define E_COMMERCE_CATALOGO_H
#include "Produto.h"
#include "Brinquedo.h"
#include "Livro.h"
#include "Eletronico.h"
#include <vector>
#include <string>

class Catalogo{
private:
    std::vector<Produto*> _produtos;
    int _id = 0;
public:
    void adicionar_produto(std::string nome, int idade_minima, float valor);
    void adicionar_produto(std::string titulo, std::string autor, int ano, float valor);
    void adicionar_produto(std::string marca, std::string modelo, float valor);
    Produto* buscar_produto(int id);
    void imprimir();
};

#endif
