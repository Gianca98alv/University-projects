#include "GestionConcierto.h"

//Constructor sin parametros
GestionConcierto::GestionConcierto() {
	cant = 0;
	tam = 100;
	v = new Concierto*[100];
}

//Esta funcion mueve el cursor de la ventana de texto a la posición según las coordenadas especificadas por los argumentos x,y. 
void GestionConcierto::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//Este método verifica si es un administrador.
//Valida que con la clave "admin" pueda ingresar a los submenus para poder modificar, eliminar, visualizar...
bool GestionConcierto::revisarAdmin() {
	system("cls");
	string contrasena = "admin";
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
	cout << "Bienvenido a la Gestion del Concierto!\n";
	for (int i = 0; i < 2; i++) {
		Sleep(500);
	}
	system("cls");
}

void GestionConcierto::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }//Recibe un número al cual le corresponde un color y lo muestra en el texto.

int GestionConcierto::getCant() {return cant;}

//Ingresa un concierto al vector de conciertos, si hay campo
//Este constructor es para conciertos predetermindados
void GestionConcierto::ingresarConcierto(Concierto *a) {
	if (cant<tam) {
		v[cant] = a;
		cant++;
	}
	else {
		col(12);
		cout << "No hay campo para ingresar un nuevo Concierto!\n";
		col(15);
	}
}

//Ingresa un concierto al vector de conciertos, si hay campo
//Este constructor es para que el administrador ingrese un nuevo concierto tamano A,B o C
//Realiza sus respectivas validaciones 
void GestionConcierto::ingresarConcierto() {
	if (cant < tam) {
		string can, fun;
		char tamanoConcierto;
		system("cls");
		col(10);
		cout << "\t\t(Ingresar Concierto)\n\n";
		col(15);
		bool tamA = true;
		cout << "Cual seria el tamaño del Concierto? \n";
		col(10);
		cout << "[ A ]";
		col(15);
		cout << " Capacidad para 500 personas" << endl;
		col(10);
		cout << "[ B ]";
		col(15);
		cout << " Capacidad para 1000 personas "<< endl;
		col(10);
		cout << "[ C ]";
		col(15);
		cout << " Capacidad para 2000 personas ";
		int fil, colu, t;
		while (tamA == true) {
			cout << "\n> ";
			if (!(cin >> tamanoConcierto)) {
				col(12);
				cerr << "Digite una letra!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
				tamA = true;
			}
			else {
				if ((tamanoConcierto == 'a') || (tamanoConcierto == 'b' || tamanoConcierto == 'c' || tamanoConcierto == 'A' || tamanoConcierto == 'B' || tamanoConcierto == 'C')) {
					if (tamanoConcierto == 'A' || tamanoConcierto == 'a') {
						t = 500;
						fil = 10;
						colu = 50;
					}	if (tamanoConcierto == 'B' || tamanoConcierto == 'b') {
						t = 1000;
						fil = 20;
						colu = 50;
					}
					else if (tamanoConcierto == 'C' || tamanoConcierto == 'c') {
						t = 2000;
						fil = 40;
						colu = 50;
					}
					tamA = false;
				}
				else {
					col(12);
					cerr << "Digite \"A\" o \"B\" o \"C\" \n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					tamA = true;
				}
			}
		}
		cout << "\nDigite el nombre del Cantante del Concierto > ";
		cin.ignore();
		getline(cin, can);
		cout << "\nDigite el Nombre de la Funcion> ";
		getline(cin, fun);
		v[cant] = new Concierto(can, fun, t, fil, colu);
		cant++;
		col(10);
		cout << "Concierto ingresado Correctamente!\n";
		col(15);
		system("PAUSE");
	}
	else {
		col(12);
		cerr << "\nNo hay espacio para mas Conciertos!\n";
		col(15);
		system("PAUSE");
	}
}

//Muestra todos los conciertos ingresados
void GestionConcierto::visualizarConciertos() {
	system("cls");
	col(10);
	cout << "\t\t(Visualizar Conciertos)\n\n";
	col(14);
	col(15);
	cout << "La empresa tiene: " << cant;
	cant > 1 ? cout << " Conciertos " << endl : cout << " Concierto " << endl;

	for (int i = 0; i < cant; i++) {
		cout << "-------------------------" << endl;
		col(11);
		cout << "Concierto: " << i+1 << endl << endl;
		col(15);
		cout<<v[i]->toString()<<endl;
	}
	cout << endl;
	system("PAUSE");
}

//Muestra los datos de los conciertos ingresados
void GestionConcierto::toString() {
	cout << "----------------------\n";
	for (int i = 0; i < cant; i++) {

			col(11);
			cout << "Concierto: " << i + 1 << endl << endl;
			col(15);
			cout << v[i]->toString() << endl;
		
	}
}

//Elimina un concierto
//Realiza sus respectivas validaciones
void GestionConcierto::eliminar() {
	system("cls");
	col(10);
	cout << "\t\t(Eliminar Conciertos)\n\n";
	col(15);
	if (cant != 0) { //si hay Conciertoes 
		cout << "\tCual Concierto desea eliminar?\n";
		for (int i = 0; i < cant; i++) { 
			col(10);
			cout << "\t[" << i + 1 << "]";
			col(15);
			cout << v[i]->getNomFuncion() << " - " << v[i]->getCantante() << endl;
		}
		col(10);
		cout << "\t[0]";
		col(15);
		cout << " Cancelar\n";
		int eliC;
		bool cic = true;
		//Verificacion
		while (cic) {
			cout << "> ";
			if (!(cin >> eliC)) {
				col(12);
				cerr << "Error! Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
				cic = true;
			}
			else {
				if (eliC >= 0 && eliC <= cant ) {
					cic = false;
				}
				else {
					col(12);
					cerr << "Error! Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					cic = true;
				}
			}
		}
		if (eliC != 0) {
			int opcA = eliC - 1;
			if (opcA == (cant - 1)) {
				cant--;
				col(10);
				cout << "Se ha eliminado un Concierto Correctamente!\n";
				col(15);
			}
			else {
				v[opcA] = v[cant - 1];
				cant--;
				col(10);
				cout << "Se ha eliminado un Concierto Correctamente!\n";
				col(15);
			}
		}
		system("PAUSE");
	}
	else {
		col(12);
		cout << "No hay Conciertos para eliminar!\n";
		col(15);
		system("PAUSE");
	}
}

