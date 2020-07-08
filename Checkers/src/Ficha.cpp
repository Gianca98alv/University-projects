#include "Ficha.h"



Ficha::Ficha() {
	caracter = ' ';
}

Ficha::Ficha(char c) :
	caracter(c) {
}


Ficha::~Ficha() {
	cout << "borrando la ficha \n";
}

char Ficha::getCaracter() { return caracter; }
void Ficha::setCaracter(char c) { caracter = c; }

bool Ficha::operator==(Ficha* f) const {
	if (f != NULL) { return (caracter == f->caracter); }
	else { return false; }
}
