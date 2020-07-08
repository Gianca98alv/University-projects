#include "GestionRecinto.h"

//Constructor sin parametros
GestionRecinto::GestionRecinto() {
	v = new Recinto*[100]; 
	cant = 0;
	tam = 100;
}

//Esta funcion mueve el cursor de la ventana de texto a la posición según las coordenadas especificadas por los argumentos x,y. 
void GestionRecinto::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//Este método verifica si es un administrador.
//Valida que con la clave "admin" pueda ingresar a los submenus para poder modificar, eliminar, visualizar...
bool GestionRecinto::revisarAdmi() {
	system("cls");
	string contrasena = "admin";
	col(15);
	cout << "\n\n\n";
	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187) << endl;
	cout << "\t\t\t" << char(186) << "  Usuario: Administrador      " << char(186) << endl;
	cout << "\t\t\t" << char(186) << "  Clave  :                    " << char(186) << endl;
	cout << "\t\t\t" << char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(188) << endl;
	col(76);
	gotoxy(36, 5);
	cin.ignore();
	getline(cin, contrasena);
	col(15);

	if (contrasena == "admin") {
		std::cout << "\n\n\t\t Contrasena correcta, sesion exitosamente iniciada ";
		std::cout << "\n\t\t ";
		system("pause");
		return true;

	}
	else {
		std::cerr << "\t\t Contraseña incorrecta, intente de nuevo "; std::cout << std::endl;
		std::cout << "\n\n\t\t "; system("pause");
		return false;

	}
	col(13);
	cout << "\n\n\n\t\t\t";
	cout << "Bienvenido a la Gestion de datos del Recinto!\n";
	for (int i = 0; i < 2; i++) {
		Sleep(500);
	}
	system("cls");
}

void GestionRecinto::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }//Recibe un número al cual le corresponde un color y lo muestra en el texto.

int GestionRecinto::getCant(){
	return cant;
}

//Ingresa un recinto al vector de rencitos, si hay campo
//Este constructor es para recintos predetermindados
void GestionRecinto::ingresarRecinto(Recinto *re) {
	if (cant<tam) {
		v[cant] = re;
		cant++;
	}
	else {
		col(12);
		cout << "\nNo hay campo para ingresar un nuevo recinto!\n";
	}
}

//Ingresa un recinto al vector de rencitos, si hay campo
//Este constructor es para que el administrador ingrese un nuevo recinto
//Realiza sus respectivas validaciones 
void GestionRecinto::ingresarRecinto() {
	if (cant < tam) {
		string lug;
		string telo;
		int duracion;
		bool d1 = true;	
		system("cls");
		col(10);
		cout << "\t\t(Ingresar datos del Recinto)\n\n";
		col(15);
		cout << "Ingrese el Lugar del concierto: ";
		cin.ignore();
		col(10);
		getline(cin, lug);
		col(15);
		cout << "\nIngrese el nombre del Telonero del concierto: ";
		col(10);
		getline(cin, telo);
		col(15);
		cout << "\nIngrese la Duracion del show: (";
		col(14);
		cout << "Cantidad de Horas";
		col(15);
		cout << ")";
		d1 = true;
		while (d1) {
			cout << " > ";
			col(14);
			if (!(cin >> duracion)) {
				col(12);
				cerr << "Error! Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				d1 = false;
			}
			col(15);
		}
		v[cant] = new Recinto(lug, telo, duracion);
		cant++;
		col(10);
		cout << "\nSe ha ingresado un recinto con su informacion respectiva correctamente!\n";
		col(15);
		system("PAUSE");
	}
	else {
		col(12);
		cout << "\nNo hay campo para ingresar un nuevo recinto!\n";
	}
}
void GestionRecinto::visualizar() {
	system("cls");
	col(10);
	cout << "\t\t(Visualizar Recintos y sus Datos)\n\n";
	col(15);
	if (cant == 1) {
		cout << "La empresa tiene: " << cant << " recinto!\n\n";
	}
	else {
		cout << "La empresa tiene: " << cant << " recintos!\n\n";
	}
	for (int i = 0; i < 30; i++) { cout << "-"; }
	cout << endl;
	for (int i = 0; i < cant;i++) {
		col(11);
		cout << "Recinto "<<i+1<<endl;
		col(15);
		cout<<v[i]->toString()<<endl;
	}
	system("PAUSE");
}

