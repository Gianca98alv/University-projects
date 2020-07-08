#include "Partida.h"


Partida::Partida() {}

Partida::Partida(int num, Estrategia* estrategia, Jugador* jugador, Tablero* tablero) :
	numPartida(num),
	estrategia(estrategia),
	jugador(jugador),
	tablero(tablero) {
}

Partida::~Partida() {
	delete estrategia;
	delete jugador;
	delete tablero;
}

void Partida::setNumPartida(int num) { numPartida = num; }
void Partida::setEstrategia(Estrategia* estrategia) { this->estrategia = estrategia; }
void Partida::setJugador(Jugador* jugador) { this->jugador = jugador; }
void Partida::setTablero(Tablero* tablero) { this->tablero = tablero; }

int Partida::getNumPartida() { return numPartida; }
Estrategia* Partida::getEstrategia() { return estrategia; }
Jugador* Partida::getJugador() { return jugador; }
Tablero* Partida::getTablero() { return tablero; }

string Partida::toString() {

	Ficha* ficha;
	char caracter;
	stringstream s;
	s << "\n";
	s << "	Numero de Partida: " << numPartida;
	s << jugador->toString();
	s << "	Miniatura del tablero: \n";

	for (int i = 0; i < 8; i++) {
		s << "\n";
		s << "			";
		for (int j = 0; j < 8; j++) {
			if (tablero->getFicha(i, j) != NULL) {
				ficha = tablero->getFicha(i, j);
				caracter = ficha->getCaracter();
				s << caracter;
			}
			else {
				caracter = '-';
				s << caracter;
			}
		}
	}
	s << "\n";
	s << "\n";
	return s.str();
}

