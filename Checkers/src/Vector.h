#ifndef VECTOR_H
#define VECTOR_H
#include"Tablero.h"

class Vector {
private:
	Posicion* vec[12];

	int tam;
	int cant;

public:
	Vector();
	~Vector();
	int  obtenerIJ();
	void agregar(Posicion*);
	Posicion* Mandar(int);
	int getI(int);
	int getJ(int);
	int getCant();
	void setCant(int);
	void llenarPosiciones(Tablero*);
	void llenarPosicionesJugador(Tablero*);
	void eliminarPos(int);
	string toString();

};
#endif 