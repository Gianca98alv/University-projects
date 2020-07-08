#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include<time.h>
#include "Tablero.h"
#include "Reglas.h"
#include "Vector.h"
using namespace std;


//-----------------------------------------------------------------------------------------------------------------
class Estrategia {
protected:

	int numero_estra;
	int direc;
	bool move = false;
public:
	Estrategia();
	Estrategia(int);
	virtual ~Estrategia();

	virtual void mover(Tablero*, Restricciones*, Vector*, int, int, int, int, Posicion*, int);
	virtual bool sePuedeComer(Tablero*, Restricciones*, int, int, int, int, Posicion*);
	virtual void comer(Tablero*, Restricciones*, int, int, int, int, Posicion*);
	virtual int getNumEst();
	virtual void jugar(Tablero*, Restricciones*, Vector*) = 0;
};

//-----------------------------------------------------------------------------------------------------------------


class EstrategiaAleatoria : public Estrategia {
public:
	EstrategiaAleatoria();
	EstrategiaAleatoria(int);
	virtual~EstrategiaAleatoria();
	virtual void jugar(Tablero*, Restricciones*, Vector*); 
};


//-----------------------------------------------------------------------------------------------------------------


class EstrategiaDefensiva : public Estrategia {
public:
	EstrategiaDefensiva();
	EstrategiaDefensiva(int);
	virtual~EstrategiaDefensiva();
	virtual void jugar(Tablero*, Restricciones*, Vector*); 
};


//-----------------------------------------------------------------------------------------------------------------


class EstrategiaOfensiva : public Estrategia {
public:
	EstrategiaOfensiva();
	EstrategiaOfensiva(int);
	virtual ~EstrategiaOfensiva();
	virtual void jugar(Tablero*, Restricciones*, Vector*); 
};
//-----------------------------------------------------------------------------------------------------------------		