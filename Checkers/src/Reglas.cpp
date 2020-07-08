#include "Reglas.h"



Restricciones::Restricciones() {}
Restricciones::~Restricciones() {}

bool Restricciones::verificarFicha(Tablero* tab, int i, int j, Posicion* pos) {
	if (tab->getFicha(i, j) == NULL) {
		cout << "\n	       No hay ficha en esta posicion";
		return false;
	}
	else if (tab->getFicha(i, j)->getCaracter() == pos->getFicha()->getCaracter()) {
		return true;
	}
	return false;
}

bool Restricciones::moverDiagonalUsuario(Tablero* tab, int i, int j, Posicion* pos) {
	if (pos->getFicha()->getCaracter() == 'B') {
		if ((((j == pos->getJ() - 1) || (j == pos->getJ() + 1)) && (i == pos->getI() - 1) || (i == pos->getI() + 1)) ||
			(((j == pos->getJ() - 2) || (j == pos->getJ() + 2)) && (i == pos->getI() - 2) || (i == pos->getI() + 2)) ||
			(((j == pos->getJ() - 3) || (j == pos->getJ() + 3)) && (i == pos->getI() - 3) || (i == pos->getI() + 3)) ||
			(((j == pos->getJ() - 4) || (j == pos->getJ() + 4)) && (i == pos->getI() - 4) || (i == pos->getI() + 4)) ||
			(((j == pos->getJ() - 5) || (j == pos->getJ() + 5)) && (i == pos->getI() - 5) || (i == pos->getI() + 5)) ||
			(((j == pos->getJ() - 6) || (j == pos->getJ() + 6)) && (i == pos->getI() - 6) || (i == pos->getI() + 6)) ||
			(((j == pos->getJ() - 7) || (j == pos->getJ() + 7)) && (i == pos->getI() - 7) || (i == pos->getI() + 7))) {
			return true;
		}
		cout << "\n	       La posicion a la que desea mover no esta en diagonal";
		return false;
	}
	else if (i == pos->getI() - 1) {
		if ((j == pos->getJ() - 1) || (j == pos->getJ() + 1)) {
			return true;
		}
		cout << "\n	       La posicion a la que desea mover no esta en diagonal";
		return false;
	}
	else {
		cout << "\n	       La posicion a la que desea mover no esta en diagonal";
		return false;
	}
}

bool Restricciones::moverDiagonalMaquina(Tablero* tab, int i, int j, Posicion* pos) {
	if (pos->getFicha()->getCaracter() == 'N') {
		if ((((j == pos->getJ() - 1) || (j == pos->getJ() + 1)) && (i == pos->getI() - 1) || (i == pos->getI() + 1)) ||
			(((j == pos->getJ() - 2) || (j == pos->getJ() + 2)) && (i == pos->getI() - 2) || (i == pos->getI() + 2)) ||
			(((j == pos->getJ() - 3) || (j == pos->getJ() + 3)) && (i == pos->getI() - 3) || (i == pos->getI() + 3)) ||
			(((j == pos->getJ() - 4) || (j == pos->getJ() + 4)) && (i == pos->getI() - 4) || (i == pos->getI() + 4)) ||
			(((j == pos->getJ() - 5) || (j == pos->getJ() + 5)) && (i == pos->getI() - 5) || (i == pos->getI() + 5)) ||
			(((j == pos->getJ() - 6) || (j == pos->getJ() + 6)) && (i == pos->getI() - 6) || (i == pos->getI() + 6)) ||
			(((j == pos->getJ() - 7) || (j == pos->getJ() + 7)) && (i == pos->getI() - 7) || (i == pos->getI() + 7))) {
			return true;
		}
		return false;
	}
	else if (i == pos->getI() + 1) {
		if ((j == pos->getJ() - 1) || (j == pos->getJ() + 1)) {
			if (tab->getPos(i + 1, j - 1)->getFicha() == NULL || tab->getPos(i + 1, j + 1)->getFicha() == NULL) {
				return true;
			}
			return false;
		}
		return false;
	}
	else {
		return false;
	}
}

void Restricciones::coronar(Tablero* t) {
	for (int j = 0; j < 8; j++) {
		if (t->getFicha(0, j) != NULL) {
			if (t->getFicha(0, j)->getCaracter() == 'x') {
				t->getFicha(0, j)->setCaracter('B');
				cout << "\n	       Coronando";
			}
		}
		for (int j = 0; j < 8; j++) {
			if (t->getFicha(7, j) != NULL) {
				if (t->getFicha(7, j)->getCaracter() == 'o') {
					t->getFicha(7, j)->setCaracter('N');
					cout << "\n	       Coronando";
				}
			}
		}
	}
}

