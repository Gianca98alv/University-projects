#ifndef FICHA_H
#define FICHA_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class Ficha {

	char caracter;

public:


	Ficha();
	Ficha(char);
	~Ficha();
	char getCaracter();
	void setCaracter(char);
	virtual bool operator ==(Ficha*)const;

};
#endif 

