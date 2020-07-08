#include "Estrategia.h"


//---------------------------------------------------ESTRATEGIA--------------------------------------------------------------
Estrategia::Estrategia() {}
Estrategia::Estrategia(int n) : numero_estra(n) {}

Estrategia::~Estrategia() {}

void Estrategia::mover(Tablero* t, Restricciones* r, Vector* vector, int i, int j, int i2, int j2, Posicion* p, int eliminar) {
	if (r->verificarFicha(t, i, j, p) && t->getPos(i2, j2)->getFicha() == NULL && r->moverDiagonalMaquina(t, i2, j2, p) && j2 > 0) {
		Ficha* ficha = t->getFicha(i, j);
		t->getPos(i, j)->setFicha(NULL);
		t->agregar(ficha, i2, j2);
		ficha = NULL;
		vector->eliminarPos(eliminar);
		Posicion* pAux = new Posicion(i2, j2, ficha);
		vector->agregar(pAux);
		move = true;
	}
}

bool Estrategia::sePuedeComer(Tablero* t, Restricciones* r, int i, int j, int i2, int j2, Posicion* p) {
	int aux = j2 - j;
	Posicion* temp = new Posicion();
	if (r->verificarFicha(t, i, j, p)) {
		if (t->getPos(i2, j2)->getFicha() == NULL) {
			if (aux > 0) {//derecha
				temp = t->getPos(i2 - 1, j2 - 1);
				if (temp->getFicha() != NULL) {
					if (temp->getFicha()->getCaracter() == 'x') {
						if (r->verificarFicha(t, i2 - 1, j2 - 1, temp)) {
							direc = 1;
							return true;
						}
					}
				}
			}
			else if (aux < 0) { //izquierda
				temp = t->getPos(i2 - 1, j2 + 1);
				if (temp->getFicha() != NULL) {
					if (temp->getFicha()->getCaracter() == 'x') {
						if (r->verificarFicha(t, i2 - 1, j2 + 1, temp)) {
							direc = 2;
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void Estrategia::comer(Tablero* t, Restricciones* r, int i, int j, int i2, int j2, Posicion* p) {
	Ficha* fichaAux = new Ficha();
	if (sePuedeComer(t, r, i, j, i2, j2, p)) {
		if (direc == 1) {//derecha
			fichaAux = t->getFicha(i, j);
			t->agregar(fichaAux, i2, j2);
			t->agregar(NULL, i2 - 1, j2 - 1);
			t->agregar(NULL, i, j);
			move = true;
		}
		else if (direc == 2) { //izquierda
			fichaAux = t->getFicha(i, j);
			t->agregar(fichaAux, i2, j2);
			t->agregar(NULL, i2 - 1, j2 + 1);
			t->agregar(NULL, i, j);
			move = true;
		}
	}
	else throw - 1;
}

int Estrategia::getNumEst() { return numero_estra; }

//-----------------------------------------------------------------------------------------------------------------


EstrategiaAleatoria::EstrategiaAleatoria() {}

EstrategiaAleatoria::EstrategiaAleatoria(int n) :
	Estrategia(n) {
}

EstrategiaAleatoria::~EstrategiaAleatoria() {}

void EstrategiaAleatoria::jugar(Tablero* tab, Restricciones* res, Vector* vector) {
	Posicion* p;
	int pos;
	int dir;

	int fila_entra, columna_entra, fila_nueva, columna_nueva;
	columna_nueva = 0;
	srand(time(NULL));

	do {
		bool continuar = false;
		pos = rand() % 12;
		if (pos < vector->getCant()) {
			p = vector->Mandar(pos);
			if (p->getFicha() != NULL) {
				fila_entra = p->getI();
				columna_entra = p->getJ();
				fila_nueva = fila_entra + 1;
				columna_nueva = columna_entra;
				dir = rand() % 2 + 1;
				if (dir == 2) {      //DERECHA
					columna_nueva = columna_nueva + 1;
				}
				else if (dir == 1 && columna_entra > 0) {     //IZQUIERDA
					columna_nueva = columna_nueva - 1;
				}
				if (tab->getFicha(fila_nueva, columna_nueva) != NULL) {
					if (tab->getFicha(fila_nueva, columna_nueva)->getCaracter() == 'x' || tab->getFicha(fila_nueva, columna_nueva)->getCaracter() == 'B') {
						if (sePuedeComer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva + 1, p)) {
							comer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva + 1, p);
						}
						if (sePuedeComer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva - 1, p)) {
							comer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva - 1, p);
						}
						else {
							mover(tab, res, vector, fila_entra, columna_entra, fila_nueva, columna_nueva, p, pos);
						}
					}
				}
				else {
					mover(tab, res, vector, fila_entra, columna_entra, fila_nueva, columna_nueva, p, pos);
				}
			}
		}
	} while (!move);
	move = false;
}


//-----------------------------------------------------------------------------------------------------------------


EstrategiaDefensiva::EstrategiaDefensiva() {}

EstrategiaDefensiva::EstrategiaDefensiva(int n) :
	Estrategia(n) {
}

EstrategiaDefensiva::~EstrategiaDefensiva() {}

void EstrategiaDefensiva::jugar(Tablero* tab, Restricciones* res, Vector* vector) {
	Posicion* p;
	int pos;
	int dir;

	int fila_entra, columna_entra, fila_nueva, columna_nueva;
	columna_nueva = 0;
	srand(time(NULL));

	do {
		bool continuar = false;
		pos = rand() % 12;
		if (pos < vector->getCant()) {
			p = vector->Mandar(pos);
			if (p->getFicha() != NULL) {
				fila_entra = p->getI();
				columna_entra = p->getJ();
				fila_nueva = fila_entra + 1;
				columna_nueva = columna_entra;
				dir = rand() % 2 + 1;
				if (dir == 2) {      //DERECHA
					columna_nueva = columna_nueva + 1;
				}
				else if (dir == 1 && columna_entra > 0) {     //IZQUIERDA
					columna_nueva = columna_nueva - 1;
				}
				if (tab->getFicha(fila_nueva, columna_nueva) != NULL) {
					if (tab->getFicha(fila_nueva, columna_nueva)->getCaracter() == 'x' || tab->getFicha(fila_nueva, columna_nueva)->getCaracter() == 'B') {
						if (sePuedeComer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva + 1, p)) {
							comer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva + 1, p);
						}
						if (sePuedeComer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva - 1, p)) {
							comer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva - 1, p);
						}
						else {
							mover(tab, res, vector, fila_entra, columna_entra, fila_nueva, columna_nueva, p, pos);
						}
					}
				}
				else {
					mover(tab, res, vector, fila_entra, columna_entra, fila_nueva, columna_nueva, p, pos);
				}
			}
		}
	} while (!move);
	move = false;
}

