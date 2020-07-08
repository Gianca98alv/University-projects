#include "Interfaz.h"

//------------------------------------------------VARIABLES GLOBALES---------------------------------------------
int contAux = 0;
int numPartida = 0;
Tablero* tablero = new Tablero();
Lista* lista = new Lista();
Nodo* actual;
Jugador* jugador;
Estrategia* estrategia;
Partida* partida;
Archivos* archivos;
Ficha* ficha;

Restricciones* reglas = new Restricciones();
Posicion* posicion;
Vector* vector = new Vector();
Vector* vectorJugador = new Vector();
//--------------------------------------------------------------------------------------------------------------

//---------------------------------------INICIO-------------------------------------------------------------
void Interfaz::pruebas() {
	//empresa->calculoSalariosPlanilla(listContPlan);
}

void Interfaz::inicio() {
	Interfaz::inicializarTablero();
	Interfaz::lecturaArchivos();
	Interfaz::asignarNumPartida();
	//estrategia = new Estrategia();
	bienvenido();
}

void Interfaz::inicializarTablero() {
	Ficha* x = new Ficha('x');
	Ficha* o = new Ficha('o');

	tablero->agregar(o, 0, 0);
	tablero->agregar(o, 0, 2);
	tablero->agregar(o, 0, 4);
	tablero->agregar(o, 0, 6);
	tablero->agregar(o, 1, 1);
	tablero->agregar(o, 1, 3);
	tablero->agregar(o, 1, 5);
	tablero->agregar(o, 1, 7);
	tablero->agregar(o, 2, 0);
	tablero->agregar(o, 2, 2);
	tablero->agregar(o, 2, 4);
	tablero->agregar(o, 2, 6);

	tablero->agregar(x, 5, 1);
	tablero->agregar(x, 5, 3);
	tablero->agregar(x, 5, 5);
	tablero->agregar(x, 5, 7);
	tablero->agregar(x, 6, 0);
	tablero->agregar(x, 6, 2);
	tablero->agregar(x, 6, 4);
	tablero->agregar(x, 6, 6);
	tablero->agregar(x, 7, 1);
	tablero->agregar(x, 7, 3);
	tablero->agregar(x, 7, 5);
	tablero->agregar(x, 7, 7);
}

void Interfaz::imprimirTablero() {
	cout << "\n\n\n";
	cout << "\n\n\n";
	cout << tablero->toString();
	cout << "\n\n\n";
}

void Interfaz::imprimir(string s) {
	cout << s;
}

void Interfaz::lecturaArchivos() {
	archivos->leerArchivoPartidas(lista);
}

void Interfaz::asignarNumPartida() {
	numPartida = lista->numElementos();
	numPartida++;
}

void Interfaz::eliminarTodo() {
	delete partida;
	delete archivos;
	delete lista;
	delete ficha;
	delete actual;
}

void Interfaz::crearPartida() {
	partida = new Partida(numPartida, estrategia, jugador, tablero);
}
//-----------------------------------------------------------------------------------------------------------


//-------------------------------------------------JUEGO---------------------------------------------------------
void Interfaz::cargarPartida() {
	system("cls");
	int num;
	cout << " \n";
	cout << "				LISTA DE PARTIDAS: ";
	cout << " \n";
	cout << lista->toStringLista();
	cout << "	Ingrese el número de la partida que desea cargar:  ";
	cin >> num;
	if (comprobarNumPartida(num)) {
		Partida* pAux;
		partida = actual->getInfo();
		jugador = partida->getJugador();
		tablero = partida->getTablero();
		estrategia = partida->getEstrategia();

		actual = lista->getPrimero();
		cout << " \n";
		cout << "\n\n\t\t\t\t\t\tCargando la partida, un momento...\n" << endl;
		cout << "\t\t\t";
		for (int i = 0; i < 60; i++) {
			color(255);
			cout << " ";
			Sleep(20);
		}
		color(15);
		cout << " \n\n";
		cout << "	     ¡La partida se ha cargado con exito! \n";
		cout << " \n";
		system("pause");
		system("cls");
		Interfaz::Juego();
	}
	else {
		cout << " \n";
		cout << " \n";
		cout << "	       El número de partida ingresado no coincide con nunguno de la lista. \n";
		cout << "	       Por favor vuelva a intentarlo. \n";
		cout << " \n";
		system("pause");
		system("cls");
		cargarPartida();
	}
}

