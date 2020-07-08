#ifndef GESTIONRECINTO_H
#define GESTIONRECINTO_H
#include "Recinto.h"
using namespace std;
const string clave = "admin";
class GestionRecinto{
private:
	Recinto **v;
	int cant, tam;
public:
	GestionRecinto();
	void gotoxy(int x, int y);
	void col(int);
	bool revisarAdmi();
	int getCant();
	void ingresarRecinto(Recinto*);
	void ingresarRecinto();
	void visualizar();
	void modificar();
	void eliminar();
	int menu();
	void mostrarRecintos();
	Recinto* devuele(int);
	~GestionRecinto();
};
#endif // !GESTIONRECINTO_H

//Clase Gesti�n de Recintos es un vector din�mico, que almacena Recintos din�micos.  Para permanecia de datos.