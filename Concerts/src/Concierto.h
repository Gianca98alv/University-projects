#ifndef CONCIERTO_H
#define CONCIERTO_H
#include "Persona.h"
using namespace std;
class Concierto{
private:
	int cantidad=0;
	Persona ***m;
	string cantante,nomFuncion;
	int cantAsientos;
	int filas, columnas;
public:
	Concierto();
	Concierto(string,string,int,int,int);
	Concierto(const Concierto *a);
	void col(int);
	void setCantante(string);
	void setNomFuncion(string);
	void setCantAsientos(int);
	void setFilasColumnas(int,int);
	int getCan();
	int getCantAsientos();
	int getFilas();
	int getColumnas();
	string getCantante();
	string getNomFuncion();
	string toString();
	void imprimeAsientos();
	bool verifica(int, int);
	int suma();
	bool insertarPersona(Persona*,int ,int);
	void eliminarPersonas();
	Persona* devuelvePersona(int,int);
	string toStringPersonas();
	~Concierto();
};
#endif // !CONCIERTO_H

//Clase Concierto, contiene en sus atributos: cantante, nombre de la funci�n y cantidad de asientos.
//Las Personas son almacenados como objetos din�micos en esta clase (matriz din�mica). Para permanecia de datos. 