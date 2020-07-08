#ifndef GESTIONFECHAS_H
#define GESTIONFECHAS_H
#include <string>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include "Fechas.h"
using namespace std;
class GestionFechas {
private:
	Fechas **v;
	int cant, tam;
	int opc;
public:
	GestionFechas();
	void col(int);
	void gotoxy(int x, int y);
	bool revisarAdm();
	void insertarFecha(Fechas*);
	void visualizar();
	void modificar();
	void eliminar();
	void imprimeMenu();
	void interfaz();
	int getOpc();
	int getCant();
	Fechas* devuelveFecha(int);
	void toString();
	void toStringBol();
	~GestionFechas();
};
#endif // !GESTIONFECHAS_H

//Clase Gesti�n de Fechas es un vector din�mico, que almacena objetos din�micos, en este caso Fechas.  Para permanecia de datos.