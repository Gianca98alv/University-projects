#include "GestionFechas.h"

//Constructor sin parámetros
GestionFechas::GestionFechas() {
	v = new  Fechas*[100]; //Declara hasta 100 fechas (no especifica cuantas fechas se pueden hacer)
	cant = 0;
	tam = 100;
}

void GestionFechas::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }//Recibe un número al cual le corresponde un color y lo muestra en el texto.


//Esta funcion mueve el cursor de la ventana de texto a la posición según las coordenadas especificadas por los argumentos x,y.
void GestionFechas::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}


//Este método verifica si es un administrador.
//Valida que con la clave "admin" pueda ingresar a los submenus para poder modificar, eliminar, visualizar...
bool GestionFechas::revisarAdm() {
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
	cout << "Bienvenido a la Gestion de Fechas!\n";
	for (int i = 0; i < 2; i++) {
		Sleep(500);
	}
	system("cls");
}



//Ingresa una fecha al vector de conciertos, si hay campo
//Este constructor es para fechas predetermindados
void GestionFechas::insertarFecha(Fechas * fe) {
	if (cant < tam) {
		v[cant] = fe;
		cant++;
	}
	else {
		col(12);
		cout << "No hay campo para insertar una nueva fecha!\n";
		col(15);
	}
}

//Modifica los datos de alguna fecha
//Realiza sus respectivas validaciones
void GestionFechas::visualizar() {
	if (cant > 1) {
		cout << "La empresa tiene: " << cant;
		cant > 1 ? cout << " fechas disponibles " << endl : cout << " fecha disponible " << endl;
		cout << "Cual fecha desea visualizar?\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "]  ";
			col(15);
		}
		cout << endl;
		int opcFe;
		bool ve = true;
		while (ve) {
			cout << "\t> ";
			col(10);
			if (!(cin >> opcFe)) {
				col(12);
				cout << "ERROR!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opcFe > 0 && opcFe <= cant) {
					ve = false;
				}
				else {
					col(12);
					cout << "ERROR!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
			}
			col(15);
		}

		cout << "\n-------------------------------------------\n";
		col(11);
		cout << " - Fecha: " << opcFe << endl << endl;
		col(15);
		cout << v[opcFe - 1]->toString() << endl;
		col(11);
		cout << " - Concierto: " << endl;
		col(15);
		cout << v[opcFe - 1]->devuelveConcierto().toString() << endl;
		v[opcFe - 1]->devuelveConcierto().imprimeAsientos();//quitar imprimirAsientos
		col(11);
		cout << "\n - Boletos" << endl << endl;
		col(15);
		cout << v[opcFe - 1]->devuelveConcierto().toStringPersonas()<<endl;
		cout << endl<<endl;
	}
	else
		col(12);
	if (cant < 1) {
		cout << "No hay fechas para visualizar!\n";
	}
	col(15);
}

