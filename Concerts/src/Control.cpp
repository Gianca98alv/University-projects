#include "Control.h"

Control::Control(){}

void Control::col(int c){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);}//Recibe un número al cual le corresponde un color y lo muestra en el texto.

//SLEEP Sleep(int) : si no dice “presione cualquier tecla para continuar…” no hay que tocar nada, por que después se corre el buffer por teclado. 
//sleep - Sleep for the specified number of seconds


//Esta funcion mueve el cursor de la ventana de texto a la posición según las coordenadas especificadas por los argumentos x,y. 
void Control::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//Método que da inicio a todas las gestiones
void Control::opciones() {

	//Creación de diferentes tipos de instancias 

	Interfaz *i = new Interfaz;
	GestionConcierto *gesConcier = new GestionConcierto;
	GestionRecinto *r = new GestionRecinto;
	GestionFechas *f = new GestionFechas;
	Concierto *a1 = new Concierto("Mariah Carey", "All I Want For Christmas Is You", 500, 10, 50);
	Concierto *a2 = new Concierto("Kelly Clarkson", "Silent Night                   ", 1000, 20, 50);
	Concierto *a3 = new Concierto("Michael Buble", "Santa Claus Is Coming To Town", 2000, 40, 50);

	gesConcier->ingresarConcierto(a1);
	gesConcier->ingresarConcierto(a2);
	gesConcier->ingresarConcierto(a3);
	Recinto *r1 = new Recinto("Estadio Ricardo Saprissa", "Elton John", 1);
	Recinto *r2 = new Recinto("Centro De Eventos Pedregal", "Gwen Stefani", 2);
	Recinto *r3 = new Recinto("Pepper's Club", "Jose Feliciano", 3);
	r->ingresarRecinto(r1);
	r->ingresarRecinto(r2);
	r->ingresarRecinto(r3);
	Fechas *v1 = new Fechas("TELETICA","27,DICIEMBRE,2018",5,6, *a1);
	Fechas *v2 = new Fechas("PEDREGAL-PRODUCCIONES", "25,DICIEMBRE,2018", 8, 11,  *a2);
	Fechas *v3 = new Fechas("REPRETEL", "8,ENERO,2019", 12, 3,  *a3);
	f->insertarFecha(v1);
	f->insertarFecha(v2);
	f->insertarFecha(v3);
	//ciclos
	bool cicloPrincipal=true;
	//----!ciclos
	srand(time(NULL));


	//El programa irá diciendo qué hacer y qué digitar, solo se podrá ingresar números o letras por teclado depende de lo que se solicite. 
	//Al empezar el programa se presenta una pantalla de inicio, se debe pulsar ENTER o cualquier otra tecla para comenzar el programa.

	bienvenido();
	while (cicloPrincipal) {
		i->imprime();
		int opc = i->menu();

		//Al ingresar al menú se presentaran 5 opciones en las que se deberá digitar una opción (1,2,3,4,0), tal y como se muestra en pantalla. 
		//Solo se puede ingresar uno de los 5 números que se le piden.

		if (opc == 1) { // Gestion de Concierto
			if (gesConcier->revisarAdmin() == true) {
				bool cicloOpcion1 = true;
				while (cicloOpcion1) {
					system("cls");

					//En la gestión de conciertos solo tienen acceso los administradores de la aplicación de la empresa por lo cual debe de ingresar la clave “admin” todo en minúscula y sin espacios. 
					//Al ingresar la clave se le desplegará un menú donde podrá, ingresar, visualizar, modificar y eliminar conciertos. Se deberá digitar una de las 5 opciones del menú (1,2,3.4,0). 

					switch (gesConcier->menu()) {
					case 0:
						system("cls");
						col(13);
						cout << "\n\n\n\t\t\t";
						cout << "SALIENDO DE [GESTION DE CONCIERTOS]\n";
						cout << "\n\t\t";
						for (int i = 0; i < 60; i++) {
							col(255);
							cout << " ";
							Sleep(15);
							col(271);
						}
						col(15);
						cicloOpcion1 = false;
						break;
					case 1:
						//Al ingresar un Concierto deberá de digitar: 
						//• Tamaño (el tamaño está definido por A,B o C) • cantante * Nombre de la Funcion; 

						gesConcier->ingresarConcierto(); break;

					case 2:
						//Le dirá cuántos Conciertos tiene la empresa 

						gesConcier->visualizarConciertos(); break;

					case 3:
						//Le permitirá al administrador modificar conciertos, seleccionando uno  y  lo que desea modificar de este. 


						gesConcier->modificar(); break;

					case 4:
						//Le permitirá eliminar conciertos, seleccionando uno.

						gesConcier->eliminar(); break;

					default:
						break;
					}

				}
			}
		}
		else if (opc == 2) {
			system("cls");
			col(13);
			if (r->revisarAdmi() == true) {
			system("cls");
			col(15);
			bool cicloOpcion = true;
			while (cicloOpcion) {
				
				 //A la gestión de recintos tendrán acceso los administradores. Al entrar se le desplegará un menú en donde podrá ingresar, visualizar, modificar, y eliminar recintos.
				//Se deberá seleccionar una de las 5 opciones(1, 2, 3, 4, 0).

				switch (r->menu()) {
				case 0:
					system("cls");
					col(13);
					cout << "\n\n\n\t\t\t";
					cout << "SALIENDO DE [GESTION DE RECINTOS]\n";
					cout << "\n\t\t";
					for (int i = 0; i < 60; i++) { col(255);	cout << " "; Sleep(15); }
					col(15);
					cicloOpcion = false;
					break;
				case 1:
					//Deberá ingresar: 
					//• Lugar • Telonero • Duración del show 

					r->ingresarRecinto(); break;

				case 2:
					//Le permitirá ver cuantos recintos tiene la empresa. 

					r->visualizar(); break;

				case 3:
					//Le permitirá modificar los recintos seleccionando uno y lo que desea modificar del recinto.

					r->modificar(); break;

				case 4:
					//Le permitirá eliminar los recintos seleccionandos.

					r->eliminar(); break;

				default:
					break;
				}
			}
		}
		}
		else if (opc == 3) {
			system("cls");
			col(15);
			if (f->revisarAdm() == true) {
				system("cls");
				col(15);
				bool cicloOpcion = true; //ciclo del menu
				while (cicloOpcion == true) {
					system("cls");

					//A la gestión de fechas tienen acceso los administradores. 
					//Al entrar se desplegará un menú en donde podrá ingresar, visualizar, modificar, y eliminar fechas, digitando una de las 5 opciones(1, 2, 3, 4, 0)

					f->imprimeMenu();
					f->interfaz();
					if (f->getOpc() == 1) {
						system("cls");
						col(10);

						//Al ingresar fechas deberá seleccionar un recinto y un concierto para asignarle el recinto
						//Seguido por una fecha, y una hora de inicio

						cout << "\t\t(Ingresar Fechas)\n\n";
						col(15);
						if (r->getCant() != 0 && gesConcier->getCant() != 0) {
							int opcRuta;
							string nomPr = "";
							string fech = "";
							int horaI = 0;
							int horaF = 0, suma = 0;
							bool cicloSelecF = true;
							bool cicloSelecHora = true;
							bool cicloSelecConcierto = true;
							cout << "Los recintos disponibles son:\n\n";
							r->mostrarRecintos(); // visualizar recintos
							cout << "Seleccione un recinto ";
							while (cicloSelecF) {
								cout << "> ";
								if (!(cin >> opcRuta)) {
									col(12);
									cerr << "Digite un numero!\n";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
								}
								else {
									if (opcRuta > 0 && opcRuta <= r->getCant()) {
										cicloSelecF = false;
									}
									else {
										col(12);
										cerr << "Digite un numero de la lista!\n";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
									}
								}
							}
							int numRecinto = opcRuta - 1; // se le resta uno por la posicion del vector
							Fechas *fec = new Fechas;
							system("cls");
							cout << "\nLos Conciertos disponibles para asignarle una fecha son: \n" << endl;
							int cont = 0;
							gesConcier->toString();
							cout << "\nSeleccione un Concierto";
							int opcConcierto; //el numero del Concierto
							while (cicloSelecConcierto) {
								cout << "> ";
								if (!(cin >> opcConcierto)) {
									col(12);
									cerr << "Digite un numero!\n";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
								}
								else {
									if (opcConcierto >= 0 && opcConcierto <= r->getCant()) {
										cicloSelecConcierto = false;
									}
									else {
										col(12);
										cerr << "Digite un numero de la lista!\n";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
									}
								}
							}
							Concierto *av;
							av = new Concierto(gesConcier->devuelve(opcConcierto - 1)); //hace una copia del Concierto
							fec->insertaConcierto(av);
							fech = fec->muestraFecha();
							cout << endl;
							cout << "\tSeleccione la hora de inicio (Solo la hora en ";
							col(14);
							cout << " AMARILLO";
							col(15);
							cout << ")\n" << endl;
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
							while (cicloSelecHora) {
								cout << "\t> ";
								col(14);
								if (!(cin >> horaI)) {
									col(12);
									cerr << "Digite un numero!\n";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
								}
								else {
									if (horaI >= 1 && horaI <= 24) {
										cicloSelecHora = false;
									}
									else {
										col(12);
										cerr << "Digite un numero de la lista!\n";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
									}
								}
								col(15);
							}
							suma = r->devuele(numRecinto)->getDuracion();
							if (suma > 24) { horaF = suma - 24; } //verificacion de la hora de llegada si se pasa de 24
							else { horaF = horaI + suma; }
							system("cls");
							cout << "\nNombre de la Produccion: " << nomPr << endl;
							cin.ignore();
							getline(cin, nomPr);
							system("cls");
							int can = f->getCant();
							fec->setNomProduccion(nomPr);
							fec->setFecha(fech);
							fec->setHoraInicio(horaI);
							fec->setHoraFin(horaF);
							f->insertarFecha(fec);
							col(10);
							cout << "Una fecha ha sido creada!\n";
							col(15);
							cont++;
							col(11);
							cout << " Concierto:\n";
							col(15);
							cout << f->devuelveFecha(can)->devuelveConcierto().toString() << endl;
							col(11);
							cout << " Recinto:\n";
							col(15);
							cout << r->devuele(numRecinto)->toString() << endl;
							col(11);
							cout << " Fecha:\n";
							col(15);
							cout << f->devuelveFecha(can)->toString() << endl;

						}
						else {
							if (r->getCant() == 0) {
								col(12);
								cerr << "No hay Recintos ingresados!";
								col(15);
								cout << "\nIngrese un Recinto primero en [Modulo Gestion de Recintos]\n\n";
								col(15);
							}
							else if (gesConcier->getCant() == 0) {
								col(12);
								cerr << "No hay Conciertos registrados!";
								col(15);
								cout << "\nRegistre un Concierto primero en [Modulo Gestion de Concierto]\n\n";
								col(15);
							}
						}
						system("PAUSE");
						cicloOpcion = true;
					}
					else if (f->getOpc() == 2) {
						system("cls");
						col(10);

						//Le permitirá visualizar las fechas disponibles

						cout << "\t\t(Visualizar Fechas)\n\n";
						col(15);
						f->visualizar();
						system("PAUSE");
						cicloOpcion = true;
					}
					else if (f->getOpc() == 3) {
						system("cls");
						col(10);

						//Le permitirá modificar las fechas disponibles, seleccionando una, y lo que quiera modificarle. 

						cout << "\t\t(Modificar Fechas)\n\n";
						col(15);
						if (r->getCant() != 0) {
							f->modificar();
						}
						else {
							col(12);
							cerr << "No hay recintos ingresados!\nIngrese un recinto primero en [Modulo Gestion de Recintos]\n";
							col(15);
						}
						system("PAUSE");
						cicloOpcion = true;
					}
					else if (f->getOpc() == 4) {
						system("cls");
						col(10);

						//Le permitirá Eliminar fecha, seleccionando unade estas. 

						cout << "\t\t(Eliminar Fechas)\n\n";
						col(15);
						if (r->getCant() != 0) {
							f->eliminar();
						}
						else {
							col(12);
							cerr << "No hay recintos ingresadas!\nIngrese un recinto primero en [Modulo Gestion de Recintos]\n";
							col(15);
						}
						system("PAUSE");
						cicloOpcion = true;
					}
					else if (f->getOpc() == 0) {
						system("cls");
						col(13);
						cout << "\n\n\n\t\t\t";
						cout << "SALIENDO DE [GESTION DE FECHAS]!\n";
						cout << "\n\t\t";
						for (int i = 0; i < 60; i++) {
							col(255);
							cout << " ";
							Sleep(15);
						}
						col(15);
						cicloOpcion = false;
					}
				}
			}
		}
		else if (opc == 4) {
			system("cls");
			col(13);

			//Primero deberá seleccionar una fecha.
			//Luego deberá digitar la cantidad de boletos que desea, sus datos, nombre e identificación personal.
			//Después deberá seleccionar su asiento, digitando el número de la fila, y el número de la columna.
			//Se le mostrará un boleto con su asiento, los datos del concierto, precio, etc.

			cout << "\n\n\n\t\t\t";
			cout << "Bienvenido a la Compra de tiquetes!\n";
		
			for (int i = 0; i < 2; i++) {Sleep(500);}
			if (f->getCant() != 0) { //si no hay fechas registrados no puede comprar asientos
				bool espacio = true;
				while (espacio == true) {
					system("cls");
					col(10);
					cout << "\t\t(Compra de Tiquetes)\n\n";
					col(15);
					f->toStringBol();
					cout << "Seleccione el concierto deseado";
					int opcFfech;
					bool cicloSelecF = true;
					while (cicloSelecF == true) {
						cout << "> ";
						if (!(cin >> opcFfech)) {
							col(12);
							cerr << "Digite un numero!\n";
							col(15);
							cin.clear();
							cin.ignore(1024, '\n');
						}
						else {
							if (opcFfech > 0 && opcFfech <= f->getCant()) {
								cicloSelecF = false;
							}
							else {
								col(12);
								cerr << "Digite un numero de la lista!\n";
								col(15);
								cin.clear();
								cin.ignore(1024, '\n');
							}
						}
					}
					int fec = opcFfech - 1;
					if (f->devuelveFecha(fec)->devuelveConcierto().getCan() < f->devuelveFecha(fec)->devuelveConcierto().getCantAsientos()) {
						int b = 0, a = 300, min = 50;
						srand(time(NULL));
							b = min + rand() % a;
						int precio = b;//metodo para un precio random
						int tamConcierto = f->devuelveFecha(fec)->devuelveConcierto().getCantAsientos(); //tamaño del Concierto seleccionado
						int colum = f->devuelveFecha(fec)->devuelveConcierto().getColumnas(); //tamaño de las columnas del Concierto seleccionado
						int filaa = f->devuelveFecha(fec)->devuelveConcierto().getFilas(); //tamaño de las filas del Concierto seleccionado
						system("cls");
						//variables locales para el nombre, id y datos de la tarjeta del usuario
						string nombre;
						string id;
						string tc, cv,fvv;
						int cantBoletos = 0;
						col(10);
						cout << "\t[Digitar los datos de la persona]\n";
						col(11);
						cout << "\n\tAsiento" << endl;
						cout << "\t--------------------------\n";
						col(15);
						cout << "\tCuantos boletos desea comprar? >";
						bool cicloB = true;
						while (cicloB) {
							cout << "\t> ";
							col(14);
							if (!(cin >> cantBoletos)) {
								col(12);
								cerr << "Digite un numero!\n";
								col(15);
								cin.clear();
								cin.ignore(1024, '\n');
							}
							else {
								if (cantBoletos >= 1 && cantBoletos <= 5) {
									cicloB = false;
								}
								else {
									col(12);
									cerr << "\t Puede comprar MAXIMO 5 boletos por persona! Intente otra vez\n";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
								}
							}
							col(15);
						}
						cout << "\tDigite su nombre > ";
						cin.ignore();
						getline(cin, nombre);
						cout << "\tDigite su identificacion >";
						getline(cin, id);

						cout << "\n\tIngrese los digitos de su tarjeta de credito o debito >";
						col(96);
						getline(cin, tc);
						col(15);
						cout << "\n\tDigite la fecha de vencimiento de de la tarjeta >";
						col(96);
						getline(cin, fvv);
						col(15);
						cout << "\n\tDigite el CVV de la tarjeta>";
						col(96);
						getline(cin, cv);
						col(159);
						cout << "\n\t DATOS CORRECTOS! \n\n\t";
						col(15);
						system("pause");
						for(int i= 0;i<cantBoletos;i++){
						bool verifica = true; //ciclo para la verificacion del asiento, si tiene campo
						while (verifica == true) {
							system("cls");
							col(10);
							cout << "\t[Digitar el asiento]\n" << endl;
							col(15);
							cout << "DISPONIBLES ";
							col(10);
							cout << char(177) << char(177);
							col(15);
							cout << "    OCUPADOS ";
							col(12);
							cout << char(177) << char(177);
							col(15);
							cout << "    VIP ";
							col(13);
							cout << char(177) << char(177) << endl << endl;
							f->devuelveFecha(fec)->devuelveConcierto().imprimeAsientos();
							int fila;
							int columna;
							cout << "\n\nDigite la fila del asiento(Numero /";
							col(11);
							cout << " 1 2 3 4...";
							col(15);
							cout << ") ";
							col(15);
							bool cicloSelecFila = true;
							while (cicloSelecFila == true) {
								cout << "> ";
								if (!(cin >> fila)) {
									col(12);
									cerr << "Digite un numero!\n";
									col(15);
									cin.clear();

									cin.ignore(1024, '\n');
								}
								else {
									if (fila > 0 && fila <= filaa) {
										cicloSelecFila = false;
									}
									else {
										col(12);
										cerr << "Digite un numero de las filas!\n";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
									}
								}
							}
							cout << "\n\nDigite la columna del asiento(Numero /";
							col(11);
							cout << " 1 2 3 4...";
							col(15);
							cout << ") ";
							col(15);
							cout << " ";
							col(15);
							bool cicloSelecNum = true;
							while (cicloSelecNum == true) {
								cout << "> ";
								if (!(cin >> columna)) {
									col(12);
									cerr << "Digite un numero!\n";
									col(15);
									cin.clear();
									cin.ignore(1024, '\n');
								}
								else {
									if (columna > 0 && columna <= colum) {
										cicloSelecNum = false;
									}
									else {
										col(12);
										cerr << "Digite un numero de las columnas!\n";
										col(15);
										cin.clear();
										cin.ignore(1024, '\n');
									}
								}
							}
							if (fila < 6) {
								int b = 0, a = 3000, min = 1000;
								srand(time(NULL));
								b = min + rand() % a;
								precio = b;
							}
							else {
								int b = 0, a = 500, min = 100;
								srand(time(NULL));
								b = min + rand() % a;
								precio = b;
							}
							col(15);
							cout << " ";
							stringstream f1;
							f1 << fila;
							string f2 = f1.str();
							stringstream s1;
							s1 << f2 << columna;
							string as = s1.str();
							Persona *persona = new Persona(nombre, id, as);
							if (f->devuelveFecha(fec)->devuelveConcierto().verifica(fila, columna) == true) {
								f->devuelveFecha(fec)->devuelveConcierto().insertarPersona(persona, fila, columna);
								cout << "\n\n\tAsiento: ";
								col(14);
								cout << f2.c_str();
								col(15);
								cout << " - ";
								col(11);
								cout << columna << endl;
								col(15);
								system("pause");
								//---------IMPRIME EL BOLETO--------
								system("cls");
								cout << endl;
								cout << char(201);
								for (int i = 0; i < 60; i++) { cout << char(205); }
								cout << char(187) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t\t   BOLETO:\t\t\t     ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << "-"; }
								cout << char(186) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t     Datos de la persona:\t\t     ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << " "; }
								cout << char(186) << endl;
								cout << char(186);
								cout << "  Nombre         : " << persona->getName() << endl;
								cout << char(186);
								cout << "  Identificacion : " << persona->getId() << endl;
								cout << char(186);
								cout << "  Asiento        : " << persona->getAsiento() << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << "-"; }
								cout << char(186) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t     Datos del Concierto:\t\t     ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << " "; }
								cout << char(186) << endl;
								cout << char(186);
								cout << "  Produccion          : " << f->devuelveFecha(fec)->getNomProduccion() << endl;
								cout << char(186);
								cout << "  Fecha               : " << f->devuelveFecha(fec)->getFecha() << endl;
								cout << char(186);
								cout << "  Hora Inicio         : " << f->devuelveFecha(fec)->getHoraInicio() << ":00" << endl;
								cout << char(186);
								cout << "  Hora Fin            : " << f->devuelveFecha(fec)->getHoraFin() << ":00" << endl;
								cout << char(186);
								cout << "  Fecha de Compra     : " << "25,DICIEMBRE,2018" << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << "-"; }
								cout << char(186) << endl;
								cout << char(186);
								col(11);
								cout << "\t\t            Concierto:\t\t             ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << " "; }
								cout << char(186) << endl;
								cout << char(186);
								cout << "  Nombre de la funcion:  " << f->devuelveFecha(fec)->devuelveConcierto().getNomFuncion();
								cout << "    " << char(186) << endl << char(186);
								cout << "  Cantante               : " << f->devuelveFecha(fec)->devuelveConcierto().getCantante() << "\t\t     " << char(186) << endl;
								cout << char(186);
								for (int i = 0; i < 60; i++) { cout << "-"; }
								//cout << char(186);
								cout << char(186) << endl;
								cout << char(186);

								col(11);
								cout << "\t\t            Precio:\t\t             ";
								col(15);
								cout << char(186) << endl;
								cout << char(186);
								double precioImp = precio + (precio * 0.13);
								if (fila < 6) {
									cout << "  Precio del tiquete (VIP):   $" << precio << "                         " << char(186) << endl;
									cout << char(186);
									cout << "   Precio con impuesto:       $" << precioImp << "                      " << char(186) << endl;
								}
								else {
									cout << "  Precio del tiquete (GENERAL): $" << precio << "                        " << char(186) << endl;
									cout << char(186);
									cout << "   Precio con impuesto:   $" << precioImp << "                           " << char(186) << endl;
								}
								cout << char(186);
								cout << "   Costo de la impresion         : $" << "10                      "; cout << char(186) << endl;
								col(15);
								cout << char(200);
								for (int i = 0; i < 60; i++) { cout << char(205); }
								cout << char(188) << endl << endl;
								//laterales derecha
								gotoxy(61, 2); cout << char(186);
								gotoxy(61, 4); cout << char(186);
								gotoxy(61, 5); cout << char(186);
								gotoxy(61, 6); cout << char(186);
								gotoxy(61, 7); cout << char(186);
								gotoxy(61, 8); cout << char(186);
								gotoxy(61, 11); cout << char(186);
								gotoxy(61, 12); cout << char(186);
								gotoxy(61, 13); cout << char(186);
								gotoxy(61, 14); cout << char(186);
								gotoxy(61, 15); cout << char(186);
								gotoxy(61, 16); cout << char(186);
								gotoxy(61, 17); cout << char(186);
								gotoxy(61, 18); cout << char(186);



								//---------!IMPRIME EL TIQUETE--------
								gotoxy(61, 32);
								cout << endl;
								cout << endl << endl;

								gotoxy(65, 2);
								cin.ignore();
								cin.get();
								verifica = false;
							}
							else {
								col(12);
								cout << "El campo esta lleno, seleccione otro asiento!";
								Sleep(1000);
								col(15);
								verifica = true;
							}
						}
						}
						espacio = false;
					}
					else {
						col(12);
						cout << "No hay asientos disponibles en la fecha seleccionado!\n";
						cout << "Digite otra fecha !\n";
						col(15);
						system("PAUSE");
					}
				}
			}
			else {
				col(12);
				cout << "No hay Fechas registrados todavia!\n";
				col(15);
				system("PAUSE");
			}
		}
		else {
			delete gesConcier;
			delete r;
			delete f;
			cicloPrincipal = false; 
		}
	}
	hastaLuego();
}

