#include "vetor.h"
#include <vector>


Vetor::Vetor(int inicio, int fim) {
	if (fim >= inicio) {
		this->inicio_ = inicio;
		int leng = fim - inicio + 1;
		this->elementos_ = new string[leng];
	}
}


void Vetor::atribuir(int i, std::string valor) {
	if ((i >= this->inicio_)) {
		int index = i - this->inicio_;
		this->elementos_[index] = valor;
	}
}


string Vetor::valor(int i) const {
	if ((i >= this->inicio_) && !this->elementos_[i - this->inicio_].empty()) {
		int index = i - this->inicio_;
		return this->elementos_[index];
	} else{
	    return "";
	}
}

Vetor::~Vetor() {
	delete[] elementos_;
}