//Modifica algún dato de la fecha 
//Realiza sus respectivas validaciones
void GestionFechas::modificar(){
	system("cls");
	col(10);
	cout << "\t\t(Modificar Fechas)\n\n";
	col(15);
	if (cant != 0) {
		cout << "\tQue fecha desea modificar?\n";
		for (int i = 0; i < cant; i++) {
			col(10);
			cout << "\t[" << i + 1 << "] ";
			col(15);
			cout << v[i]->getFecha() << "- Produccion (" << v[i]->getNomProduccion() << ")"<< endl;
		}
		col(10);
		cout << "\t[0]";
		col(15);
		cout << " Cancelar\n";
		int opcF;
		bool opcVueloCiclo = true;
		while (opcVueloCiclo) { //valida que haya ingresado bien los datos y que este en el rango de numeros
			cout << "\t> ";
			col(10);
			if (!(cin >> opcF)) {
				col(12);
				cerr << "Error! Digite numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (opcF >= 0 && opcF <= cant) {
					opcVueloCiclo = false;
				}
				else {
					col(12);
					cerr << "Error! Digite numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					opcVueloCiclo = true;
				}
			}
			col(15);
		}
		if (opcF != 0) {
			
			int opciFech = opcF - 1;
			cout << "\tQue desea modificar?\n\n";
			col(10);
			cout << "\t[1]";
			col(15);
			cout << " Año-Mes-Dia";
			col(10);
			cout << "\t[2]";
			col(15);
			cout << " Hora de Inicio\n";
			col(10);
			cout << "\t[3]";
			col(15);
			cout << " Nombre de la Produccion";
			col(10);
			cout << "\t[0] ";
			col(15);
			cout << "Cancelar\n";
			int opcModifica;
			bool c = true;
			while (c) {
				cout << "\t> ";
				col(10);
				if (!(cin >> opcModifica)) {
					col(12);
					cerr << "Error! Digite numero!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
				}
				else {
					if (opcModifica >= 0 && opcModifica <= 6) {
						c = false;
					}
					else {
						col(12);
						cerr << "Error! Digite numero!\n";
						col(15);
						cin.clear();
						cin.ignore(1024, '\n');
						c = true;
					}
				}
				col(15);
			}
			string nomP;
			string cadena;
			string fe;
			int horaIn;
			int horaFi;
			bool ciclo_validaciones = true;
			system("cls");
			int dura;
			int suma;
			switch (opcModifica) {
			case 1:
				col(10);
				cout << "\t\t(Fecha)\n\n";
				col(15);
				cout << "La fecha del Concierto es: " << v[opciFech]->getFecha() << endl;
				v[opciFech]->setFecha(v[opciFech]->muestraFecha());
				cout << endl;
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			case 2:
				col(10);
				cout << "\t\t(Hora de Inicio)\n\n";
				col(15);
				cout << "La hora de inicio del show es: " << v[opciFech]->getHoraInicio() << endl;
				cout << "\tAM\t\t\t\tPM\n";
				for (int i = 0; i < 12; i++) {
					for (int j = 0; j < 2; j++) {
						if (j == 1) {
							col(14);
							cout << "\t" << i + 13;
							col(15);
							cout << ":" << "00\t\t\t";
						}
						else {
							col(14);
							cout << "\t" << i + 1;
							col(15);
							cout << ":" << "00\t\t\t";
						}
					}
					cout << endl;
				}
				cout << endl;
				cout << "\nDigite la nueva hora de inicio para el show: >";
				while (ciclo_validaciones) {
					cout << ">";
					if (!(cin >> horaIn)) {
						col(12);
						cerr << "Error! Digite un numero!\n";
						col(15);
						cin.clear();
						cin.ignore(1024, '\n');
						ciclo_validaciones = true;
					}
					else { ciclo_validaciones = false; }
				}
				//--una verificacion para saber la hora de inicio del concierto
				dura = (v[opciFech]->getHoraFin()) - (24) - (v[opciFech]->getHoraInicio()) + 24; 
				v[opciFech]->setHoraInicio(horaIn);
				suma = v[opciFech]->getHoraInicio() + dura;
				if (suma > 24) { horaIn = suma - 24; }
				else { horaFi = suma; }
				//--!una verificacion para saber la hora de fin del concierto
				v[opciFech]->setHoraFin(horaFi);
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			case 3:
				col(10);
				cout << "\t\t(Fecha)\n\n";
				col(192);
				cout << "[La fecha esta relacionado directamente con el recinto]\n\n";
				col(15);
				Sleep(700);
				cout << "El nombre de la Produccion es: " << v[opciFech]->getNomProduccion() << endl;
				cout << endl;
				cout << "Digite el nuevo nombre de la Produccion: >";
				cin.ignore();
				getline(cin, nomP);
				for (int i = 0; nomP[i]; i++) {
					nomP[i] = toupper(nomP[i]);
				}
				v[opciFech]->setNomProduccion(nomP);
				col(10);
				cout << "Cambio relizado correctamente!\n";
				col(15);
				break;
			default:
				break;
			}
		}
	}
	else {
		col(12);
		cout << "No hay fechas para modificar!\n";
		col(15);
	}
}

