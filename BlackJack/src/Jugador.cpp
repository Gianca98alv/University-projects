#include "Jugador.h"

//constructor y destructor

Jugador::Jugador(){}
Jugador::~Jugador(){}

//metodos
void Jugador::pedirCarta(){
	mano->agregarCarta();
}

bool Jugador::sePaso() {
	if (mano->pts() > 21) {
		std::cout << "El puntaje es superior a veintiuno. Quedo eliminado" << std::endl;
		return false;
	}
}