void Interfaz::guardarPartida() {

	if (comprobarNumPartida(numPartida)) {
		system("cls");
		Partida* pAux;
		pAux = actual->getInfo();
		pAux->setJugador(jugador);
		pAux->setTablero(tablero);
		pAux->setEstrategia(estrategia);
		actual = lista->getPrimero();
		archivos->guardarPartidas(lista);
		Interfaz::imprimirTablero();
		cout << "	     Partida #" << partida->getNumPartida();
		cout << " \n";
		cout << "        Nombre del Jugador: " << jugador->getNombre() << endl;
		cout << " \n";
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       |                                               |" << endl;
		cout << "	    |    1. Realizar Jugada                         |" << endl;
		cout << "	    |    2. Cambiar Dificultad                      |" << endl;
		cout << "	    |    3. Guardar Partida                         |" << endl;
		cout << "	    |    4. Salir                                   |" << endl;
		cout << "       |                                               |" << endl;
		cout << "       +-----------------------------------------------+" << endl;
		
		cout << " \n";
		cout << "	       Opción: ";
		cout << " \n";
		cout << "\n\n\t\t\t\t\t\tGuardando, no apagues la consola...\n" << endl;
		cout << "\t\t\t";
		for (int i = 0; i < 60; i++) {
			color(255);
			cout << " ";
			Sleep(20);
		}
		color(15);
		cout << " \n\n";
		cout << "	          La partida que quiere guardar ya se encontraba registrada.\n";
		cout << "	          La partida se ha sobre-escrito con exito. \n";
		cout << " \n";
	}
	else {
		lista->agregar(partida);
		archivos->guardarPartidas(lista);
		Interfaz::imprimirTablero();
		cout << "	          Numero de Partida: " << partida->getNumPartida();
		cout << " \n";
		cout << "        Nombre del Jugador: " << jugador->getNombre() << endl;
		cout << " \n";
		cout << "	          1. Realizar Jugada                           " << endl;
		cout << "	          2. Cambiar Dificultad                        " << endl;
		cout << "	          3. Guardar Partida                           " << endl;
		cout << "	          4. Salir                                     " << endl;
		cout << " \n";
		cout << "	       Opción: ";
		cout << " \n";
		cout << "\n\n\t\t\t\t\t\tGuardando, no apagues la consola...\n" << endl;
		cout << "\t\t\t";
		for (int i = 0; i < 60; i++) {
			color(255);
			cout << " ";
			Sleep(20);
		}
		color(15);
		cout << " \n";
		cout << " \n";
		cout << "	          La partida se ha guardado exitosamente. \n";
		cout << " \n";
	}
}

void Interfaz::Juego() {
	Interfaz::menuJuego();
}

string Interfaz::leerString() {

	char chain[100];
	cin.getline(chain, 99);
	stringstream s;
	s << chain;
	int size = s.str().length();

	if (size == 0 || s.str()[0] == 32) {
		if (contAux > 0) {
			cout << "Texto incorrecto, por favor ingreselo nuevamente: ";
		}
		contAux++;
		return leerString();
	}
	contAux = 0;
	return s.str();
}

