#include "Lista.h"

//------------------------------------------LISTA--------------------------------------------------
Lista::Lista() :
	n(n),
	primero(NULL),
	ultimo(ultimo) {
}

Lista::Lista(const Lista& L2) : n(0), primero(NULL), ultimo(NULL) {
	Nodo* actual = L2.primero;
	while (actual != NULL) {
		Nodo* t = new Nodo(actual->getInfo());
		if (primero == NULL) {
			primero = ultimo = t;
		}
		else {
			ultimo->setSig(t);
			ultimo = t;
		}
		n++;
		actual = actual->getSig();
	}
}

Lista::~Lista() { eliminarTodos(); }
IteradorLista* Lista::obtenerIterador() const { return new IteradorLista(primero); }
Nodo* Lista::getPrimero() { return primero; }
bool Lista::vacia() const { return primero == NULL; }
int Lista::numElementos() const { return n; }

Lista& Lista::operator=(const Lista& L2) {
	if (this != &L2) {
		eliminarTodos();

		n = 0;
		primero = ultimo = NULL;
		Nodo* actual = L2.primero;
		while (actual != NULL) {
			Nodo* t = new Nodo(actual->getInfo());
			if (primero == NULL) {
				primero = ultimo = t;
			}
			else {
				ultimo->setSig(t);
				ultimo = t;
			}
			n++;
			actual = actual->getSig();
		}
	}
	return *this;
}

Partida* Lista::obtener(int i) const {
	Partida* r = NULL;
	if (i < n) {
		int p = 0;
		Nodo* actual = primero;
		while (p < i) {
			p++;
			actual = actual->getSig();
		}
		r = actual->getInfo();
	}
	return r;
}

void Lista::agregar(const Partida* e) {
	Nodo* t = new Nodo(e);
	if (vacia()) {
		primero = ultimo = t;
	}
	else {
		ultimo->setSig(t);
		ultimo = t;
	}
	n++;
}

Partida* Lista::eliminar(int i) {
	Partida* r = NULL;
	Nodo* aEliminar = NULL;

	// Se verifica si la posici�n solicitada se encuentra
	// dentro de la lista. Cuando el valor del parámetro es -1,
	// esto indica que se desea eliminar el último elemento.

	if (i == -1) {
		i = n - 1;
	}

	if (i < n) {

		// Si el elemento a eliminar es el primero, se actualiza
		// la referencia al primer elemento y se elimina el nodo.

		if (i == 0) {
			r = primero->getInfo();
			aEliminar = primero;
			primero = primero->getSig();
			if (primero == NULL) {
				ultimo = NULL;
			}

		}
		else {

			// Si se está eliminado un elemento diferente, se debe
			// mantener el cursor una posición atrás del elemento,
			// para poder actualizar la referencia al siguiente.

			int pos = 1;
			Nodo* cursor = primero;
			while (pos < i) {
				pos++;
				cursor = cursor->getSig();
			}
			r = cursor->getSig()->getInfo();
			aEliminar = cursor->getSig();
			cursor->setSig(cursor->getSig()->getSig());
			if (cursor->getSig() == NULL) {
				ultimo = cursor;
			}
		}

		if (aEliminar != NULL) {
			delete aEliminar;
		}
		n--;
	}
	return r;
}

void Lista::eliminar(Partida* e) {
	Partida* r = NULL;
	Nodo* aEliminar = NULL;

	if (!vacia()) {
		if (primero->getInfo() == e) {
			aEliminar = primero;
			primero = primero->getSig();
			if (primero == NULL) {
				ultimo = NULL;
			}
			n--;
		}
		else {
			Nodo* cursor = primero;
			bool encontrado = false;
			while ((cursor->getSig() != NULL) && !encontrado) {
				if (!(encontrado = cursor->getSig()->getInfo() == e)) {
					cursor = cursor->getSig();
				}
			}
			if (encontrado) {
				aEliminar = cursor->getSig();
				cursor->setSig(cursor->getSig()->getSig());
				if (cursor->getSig() == NULL) {
					ultimo = cursor;
				}
				n--;
			}
		}
	}
	if (aEliminar != NULL) {
		delete aEliminar;
	}
}

void Lista::eliminarTodos(bool purgar) {
	while (!vacia()) {
		Partida* e = eliminar();
		if (purgar) {
			delete e;
		}
	}
}

string Lista::toStringLista() {
	Nodo* actual = primero;
	stringstream s;
	while (actual != NULL) {
		s << actual->toString();
		actual = actual->getSig();
	}
	return s.str();
}
//--------------------------------------------------------------------------------------------------


//------------------------------------------NODO--------------------------------------------------
Nodo::Nodo(const Partida* info, Nodo* sig) :
	info((Partida*)info),
	sig(sig) {
}

Nodo* Nodo::getSig() const { return sig; }
void Nodo::setSig(Nodo* sig) { this->sig = sig; }
Partida* Nodo::getInfo() const { return info; }

string Nodo::toString() const {
	return info->toString();
}
//--------------------------------------------------------------------------------------------------


//------------------------------------------ITERADOR LISTA--------------------------------------------------
IteradorLista::IteradorLista(Nodo* p) :
	actual(p) {
}

bool IteradorLista::masElementos() const { return (actual != NULL); }
void IteradorLista::Siguiente() { actual = actual->getSig(); }


Partida* IteradorLista::proximoElemento() {
	Partida* r = NULL;
	if (masElementos()) {
		r = actual->getInfo();
		actual = actual->getSig();
	}
	return r;
}

Partida* IteradorLista::ElementoActual() {
	Partida* p = actual->getInfo();
	return p;
}
//--------------------------------------------------------------------------------------------------#include "Lista.h"
