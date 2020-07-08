#include "Lista.h"


//constructor y destructor
Lista::Lista() { inicio = nullptr; }

Lista::~Lista() { borrarLista(); }


//metodos


void Lista::mostrarLista() {
	if (listaVacia()) {
		std::cout << std::endl << std::endl << "La lista no tiene jugadores: " << std::endl;
	}
	else
	{
		int i = 1;
		struct Nodo *aux;
		aux = inicio;
		while (aux != nullptr) {
			std::cout << "Jugador: " << i++ << " " << aux->juga->getNickname() << " " << std::endl;
			std::cout << aux->juga->getMano()->MuestraMazo() << " " << std::endl; 
			/*std::cout << aux->juga->getMano()->getMazo()->getCard()->getValor() << " " << std::endl;
			std::cout << aux->juga->getMano()->getMazo()->getCard()->getPalo() << " " << std::endl;*/
			aux = aux->next;
		}
	}
}


void Lista::insertar(JugadorGenerico* jugad) {
	struct Nodo *nuevo;
	
	nuevo = new struct Nodo;
	nuevo->juga = jugad;
	nuevo->next = nullptr;
	

	if (inicio == nullptr)
		inicio = nuevo;
	else {
		struct Nodo* aux = inicio;
		while (aux->next != nullptr)
			aux = aux->next;
		aux->next = nuevo;
	
	}
}


void Lista::borrarLista() {
	struct Nodo *tmp;
	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->next;
		delete tmp;
	}
}


bool Lista::listaVacia() {
	if (inicio == nullptr)
		return true;
	else
		return false;
}

void Lista::compara() {
	struct Nodo* aux;
	int val, val2;

	aux = inicio;

	val = inicio->juga->getMano()->pts();
	

	while (aux != nullptr) {
		aux = aux->next;

		val2 = aux->juga->getMano()->pts();

		if (val > val2)
			std::cout << "El jugador " << aux->juga->getNickname() << " perdio" << std::endl;

		else if (val < val2)
			std::cout << "El jugador " << aux->juga->getNickname() << " gano" << std::endl;

		else if (val == val2)
			std::cout << "El jugador " << aux->juga->getNickname() << " empato" << std::endl;

		else
			aux = aux->next;
	}
}

bool Lista::guardarEnArchivo() {
	struct Nodo* aux;

	std::ofstream archi;
	archi.open("juego.txt");

	if (!archi.is_open()){
		return 1;
	}

		aux = inicio;

		while (aux != nullptr) {
			archi << aux->juga->getNickname();
			archi << aux->juga->getMano()->getMazo()->getCard()->getValor();
			archi << aux->juga->getMano()->getMazo()->getCard()->getPalo() << std::endl;
		
			aux = aux->next;
		}
	

	archi.close();

	return 0;
}

int Lista::cargarDeArchivo() {
	struct Nodo* aux;

	std::ifstream archi;

	std::string n;
	std::string v;
	char p;


	archi.open("persona.txt");

	if (!archi.is_open())
		return -1;

	aux = inicio;
	while (archi.eof()) {
		archi >> n;
		archi >> v;
		archi >> p;

		aux->juga->setNickname(n);
		aux->juga->getMano()->getMazo()->getCard()->setValor(v);
		aux->juga->getMano()->getMazo()->getCard()->setPalo(p);
		
		aux = aux->next;
	}

	archi.close();

	return 0;
}
