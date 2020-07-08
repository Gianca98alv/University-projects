#ifndef MANO_H
#define MANO_H

#include <iostream>
#include <sstream>

#include "Mazo.h"

class Mano{
protected:
	// el tamanno de mano[] es 11,
	//porque es el numero maximo de cartas que puede tener un jugador sin pasarse de 21	
	Carta *mano[11];
	Mazo* mazo;
	int cont;
	int tam;

public:
	Mano();
	~Mano();
	//metodos
	void setMazo(Mazo* m) { mazo = m; }
	Mazo * getMazo() { return mazo; }
	Carta * getPos() { return mano[0]; }
	void agregarCarta();
	void limpiar();
	int pts();
	int convertir();

	std::string MuestraMazo();
	std::string MuestraMazoD();
};
#endif
