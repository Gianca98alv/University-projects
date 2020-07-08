#include "Posicion.h"



Posicion::Posicion() {}
Posicion::Posicion(int i, int j, Ficha* ficha) :
	i(i),
	j(j),
	ficha(ficha) {
}

Posicion::~Posicion() {
	cout << "borrando la posicion \n";
	delete ficha;
}

Ficha* Posicion::getFicha() { return ficha; }
int Posicion::getI() { return i; }
int Posicion::getJ() { return j; }

void Posicion::setFicha(Ficha* ficha) { this->ficha = ficha; }

string Posicion::toString() {
	stringstream s;
	s << i << "," << j << " ";
	return s.str();
}
