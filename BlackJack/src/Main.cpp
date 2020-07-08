/*
Universidad Nacional de Costa Rica

PROGRAMACION I
SEGUNDO PROYECTO DE PROGRAMACION

ESTUDIANTES:
		ALEXANDRA RODRÍGUEZ AGUILAR
		GIANCARLO ALVARADO SÁNCHEZ
PROFESOR:
		JOSE PABLO CALVO SUÁREZ

VERANO 2018
*/

#include <ctime>
#include <iostream>

#include "Juego.h"
#include "Lista.h"
#include "Mazo.h"
#include "Mano.h"
#include "Jugador.h"
#include "Dealer.h"

int main() {
	srand(static_cast <unsigned int>(time(nullptr)));

	int guarda = 0;
	char menu, otra, ju, meJ;
	std::string nick, nick2, nick3, nick4, nick5, nick6, nick7;

	Juego* ptrJ = new Juego();
	Lista* list = new Lista();
	Mazo* maz = new Mazo();
	Mano* man = new Mano();
	Dealer* ptrD1 = new Dealer();

	JugadorGenerico* ptrD = new Dealer();

	JugadorGenerico* ptr1 = new Jugador();
	JugadorGenerico* ptr2 = new Jugador();
	JugadorGenerico* ptr3 = new Jugador();
	JugadorGenerico* ptr4 = new Jugador();
	JugadorGenerico* ptr5 = new Jugador();
	JugadorGenerico* ptr6 = new Jugador();
	JugadorGenerico* ptr7 = new Jugador();

		//menu inicial
		std::cout << "*****BLACKJACK*****" << std::endl;
		std::cout << "Menu" << std::endl;
		std::cout << "1)Nuevo Juego" << std::endl;
		std::cout << "2)Cargar Partida" << std::endl;
		std::cout << "3)Salir" << std::endl;
		std::cin >> menu;

		//opcion 1, nuevo juego
		if (menu == '1') {
			std::cout << "Digite la cantidad de jugadores:  " << std::endl;
			std::cout << "(Minimo 1)              (Maximo 7)" << std::endl;
			std::cin >> ju;

			//ingresa los nicknames segun la cantidad de jugadores 
			switch (ju) {
			case '1': {

				std::cout << "Digite el nombre del/la jugador/a: " << std::endl; std::cin >> nick;
				ptr1->setNickname(nick);
				ptrD->setNickname("Dealer");
				list->insertar(ptr1);
				
				//inizializa el mazo
				maz->inicializar();

				//baraja las cartas
				maz->barajar();
				
				//jugador
				//repartir cartas	
				ptr1->getMano()->setMazo(maz);
				ptr1->pedirCarta();
				system("cls"); //Limpia la pantalla

				do {
					//muestra nickname y la mano
					std::cout << "Turno del jugador/a: " << std::endl;
					std::cout << std::endl << ptr1->getNickname() << std::endl;
					std::cout << ptr1->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar Partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr1->getMano()->setMazo(maz);
						ptr1->pedirCarta();
						std::cout << ptr1->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						list->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr1->sePaso() && meJ != '2');
				//juega dealer

				//repartir cartas
				ptrD->getMano()->setMazo(maz);
				ptrD->pedirCarta();

				//muestra nickname y la mano
				std::cout << "Turno del dealer" << std::endl;
				std::cout << ptrD->getNickname() << std::endl;
				std::cout << ptrD->getMano()->MuestraMazoD() << std::endl;
				do {
					if (ptrD->getMano()->pts() <= 16) {
						std::cout << "El dealer pide carta" << std::endl;
						ptrD->getMano()->setMazo(maz);
						ptrD->pedirCarta();
					}
					else
						std::cout << "El dealer se queda" << std::endl;
					std::cout << ptrD->getMano()->MuestraMazo() << std::endl;
					std::cout << "Presione enter para seguir" << std::endl;
					system("pause"); //Da pausa para que el/la jugador/a vea las cartas de dealer

				} while (ptrD->getMano()->pts() <= 16);

				//resultados jugador
				//gane
				if ((ptr1->getMano()->pts() > ptrD->getMano()->pts()) && (ptr1->getMano()->pts() <= 21)) {
					std::cout << "Jugador/a " << ptr1->getNickname() << " gana" << std::endl;
				}
				//pierde
				else if ((ptr1->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
					std::cout << "Jugador/a " << ptr1->getNickname() << " pierde" << std::endl;
				}
				//empato
				if (ptr1->getMano()->pts() == ptrD->getMano()->pts()) {
					std::cout << "Jugador/a " << ptr1->getNickname() << " empato" << std::endl;
				}
				
			} break;

			case '2': {

				std::cout << "Digite el nombre del/la primer/a jugador/a: " << std::endl; std::cin >> nick;
				std::cout << "Digite el nombre del/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;

				do {
					if (ptrJ->comparaNicknames(nick, nick2) == false) {
						std::cout << " Por favor digite un nuevo nombre para el/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
					}

				} while (ptrJ->comparaNicknames(nick, nick2) == false);
				system("cls"); //Limpia la pantalla

				//agrega los nicknames
				ptr1->setNickname(nick);
				ptr2->setNickname(nick2);
				ptrD->setNickname("Dealer");

				//agrega los jugadores a lista
				list->insertar(ptr1);
				list->insertar(ptr2);

				

				//inizializa el mazo
				maz->inicializar();

				//baraja las cartas
				maz->barajar();

				//jugador 1
				//repartir cartas	
				ptr1->getMano()->setMazo(maz);
				ptr1->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr1->getNickname() << std::endl;
					std::cout << ptr1->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr1->getMano()->setMazo(maz);
						ptr1->pedirCarta();
						std::cout << ptr1->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				

				} while (ptr1->sePaso() && meJ != '2');

				//jugador 2
				//repartir cartas
				ptr2->getMano()->setMazo(maz);
				ptr2->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr2->getNickname() << std::endl;
					std::cout << ptr2->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr2->getMano()->setMazo(maz);
						ptr2->pedirCarta();
						std::cout << ptr2->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {

					

						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr2->sePaso() == true && meJ != '2');

				//juega dealer

				//repartir cartas
				ptrD->getMano()->setMazo(maz);
				ptrD->pedirCarta();
				//muestra nickname y la mano
				std::cout << "Turno del dealer" << std::endl;
				std::cout << ptrD->getNickname() << std::endl;
				std::cout << ptrD->getMano()->MuestraMazoD() << std::endl;
				do {
					if (ptrD->getMano()->pts() <= 16) {
						std::cout << "El dealer pide carta" << std::endl;
						ptrD->getMano()->setMazo(maz);
						ptrD->pedirCarta();
					}
					else
						std::cout << "El dealer se queda" << std::endl;
					std::cout << ptrD->getMano()->MuestraMazo() << std::endl;
					std::cout << "Presione enter para seguir" << std::endl;
					system("pause"); //Da pausa para que los jugadores vean las cartas de dealer

				} while (ptrD->getMano()->pts() <= 16);

				//mostrar resultados
				//resultados generales
				if ((ptrD->getMano()->pts() > 21 && ptr1->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr2->getMano()->pts() <= 21)) {
					std::cout << "Todos los jugadores ganaron porque solo el dealer se paso de veintiuno " << std::endl;
					std::cout << "El dealer pierde" << std::endl;
				}

				else {
					
					//resultados jugador 1
					//gane
					if ((ptr1->getMano()->pts() > ptrD->getMano()->pts()) && (ptr1->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr1->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " pierde" << std::endl;
					}
					//empato
					if (ptr1->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 2
					//gane
					if ((ptr2->getMano()->pts() > ptrD->getMano()->pts()) && (ptr2->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr2->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr2->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " empato" << std::endl;
					}
				}

			} break;

			case '3': {

				std::cout << "Digite el nombre del/la primer/a jugador/a: " << std::endl; std::cin >> nick;
				std::cout << "Digite el nombre del/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
				std::cout << "Digite el nombre del/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;

				//Compara jugador dos
				do {
					if (ptrJ->comparaNicknames(nick, nick2) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
					}
				} while (ptrJ->comparaNicknames(nick, nick2) == false);
				
				//Compara jugador tres
				do {
					if (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
					}
				} while (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false);
				system("cls"); //Limpia la pantalla

				//agrega los nicknames
				ptr1->setNickname(nick);
				ptr2->setNickname(nick2);
				ptr3->setNickname(nick3);
				ptrD->setNickname("Dealer");

				//agrega los jugadores a lista
				list->insertar(ptr1);
				list->insertar(ptr2);
				list->insertar(ptr3);

				//inizializa el mazo
				maz->inicializar();

				//baraja las cartas
				maz->barajar();
				
				//jugador 1
				//repartir cartas	
				ptr1->getMano()->setMazo(maz);
				ptr1->pedirCarta();
				do {
					//jugador1
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr1->getNickname() << std::endl;
					std::cout << ptr1->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr1->getMano()->setMazo(maz);
						ptr1->pedirCarta();
						std::cout << ptr1->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr1->sePaso() && meJ != '2');

				//jugador 2
				//repartir cartas
				ptr2->getMano()->setMazo(maz);
				ptr2->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr2->getNickname() << std::endl;
					std::cout << ptr2->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr2->getMano()->setMazo(maz);
						ptr2->pedirCarta();
						std::cout << ptr2->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr2->sePaso() == true && meJ != '2');

				//jugador 3
				//repartir cartas
				ptr3->getMano()->setMazo(maz);
				ptr3->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr3->getNickname() << std::endl;
					std::cout << ptr3->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr3->getMano()->setMazo(maz);
						ptr3->pedirCarta();
						std::cout << ptr3->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr3->sePaso() == true && meJ != '2');

				//juega dealer

				//repartir cartas
				ptrD->getMano()->setMazo(maz);
				ptrD->pedirCarta();
				//muestra nickname y la mano
				std::cout << "Turno del dealer" << std::endl;
				std::cout << ptrD->getNickname() << std::endl;
				std::cout << ptrD->getMano()->MuestraMazoD() << std::endl;
				do {
					if (ptrD->getMano()->pts() <= 16) {
						std::cout << "El dealer pide carta" << std::endl;
						ptrD->getMano()->setMazo(maz);
						ptrD->pedirCarta();
					}
					else
						std::cout << "El dealer se queda" << std::endl;
					std::cout << ptrD->getMano()->MuestraMazo() << std::endl;
					std::cout << "Presione enter para seguir" << std::endl;
					system("pause"); //Da pausa par que los jugadores vean las cartas de dealer

				} while (ptrD->getMano()->pts() <= 16);

				//mostrar resultados
				//resultados generales
				if ((ptrD->getMano()->pts() > 21 && ptr1->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr2->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr3->getMano()->pts() <= 21)) {
					std::cout << "Todos los jugadores ganaron porque solo el dealer se paso de veintiuno " << std::endl;
					std::cout << "El dealer pierde" << std::endl;
				}

				else {
					
					//resultados jugador 1
					//gane
					if ((ptr1->getMano()->pts() > ptrD->getMano()->pts()) && (ptr1->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr1->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " pierde" << std::endl;
					}
					//empato
					if (ptr1->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 2
					//gane
					if ((ptr2->getMano()->pts() > ptrD->getMano()->pts()) && (ptr2->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr2->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr2->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 3
					//gane
					if ((ptr3->getMano()->pts() > ptrD->getMano()->pts()) && (ptr3->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr3->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr3->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " empato" << std::endl;
					}
				}
			} break;

			case '4': { 
				std::cout << "Digite el nombre del/la primer/a jugador/a: " << std::endl; std::cin >> nick;
				std::cout << "Digite el nombre del/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
				std::cout << "Digite el nombre del/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
				std::cout << "Digite el nombre del/la cuarto/a jugador/a: " << std::endl; std::cin >> nick4;
				
				//Compara jugador dos
				do {
					if (ptrJ->comparaNicknames(nick, nick2) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
					}
				} while (ptrJ->comparaNicknames(nick, nick2) == false);

				//Compara jugador tres
				do {
					if (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
					}
				} while (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false);

				//Compara jugador cuatro
				do {
					if (ptrJ->comparaNicknames(nick, nick4) == false || ptrJ->comparaNicknames(nick2, nick4) == false || ptrJ->comparaNicknames(nick3, nick4) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la cuarto/a jugador/a: " << std::endl; std::cin >> nick4;
					}
				} while (ptrJ->comparaNicknames(nick, nick4) == false || ptrJ->comparaNicknames(nick2, nick4) == false || ptrJ->comparaNicknames(nick3, nick4) == false);
				system("cls"); //Limpia la pantalla

				//agrega los nicknames
				ptr1->setNickname(nick);
				ptr2->setNickname(nick2);
				ptr3->setNickname(nick3);
				ptr4->setNickname(nick4);
				ptrD->setNickname("Dealer");

				//agrega los jugadores a lista
				list->insertar(ptr1);
				list->insertar(ptr2);
				list->insertar(ptr3);
				list->insertar(ptr4);

				//inizializa el mazo
				maz->inicializar();

				//baraja las cartas
				maz->barajar();

				//jugador 1
				//repartir cartas	
				ptr1->getMano()->setMazo(maz);
				ptr1->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr1->getNickname() << std::endl;
					std::cout << ptr1->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr1->getMano()->setMazo(maz);
						ptr1->pedirCarta();
						std::cout << ptr1->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr1->sePaso() && meJ != '2');

				//jugador 2
				//repartir cartas
				ptr2->getMano()->setMazo(maz);
				ptr2->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr2->getNickname() << std::endl;
					std::cout << ptr2->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr2->getMano()->setMazo(maz);
						ptr2->pedirCarta();
						std::cout << ptr2->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr2->sePaso() == true && meJ != '2');

				//jugador 3
				//repartir cartas
				ptr3->getMano()->setMazo(maz);
				ptr3->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr3->getNickname() << std::endl;
					std::cout << ptr3->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr3->getMano()->setMazo(maz);
						ptr3->pedirCarta();
						std::cout << ptr3->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr3->sePaso() == true && meJ != '2');

				//jugador 4
				//repartir cartas	
				ptr4->getMano()->setMazo(maz);
				ptr4->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr4->getNickname() << std::endl;
					std::cout << ptr4->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr4->getMano()->setMazo(maz);
						ptr4->pedirCarta();
						std::cout << ptr4->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr4->sePaso() && meJ != '2');

				//juega dealer

				//repartir cartas
				ptrD->getMano()->setMazo(maz);
				ptrD->pedirCarta();
				//muestra nickname y la mano
				std::cout << "Turno del dealer" << std::endl;
				std::cout << ptrD->getNickname() << std::endl;
				std::cout << ptrD->getMano()->MuestraMazoD() << std::endl;
				do {
					if (ptrD->getMano()->pts() <= 16) {
						std::cout << "El dealer pide carta" << std::endl;
						ptrD->getMano()->setMazo(maz);
						ptrD->pedirCarta();
					}
					else
						std::cout << "El dealer se queda" << std::endl;
					std::cout << ptrD->getMano()->MuestraMazo() << std::endl;
					std::cout << "Presione enter para seguir" << std::endl;
					system("pause"); //Da pausa para que los jugadores vean las cartas de dealer

				} while (ptrD->getMano()->pts() <= 16);

				//mostrar resultados
				//resultados generales
				if ((ptrD->getMano()->pts() > 21 && ptr1->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr2->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr3->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr4->getMano()->pts() <= 21)) {
					std::cout << "Todos los jugadores ganaron porque solo el dealer se paso de veintiuno " << std::endl;
					std::cout << "El dealer pierde" << std::endl;
				}

				else {

					//resultados jugador 1
					//gane
					if ((ptr1->getMano()->pts() > ptrD->getMano()->pts()) && (ptr1->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr1->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " pierde" << std::endl;
					}
					//empato
					if (ptr1->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 2
					//gane
					if ((ptr2->getMano()->pts() > ptrD->getMano()->pts()) && (ptr2->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr2->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr2->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 3
					//gane
					if ((ptr3->getMano()->pts() > ptrD->getMano()->pts()) && (ptr3->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr3->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr3->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 4
					//gane
					if ((ptr4->getMano()->pts() > ptrD->getMano()->pts()) && (ptr4->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr4->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr4->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " empato" << std::endl;
					}
				}

			} break;

			case '5': {
				std::cout << "Digite el nombre del/la primer/a jugador/a: " << std::endl; std::cin >> nick;
				std::cout << "Digite el nombre del/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
				std::cout << "Digite el nombre del/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
				std::cout << "Digite el nombre del/la cuarto/a jugador/a: " << std::endl; std::cin >> nick4;
				std::cout << "Digite el nombre del/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;

				//Compara jugador dos
				do {
					if (ptrJ->comparaNicknames(nick, nick2) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
					}
				} while (ptrJ->comparaNicknames(nick, nick2) == false);

				//Compara jugador tres
				do {
					if (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
					}
				} while (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false);

				//Compara jugador cuatro
				do {
					if (ptrJ->comparaNicknames(nick, nick4) == false || ptrJ->comparaNicknames(nick2, nick4) == false || ptrJ->comparaNicknames(nick3, nick4) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la cuarto/a jugador/a: " << std::endl; std::cin >> nick4;
					}
				} while (ptrJ->comparaNicknames(nick, nick4) == false || ptrJ->comparaNicknames(nick2, nick4) == false || ptrJ->comparaNicknames(nick3, nick4) == false);

				//Compara jugador cinco
				do {
					if (ptrJ->comparaNicknames(nick, nick5) == false || ptrJ->comparaNicknames(nick2, nick5) == false || ptrJ->comparaNicknames(nick3, nick5) == false || ptrJ->comparaNicknames(nick4, nick5) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;
					}
				} while (ptrJ->comparaNicknames(nick, nick5) == false || ptrJ->comparaNicknames(nick2, nick5) == false || ptrJ->comparaNicknames(nick3, nick5) == false || ptrJ->comparaNicknames(nick4, nick5) == false);
				system("cls"); //Limpia la pantalla

				//agrega los nicknames
				ptr1->setNickname(nick);
				ptr2->setNickname(nick2);
				ptr3->setNickname(nick3);
				ptr4->setNickname(nick4);
				ptr5->setNickname(nick5);
				ptrD->setNickname("Dealer");

				//agrega los jugadores a lista
				list->insertar(ptr1);
				list->insertar(ptr2);
				list->insertar(ptr3);
				list->insertar(ptr4);
				list->insertar(ptr5);

				//inizializa el mazo
				maz->inicializar();

				//baraja las cartas
				maz->barajar();

				//jugador 1
				//repartir cartas	
				ptr1->getMano()->setMazo(maz);
				ptr1->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr1->getNickname() << std::endl;
					std::cout << ptr1->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr1->getMano()->setMazo(maz);
						ptr1->pedirCarta();
						std::cout << ptr1->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr1->sePaso() && meJ != '2');

				//jugador 2
				//repartir cartas
				ptr2->getMano()->setMazo(maz);
				ptr2->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr2->getNickname() << std::endl;
					std::cout << ptr2->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr2->getMano()->setMazo(maz);
						ptr2->pedirCarta();
						std::cout << ptr2->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr2->sePaso() == true && meJ != '2');

				//jugador 3
				//repartir cartas
				ptr3->getMano()->setMazo(maz);
				ptr3->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr3->getNickname() << std::endl;
					std::cout << ptr3->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr3->getMano()->setMazo(maz);
						ptr3->pedirCarta();
						std::cout << ptr3->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr3->sePaso() == true && meJ != '2');

				//jugador 4
				//repartir cartas	
				ptr4->getMano()->setMazo(maz);
				ptr4->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr4->getNickname() << std::endl;
					std::cout << ptr4->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr4->getMano()->setMazo(maz);
						ptr4->pedirCarta();
						std::cout << ptr4->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr4->sePaso() && meJ != '2');

				//jugador 5
				//repartir cartas	
				ptr5->getMano()->setMazo(maz);
				ptr5->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr5->getNickname() << std::endl;
					std::cout << ptr5->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr5->getMano()->setMazo(maz);
						ptr5->pedirCarta();
						std::cout << ptr5->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr5->sePaso() && meJ != '2');

				//juega dealer

				//repartir cartas
				ptrD->getMano()->setMazo(maz);
				ptrD->pedirCarta();
				//muestra nickname y la mano
				std::cout << "Turno del dealer" << std::endl;
				std::cout << ptrD->getNickname() << std::endl;
				std::cout << ptrD->getMano()->MuestraMazoD() << std::endl;
				do {
					if (ptrD->getMano()->pts() <= 16) {
						std::cout << "El dealer pide carta" << std::endl;
						ptrD->getMano()->setMazo(maz);
						ptrD->pedirCarta();
					}
					else
						std::cout << "El dealer se queda" << std::endl;
					std::cout << ptrD->getMano()->MuestraMazo() << std::endl;
					std::cout << "Presione enter para seguir" << std::endl;
					system("pause"); //Da pausa para que los jugadores vean las cartas de dealer

				} while (ptrD->getMano()->pts() <= 16);

				//mostrar resultados
				//resultados generales
				if ((ptrD->getMano()->pts() > 21 && ptr1->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr2->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr3->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr4->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr5->getMano()->pts() <= 21)) {
					std::cout << "Todos los jugadores ganaron porque solo el dealer se paso de veintiuno " << std::endl;
					std::cout << "El dealer pierde" << std::endl;
				}

				else {

					//resultados jugador 1
					//gane
					if ((ptr1->getMano()->pts() > ptrD->getMano()->pts()) && (ptr1->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr1->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " pierde" << std::endl;
					}
					//empato
					if (ptr1->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 2
					//gane
					if ((ptr2->getMano()->pts() > ptrD->getMano()->pts()) && (ptr2->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr2->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr2->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 3
					//gane
					if ((ptr3->getMano()->pts() > ptrD->getMano()->pts()) && (ptr3->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr3->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr3->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 4
					//gane
					if ((ptr4->getMano()->pts() > ptrD->getMano()->pts()) && (ptr4->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr4->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr4->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 5
					//gane
					if ((ptr5->getMano()->pts() > ptrD->getMano()->pts()) && (ptr5->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr5->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr5->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " empato" << std::endl;
					}
				}
			} break;

			case '6': {
				std::cout << "Digite el nombre del/la primer/a jugador/a: " << std::endl; std::cin >> nick;
				std::cout << "Digite el nombre del/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
				std::cout << "Digite el nombre del/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
				std::cout << "Digite el nombre del/la cuarto/a jugador/a: " << std::endl; std::cin >> nick4;
				std::cout << "Digite el nombre del/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;
				std::cout << "Digite el nombre del/la sexto/a jugador/a: " << std::endl; std::cin >> nick6;

				//Compara jugador dos
				do {
					if (ptrJ->comparaNicknames(nick, nick2) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
					}
				} while (ptrJ->comparaNicknames(nick, nick2) == false);

				//Compara jugador tres
				do {
					if (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
					}
				} while (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false);

				//Compara jugador cuatro
				do {
					if (ptrJ->comparaNicknames(nick, nick4) == false || ptrJ->comparaNicknames(nick2, nick4) == false || ptrJ->comparaNicknames(nick3, nick4) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la cuarto/a jugador/a: " << std::endl; std::cin >> nick4;
					}
				} while (ptrJ->comparaNicknames(nick, nick4) == false || ptrJ->comparaNicknames(nick2, nick4) == false || ptrJ->comparaNicknames(nick3, nick4) == false);

				//Compara jugador cinco
				do {
					if (ptrJ->comparaNicknames(nick, nick5) == false || ptrJ->comparaNicknames(nick2, nick5) == false || ptrJ->comparaNicknames(nick3, nick5) == false || ptrJ->comparaNicknames(nick4, nick5) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;
					}
				} while (ptrJ->comparaNicknames(nick, nick5) == false || ptrJ->comparaNicknames(nick2, nick5) == false || ptrJ->comparaNicknames(nick3, nick5) == false || ptrJ->comparaNicknames(nick4, nick5) == false);

				//Compara jugador seis
				do {
					if (ptrJ->comparaNicknames(nick, nick6) == false || ptrJ->comparaNicknames(nick2, nick6) == false || ptrJ->comparaNicknames(nick3, nick6) == false || ptrJ->comparaNicknames(nick4, nick6) == false || ptrJ->comparaNicknames(nick5, nick6) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;
					}
				} while (ptrJ->comparaNicknames(nick, nick6) == false || ptrJ->comparaNicknames(nick2, nick6) == false || ptrJ->comparaNicknames(nick3, nick6) == false || ptrJ->comparaNicknames(nick4, nick6) == false || ptrJ->comparaNicknames(nick5, nick6) == false);
				system("cls"); //Limpia la pantalla

				//agrega los nicknames
				ptr1->setNickname(nick);
				ptr2->setNickname(nick2);
				ptr3->setNickname(nick3);
				ptr4->setNickname(nick4);
				ptr5->setNickname(nick5);
				ptr6->setNickname(nick6);
				ptrD->setNickname("Dealer");

				//agrega los jugadores a lista
				list->insertar(ptr1);
				list->insertar(ptr2);
				list->insertar(ptr3);
				list->insertar(ptr4);
				list->insertar(ptr5);
				list->insertar(ptr6);

				//inizializa el mazo
				maz->inicializar();

				//baraja las cartas
				maz->barajar();

				//jugador 1
				//repartir cartas	
				ptr1->getMano()->setMazo(maz);
				ptr1->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr1->getNickname() << std::endl;
					std::cout << ptr1->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr1->getMano()->setMazo(maz);
						ptr1->pedirCarta();
						std::cout << ptr1->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr1->sePaso() && meJ != '2');

				//jugador 2
				//repartir cartas
				ptr2->getMano()->setMazo(maz);
				ptr2->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr2->getNickname() << std::endl;
					std::cout << ptr2->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr2->getMano()->setMazo(maz);
						ptr2->pedirCarta();
						std::cout << ptr2->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr2->sePaso() == true && meJ != '2');

				//jugador 3
				//repartir cartas
				ptr3->getMano()->setMazo(maz);
				ptr3->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr3->getNickname() << std::endl;
					std::cout << ptr3->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr3->getMano()->setMazo(maz);
						ptr3->pedirCarta();
						std::cout << ptr3->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr3->sePaso() == true && meJ != '2');

				//jugador 4
				//repartir cartas	
				ptr4->getMano()->setMazo(maz);
				ptr4->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr4->getNickname() << std::endl;
					std::cout << ptr4->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr4->getMano()->setMazo(maz);
						ptr4->pedirCarta();
						std::cout << ptr4->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr4->sePaso() && meJ != '2');

				//jugador 5
				//repartir cartas	
				ptr5->getMano()->setMazo(maz);
				ptr5->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr5->getNickname() << std::endl;
					std::cout << ptr5->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr5->getMano()->setMazo(maz);
						ptr5->pedirCarta();
						std::cout << ptr5->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr5->sePaso() && meJ != '2');

				//jugador 6
				//repartir cartas	
				ptr6->getMano()->setMazo(maz);
				ptr6->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr6->getNickname() << std::endl;
					std::cout << ptr6->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr6->getMano()->setMazo(maz);
						ptr6->pedirCarta();
						std::cout << ptr6->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr6->sePaso() && meJ != '2');
				
				//juega dealer

				//repartir cartas
				ptrD->getMano()->setMazo(maz);
				ptrD->pedirCarta();
				//muestra nickname y la mano
				std::cout << "Turno del dealer" << std::endl;
				std::cout << ptrD->getNickname() << std::endl;
				std::cout << ptrD->getMano()->MuestraMazoD() << std::endl;
				do {
					if (ptrD->getMano()->pts() <= 16) {
						std::cout << "El dealer pide carta" << std::endl;
						ptrD->getMano()->setMazo(maz);
						ptrD->pedirCarta();
					}
					else
						std::cout << "El dealer se queda" << std::endl;
					std::cout << ptrD->getMano()->MuestraMazo() << std::endl;
					std::cout << "Presione enter para seguir" << std::endl;
					system("pause"); //Da pausa para que los jugadores vean las cartas del dealer

				} while (ptrD->getMano()->pts() <= 16);

				//mostrar resultados
				//resultados generales
				if ((ptrD->getMano()->pts() > 21 && ptr1->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr2->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr3->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr4->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr5->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr6->getMano()->pts() <= 21)) {
					std::cout << "Todos los jugadores ganaron porque solo el dealer se paso de veintiuno " << std::endl;
					std::cout << "El dealer pierde" << std::endl;
				}

				else {

					//resultados jugador 1
					//gane
					if ((ptr1->getMano()->pts() > ptrD->getMano()->pts()) && (ptr1->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr1->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " pierde" << std::endl;
					}
					//empato
					if (ptr1->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 2
					//gane
					if ((ptr2->getMano()->pts() > ptrD->getMano()->pts()) && (ptr2->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr2->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr2->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 3
					//gane
					if ((ptr3->getMano()->pts() > ptrD->getMano()->pts()) && (ptr3->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr3->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr3->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 4
					//gane
					if ((ptr4->getMano()->pts() > ptrD->getMano()->pts()) && (ptr4->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr4->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr4->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 5
					//gane
					if ((ptr5->getMano()->pts() > ptrD->getMano()->pts()) && (ptr5->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr5->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr5->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 6
					//gane
					if ((ptr6->getMano()->pts() > ptrD->getMano()->pts()) && (ptr6->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr6->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr6->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr6->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr6->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr6->getNickname() << " empato" << std::endl;
					}
				}
			} break;

			case '7': {
				std::cout << "Digite el nombre del/la primer/a jugador/a: " << std::endl; std::cin >> nick;
				std::cout << "Digite el nombre del/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
				std::cout << "Digite el nombre del/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
				std::cout << "Digite el nombre del/la cuarto/a jugador/a: " << std::endl; std::cin >> nick4;
				std::cout << "Digite el nombre del/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;
				std::cout << "Digite el nombre del/la sexto/a jugador/a: " << std::endl; std::cin >> nick6;
				std::cout << "Digite el nombre del/la septimo/a jugador/a: " << std::endl; std::cin >> nick7;

				//Compara jugador dos
				do {
					if (ptrJ->comparaNicknames(nick, nick2) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la segundo/a jugador/a: " << std::endl; std::cin >> nick2;
					}
				} while (ptrJ->comparaNicknames(nick, nick2) == false);

				//Compara jugador tres
				do {
					if (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la tercer/a jugador/a: " << std::endl; std::cin >> nick3;
					}
				} while (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false);

				//Compara jugador cuatro
				do {
					if (ptrJ->comparaNicknames(nick, nick4) == false || ptrJ->comparaNicknames(nick2, nick4) == false || ptrJ->comparaNicknames(nick3, nick4) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la cuarto/a jugador/a: " << std::endl; std::cin >> nick4;
					}
				} while (ptrJ->comparaNicknames(nick, nick3) == false || ptrJ->comparaNicknames(nick2, nick3) == false || ptrJ->comparaNicknames(nick3, nick4) == false);

				//Compara jugador cinco
				do {
					if (ptrJ->comparaNicknames(nick, nick5) == false || ptrJ->comparaNicknames(nick2, nick5) == false || ptrJ->comparaNicknames(nick3, nick5) == false || ptrJ->comparaNicknames(nick4, nick5) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;
					}
				} while (ptrJ->comparaNicknames(nick, nick5) == false || ptrJ->comparaNicknames(nick2, nick5) == false || ptrJ->comparaNicknames(nick3, nick5) == false || ptrJ->comparaNicknames(nick4, nick5) == false);

				//Compara jugador seis
				do {
					if (ptrJ->comparaNicknames(nick, nick6) == false || ptrJ->comparaNicknames(nick2, nick6) == false || ptrJ->comparaNicknames(nick3, nick6) == false || ptrJ->comparaNicknames(nick4, nick6) == false || ptrJ->comparaNicknames(nick5, nick6) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;
					}
				} while (ptrJ->comparaNicknames(nick, nick6) == false || ptrJ->comparaNicknames(nick2, nick6) == false || ptrJ->comparaNicknames(nick3, nick6) == false || ptrJ->comparaNicknames(nick4, nick6) == false || ptrJ->comparaNicknames(nick5, nick6) == false);

				//Compara jugador siete
				do {
					if (ptrJ->comparaNicknames(nick, nick7) == false || ptrJ->comparaNicknames(nick2, nick7) == false || ptrJ->comparaNicknames(nick3, nick7) == false || ptrJ->comparaNicknames(nick4, nick7) == false || ptrJ->comparaNicknames(nick5, nick7) == false || ptrJ->comparaNicknames(nick6, nick7) == false) {
						std::cout << "Por favor digite un nuevo nombre para el/la quinto/a jugador/a: " << std::endl; std::cin >> nick5;
					}
				} while (ptrJ->comparaNicknames(nick, nick6) == false || ptrJ->comparaNicknames(nick2, nick6) == false || ptrJ->comparaNicknames(nick3, nick6) == false || ptrJ->comparaNicknames(nick4, nick6) == false || ptrJ->comparaNicknames(nick5, nick6) == false || ptrJ->comparaNicknames(nick6, nick7) == false);
				system("cls"); //Limpia la pantalla

				//agrega los nicknames
				ptr1->setNickname(nick);
				ptr2->setNickname(nick2);
				ptr3->setNickname(nick3);
				ptr4->setNickname(nick4);
				ptr5->setNickname(nick5);
				ptr6->setNickname(nick6);
				ptr7->setNickname(nick7);
				ptrD->setNickname("Dealer");

				//agrega los jugadores a lista
				list->insertar(ptr1);
				list->insertar(ptr2);
				list->insertar(ptr3);
				list->insertar(ptr4);
				list->insertar(ptr5);
				list->insertar(ptr6);
				list->insertar(ptr7);

				//inizializa el mazo
				maz->inicializar();

				//baraja las cartas
				maz->barajar();

				//jugador 1
				//repartir cartas	
				ptr1->getMano()->setMazo(maz);
				ptr1->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr1->getNickname() << std::endl;
					std::cout << ptr1->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr1->getMano()->setMazo(maz);
						ptr1->pedirCarta();
						std::cout << ptr1->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr1->sePaso() && meJ != '2');

				//jugador 2
				//repartir cartas
				ptr2->getMano()->setMazo(maz);
				ptr2->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr2->getNickname() << std::endl;
					std::cout << ptr2->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr2->getMano()->setMazo(maz);
						ptr2->pedirCarta();
						std::cout << ptr2->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr2->sePaso() == true && meJ != '2');

				//jugador 3
				//repartir cartas
				ptr3->getMano()->setMazo(maz);
				ptr3->pedirCarta();

				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr3->getNickname() << std::endl;
					std::cout << ptr3->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr3->getMano()->setMazo(maz);
						ptr3->pedirCarta();
						std::cout << ptr3->getMano()->MuestraMazo() << std::endl;
					}
					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr3->sePaso() == true && meJ != '2');

				//jugador 4
				//repartir cartas	
				ptr4->getMano()->setMazo(maz);
				ptr4->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr4->getNickname() << std::endl;
					std::cout << ptr4->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr4->getMano()->setMazo(maz);
						ptr4->pedirCarta();
						std::cout << ptr4->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr4->sePaso() && meJ != '2');

				//jugador 5
				//repartir cartas	
				ptr5->getMano()->setMazo(maz);
				ptr5->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr5->getNickname() << std::endl;
					std::cout << ptr5->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr5->getMano()->setMazo(maz);
						ptr5->pedirCarta();
						std::cout << ptr5->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr5->sePaso() && meJ != '2');

				//jugador 6
				//repartir cartas	
				ptr6->getMano()->setMazo(maz);
				ptr6->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr6->getNickname() << std::endl;
					std::cout << ptr6->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr6->getMano()->setMazo(maz);
						ptr6->pedirCarta();
						std::cout << ptr6->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr6->sePaso() && meJ != '2');
				
				//jugador 7
				//repartir cartas	
				ptr7->getMano()->setMazo(maz);
				ptr7->pedirCarta();
				do {
					//muestra nickname y la mano
					std::cout << "Turno de jugador/a " << std::endl;
					std::cout << std::endl << ptr7->getNickname() << std::endl;
					std::cout << ptr7->getMano()->MuestraMazo() << std::endl;

					//menu
					std::cout << "Digite 1) Pedir carta" << std::endl;
					std::cout << "Digite 2) Pasar" << std::endl;
					std::cout << "Digite 3) Guardar partida" << std::endl;
					std::cout << "Digite 4) Salir" << std::endl;
					std::cin >> meJ;

					if (meJ == '1') {
						ptr7->getMano()->setMazo(maz);
						ptr7->pedirCarta();
						std::cout << ptr7->getMano()->MuestraMazo() << std::endl;
					}

					else if (meJ == '2') {
						std::cout << "Se pasara de turno" << std::endl;
					}
					else if (meJ == '3') {
						ptrJ->getLis()->guardarEnArchivo();
						guarda++;
						return 0;
					}
					else if (meJ == '4') {
						std::cout << "Se saldra del programa" << std::endl;
						return 0;
					}

				} while (ptr7->sePaso() && meJ != '2');
				//juega dealer

				//repartir cartas
				ptrD->getMano()->setMazo(maz);
				ptrD->pedirCarta();
				//muestra nickname y la mano
				std::cout << "Turno del dealer" << std::endl;
				std::cout << ptrD->getNickname() << std::endl;
				std::cout << ptrD->getMano()->MuestraMazoD() << std::endl;
				do {
					if (ptrD->getMano()->pts() <= 16) {
						std::cout << "El dealer pide carta" << std::endl;
						ptrD->getMano()->setMazo(maz);
						ptrD->pedirCarta();
					}
					else
						std::cout << "El dealer se queda" << std::endl;
					std::cout << ptrD->getMano()->MuestraMazo() << std::endl;
					std::cout << "Presione enter para seguir" << std::endl;
					system("pause"); //Da pausa para que los jugadores vean las cartas de dealer 

				} while (ptrD->getMano()->pts() <= 16);

				//mostrar resultados
				//resultados generales
				if ((ptrD->getMano()->pts() > 21 && ptr1->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr2->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr3->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr4->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr5->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr6->getMano()->pts() <= 21) && (ptrD->getMano()->pts() > 21 && ptr7->getMano()->pts() <= 21)) {
					std::cout << "Todos los jugadores ganaron porque solo el dealer se paso de veintiuno " << std::endl;
					std::cout << "El dealer pierde" << std::endl;
				}

				else {

					//resultados jugador 1
					//gane
					if ((ptr1->getMano()->pts() > ptrD->getMano()->pts()) && (ptr1->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr1->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " pierde" << std::endl;
					}
					//empato
					if (ptr1->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr1->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 2
					//gane
					if ((ptr2->getMano()->pts() > ptrD->getMano()->pts()) && (ptr2->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr2->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr2->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr2->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 3
					//gane
					if ((ptr3->getMano()->pts() > ptrD->getMano()->pts()) && (ptr3->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr3->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr3->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr3->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 4
					//gane
					if ((ptr4->getMano()->pts() > ptrD->getMano()->pts()) && (ptr4->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr4->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr4->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr4->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 5
					//gane
					if ((ptr5->getMano()->pts() > ptrD->getMano()->pts()) && (ptr5->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr5->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr5->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr5->getNickname() << " empato" << std::endl;
					}

					//resultados jugador 6
					//gane
					if ((ptr6->getMano()->pts() > ptrD->getMano()->pts()) && (ptr6->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr6->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr6->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr6->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr6->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr6->getNickname() << " empato" << std::endl;
					}
					
					//resultados jugador 7
					//gane
					if ((ptr7->getMano()->pts() > ptrD->getMano()->pts()) && (ptr7->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr7->getNickname() << " gana" << std::endl;
					}
					//pierde
					else if ((ptr7->getMano()->pts() < ptrD->getMano()->pts()) && (ptrD->getMano()->pts() <= 21)) {
						std::cout << "Jugador/a " << ptr7->getNickname() << " pierde" << std::endl;
					}
					//empato
					else if (ptr7->getMano()->pts() == ptrD->getMano()->pts()) {
						std::cout << "Jugador/a " << ptr7->getNickname() << " empato" << std::endl;
					}
				}

			} break;

			} //cierra switch

		}

		//opcion 2, cargar partida
		else if (menu == '2') {
			if (guarda != 0) {
				ptrJ->getLis()->cargarDeArchivo();
			
			}
			else
				std::cout << "No hay partida guardada" << std::endl;
		}

		//opcion 3, salir
		else if (menu = '3') {
			std::cout << "Se saldra del programa" << std::endl;
			return 0;
		}

	delete ptrJ;
	delete list;
	delete maz;
	delete man;
	delete ptrD1;
	delete ptrD;
	delete ptr1;
	delete ptr2;
	delete ptr3;
	delete ptr4;
	delete ptr5;
	delete ptr6;
	delete ptr7;

	return 0;
}