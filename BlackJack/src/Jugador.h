#ifndef JUGADOR_H
#define JUGADOR_H

#include "JugadorGenerico.h"

class Jugador : public JugadorGenerico {
	JugadorGenerico* jugado;
public:
	//constructor y destructor
	Jugador();
	~Jugador();

	//metodos
	void pedirCarta();
	bool sePaso();
};

#endif