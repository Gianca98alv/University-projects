#ifndef DEALER_H
#define DEALER_H

#include <iostream>

#include "JugadorGenerico.h"

class Dealer : public JugadorGenerico {

	JugadorGenerico* jugad;

public:
	//constructor y destructor
	Dealer();
	~Dealer();

	//metodos	
	
	void pedirCarta();
	bool sePaso();
};

#endif