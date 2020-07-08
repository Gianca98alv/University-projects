#include "Persona.h"

Persona::Persona(){} //Constructor por default

Persona::Persona(string n, string i,string a) : name(n), id(i), asiento(a){} //Constructor con parámetros

//Sets y Gets de los Atributos

void Persona::setName(string n) { name = n; }

void Persona::setId(string i) { id = i; }

string Persona::getName() {	return name; }

string Persona::getId() { return id; }

string Persona::getAsiento() { return asiento; }

//Muestra el valor de los atributos
string Persona::toString(){
	stringstream p;
	p << "Nombre: "<<name<<endl;
	p << "Identificacion: " << id << endl;
	p << "Asiento: " << asiento << endl;
	return p.str();
}

//Destructor
Persona::~Persona(){
	name = " ";
	id = " ";
	asiento = " ";
	cout << "Se ha destruido una persona!" << endl;
}
