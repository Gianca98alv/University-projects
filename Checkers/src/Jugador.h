#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include "Tablero.h"
#include "Reglas.h"


class Jugador {

private:

	string nombre;
	int direc;

public:

	Jugador();
	Jugador(string);
	~Jugador();
	void setNombre(string);
	string getNombre();
	string toString();
	void mover(Tablero*, Restricciones*, int, int, int, int, Posicion*);
	bool sePuedeComer(Tablero*, Restricciones*, int, int, int, int, Posicion*);
	void comer(Tablero*, Restricciones*, int, int, int, int, Posicion*);
};
#endif 

