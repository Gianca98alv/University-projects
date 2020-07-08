#ifndef MAZO_H
#define MAZO_H

#include <cstdlib>


#include "Carta.h"

#define cant 52

class Mazo {
	Carta* carta[cant];
	Carta* card;
	int cont;
public:
	//constructor y destructor
	Mazo();
	~Mazo();
	
	//metodos   
	Carta* getCard() { return card; }
	std::string descifrarValor(int);
	char descifrarPalo(int);
	void inicializar();
	void barajar();
	Carta* tomarCarta();
};

#endif