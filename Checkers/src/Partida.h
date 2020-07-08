#ifndef PARTIDA_H
#define PARTIDA_H
#include "Estrategia.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Reglas.h"

using namespace std;

class Partida {

private:
	int numPartida;
	Estrategia* estrategia;
	Jugador* jugador;
	Tablero* tablero;

public:
	Partida();
	Partida(int, Estrategia*, Jugador*, Tablero*);
	~Partida();

	void setNumPartida(int);
	void setEstrategia(Estrategia*);
	void setJugador(Jugador*);
	void setTablero(Tablero*);

	int getNumPartida();
	Estrategia* getEstrategia();
	Jugador* getJugador();
	Tablero* getTablero();

	string toString();

};
#endif 

