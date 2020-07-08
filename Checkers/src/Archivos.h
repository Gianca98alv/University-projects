#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <fstream>
#include <iostream>
using namespace std;
#include "Estrategia.h"
#include "Ficha.h"
#include "Jugador.h"
#include "Lista.h"
#include "Partida.h"
#include "Tablero.h"

class Archivos {


public:
	Archivos();
	~Archivos();

	void leerArchivoPartidas(Lista* lista);
	void guardarPartidas(Lista* lista);

};
#endif

