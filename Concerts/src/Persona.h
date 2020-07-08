#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

class Persona{
private:
	string name;
	string id;
	string asiento;
public:
	Persona();
	Persona(string,string,string);
	string getName();
	string getId();
	string getAsiento();
	void setName(string);
	void setId(string);
	string toString();
	~Persona();
};
#endif // !PERSONA_H

//Clase Persona, contiene en sus atributos: nombre e identificación.
//En la clase persona el atributo (asiento) es por el tipo de encapsulación que se utilizó.
//Las personas son el tipo de objetos dinámicos de concierto (matriz dinámica ).