#ifndef POSICION_H
#define POSICION_H
#include "Ficha.h"

class Posicion {

private:
	int i;
	int j;
	Ficha* ficha;

public:
	Posicion();
	Posicion(int, int, Ficha*);
	~Posicion();
	Ficha* getFicha();
	int getI();
	int getJ();
	void setFicha(Ficha*);
	string toString();
};
#endif 