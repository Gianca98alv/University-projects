#include "Fechas.h"

//Constructor sin parámetros.
Fechas::Fechas() {
	nomProduccion = "";
	fecha = "";
	horaInicio = 0;
	horaFin = 0;
}

Fechas::Fechas(string n, string f , int in, int fi, Concierto cc) : nomProduccion(n), fecha(f), horaInicio(in) ,horaFin(fi), Concier(cc){} //Constructor con parámetros.

void Fechas::col(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }//Recibe un número al cual le corresponde un color y lo muestra en el texto.

//Muestra solamente el nombre de los meses, para que el usuario seleccione uno. 
//Este será introducido en el siguiente método (switch).
//Además se encuentra su respectiva validación, por si el usuario digita un valor erróneo.
string Fechas::muestraFecha(){
	int mes;
	int cantidadDias = 0;
	int dia;
	string mesL;
	bool cicloMes = true;
	bool cicloDia = true;
	system("cls");
	col(10);
	cout << "\t(Fecha del Concierto)\n";
	col(15);
	int annio;
	cout << endl << "\tDigite el a"<<char(164)<<"o: > ";
	cin >> annio;
	cout << "\n\tSeleccione el numero del mes:\n";
	col(11);
	cout << "\t[1] ";
	col(15);
	cout << "Enero\t\t\t";
	col(11);
	cout << "[7]  ";
	col(15);
	cout << "Julio\n";
	col(11);
	cout << "\t[2] ";
	col(15);
	cout << "Febrero\t\t\t";
	col(11);
	cout << "[8]  ";
	col(15);
	cout << "Agosto\n";
	col(11);
	cout << "\t[3] ";
	col(15);
	cout << "Marzo\t\t\t";
	col(11);
	cout << "[9]  ";
	col(15);
	cout << "Septiembre\n";
	col(11);
	cout << "\t[4] ";
	col(15);
	cout << "Abril\t\t\t";
	col(11);
	cout << "[10] ";
	col(15);
	cout << "Octubre\n";
	col(11);
	cout << "\t[5] ";
	col(15);
	cout << "Mayo\t\t\t";
	col(11);
	cout << "[11] ";
	col(15);
	cout << "Noviembre\n";
	col(11);
	cout << "\t[6] ";
	col(15);
	cout << "Junio\t\t\t";
	col(11);
	cout << "[12] ";
	col(15);
	cout << "Diciembre\n\n";
	col(15);
	while (cicloMes) {
		cout << "\t> ";
		col(11);
		if (!(cin >> mes)) {
			col(12);
			cerr << "Digite un numero!\n";
			col(15);
			cin.clear();
			cin.ignore(1024,'\n');
		}
		else {
			if (1 <= mes && mes <= 12) {
				cicloMes = false;
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
	cout << endl;


	//Se crea un switch para mostrar los días de cada mes del año, en el switch se introduce la opción seleccionada anteriormente (o sea el mes).
	//En este se muestra el nombre del mes junto con sus respectivos días reales, para que la interfaz sea más realista y amigable para el usuario.
	//Incluso a la hora de mostrar los días del mes, estos aparecen como un calendario real.
	//Además en cada Case se encuentra la respectiva validación por si el usuario digita un valor erróneo.
	switch (mes) {
	case 1:
		mesL = "ENERO";
		cantidadDias = 31;
		cout << "\t\t\t"<<mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i==21 || i==28) {
				cout << endl<<"\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 2:
		mesL = "FEBRERO";
		cantidadDias = 28;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21) {
				cout << endl<<"\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 3:
		mesL = "MARZO";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl<<"\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 4:
		mesL = "ABRIL";
		cantidadDias = 30;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl<<"\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 5:
		mesL = "MAYO";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 6:
		mesL = "JUNIO";
		cantidadDias = 30;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 7:
		mesL = "JULIO";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 8:
		mesL = "AGOSTO";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 9:
		mesL = "SEPTIEMBRE";
		cantidadDias = 30;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 10:
		mesL = "OCTUBRE";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 11:
		mesL = "NOVIEMBRE";
		cantidadDias = 30;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	case 12:
		mesL = "DICIEMBRE";
		cantidadDias = 31;
		cout << "\t\t\t" << mesL << endl;
		cout << "\t\t\t---------------------\n";
		for (int i = 0; i < cantidadDias; i++) {
			if (i == 0 || i == 14 || i == 7 || i == 21 || i == 28) {
				cout << endl << "\t\t\t";
			}
			col(14);
			cout << i + 1 << " ";
		}
		col(15);
		cout << "\n\t\t\tDigite un dia:";
		while (cicloDia) {
			cout << "\n\t\t\t> ";
			col(14);
			if (!(cin >> dia)) {
				col(12);
				cerr << "Digite un numero!\n";
				col(15);
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				if (1 <= dia && dia <= cantidadDias) {
					cicloDia = false;
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
		break;
	default:
		break;
	}
	stringstream s;
	s << dia<<","<<mesL<<","<<annio;
	return s.str();
}

//Sets y Gets de los Atributos.
string Fechas::getNomProduccion() { return nomProduccion; }
string Fechas::getFecha() { return fecha; }
int Fechas::getHoraInicio() { return horaInicio; }
int Fechas::getHoraFin() { return horaFin; }
void Fechas::setNomProduccion(string n) { nomProduccion = n; }
void Fechas::setFecha(string f) { fecha = f; }
void Fechas::setHoraInicio(int hi) { horaInicio = hi; }
void Fechas::setHoraFin(int hf) { horaFin = hf; }

// Muestra el valor de los atributos.
string Fechas::toString() {
	stringstream s;
	s << "Nombre de la Produccion: ";
	s << nomProduccion << endl;
	s << "Fecha: ";
	s << fecha << endl;
	s << "Hora de Inicio: ";
	s << horaInicio;
	s <<":00"<<endl;
	s << "Hora de Fin: ";
	s << horaFin;
	s << ":00"<<endl;
	return s.str();
}

//Inserta un Concierto, esto para relacionar al concierto con los datos más específicos (fecha, horas...)
void Fechas::insertaConcierto(Concierto a) {Concier = a;}

//Retorna un concierto.
Concierto Fechas::devuelveConcierto() { return Concier; }

//Destructor 
Fechas::~Fechas(){
	nomProduccion = "";
	fecha = "";
	horaInicio = 0;
	horaFin = 0;
}
