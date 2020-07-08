#include "Vector.h"

Vector::Vector() {
	tam = 12;
	cant = 0;
	for (int l = 0; l < 12; l++)
		vec[l] = NULL;
}

Vector::~Vector() {
	cout << "Borrando vec" << endl;
	delete vec;
}

int Vector::obtenerIJ() { return 0; }// {return i; }

void Vector::agregar(Posicion* p) {
	if (cant < tam) {
		vec[cant++] = p;
	}
}

Posicion* Vector::Mandar(int i) { return vec[i]; }
int Vector::getI(int i) { return vec[i]->getI(); }
int Vector::getJ(int i) { return vec[i]->getJ(); }
int Vector::getCant() { return cant; }

void Vector::setCant(int c) { cant = c; }

//void Vector::setI(int i) {this->i = i;}
//void Vector::setJ(int j) {this->j = j;}

void Vector::llenarPosiciones(Tablero* t) {
	cant = 0;
	char caracter;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (t->getPos(i, j)->getFicha() != NULL) {
				if (t->getFicha(i, j)->getCaracter() == 'o' || t->getFicha(i, j)->getCaracter() == 'N') {
					caracter = t->getFicha(i, j)->getCaracter();
					Ficha* temp = new Ficha(caracter);
					Posicion* p = new Posicion(i, j, temp);
					agregar(p);
				}
			}
		}
	}
}

void Vector::llenarPosicionesJugador(Tablero* t) {
	cant = 0;
	char caracter;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (t->getPos(i, j)->getFicha() != NULL) {
				if (t->getFicha(i, j)->getCaracter() == 'x' || t->getFicha(i, j)->getCaracter() == 'B') {
					caracter = t->getFicha(i, j)->getCaracter();
					Ficha* temp = new Ficha(caracter);
					Posicion* p = new Posicion(i, j, temp);
					agregar(p);
				}
			}
		}
	}
}

void Vector::eliminarPos(int posicion) {
	if ((0 <= posicion) && (posicion < cant)) {
		delete vec[posicion];
		for (int i = posicion; i < cant; i++) {
			vec[i] = vec[i + 1];
		}
		cant--;
	}
}

string Vector::toString() {
	stringstream s;

	for (int i = 0; i < cant; i++) {
		s << vec[i]->toString() << "\n";
	}

	return s.str();
}
