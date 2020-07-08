#include "Juego.h"

//constructor y destructor
Juego::Juego() {}
Juego::~Juego() {}

//metodos
void Juego::Ganar() {
	lis->compara();
}

void Juego::setLis(Lista* lis) {
	this->lis = lis;
}

bool Juego::comparaNicknames(std::string ni, std::string ni2) {

	if (ni != ni2){
		return true;
	}
	
	else {
		std::cout << "El nickname que usted selecciono ya esta siendo utilizado " << std::endl;
		return false;
	}
}






