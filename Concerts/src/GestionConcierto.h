#ifndef GESTIONCONCIERTO_H
#define GESTIONCONCIERTO_H
#include "Concierto.h"
#include <conio.h>
#include <stdio.h>
#include <cctype>
using namespace std;
class GestionConcierto {
private:
	Concierto **v;
	int cant = 0, tam;
public:
	GestionConcierto();
	void gotoxy(int x, int y);
	bool revisarAdmin();
	void col(int);
	int getCant();
	void ingresarConcierto();
	void ingresarConcierto(Concierto *a);
	void visualizarConciertos();
	void toString();
	void modificar();
	void eliminar();
	int menu();
	Concierto* devuelve(int);
	~GestionConcierto();
};
#endif // !GESTIONCONCIERTO_H


//Clase Gesti�n de Concierto es un vector din�mico, que almacena Conciertos din�micos (matrices).  Para permanecia de datos.