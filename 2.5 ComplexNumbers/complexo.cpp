#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
	this->real_ = 0.0;
	this->imag_ = 0.0;
}

Complexo::Complexo(double a, double b) {
	this->real_ = sqrt(a*a + b*b);
	this->imag_ = atan2(b,a);

}

double Complexo::real() {
	return this->real_*cos(this->imag_);
}

double Complexo::imag() {
	return this->real_ * sin(this->imag_);
}

bool Complexo::igual(Complexo x) {
	if (this->real_ == x.real_ && this->imag_ == x.imag_) {
		return true;
	}
	else {
		return false;
	}
}

void Complexo::Atribuir(Complexo x) {
	this->real_ = x.real_;
	this->imag_ = x.imag_;
}

double Complexo::modulo() {
	return this->real_;
}

Complexo Complexo::conjugado() {
	Complexo c;
	c.real_ = this->real_;
	c.imag_ = (this->imag_) * (-1);
	return c;
}

Complexo Complexo::simetrico() {
	Complexo c;
	c.real_ = (this->real_) * (-1);
	c.imag_ = (this->imag_) * (-1);
	return c;
}

Complexo Complexo::inverso() {
	Complexo i;
	return i;
}

Complexo Complexo::somar(Complexo y) {
	Complexo s;
	s.real_ = this->real_ + y.real_;
	s.imag_ = this->imag_ + y.imag_;
	return s;
}

Complexo Complexo::subtrair(Complexo y) {
	Complexo s;
	s.real_ = this->real_ - y.real_;
	s.imag_ = this->imag_ - y.imag_;
	return s;
}

Complexo Complexo::multiplicar(Complexo y) {
	Complexo p;
	p.real_ = this->real_ * y.real_;
	p.imag_ = this->imag_ * y.imag_;
	return p;
}

Complexo Complexo::dividir(Complexo y) {
	Complexo d;
	d.real_ = this->real_ / y.real_;
	d.imag_ = this->imag_ / y.imag_;
	return d;
}
