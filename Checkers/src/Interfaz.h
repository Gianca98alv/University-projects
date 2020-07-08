#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
using namespace std;
#include "Archivos.h"
#include "Ficha.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Controladora.h"
#include "Estrategia.h"
#include "Lista.h"
#include "Partida.h"

class Archivos;

class Interfaz {

public:
	static void pruebas();
	static void inicio();

	static void inicializarTablero();
	static void imprimirTablero();
	static void imprimir(string);
	static void lecturaArchivos();
	static void asignarNumPartida();
	static void eliminarTodo();
	static void crearPartida();
	static void elegirEstrategia();

	static void cargarPartida();
	static void guardarPartida();
	static void Juego();
	static string leerString();
	static void color(int);
	static bool comprobarNumPartida(int);
	static void moverFicha(int, int, int, int);

	static void menuJuego();
	static void confirmarSalir();
	static void crearJugador();
	static void bienvenido();
	static void realizarJugada();
	static void jugarMaquina();
	static void finalizarTurno();
	static void JugadorGana();
	static void MaquinaGana();

};
#endif