//Solamente son couts para mostrar una página de inicio amigable y colorida
void Control::bienvenido(){

	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << " https ://www.MillanAlvaradoTickets.com/conciertos "; std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "               ";
	col(224);
	std::cout << "                              BIENVENIDO A                                      ";
	col(271);
	std::cout << "                                        ";
	std::cout << std::endl;
	std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << "         v"; std::cout << std::endl;
	std::cout << "        >X<"; std::cout << std::endl;
	std::cout << "         A"; std::cout << std::endl;
	std::cout << "        dSb"; std::cout << std::endl;
	std::cout << "      .d888";
	std::cout << "b."; std::cout << std::endl;
	std::cout << "    .d8888888d."; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 256);
	std::cout << "\t\t\t       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176); 
	cout<<"	   \t       MA's Tickets"; cout << char(169); cout << "                  ";	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 256);
	cout << ".";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << std::endl;
	std::cout << "       88888                    ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 256);
	std::cout << "  .  \n";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << "      8888888"; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 271);
	cout << "	   \t\t\t             Edici"<<char(162);cout<<"n Navide" <<char(164) ; cout << "a                  ";
	std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << "    .d888888888"; std::cout << std::endl;
	std::cout << "  .d88888888888b.		   "; std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << "      8888888		             ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << "	       888888888888888888888888888 "; std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << "      8888888		             ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << "  	     8888888888888888888888888888888 "; std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << "     d88888888		             ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << "      8888888888888888888888888888888888 "; std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << "  .d88888888888b.		        ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << "   ||&%&%&_.'               '._&%&%&|| "; std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	std::cout << " .d88888888888888b.		           ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << "||&%&%&_.'       "; cout << char(244) <<"       '._&%&%&|| "; std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "        ###		             ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << "      ||&%&%&_.'            "; cout << char(244) << "  '._&%&%&|| "; std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "        ###		             ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << "	   ||&%'''                     '''%&||"; std::cout << std::endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "        ### mh		             ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
	std::cout << "      ||&%'''                   "; cout<<char(244)<<" '''%&||"; std::cout << std::endl;
	std::cout << "			                   ||&%&                  ~O     &%&|| "; std::cout << std::endl;
	std::cout << " 		                       	   ||&%&     o   )______  <|/    &%&|| "; std::cout << std::endl;
	std::cout << "		             	           ||&%&    /_= -/______|  |     &%&|| "; std::cout << std::endl;
	std::cout << "		             	           ||&%&&   (/| .|     |   /)   &&%&|| "; std::cout << std::endl;
	std::cout << "		             	       ____||&%&&=======================&&%&||____ "; std::cout << std::endl;
	col(15);
	system("pause");
}

//Solamente aparece cuando se cierra el programa, de forma de despedida al usuario 
void Control::hastaLuego(){
	system("cls");
	for (int i = 0; i < 6; i++) { cout << "\n"; }
	col(15);
	cout << "\n\n\t\t\t\t\t\tCerrando...\n" << endl;
	cout << "\t\t\t";
	for (int i = 0; i<60; i++) {
		col(255);
		cout << " ";
		Sleep(15);
	}
	cin.clear();
	cin.ignore();
}
Control::~Control(){}
