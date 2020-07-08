#include "Controladora.h"
#include "Tablero.h"
#include "Ficha.h"

Controladora::Controladora() {}
Controladora::~Controladora() {}

//-----------------------------------menu principal----------------------------------------------------
void Controladora::menuprincipal() {
	system("cls");
	char entrar;
	do {
		cout << " \n";
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       |                      MENU                     |" << endl;
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       |                                               |" << endl;
		cout << "       |  1. Nueva Partida                             |" << endl;
		cout << "       |  2. Cargar Partida                            |" << endl;
		cout << "       |  3. Salir                                     |" << endl;
		cout << "       |                                               |" << endl;
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       Opcion: ";
		cin >> entrar;
		switch (entrar) {

		case '1':
			system("cls");
			Interfaz::crearJugador();
			system("pause");
			system("cls");
			break;

		case '2':
			system("cls");
			Interfaz::cargarPartida();
			system("pause");
			system("cls");
			break;

		case '3':
			cout << " \n";
			cout << "      Saliendo del programa \n";
			cout << " \n";
			cout << "\n\n\t\t\t\t\t\tCargando...\n" << endl;
			cout << "\t\t\t";
			for (int i = 0; i < 60; i++) {
				color(255);
				cout << " ";
				Sleep(12);
			}
			color(15);
			system("pause");
			exit(1);

			break;
		default:
			cout << " \n";
			cout << "      La opción digitada es incoreccta: " << endl;
			cout << " \n";
			system("pause");
			system("cls");
			break;
		}
	} while (entrar > 3);
}

void Controladora::color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Controladora::inicio() {
	Interfaz::inicio();
	Controladora::menuprincipal();
}
//------------------------------------------------------------------------------------------------------------

