//es la clase central del programa


#ifndef JUEGO_H
#define JUEGO_H

#include "Mano.h"
#include "Lista.h"

class Juego {
	Lista * lis;
	Mano * handle;
public:
	//constructor y destructor
	Juego();
	~Juego();

	//metodos
	Lista* getLis() { return lis; }
	Mano* getHandle() { return handle; }
	void setLis(Lista*);
	void Ganar();
	bool comparaNicknames(std::string, std::string);
	
};

#endif
