#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;
using namespace std;


void FilaDePrioridade::Adicionar(Pessoa p) {
	bool in = false;
	list<Pessoa>::iterator it;
	if (lista_.empty() == true) {
		lista_.push_back(p);
	}
	else {
		for (it = lista_.begin(); it != lista_.end(); ++it) {
			if (p.prioridade > it->prioridade) {
				lista_.insert(it, p);
				in = true;
				break;
			}
			if (p.prioridade == it->prioridade) {
				while (p.prioridade == it->prioridade) {
					it++;
				}
				lista_.insert(it, p);
				in = true;
				break;
			}
		}

		if (in == false) {
			lista_.push_back(p);
		}
	}	
}


string FilaDePrioridade::RemoverMaiorPrioridade() {
	if (!lista_.empty()) {
		Pessoa p = lista_.front();
		string nome = p.nome;
		lista_.pop_front();
		return nome;
	}
	else {
		return 0;
	}
	
}

void FilaDePrioridade::Remover(string nome) {
	list<Pessoa>::iterator it;
	for (it = lista_.begin(); it != lista_.end(); ++it) {
		if (it->nome == nome) {
			it = lista_.erase(it);
		}
	}
		
}

int FilaDePrioridade::tamanho() {
	return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
	vector<string> v;
	list<Pessoa>::iterator it;
	for (it = lista_.begin(); it != lista_.end(); ++it) {
		v.push_back(it->nome);
	}
	return v;
}
