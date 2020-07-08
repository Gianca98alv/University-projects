#ifndef RESTRICCIONES_H
#define RESTRICCIONES_H
#include "Tablero.h"

class Restricciones {

public:
	Restricciones();
	~Restricciones();
	bool verificarFicha(Tablero*, int, int, Posicion*);
	bool moverDiagonalUsuario(Tablero*, int, int, Posicion*);
	bool moverDiagonalMaquina(Tablero*, int, int, Posicion*);
	void coronar(Tablero*);

};
#endif 
