#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <time.h>
#include "Concierto.h"
#include "Interfaz.h"
#include "Persona.h"
#include "GestionConcierto.h"
#include "GestionFechas.h"
#include "Fechas.h"
#include "GestionRecinto.h"
using namespace std;
class Control {
public:
	Control();
	void col(int);
	void gotoxy(int x, int y);
	void opciones();
	void bienvenido();
	void hastaLuego();
	~Control();
};
#endif // !CONTROL_H

//Esta clase se encarga de juntar la interfaz junto con todos los menus y submenus de las clases, para lograr el funcionamiento del programa.