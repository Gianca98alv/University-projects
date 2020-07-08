#include "Mazo.h"


//constructor y destructor
Mazo::Mazo() {
	for (int i = 0; i < cant; i++)
		carta[i] = nullptr;
}

Mazo::~Mazo() {}



//metodos


std::string Mazo::descifrarValor(int j) {
	if (j == 1)
		return "A";
	else if (j == 2)
		return "2";
	else if (j == 3)
		return "3";
	else if (j == 4)
		return "4";
	else if (j == 5)
		return "5";
	else if (j == 6)
		return "6";
	else if (j == 7)
		return "7";
	else if (j == 8)
		return "8";
	else if (j == 9)
		return "9";
	else if (j == 10)
		return "10";
	else if (j == 11)
		return "J";
	else if (j == 12)
		return "Q";
	else if (j == 13)
		return "K";
}

char Mazo::descifrarPalo(int i) {

	if (i == 0)
		return 'P';
	else if (i == 1)
		return 'T';
	else if (i == 2)
		return 'C';
	else if (i == 3)
		return 'D';
}




void Mazo::inicializar() {
	int contador = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			carta[contador++] = new Carta(descifrarValor(j), descifrarPalo(i));
		}
	}

}

void Mazo::barajar() {
	cont = 0;

	Carta * var = nullptr;
	int pos = 0;

	for (int i = 0; i < cant; i++) {
		pos = rand() % 52;

		var = carta[pos];
		carta[pos] = carta[i];
		carta[i] = var;
	}
}

Carta * Mazo::tomarCarta() {

	for (int i = cont; i < cant; i++) {
		cont++;
		return carta[i];
	}
}




