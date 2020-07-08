#ifndef TABLERO_H
#define TABLERO_H
#include "Ficha.h"
#include "Posicion.h"
#include <iostream>

class Tablero {

private:

	Posicion* tablero[8][8];

public:
	Tablero();
	~Tablero();
	void agregar(Ficha*, int, int);
	Ficha* getFicha(int i, int j);
	Posicion* getPos(int i, int j);
	string toString();

};
#endif 