//-----------------------------------------------------------------------------------------------------------------



EstrategiaOfensiva::EstrategiaOfensiva() {}

EstrategiaOfensiva::EstrategiaOfensiva(int n) :
	Estrategia(n) {
}

EstrategiaOfensiva::~EstrategiaOfensiva() {}

void EstrategiaOfensiva::jugar(Tablero* tab, Restricciones* res, Vector* vector) {
	Posicion* p;
	int pos;
	int dir;

	int fila_entra, columna_entra, fila_nueva, columna_nueva;
	columna_nueva = 0;
	srand(time(NULL));

	do {
		bool continuar = false;
		pos = rand() % 12;
		if (pos < vector->getCant()) {
			p = vector->Mandar(pos);
			if (p->getFicha() != NULL) {
				fila_entra = p->getI();
				columna_entra = p->getJ();
				fila_nueva = fila_entra + 1;
				columna_nueva = columna_entra;
				dir = rand() % 2 + 1;
				if (dir == 2) {      //DERECHA
					columna_nueva = columna_nueva + 1;
				}
				else if (dir == 1 && columna_entra > 0) {     //IZQUIERDA
					columna_nueva = columna_nueva - 1;
				}
				if (tab->getFicha(fila_nueva, columna_nueva) != NULL) {
					if (tab->getFicha(fila_nueva, columna_nueva)->getCaracter() == 'x' || tab->getFicha(fila_nueva, columna_nueva)->getCaracter() == 'B') {
						if (sePuedeComer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva + 1, p)) {
							comer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva + 1, p);
						}
						if (sePuedeComer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva - 1, p)) {
							comer(tab, res, fila_entra, columna_entra, fila_nueva + 1, columna_nueva - 1, p);
						}
						else {
							mover(tab, res, vector, fila_entra, columna_entra, fila_nueva, columna_nueva, p, pos);
						}
					}
				}
				else {
					mover(tab, res, vector, fila_entra, columna_entra, fila_nueva, columna_nueva, p, pos);
				}
			}
		}
	} while (!move);
	move = false;
}
//-----------------------------------------------------------------------------------------------------------------






