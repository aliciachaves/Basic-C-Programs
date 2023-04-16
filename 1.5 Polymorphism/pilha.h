#ifndef PILHAPOLIMORFICA_PILHA_H
#define PILHAPOLIMORFICA_PILHA_H

#include <iostream>

template<class T>
class Pilha{

private:
    T * _arr;
    int max;
    int _top=-1;

public:

    Pilha(int _max_tam);

    ~Pilha();

    bool push(const T& novo_e);

    bool pop(T& valor);

    bool get_maior(T& valor);

    bool vazia();

    void print();

};

template <class T>
Pilha<T>::Pilha(int _max_tam) {
    _arr = new T[_max_tam];
    max = _max_tam;
}

template<class T>
Pilha<T>::~Pilha() {
    delete[] _arr;
    _top = 0;
    _arr = 0;
    
}

template<class T>
bool Pilha<T>::push(const T& novo_e){
    if(_top+1<max){
        _top++;
        _arr[_top] = novo_e;
        return true;
    } else{
        return false;
    }
}

template<class T>
bool Pilha<T>::pop(T& valor){
    int i = _top;
    if(i> -1) {
        valor = T(_arr[_top]);
        _top--;
        return true;
    } else{
        return false;
}
}

template<class T>
bool Pilha<T>::get_maior(T& valor) {
    if (_top >= 0) {
        T maior = _arr[_top];
            for(int j=0; j<=_top; j++) {
                if (_arr[j] > maior) {
                    maior = _arr[j];
                }
            }
        valor = maior;
        return true;
    } else{
        return false;
    }
}

template<class T>
bool Pilha<T>::vazia(){
    if(_top<0){
        return true;
    } else{
        return false;
    }
}

template<class T>
void Pilha<T>::print(){
        for (int i = 0; i <= _top; i++) {
            std::cout << _arr[i] << std::endl;
        }
}

#endif
