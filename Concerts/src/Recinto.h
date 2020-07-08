#ifndef RECINTO_H
#define RECINTO_H
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <time.h>
using namespace std;
class Recinto{
private:
	string lugar;
	string telonero;
	int duracion;

public:
	Recinto(string,string,int);
	void col(int);
	void setLugar(string);
	void setTelonero(string);
	void setDuracion(int);
	string sumaRecinto();
	string getLugar();
	string getTelonero();
	int getDuracion();
	string toString();
	~Recinto();
};
#endif // !RECINTO_H

//Clase Recinto, contiene en sus atributos: lugar, telonero y duración.
//Los Recintos son almacenados como objetos dinámicos en Gestión de Recintos (vector dinámico).