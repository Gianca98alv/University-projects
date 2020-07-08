//es la clase base de la herencia

#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include <string>
#include <iostream>
#include <fstream>

#include "Mano.h"


class JugadorGenerico {
protected:
	std::string nickname;
	Mano* mano;
public:
	//constructor y destructor
	JugadorGenerico();
	~JugadorGenerico();


	//metodos
	Mano* getMano() { return mano; }
	void setNickname(std::string nickname) { this->nickname = nickname; }
	std::string getNickname() { return nickname; }

	virtual bool sePaso() { return true;  };
	virtual void pedirCarta() {};


};

#endif