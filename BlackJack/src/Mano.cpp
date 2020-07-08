#include "Mano.h"

Mano::Mano(){
	for (int i = 0; i < 11; i++)
		mano[i] = nullptr;

	int cont = 0;
	int tam = 0;
}

Mano::~Mano(){}


//metodos

void Mano::agregarCarta() {
	if (cont == 0) {
		while (cont < 2) {
			mano[cont] = mazo->tomarCarta();
			cont++;
			tam++;
		}
	}
	else if (cont >= 2) {
		mano[cont] = mazo->tomarCarta();
		cont++;
		tam++;
	}
}


void Mano::limpiar() {
	for (int i = 0; i < tam; i++)
		mano[i] = nullptr;
}

int Mano::pts() {
	int total = 0;
	for (int i = 0; i < tam; i++) {
		if ((mano[i]->getValor() == "J") || (mano[i]->getValor() == "Q") || (mano[i]->getValor() == "K")) {
			total += 10;
		}
		else if (mano[i]->getValor() == "A") {
			if (total <= 10) {
				total += 11;
			}
			else if (total > 10) {
				total += 1;
			}
		}
		else
			total += convertir();
	}
	return total;
}

int Mano::convertir() {
	for (int i = 0; i < tam; i++)
		if (mano[i]->getValor() == "2")
			return 2;
		else if (mano[i]->getValor() == "3")
			return 3;
		else if (mano[i]->getValor() == "4")
			return 4;
		else if (mano[i]->getValor() == "5")
			return 5;
		else if (mano[i]->getValor() == "6")
			return 6;
		else if (mano[i]->getValor() == "7")
			return 7;
		else if (mano[i]->getValor() == "8")
			return 8;
		else if (mano[i]->getValor() == "9")
			return 9;
		else if (mano[i]->getValor() == "10")
			return 10;
}




std::string Mano::MuestraMazo(){
	std::stringstream s;

	s << "Las cartas son: " << std::endl;

	for (int i = 0; i < tam; i++) {
		s << "|";
		s << mano[i]->getValor();
		s << mano[i]->getPalo();
		s << "|";
		s << std::endl;
	}

	return s.str();
}


std::string Mano::MuestraMazoD() {
	std::stringstream s;

	s << "Las cartas son: " << std::endl;

		s << "|";
		s << mano[0]->getValor();
		s << mano[0]->getPalo();
		s << "|";
		s << std::endl;
		s << "La segunda carta esta oculta";
		s << std::endl;

	return s.str();
}

