#include "Dealer.h"


//constructor y destructor
Dealer::Dealer(){}
Dealer::~Dealer(){}


//metodos

bool Dealer::sePaso() {
	if (mano->pts() > 21) {
		std::cout << "El puntaje del es superior a veintiuno. Quedo eliminado" << std::endl;
		return false;
	}
}


void Dealer::pedirCarta() {
	mano->agregarCarta();
}
