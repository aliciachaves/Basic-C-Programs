#include <iostream>
#include "vetor.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    try {
        int inicio, fim;
        cin >> inicio >> fim;
        if (inicio > fim) {
            throw IntervaloVazio{ inicio, fim };
        }
        Vetor v(inicio, fim);
        char opcao;
        while (cin >> opcao) {
            int indice = -300;
            string valor;
            if (opcao == 'a') {
                cin >> indice;
                if (!(indice >= inicio && indice <= fim)) {
                    throw IndiceInvalido{ inicio, fim, indice };
                }
                string valor;
                cin >> valor;
                v.atribuir(indice, valor);
            }
            else if (opcao == 'v') {
                cin >> indice;
                if (!(indice >= inicio && indice <= fim)) {
                    throw IndiceInvalido{ inicio, fim, indice };
                }
                if (v.valor(indice)=="") {
                throw IndiceNaoInicializado{ indice };
                }
                string valor = v.valor(indice);
                cout << valor << endl;
            }
            else if (opcao == 'f') {
                return 0;
            }
            else {
                cout << "Opção inválida!" << endl;
            }
        }
    }
    catch (IntervaloVazio e) {
        cout << "Não foi possível executar a operação: intervalo [" << e.inicio << ", " << e.fim << "] é vazio." << endl;
    }
    catch (IndiceNaoInicializado e) {
        cout << "Não foi possível executar a operação: índice " << e.indice << " não foi inicializado." << endl;
    }
    catch (IndiceInvalido e) {
        cout << "Não foi possível executar a operação: índice " << e.indice << " não pertence ao intervalo [" << e.inicio << ", " << e.fim << "]." << endl;
    }
    catch (...) {
        cout << "Erro desconhecido!" << endl;
    }
    return 0;
}
