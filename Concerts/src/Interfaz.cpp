#include "Interfaz.h"

Interfaz::Interfaz(){}

void Interfaz::col(int c){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); }//Recibe un número al cual le corresponde un color y lo muestra en el texto.


//Esta funcion mueve el cursor de la ventana de texto a la posición según las coordenadas especificadas por los argumentos x,y. 
void Interfaz::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int Interfaz::menu() { //Cuantas opciones hay en el menu
	int opc;
	opc = validar();
	return opc;
}

//Despliega el MENU PRINCIPAL y sus opciones
void Interfaz::imprime(){
	system("cls");
	col(15);
	cout << endl << endl<<endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout<< char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	col(48);
	cout << "        MENU PRINCIPAL        ";
	col(15);
	cout << char(186) << endl;
	col(15);
	cout << "\t\t\t\t"<<char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout<<char(188)<<endl;
	
	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186)<<endl;

	cout << "\t\t\t";
	cout << char(186);
	col(11);
	cout << "  [1]   ";
	col(15);
	cout << "GESTION DEL CONCIERTO \n";
	col(15);
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(11);
	cout << "  [2]   ";
	col(15);
	cout << "GESTION DE RECINTOS\n";
	col(15);
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(11);
	cout << "  [3]   ";
	col(15);
	cout<<"GESTION DE FECHAS\n";
	col(15);
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(11);
	cout << "  [4]   ";
	col(15);
	cout << "COMPRAR BOLETOS\n";
	col(15);
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	col(11);
	cout << "  [0]   ";
	col(207);
	cout << "SALIR \n";
	col(15);
	cout << "\t\t\t";
	cout << char(186);

	cout << "\n\t\t\t" << char(204);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(185)<<endl;
	cout << "\t\t\t" << char(186)<<endl;
	cout << "\t\t\t" << char(186)<<endl;
	cout << "\t\t\t"<<char(186);
	cout << "\n\t\t\t" << char(200);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(188) << endl;
	for (int i = 0; i < 11; i++) {
		gotoxy(71,7+i); cout << char(186);
	}
	gotoxy(71, 19); cout << char(186);
	gotoxy(71, 20); cout << char(186);
	gotoxy(71, 21); cout << char(186);
}

//Validación, por si el usuario digita un valor erróneo.
int Interfaz::validar() {
	int opc;
	bool c = true;
	while (c) {
		gotoxy(35, 20); cout << "Opcion > ";
		col(10);
		if (!(cin>>opc)) { //revisa si falla
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
		else if ( opc <0 || opc >4) { //PONER HASTA 5 PARA HACER METODO DE REVISAR
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
		else {c = false;}
		col(15);
	}
	return opc;
}

//Destructor
Interfaz::~Interfaz(){}
