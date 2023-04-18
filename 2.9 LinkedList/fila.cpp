#include "fila.h"


Fila::Fila() {
	this->primeiro_ = nullptr;
	this->ultimo_ = nullptr;
}


string Fila::primeiro() {
	if (!vazia()) {
		return primeiro_->chave;
	}
}
 
string Fila::ultimo() {
	if (!vazia()) {
		return ultimo_->chave;
	}
}

bool Fila::vazia() {
	return (this->primeiro_ == nullptr && this->ultimo_ == nullptr);
}

void Fila::Inserir(string k) {
	No* novo = new No;
	novo->chave = k;
	novo->proximo = nullptr;
    if (vazia()) {
        primeiro_ = novo;
    } else {
        ultimo_->proximo = novo;
    }
  ultimo_ = novo;
}


void Fila::Remover() {
	if (!vazia()) {
		primeiro_ = primeiro_->proximo;
		if (primeiro_ == nullptr) {
			ultimo_ = nullptr;
		}
	}
}

int Fila::tamanho() {
	int tam = 0;
	No* current = primeiro_;
	while (current != nullptr) {
		current = current->proximo;
		tam++;		
	}
	return tam;
}

Fila::~Fila() {
	while (!vazia()) {
		Remover();
	}
}