//Modifica los datos de algún recinto
//Realiza sus respectivas validaciones
void GestionRecinto::modificar(){
	system("cls");
	col(10);
	cout << "\t\t(Modificar Recinto)\n\n";
	col(15);
	if (cant != 0) {
		cout << "\tDigite el recinto que quiera modificar:\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "] ";
			col(15);
			cout << v[i]->sumaRecinto() << endl;
		}
		col(10);
		cout << "\t[0] ";
		col(15);
		cout << "Cancelar\n";
		int opc;
		bool ciclo = true;
		while (ciclo) {
			cout << "\t> ";
			if (!(cin >> opc)) {
				col(12);
				cerr << "Error!\nDigite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opc >= 0 && opc <= cant) {
					ciclo = false;
				}
				else {
					col(12);
					cerr << "Error! Digite numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					ciclo = true;
				}
			}
		}
		if (opc != 0) {
			int opcR = opc - 1;
			
			cout << "\n\n";
			cout << "\tQue desea modificar?\n";
			col(10);
			cout << "\t[1]";
			col(15);
			cout << " Lugar del concierto\n";
			col(10);
			cout << "\t[2]";
			col(15);
			cout << " Telonero \n";
			col(10);
			cout << "\t[3]";
			col(15);
			cout << " Duracion\n";
			col(10);
			cout << "\t[0]";
			col(15);
			cout << " Cancelar\n";

			int opc2;
			bool ciclo2 = true;
			string cambio;
			int cambioN;
			bool d = true;
			bool d1 = true;
			while (ciclo2) {
				cout << "\t> ";
				if (!(cin >> opc2)) {
					col(12);
					cerr << "Error!\nDigite un numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					if (opc2 >= 0 && opc2 < 5) {
						ciclo2 = false;
					}
					else {
						ciclo2 = true;
					}
				}
			}
			if (opc2 != 0) {
				switch (opc2) {
				case 1:
					col(11);
					cout << "(Lugar)\n\n";
					col(15);
					cout << "[" << opc << "] " << v[opcR]->sumaRecinto() << endl;
					cout << "Digite el nuevo lugar donde se realizara el concierto:\n>";
					cin.ignore();
					getline(cin, cambio);
					v[opcR]->setLugar(cambio);
					col(10);
					cout << "\nCambio realizado correctamente!\n";
					col(15);
					break;
				case 2:
					col(11);
					cout << "(Telonero)\n\n";
					col(15);
					cout << "[" << opc << "] " << v[opcR]->sumaRecinto() << endl;
					cout << "Digite el nuevo telonero:\n>";
					cin.ignore();
					getline(cin, cambio);

					v[opcR]->setTelonero(cambio);
					col(10);
					cout << "\nCambio realizado correctamente!\n";
					col(15);
					break;
				case 3:
					col(11);
					cout << "(Duracion)\n\n";
					col(15);
					cout << "[" << opc << "] " << v[opcR]->getDuracion() << endl;
					cout << "Digite la nueva duracion:\n";
					while (d1) {
						cout << "> ";
						if (!(cin >> cambioN)) {
							col(12);
							cerr << "Error!\nDigite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							d1 = false;
						}
					}
					v[opcR]->setDuracion(cambioN);
					col(10);
					cout << "\nCambio realizado correctamente!\n";
					col(15);
					break;
				default:
					break;
				}
			}
		}
	}
	else {
		col(12);
		cout << "No hay recintos que modificar!\n";
		col(15);
	}
	system("PAUSE");
}


