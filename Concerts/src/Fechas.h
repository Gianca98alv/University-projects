#ifndef FECHAS_H
#define FECHAS_H
#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <ctime>
#include <Windows.h>
#include "GestionConcierto.h"
using namespace std;
class Fechas {
private:
	Concierto Concier;
	string nomProduccion;
	string fecha;
	int horaInicio;
	int horaFin;
public:
	Fechas();
	Fechas(string,string,int,int, Concierto);
	void col(int);
	string muestraFecha();
	string getNomProduccion();
	string getFecha();
	int getHoraInicio();
	int getHoraFin();
	void setNomProduccion(string);
	void setFecha(string);
	void setHoraInicio(int);
	void setHoraFin(int);
	void insertaConcierto(Concierto);
	Concierto devuelveConcierto();
	string toString();
	~Fechas();
};
#endif // !FECHAS_H

//Clase Fechas, contiene en sus atributos: concierto, nombre de la producci�n, fecha, hora de inicio y fin.
//Los Fechas son almacenados como objetos din�micos en Gesti�n de Fechas (vector din�mico).  Para permanecia de datos.