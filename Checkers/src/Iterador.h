#ifndef ITERADOR_H
#define ITERADOR_H
#include "Partida.h"

class Iterador {
public:
	virtual ~Iterador() {}
	virtual bool masElementos() const = 0;
	virtual Partida* proximoElemento() = 0;
};
#endif 