//Elimina una fecha 
//Realiza sus respectivas validaciones
void GestionFechas::eliminar(){
	system("cls");
	col(10);
	cout << "\t\t(Eliminar Fechas)\n\n";
	col(15);
	if (cant != 0) { //si hay vuelos 
		cout << "\tCual fecha desea eliminar?\n";
		for (int i = 0; i < cant; i++) { 
			col(10);
			cout << "\t[" << i+1 << "]";
			col(15);
			cout << v[i]->getFecha()<< " - (" << v[i]->getNomProduccion() <<") "<< endl;
		}
		col(10);
		cout << "\t[0]";
		col(15);
		cout << " Cancelar\n";
		int opcEligeF;
		bool cic = true;
		while (cic) {
			cout << "\t> ";
			if (!(cin >> opcEligeF)) {
				col(12);
				cerr << "\tError! Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
				cic = true;
			}
			else {
				if (opcEligeF >= 0 && opcEligeF <= cant) {
					cic = false;
				}
				else {
					col(12);
					cerr << "\tError! Digite un numero de la lista!\n";
					col(15);
					cin.clear();
					cin.ignore(1024, '\n');
					cic = true;
				}
			}
		}
		if (opcEligeF != 0) {
			int eligeVuelo = opcEligeF - 1;
			if (eligeVuelo == cant - 1) {
				cant--;
				col(10);
				cout << "Se ha eliminado una fecha Correctamente!\n";
				col(15);
			}
			else {
				v[eligeVuelo] = v[cant - 1];
				cant--;
				col(10);
				cout << "Se ha eliminado una fecha Correctamente!\n";
				col(15);
			}
		}
	}
	else {
		col(12);
		cout << "No hay fechas para eliminar!\n";
		col(15);
	}
}

//Muestra el Menu principal de la clase Gestion de Fechas
//En el cual se podrá eliminar, modificar e ingresar fechas
void GestionFechas::imprimeMenu(){
	system("cls");
	col(15);
	cout << endl << endl << endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	col(224);
	cout << "     GESTION DE FECHAS        ";
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
	col(6);
	cout << "  [1]";
	col(15);
	cout << "   Ingresar        \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(6);
	cout << "  [2]";
	col(15);
	cout << "   Visualizar      \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(6);
	cout << "  [3]";
	col(15);
	cout << "   Modificar       \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(6);
	cout << "  [4]";
	col(15);
	cout << "   Eliminar        \n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(6);
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
}

//Validación, por si el usuario digita un dato erróneo
void GestionFechas::interfaz(){
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
}


int GestionFechas::getOpc(){
	return opc;
}

int GestionFechas::getCant(){return cant;}


//Retorna la fecha que se encuentre en la posición recibida del vector
Fechas* GestionFechas::devuelveFecha(int i) {return v[i];}

//Muestra los datos de la fecha y los datos con el concierto al que fue asociada, también imprime todos los asientos del concierto en la fecha asignada
void GestionFechas::toString() {
	for (int i = 0; i < cant; i++) {
		cout << "---------------------------------------------------------------------------------------------" << endl;
		col(11);
		cout << "Fecha: " << i + 1 << endl << endl;
		col(15);
		cout << v[i]->toString() << endl;
		cout << "Concierto asignado: " << endl<<endl;
		cout << v[i]->devuelveConcierto().toString() << endl;
		v[i]->devuelveConcierto().imprimeAsientos();
		cout << endl;
	}
}

//Muestra los datos de la fecha y los datos con el concierto al que fue asociada, si que se impriman todos los asientos
void GestionFechas::toStringBol() {
	for (int i = 0; i < cant; i++) {
		cout << "---------------------------------------------------------------------------------------------" << endl;
		col(11);
		cout << "Fecha: " << i + 1 << endl << endl;
		col(15);
		cout << v[i]->toString() << endl;
		cout << "Concierto asignado: " << endl << endl;
		cout << v[i]->devuelveConcierto().toString() << endl;
		cout << endl;
	}
}


//Destructor
//Es muy importante siempre incluir este destructor cuando se trabaja con un vector dinámico de objetos al igual dinámicos
GestionFechas::~GestionFechas() {
	for (int i = 0; i < cant; i++) {
		delete v[i];
	}
	delete[] v;
	cant = 0;
	tam = 0;
	col(10);
	cout << "Se han destruido las fechas!" << endl;
	col(15);
}