//Elimina un recinto
//Realiza sus respectivas validaciones
void GestionRecinto::eliminar() {
	system("cls");
	col(10);
	cout << "\t\t(Eliminar Recintos)\n\n";
	col(15);
	if (cant != 0) {
		cout << "Cual recinto desea eliminar?\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "] ";
			col(15);
			cout << v[i]->getLugar() << "-" << v[i]->getTelonero() << endl;
		}
		col(10);
		cout << "\t[0] ";
		col(15);
		cout << "Cancelar\n";
		int opc1;
		bool ciclo = true;
		while (ciclo) {
			cout << "\t> ";
			if (!(cin >> opc1)) {
				col(12);
				cerr << "Error!\nDigite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opc1 >= 0 && opc1 <= cant) {
					ciclo = false;
				}
				else {
					col(12);
					cerr << "Error!\nDigite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
		}
		if (opc1 != 0) {
			int opcR = opc1 - 1;
			if (opcR == (cant - 1)) {
				cant--;
			}
			else {
				v[opcR] = v[cant - 1];
				cant--;
			}
			col(10);
			cout << "\nSe ha eliminado el recinto correctamente!\n";
			col(15);
		}
	}
	else {
		col(12);
		cout << "No hay recinto para eliminar!\n";
		col(15);
	}
	system("PAUSE");
}


//Muestra el Menu principal de la clase Gestion de Recintos
//En el cual se podrá eliminar, modificar e ingresar conciertos
int GestionRecinto::menu(){
	system("cls");
	col(15);
	cout << endl << endl << endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	col(208);
	cout << "      GESTION DE RECINTO      ";
	col(15);
	cout << char(186) << endl;
	col(15);
	cout << "\t\t\t\t" << char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(188) << endl;

	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186) << endl;

	cout << "\t\t\t";
	cout << char(186);
	col(5);
	cout << "  [1]";
	col(15);
	cout << "   Ingresar        \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(5);
	cout << "  [2]";
	col(15);
	cout << "   Visualizar      \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(5);
	cout << "  [3]";
	col(15);
	cout << "   Modificar       \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(5);
	cout << "  [4]";
	col(15);
	cout << "   Eliminar        \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(5);
	cout << "  [0]";
	col(15);
	cout << "   Menu Principal    \n";
	cout << "\t\t\t";
	cout << char(186);

	cout << "\n\t\t\t" << char(204);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(185) << endl;
	cout << "\t\t\t" << char(186) << endl;
	cout << "\t\t\t" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "\n\t\t\t" << char(200);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(188) << endl;
	for (int i = 0; i < 11; i++) {
		gotoxy(71, 7 + i); cout << char(186);
	}
	gotoxy(71, 19); cout << char(186);
	gotoxy(71, 20); cout << char(186);
	gotoxy(71, 21); cout << char(186);
	int opci;
	bool c = true;
	while (c) {
		gotoxy(35, 20); cout << "Opcion > ";
		col(10);
		if (!(cin >> opci)) { //revisa si falla
			col(15);
			gotoxy(44, 20); cout << "                           " << char(186) << "            "; //limpia el buffer
			col(12);
			gotoxy(55, 20); cout << "Error!";
			col(15);
			Sleep(700);
			gotoxy(44, 20); cout << "                           "; //limpia el error
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (opci < 0 || opci >4) {
			col(15);
			gotoxy(44, 20); cout << "                           " << char(186) << "            ";//limpia el buffer
			col(12);
			gotoxy(55, 20); cout << "Error!";
			col(15);
			Sleep(700);
			gotoxy(44, 20); cout << "                           "; //limpia el error
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else { c = false; }
		col(15);
	}
	return opci;
}

//Muestra los datos de los recintos
void GestionRecinto::mostrarRecintos() {
	for (int i = 0; i < cant; i++) {
		col(11);
		cout << "Recinto: " << i + 1 << endl;
		col(15);
		cout << v[i]->toString() << endl;
	}
}

//Retorna el recinto que se encuentre en la posición recibida del vector
Recinto* GestionRecinto::devuele(int i){
	return v[i];
}

//Destructor
//Es muy importante siempre incluir este destructor cuando se trabaja con un vector dinámico de objetos al igual dinámicos
GestionRecinto::~GestionRecinto(){
	for (int i = 0; i < cant; i++) {
		delete v[i];
	}
	delete[] v;
	cant = 0;
	tam = 0;
	col(10);
	cout << "Se han destruido los recintos disponibles!" << endl;
	col(15);
}

