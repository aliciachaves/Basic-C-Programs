#include "dicionario.h"

// Cria um dicionário vazio.
Dicionario::Dicionario() {

}

// Retorna quantos pares chave/valor estão no dicionário.
int Dicionario::tamanho() {
    return this->elementos_.size();
}

// Testa se uma chave pertence ao dicionário.
bool Dicionario::pertence(string chave) {
    for (Elemento e : this->elementos_) {
        if (chave == e.chave) {
            return 1;
        }
    }
    return 0;
}

// Retorna a *menor* chave do dicionário.
// Pré-condição: o dicionário não está vazio.
string Dicionario::menor() {
    if (tamanho() != 0) {
        string menor = this->elementos_.front().chave;
        for (Elemento e : this->elementos_) {
            if (e.chave < menor) {
                menor = e.chave;
            }
        }
        return menor;
    }
    else {
        throw DicionarioVazio{};
    }
}

// Retorna o valor associado a chave.
// Pré-condição: a chave *necessariamente* está no dicionário.
string Dicionario::valor(string chave) {
    if (pertence(chave)) {
        for (Elemento e : this->elementos_) {
            if (e.chave == chave) {
                return e.valor;
            }
        }
    }
    else {
        throw ChaveInexistente{ chave };
    }

}

// Insere um par chave/valor no dicionário.
// Pré-condição: a chave *não* está no dicionário.
void Dicionario::Inserir(string chave, string valor) {
    if (!pertence(chave)) {
        Elemento novo;
        novo.chave = chave;
        novo.valor = valor;
        this->elementos_.push_back(novo);
    }
    else {
        throw ChaveRepetida{ chave };
    }
}

// Remove um par chave/valor do dicionário.
// Pré-condição: a chave *necessariamente* está no dicionário.
void Dicionario::Remover(string chave) {
    if (pertence(chave)) {
        std::list<Elemento>::iterator it;
        for (it = elementos_.begin(); it != elementos_.end(); it++) {
            if (it->chave == chave) {
                it = elementos_.erase(it);
            }
        }
    }
    else {
        throw ChaveInexistente{ chave };
    }
}

// Altera o valor associado a uma chave do dicionário.
// Pré-condição: a chave *necessariamente* está no dicionário.
void Dicionario::Alterar(string chave, string valor) {
    if (pertence(chave)) {
        std::list<Elemento>::iterator it;
        for (it = elementos_.begin(); it != elementos_.end(); it++) {
            if (it->chave == chave) {
                it->valor = valor;
            }
        }
    }
    else {
        throw ChaveInexistente{ chave };
    }

}

// Libera toda a memória alocada para armazenar os dados no
// dicionário.
Dicionario::~Dicionario() {
}
