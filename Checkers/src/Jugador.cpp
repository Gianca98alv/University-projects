#include"Jugador.h"



Jugador::Jugador() {}

Jugador::Jugador(string n) {
	nombre = n;
}

Jugador::~Jugador() {}
string Jugador::getNombre() { return nombre; }
void Jugador::setNombre(string n) { nombre = n; }

string Jugador::toString() {
	stringstream s;
	s << "        Nombre del Jugador: " << nombre << endl;
	return s.str();
}

void Jugador::mover(Tablero* t, Restricciones* r, int i, int j, int i2, int j2, Posicion* p) {
	if (r->verificarFicha(t, i, j, p) && t->getPos(i2, j2)->getFicha() == NULL && r->moverDiagonalUsuario(t, i2, j2, p)) {
		Ficha* ficha = t->getFicha(i, j);
		t->getPos(i, j)->setFicha(NULL);
		t->agregar(ficha, i2, j2);
		ficha = NULL;
	}
	else { throw - 1; }
}

bool Jugador::sePuedeComer(Tablero* t, Restricciones* r, int i, int j, int i2, int j2, Posicion* p) {

	int aux = j2 - j;
	Posicion* temp = new Posicion();

	if (r->verificarFicha(t, i, j, p)) {
		if (t->getPos(i2, j2)->getFicha() == NULL) {
			if (aux > 0) {//derecha

				temp = t->getPos(i2 + 1, j2 - 1);
				if (temp->getFicha() != NULL) {
					if (temp->getFicha()->getCaracter() == 'o') {
						if (r->verificarFicha(t, i2 + 1, j2 - 1, temp)) {
							direc = 1;
							return true;
						}

					}
				}




				//if (p->getFicha()->getCaracter() == 'B') {
				//	temp = t->getPos(i2 - 1, j2 - 1);
				//	if (r->verificarFicha(t, i2 - 1, j2 - 1, temp)) {
				//		direccion = 1;
				//		return true;
				//	}
				//}
			}
			else if (aux < 0) { //izquierda
				temp = t->getPos(i2 + 1, j2 + 1);
				if (temp->getFicha() != NULL) {
					if (temp->getFicha()->getCaracter() == 'o') {
						if (r->verificarFicha(t, i2 + 1, j2 + 1, temp)) {
							direc = 2;
							return true;
						}
					}
				}






				//if (p->getFicha()->getCaracter() == 'B') {
				//	temp = t->getPos(i2 - 1, j2 - 1);
				//	if (r->verificarFicha(t, i2 - 1, j2 - 1, temp)) {
				//		direccion = 1;
				//		return true;
				//	}
				//}
			}
		}
	}
	return false;
}

void Jugador::comer(Tablero* t, Restricciones* r, int i, int j, int i2, int j2, Posicion* p) {

	Ficha* fichaAux = new Ficha();

	if (sePuedeComer(t, r, i, j, i2, j2, p)) {
		if (direc == 1) {//derecha
			//if (p->getFicha()->getCaracter() == 'B') {
			//	fichaAux = t->getFicha(i, j);
			//	t->agregar(fichaAux, i2, j2);
			//	t->agregar(NULL, i2 - 1, j2 - 1);
			//	t->agregar(NULL, i, j);
			//}
			//else {
			fichaAux = t->getFicha(i, j);
			t->agregar(fichaAux, i2, j2);
			t->agregar(NULL, i2 + 1, j2 - 1);
			t->agregar(NULL, i, j);
			//}
		}
		else if (direc == 2) { //izquierda

			//if (p->getFicha()->getCaracter() == 'B') {
			//	fichaAux = t->getFicha(i, j);
			//	t->agregar(fichaAux, i2, j2);
			//	t->agregar(NULL, i2 - 1, j2 + 1);
			//	t->agregar(NULL, i, j);
			//}
			//else {
			fichaAux = t->getFicha(i, j);
			t->agregar(fichaAux, i2, j2);
			t->agregar(NULL, i2 + 1, j2 + 1);
			t->agregar(NULL, i, j);

			//}
		}
	}
	else throw - 1;
}


