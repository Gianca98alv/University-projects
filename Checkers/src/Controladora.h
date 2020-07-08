#ifndef CONTROLADORA_H
#define CONTROLADORA_H
#include "Interfaz.h"
using namespace std;

class Controladora {
	string tecla;
public:
	Controladora();
	~Controladora();
	static void menuprincipal();
	static void color(int);
	static void inicio();
};
#endif 