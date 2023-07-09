#include "venda.hpp"
#include <iomanip>

Venda::~Venda() {
  for(auto it=this->m_pedidos.begin(); it!=this->m_pedidos.end(); it++){
    delete *it;
  }
}

void Venda::adicionaPedido(Pedido* p) {
  this->m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  float preco = 0.0;
  int i = 0;
  for(auto it=this->m_pedidos.begin(); it!=this->m_pedidos.end(); it++){
    i++;
    std::cout << "Pedido " << std::to_string(i) << "\n" << (*it)->resumo();
    preco += (*it)->calculaTotal();
  }
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Relatorio de Vendas" << "\nTotal de vendas: R$ " << preco << "\nTotal de pedidos: " << i << std::endl;
}
