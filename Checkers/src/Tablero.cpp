#include "Tablero.h"



Tablero::Tablero() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			tablero[i][j] = new Posicion(i, j, NULL);
		}
}

Tablero::~Tablero() {
	cout << "borrando el tablero \n";
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			delete tablero[i][j];
		}
}

void Tablero::agregar(Ficha* f, int i, int j) {
	tablero[i][j]->setFicha(f);
}

Ficha* Tablero::getFicha(int i, int j) { return tablero[i][j]->getFicha(); }
Posicion* Tablero::getPos(int i, int j) { return tablero[i][j]; }

string Tablero::toString() {
	int f = 1;
	int c = 1;
	stringstream s;
	s << "		    ";
	for (int k = 0; k < 8; k++) {
		s << "  " << c << "   ";
		c++;
	}
	s << "\n";
	s << "		    ================================================\n";
	for (int i = 0; i < 8; i++) {
		s << "		" << f << "  ";
		for (int j = 0; j < 8; j++) {
			if (tablero[i][j]->getFicha() == NULL) {
				s << "|     ";
			}
			else { s << "|  " << tablero[i][j]->getFicha()->getCaracter() << "  "; }
		}
		s << "|";
		s << "\n";
		s << "		    ================================================";
		f++;
		s << endl;
	}
	s << endl;
	return s.str();
}
