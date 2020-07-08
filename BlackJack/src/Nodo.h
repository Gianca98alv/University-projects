#ifndef NODO_H
#define NODO_H

#include "JugadorGenerico.h"

struct Nodo {
	JugadorGenerico* juga;
	struct Nodo* next;
};
#endif