void Interfaz::color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool Interfaz::comprobarNumPartida(int codAux) {
	int codAux2;
	actual = lista->getPrimero();
	Partida* pAux;
	while (actual != NULL) {
		pAux = actual->getInfo();
		codAux2 = pAux->getNumPartida();
		if (codAux == codAux2) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

void Interfaz::moverFicha(int i, int j, int k, int l) {
	ficha = tablero->getFicha(i, j);
	tablero->getPos(i, j)->setFicha(NULL);
	tablero->agregar(ficha, k, l);
	ficha = NULL;
}
//-----------------------------------------------------------------------------------------------------------


//----------------------------------------------MENUS-------------------------------------------------------------
void Interfaz::menuJuego() {
	char entrar;
	do {
		Interfaz::imprimirTablero();
		cout << "	         Partida #" << partida->getNumPartida();
		cout << jugador->toString();
		cout << " \n";
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       |                                               |" << endl;
		cout << "       |     1. Realizar Jugada                        |" << endl;
		cout << "       |     2. Cambiar Dificultad                     | " << endl;
		cout << "       |     3. Guardar Partida                        |" << endl;
		cout << "       |     4. Salir                                  |" << endl;
		cout << "       |                                               |" << endl;
		cout << "       +-----------------------------------------------+" << endl;
		cout << " \n";
		cout << "	       Opcion: ";
		cin >> entrar;
		switch (entrar) {

		case '1':
			system("cls");
			Interfaz::realizarJugada();
			system("pause");
			system("cls");
			break;

		case '2':
			system("cls");
			system("pause");
			system("cls");
			break;

		case '3':
			system("cls");
			Interfaz::guardarPartida();
			system("pause");
			system("cls");
			break;

		case '4':
			cout << " \n";
			Interfaz::confirmarSalir();
			cout << "       Regresando al menu principal \n";
			cout << " \n";
			system("pause");
			system("cls");
			Controladora::menuprincipal();

			break;
		default:
			cout << " \n";
			cout << "       La opcion digitada es incoreccta, por favor digite una correcta " << endl;
			cout << " \n";
			system("pause");
			system("cls");
			break;

		}
	} while (entrar > 4);

}

void Interfaz::confirmarSalir() {
	cout << " \n";
	cout << "	      Si sale en este momento, cualquier cambio no guardado se borrará  " << endl; 
	cout << "	      ¿Desea guardar la partida antes de salir?:    " << endl; 
	char entrar;
	do {
		cout << " \n";
		cout << "	   1. Volver                    " << endl;
		cout << "	   2. Guardar Partida           " << endl;
		cout << "	   3. Salir sin guardar         " << endl;
		cout << " \n";
		cout << "	       Opción: ";
		cin >> entrar;
		switch (entrar) {

		case '1':
			
			system("cls");
			Interfaz::Juego();
			system("pause");
			system("cls");
			break;

		case '2':
		
			system("cls");
			system("pause");
			system("cls");
			break;

		case '3':
			cout << " \n";
			cout << "     Regresando al menu principal \n";
			cout << "\n\n\t\t\t\t\t\tCargando...\n" << endl;
			cout << "\t\t\t";
			for (int i = 0; i < 60; i++) {
				color(255);
				cout << " ";
				Sleep(12);
			}
			color(15);
			//system("pause");
			system("cls");
			tablero = new Tablero();
			inicializarTablero();
			Controladora::menuprincipal();

			break;
		default:
			cout << " \n";
			cout << "       La opcion digitada es incoreccta, por favor digite una nueva " << endl;
			cout << " \n";
			system("pause");
			system("cls");
			break;

		}
	} while (entrar > 3);


}

void Interfaz::crearJugador() {
	string nombre;
	cout << " \n";
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       |                    INICIO                     |" << endl;
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       |                                               |" << endl;
	cout << "       |  Por favor, ingrese los datos del jugador     |" << endl;
	cout << "       |                                               |" << endl;
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       Nombre del jugador: ";
	nombre = Interfaz::leerString();
	jugador = new Jugador(nombre);
	system("cls");
	cout << " \n";
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       |                     INICIO                    |" << endl;
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       |                                               |" << endl;
	cout << "       |  Jugador ingresado, disfrute de la partida    |" << endl;
	cout << "       |                                               |" << endl;
	cout << "       +-----------------------------------------------+" << endl;
	system("cls");
	Interfaz::elegirEstrategia();
}

void Interfaz::elegirEstrategia() {
	char entrar;
	int num;
	do {
		cout << " \n";
		cout << "       +--------------------------------------------------------+" << endl;
		cout << "       |                            INICIO                      |" << endl;
		cout << "       +--------------------------------------------------------+" << endl;
		cout << "       |                                                        |" << endl;
		cout << "       |  Por favor, elija el nivel de dificultad que desea:    |" << endl;
		cout << "       |                                                        |" << endl;
		cout << "       |                    1. Fácil                            |" << endl;
		cout << "       |                    2. Medio                            |" << endl;
		cout << "       |                    3. Dificil                          |" << endl;
		cout << "       +--------------------------------------------------------+" << endl;
		cout << "       Opción: "; cin >> entrar;
		

		//entrar = '1';

		switch (entrar) {

		case '1':
			system("cls");
			num = 1;
			estrategia = new EstrategiaAleatoria(num);
			Interfaz::crearPartida();
			Interfaz::Juego();
			system("pause");
			system("cls");
			break;

		case '2':
			system("cls");
			num = 2;
			estrategia = new EstrategiaDefensiva(num);
			Interfaz::crearPartida();
			Interfaz::Juego();
			system("pause");
			system("cls");
			break;

		case '3':
			system("cls");
			num = 3;
			estrategia = new EstrategiaOfensiva(num);
			Interfaz::crearPartida();
			Interfaz::Juego();
			system("pause");
			system("cls");
			break;

		default:
			cout << " \n";
			cout << "       La opción digitada es incoreccta: " << endl;
			cout << " \n";
			system("pause");
			system("cls");
			break;

		}
	} while (entrar > 3);
}

void Interfaz::bienvenido() {
	for (int i = 0; i < 3; i++) { cout << "\n"; }
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	color(13);
	cout << "  ¡ B i e n v e n i d o s ! \n";
	for (int i = 0; i < 1; i++) { cout << "\n"; }
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	color(15);
	cout << "     Damas Españolas: \n";
	for (int i = 0; i < 2; i++) { cout << "\n"; }
	color(13);
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << " ________      __     __      \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|   _____|    |  |   |  |     \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|  |   __     |  |___|  |     \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|  |  |  |    |   ___   |     \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|  |__|  |    |  |   |  |     \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|________|    |__|   |__|     \n";
	color(15);
	cout << "\n\n\n";
	cout << "\t\t\t\t      [Pulse ";
	color(10);
	cout << " ENTER ";
	color(15);
	cout << " para continuar ] ";
	cin.clear();
	cin.get();
	cout << "\n\n\t\t\t\t\t\tCargando...\n" << endl;
	cout << "\t\t\t";
	for (int i = 0; i < 60; i++) {
		color(255);
		cout << " ";
		Sleep(7);
	}
	color(15);
}

void Interfaz::realizarJugada() {
	int i, j, k, l;

	Interfaz::imprimirTablero();
	try {
		cout << "      Ingrese la columna de la ficha que desea mover: ";
		cin >> j;
		if (j < 1 || j>8) { throw 3; }
		cout << "	   Ingrese la fila de la ficha que desea mover: ";
		cin >> i;
		if (i < 1 || i>8) { throw 3; }
		cout << "	    Ingrese la columna de la posición a la que desea mover la ficha: ";
		cin >> l;
		if (l < 1 || l>8) { throw 3; }
		cout << "	     Ingrese la fila de la posición a la que desea mover la ficha: ";
		cin >> k;
		if (k < 1 || k>8) { throw 3; }
		j--;
		i--;
		k--;
		l--;
		posicion = tablero->getPos(i, j);
		ficha = tablero->getFicha(i, j);
		if (!(reglas->verificarFicha(tablero, i, j, posicion))) { throw - 1; }
		if (ficha->getCaracter() == 'o' || ficha->getCaracter() == 'N') { throw 1; }
		if (tablero->getPos(k, l)->getFicha() != NULL) { throw 2; }

		if (jugador->sePuedeComer(tablero, reglas, i, j, k, l, posicion)) {
			jugador->comer(tablero, reglas, i, j, k, l, posicion);
			cout << "\n	       Realizando movimiento...\n\n";
			finalizarTurno();
			jugarMaquina();
		}
		else {
			jugador->mover(tablero, reglas, i, j, k, l, posicion);
			cout << "\n	       Realizando movimiento \n\n";
			finalizarTurno();
			jugarMaquina();
		}
	}
	catch (int e) {
		if (e == 1) { cout << "\n	    Solo se pueden mover fichas que correspondan al jugador"; }
		if (e == 2) { cout << "\n	    Posicion final ocupada"; }
		if (e == 3) { cout << "\        El numero digitado no corresponde a ninguna fila o columna disponible"; }
		cout << "\n	       Movimiento inválido \n\n";
	}
}
void Interfaz::jugarMaquina() {
	system("cls");
	Interfaz::imprimirTablero();
	try {
		vector->llenarPosiciones(tablero);
		estrategia->jugar(tablero, reglas, vector);
		cout << "\n	       Ahora es el turno de la maquina \n\n";
		system("pause");
		finalizarTurno();
	}
	catch (int c) {
		cout << "	       ERROR CON LA MAQUINA \n";
		system("pause");
	}
	//finalizarTurno();
}

void Interfaz::finalizarTurno() {

	system("cls");
	Interfaz::imprimirTablero();
	try {
		reglas->coronar(tablero);
		vector->llenarPosiciones(tablero);
		cout << vector->getCant() << endl;
		vectorJugador->llenarPosicionesJugador(tablero);
		cout << vectorJugador->getCant() << endl;
		cout << "\n	       Finalizando turno \n\n";
		system("pause");

	}
	catch (int c) {
		cout << "	       ERROR AL FINALIZAR TURNO \n";
		system("pause");
	}
	if (vector->getCant() == 0) {
		JugadorGana();
	}

	if (vectorJugador->getCant() == 0) {
		MaquinaGana();
	}
}

void Interfaz::JugadorGana() {
	system("cls");
	Interfaz::imprimirTablero();
	cout << "\n	       FELICIDADES, HA GANADO LA PARTIDA!!!! \n\n";
	system("pause");
	cout << "\n	       volvera al menu principal \n\n";
	system("pause");
	system("cls");
	tablero = new Tablero();
	inicializarTablero();
	Controladora::menuprincipal();
}

void Interfaz::MaquinaGana() {
	system("cls");
	Interfaz::imprimirTablero();
	cout << "\n	       ¡El juego ha terminado! ";
	cout << "\n	       mejor suerte la proxima vez \n\n";
	system("pause");
	cout << "\n	       volvera al menu principal \n\n";
	system("pause");
	system("cls");
	tablero = new Tablero();
	inicializarTablero();
	Controladora::menuprincipal();
}
//-----------------------------------------------------------------------------------------------------------