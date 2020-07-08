#include "Recinto.h"

Recinto::Recinto(string o, string d, int du) : lugar(o), telonero(d), duracion(du) {}//Constructor con parámetros

void Recinto::col(int c){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }//Recibe un número al cual le corresponde un color y lo muestra en el texto.

//Sets y Gets de los Atributos
void Recinto::setLugar(string o) { lugar = o; }

void Recinto::setTelonero(string d) { telonero = d; }

void Recinto::setDuracion(int d) { duracion = d; }

string Recinto::getLugar() { return lugar; }

string Recinto::getTelonero() { return telonero; }

int Recinto::getDuracion() { return duracion; }

//Une la cadena(string) que se encuentre en el atributo lugar con la del atributo telonero y devuelve una nueva cadena (string) conformada por estas dos. Además las coloca en mayúscula.
string Recinto::sumaRecinto(){
	string cadena = lugar + "-" + telonero;
	for (int i = 0; cadena[i]; i++)
		cadena[i] = toupper(cadena[i]);
	return cadena;
}

//Muestra los valores de los atributos.
string Recinto::toString() {
	stringstream s;
	s << "\nLugar del Concierto: \n";
	s << lugar << "\n";
	s << "Nombre del Telonero:\n";
	s << telonero << "\n";
	s << "Duracion del show:\n";
	if (duracion == 1) {
		s << duracion << " hora\n";
	}
	else {
		s << duracion << " horas\n";
	}
	return s.str();
}

//Destructor
Recinto::~Recinto(){
	lugar = " ";
	telonero = " ";
	duracion = 0;
}
