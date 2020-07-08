#include "Concierto.h"

Concierto::Concierto(){}//Constructor por default

//Constructor con parámetros
Concierto::Concierto(string can, string fun,int t,int f,int c) : cantante(can), nomFuncion(fun), cantidad(0),filas(f),columnas(c),cantAsientos(t) {
	m = new Persona**[filas];
	for (int i = 0; i < filas; i++) {
		m[i] = new Persona*[columnas];
	}
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			m[i][j] = NULL;
		}
	}
}

//Constructor copia
//En caso de que se le asignen recintos con diferentes conciertos a diferentes fechas
Concierto::Concierto(const Concierto *a) : cantante(a->cantante), nomFuncion(a->nomFuncion), cantidad(a->cantidad), filas(a->filas), columnas(a->columnas), cantAsientos(a->cantAsientos) {
	m = new Persona**[filas];
	for (int i = 0; i < filas; i++) {
		m[i] = new Persona*[columnas];
	}
	for (int i = 0; i < a->filas; i++) {
		for (int j = 0; j < a->columnas; j++) {
			m[i][j] = NULL;
		}
	}

}

void Concierto::col(int c){	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);}//Recibe un número al cual le corresponde un color y lo muestra en el texto.

//Sets y Gets de los Atributos

void Concierto::setCantante(string c) { cantante = c; }

void Concierto::setNomFuncion(string m) { nomFuncion = m; }

void Concierto::setCantAsientos(int p) { cantAsientos = p; }

void Concierto::setFilasColumnas(int f, int c) { filas = f; columnas = c; }

int Concierto::getCantAsientos() { return cantAsientos; }

int Concierto::getFilas() { return filas; }

int Concierto::getColumnas() { return columnas; }

string Concierto::getCantante() { return cantante; }

string Concierto::getNomFuncion() { return nomFuncion; }

//Devuelve la cantidad de conciertos que hay, al verificar que su espacio en la matriz se encuentra ocupado (diferente de NULL)
int Concierto::getCan() {
	int cont = 0;
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			if (m[i][j] != NULL)
				cont++;
	return cont;
}

//Muestra el valor de sus atributos
string Concierto::toString() {
	int ca = suma();
	stringstream s;
	s << "Cantante: " << cantante << endl;
	s<< "Nombre de la Funcion: " << nomFuncion << endl;
	s << "Cantidad de Asientos: " << cantAsientos << endl;
	s << "Asientos ocupados: " << ca << endl;
	s << "Asientos disponibles: " << (cantAsientos - ca) << endl;
	s << "Cantidad de Filas: " << filas << " Columnas: " << columnas << endl;
	return s.str();
}

//Devuelve la cantidad de conciertos que hay, al verificar que su espacio en la matriz se encuentra ocupado (diferente de NULL)
int Concierto::suma() { 
	int ca=0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (m[i][j] != NULL) {
				ca++;
			}
		}
	}
	return ca;
}

//Imprime todos los asientos según el tamaño del recinto (A,B o C)
//Muestra los asientos de la siguiente manera:
//Disponible = verde, Ocupado = rojo, VIP = morado (el VIP son las primeras 5 filas en cada recinto)
void Concierto::imprimeAsientos() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = 0; i < columnas; i++) { i >= 9 ? cout << i + 1 << " " : cout << " " << i + 1 << " "; } //imprime los numeros de las columnas
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl<<endl;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if ((m[i][j]) != NULL) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //rojo 
				cout << char(177) << char(177); cout << " ";
			}
			else {
				if (i<=4) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //morado
					cout << char(177) << char(177);
					//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 271);
					cout << " ";
				}
				else {
					if (i > 4) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //verde
						cout << char(177) << char(177); cout << " ";
					}
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << i+1 << endl << endl; //imprime  los numeros de las filas
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << endl;
}

//Verifica que el asiento se encuentra desocupado, para así poderlo reservar 
bool Concierto::verifica(int f, int c) {

	if (m[f- 1][c - 1] == NULL) {
		return true;
	}
	return false;
}

//Inserta a una persona en la matriz (en el asiento) si hay espacio, si no desplegará un mensaje de que no hay espacio.
bool Concierto::insertarPersona(Persona *p,int f,int c){
	if (suma() < cantAsientos) {
		if (m[f - 1][c - 1] == NULL) {
			m[f - 1][c - 1] = p;
			col(10);
			cout << "Se ha insertado una persona correctamente!\n";
			col(15);
			return true;
		}
		else { return false; }
	}
	else {
		col(12);
		cout << "No hay espacio!\n";
		col(15);
		return false;
	}
	cantidad = suma();
}
void Concierto::eliminarPersonas() {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			
			m[i][j] = NULL;
		}
	}
}

//Recibe una fila y columna de la matriz y retorna a la persona que se encuentra en ese asiento
Persona* Concierto::devuelvePersona(int f,int c){return m[f][c];}
string Concierto::toStringPersonas() {
	stringstream s;
	for (int i = 0; i < filas;i++) {
		for (int j = 0; j < columnas; j++) {
			if (m[i][j] != NULL) {
				s << m[i][j]->toString()<<endl;
			}
		}
	}
	return s.str();
}

//Destructor
//Es muy importante siempre colocar el destructor cuando se crea una matriz dinámica de objetos dinámicos
//Sin embargo, en este caso se tuvo que comentar el destructor
//Debido a que si se dejaba se creaba un inconveniente a la hora de visualizar los Conciertos, el programa se caía y señalaba problema en el método suma();

Concierto::~Concierto(){
/*	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {

			m[i][j] = NULL;
		}
	}	for (int i = 0; i < filas; i++) {
		delete[]m[i];
	}delete[] m;
*/
	//Si no comento el destructor no se visualizan los conciertos y se cae. Me tira error en el metodo suma(); 
	cantante = " ";
	nomFuncion = " ";
	cantAsientos = 0;
	cantidad = 0;
	filas = 0;
	columnas = 0;
}