//Muestra el Menu principal de la clase Gestion de Conciertos
//En el cual se podrá eliminar, modificar e ingresar conciertos
int GestionConcierto::menu() {
	system("cls");
	col(15);
	cout << endl << endl << endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	col(160);
	cout << "     GESTION DEL CONCIERTO    ";
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
	col(2);
	cout << "  [1]";
	col(15);
	cout << "   Ingresar        \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(2);
	cout << "  [2]";
	col(15);
	cout << "   Visualizar      \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(2);
	cout << "  [3]";
	col(15);
	cout << "   Modificar       \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(2);
	cout << "  [4]";
	col(15);
	cout << "   Eliminar        \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(2);
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
	int opc;
	bool c = true;
	while (c) {
		gotoxy(35, 20); cout << "Opcion > ";
		col(10);
		if (!(cin >> opc)) { //revisa si falla
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
		else if (opc < 0 || opc >4) { 
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
	return opc;
}

//Modifica los datos de algún concierto
//Realiza sus respectivas validaciones
void GestionConcierto::modificar() {
	system("cls");
	col(10);
	cout << "\t\t(Modificar Conciertos)\n\n";
	col(15);
	if (cant != 0) {
		cout << "Que Concierto desea modificar?\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "] ";
			col(15);
			cout << v[i]->getNomFuncion() << " - " << v[i]->getCantante() << endl;
		}
		col(10);
		cout << "\t[0]";
		col(15);
		cout << " Cancelar\n";
		int opcConcierto;
		bool opcConciertoCiclo = true;
		while (opcConciertoCiclo) { //valida que haya ingresado bien los datos y que este en el rango de numeros
			cout << " \n\t> ";
			col(10);
			if (!(cin >> opcConcierto)) {
				col(12);
				cerr << "Error! Digite numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opcConcierto >= 0 && opcConcierto <= (cant)) {
					opcConciertoCiclo = false;
				}
				else {
					col(12);
					cerr << "Error! Digite numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					opcConciertoCiclo = true;
				}
			}
			col(15);
		}
		int opcA = opcConcierto - 1;
		if (opcConcierto != 0) {
			cout << "Que desea modificar?\n";
			col(10);
			cout << "\t[1]";
			col(15);
			cout << " Cantante\n";
			col(10);
			cout << "\t[2]";
			col(15);
			cout << " Nombre de la Funcion \n";
			col(10);
			cout << "\t[0]";
			col(15);
			cout << " Cancelar\n";
			int opc;
			bool c = true;
			while (c) {
				cout << "\t> ";
				col(10);
				if (!(cin >> opc)) {
					col(12);
					cerr << "Error! Digite numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					if (opc >= 0 && opc <= 3) {
						c = false;
					}
					else {
						col(12);
						cerr << "Error! Digite numero de la lista!\n";
						col(15);
						cin.clear();
						cin.ignore(1024, '\n');
						c = true;
					}
				}
				col(15);
			}
			if (opc != 0) {
				int an = 0;
				string cantan = " ";
				string fun = " ";
				bool ciAn = true;
				switch (opc) {
				case 1:
					col(10);
					cout << "\t\t(Cantante)\n\n";
					col(15);
					cout << "El cantante del Concierto (" << v[opcA]->getNomFuncion() << ") "<< " es: " << v[opcA]->getCantante() << endl;
					cout << "Digite el nuevo cantante \n> ";
					cin.ignore();
					getline(cin, cantan);
					v[opcA]->setCantante(cantan);
					col(10);
					cout << "Cambio relizado correctamente!\n";
					col(15);
					break;
				case 2:
					col(10);
					cout << "\t\t(Nombre de la Funcion)\n\n";
					col(15);
					cout << "El nombre de la funcion es: " << v[opcA]->getNomFuncion() << endl;
					cout << "Digite el nuevo nombre \n>";
					cin.ignore();
					getline(cin, fun);
					v[opcA]->setNomFuncion(fun);
					col(10);
					cout << "Cambio relizado correctamente!\n";
					col(15);
					break;
				case 0:
					break;
				default:
					col(10);
					cout << "Ha digitado mal un numero!\nComience de nuevo!\n";
					col(15);
					break;
				}
			}
			else{}
		}
		else {}
	}
	else {
		col(12);
		cout << "No hay Conciertos para modificar!\n";
		col(15);
	}
	system("PAUSE");
}

//Retorna el concierto que se encuentre en la posición recibida del vector
Concierto* GestionConcierto::devuelve(int i) {return v[i];}

//Destructor
//Es muy importante siempre incluir este destructor cuando se trabaja con un vector dinámico de objetos al igual dinámicos
GestionConcierto::~GestionConcierto() { 
	for (int i = 0; i < cant; i++)
		delete v[i];
	delete[] v;
	tam = 0;
	cant = 0;
	col(10);
	cout << "Se han destruido todos los Conciertos!"<<endl;
	col(15);
}
