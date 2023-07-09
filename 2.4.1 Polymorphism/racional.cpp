#include "racional.h"

 Racional::Racional() {
    this->numerador_ = 0;
    this->denominador_ = 1;
}

Racional::Racional(int n)  {
    this->numerador_ = n;
    this->denominador_ = 1;
}

Racional::Racional(int n, int d) {

    if (d == 0) {
        throw ExcecaoDivisaoPorZero {};
    } else{
        this->numerador_ = n;
        this->denominador_ = d;
        Simplificar();
    }

}


int Racional::numerador() const {
    return this->numerador_;
}

int Racional::denominador() const {
    return this->denominador_;
}

  // Retorna o simétrico de *this.
  Racional Racional::operator-() const{
    Racional r;
    r.numerador_ = -numerador_;
    r.denominador_ = -denominador_;
    return r;
  }  

  // Retorna a soma de *this e k.
  Racional Racional::operator+(Racional k) const{

    int novodem = this->denominador_ * k.denominador_;
    int novonum = ((this->numerador_*k.denominador_)+(this->denominador_*k.numerador_));
    Racional r = Racional(novonum, novodem);
    r.Simplificar();
    return r;

  }
  


  // Retorna a subtração de *this e k.
  Racional Racional::operator-(Racional k) const{
    int novodem = this->denominador_ * k.denominador_;
    int novonum = ((this->numerador_*k.denominador_)-(this->denominador_*k.numerador_));
    Racional r = Racional(novonum, novodem);
    r.Simplificar();
    return r;
  }

  // Retorna a multiplicação de *this e k.
  Racional Racional::operator*(Racional k) const{
    int novonum = this->numerador_ * k.numerador_;
    int novodem = this->denominador_ * k.denominador_;
    Racional r = Racional(novonum, novodem);
    r.Simplificar();
    return r;
  }

  // Retorna a divisão de *this por k.
  // PRÉ-CONDIÇÃO: d != 0
  // LANÇA: ExcecaoDivisaoPorZero. 
  Racional Racional::operator/(Racional k) const{
    if(k.numerador_==0){
        throw ExcecaoDivisaoPorZero {};
    } else{
    int novonum = this->numerador_ * k.denominador_;
    int novodem = this->denominador_ * k.numerador_;
    Racional r = Racional(novonum, novodem);
    r.Simplificar();
    return r;
    }
  }

  // Converte um número Racional em um float.
  Racional::operator float() const{
    return static_cast<float>(this->numerador_) / this->denominador_;
  }

  // Converte um número Racional em uma string no formato
  // "numerador_/denominador_".
  Racional::operator string() const{
    return std::to_string(numerador_) + "/" + std::to_string(denominador_);
  }

ostream& operator<<(ostream& out, Racional r) {   
    r.Simplificar();
    out << string(r);
    return out;
}

istream& operator>>(istream& in, Racional& r) {
  in >> r.numerador_ >> r.denominador_;
  r.Simplificar();
  return in;
}

int MDC(int a, int b) {
  if (b == 0) {
    return a;
  }
  return MDC(b, a % b);
}

void Racional::Simplificar() {
  if (denominador_ < 0) {
    numerador_ *= -1;
    denominador_ *= -1;
  }
  int mdc = MDC(abs(numerador_), abs(denominador_));
  numerador_ /= mdc;
  denominador_ /= mdc;
}
