#include "racional.h"

#include <cmath>
#include <iostream>

Racional::Racional() {
    this->numerador_ = 0;
    this->denominador_ = 1;
}

Racional::Racional(int n)  {
    this->numerador_ = n;
    this->denominador_ = 1;
}

Racional::Racional(int n, int d) {
    this->numerador_ = n;
    if (d != 0) {
        this->denominador_ = d;
    }
    
    for (int i = this->denominador_ * this->numerador_; i > 1; i--) {
        if ((this->denominador_ % i == 0) && (this->numerador_ % i == 0)) {
            this->denominador_ /= i;
            this->numerador_ /= i;
        }

    }

}


int Racional::numerador() const {
    return this->numerador_;
}

int Racional::denominador() const {
    return this->denominador_;
}

Racional Racional::simetrico() const {
    return Racional((this->numerador_-(2*this->numerador_)),(this->denominador_));
}

Racional Racional::somar(Racional k) const {
    int novod = k.denominador_*this->denominador_;
    int novon = (this->numerador_*k.denominador_)+(this->denominador_*k.numerador_);
    for (int i = this->denominador_ * this->numerador_; i > 1; i--) {
        if ((novod % i == 0) && (novon % i == 0)) {
            novod /= i;
            novon /= i;
        }
    }
    return Racional(novon, novod);
}

Racional Racional::subtrair(Racional k) const {
    int novod = k.denominador_*this->denominador_;
    int novon = (this->numerador_*k.denominador_)-(this->denominador_*k.numerador_);
    for (int i = this->denominador_ * this->numerador_; i > 1; i--) {
        if ((novod % i == 0) && (novon % i == 0)) {
            novod /= i;
            novon /= i;
        }
    }
    return Racional(novon, novod);
}

Racional Racional::multiplicar(Racional k) const {
    int novod = k.denominador_*this->denominador_;
    int novon = this->numerador_*k.numerador_;
    for (int i = this->denominador_ * this->numerador_; i > 1; i--) {
        if ((novod % i == 0) && (novon % i == 0)) {
            novod /= i;
            novon /= i;
        }
    }
    return Racional(novon, novod);
}

Racional Racional::dividir(Racional k) const {
    int novod = this->denominador_*k.numerador_; 
    int novon = k.denominador_*this->numerador_;
    for (int i = this->denominador_ * this->numerador_; i > 1; i--) {
        if ((novod % i == 0) && (novon % i == 0)) {
            novod /= i;
            novon /= i;
        }
    }
    return Racional(novon, novod);
}
