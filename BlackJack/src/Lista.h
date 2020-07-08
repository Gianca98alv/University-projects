#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
	struct Nodo* inicio;
public:
	//constructor, edstructor
	Lista();
	~Lista();

	//metodos
	Nodo* getInicio() { return inicio; }
	void insertar(JugadorGenerico*);
	void mostrarLista();
	void borrarLista();
	bool listaVacia();
	void compara();
	bool guardarEnArchivo();
	int cargarDeArchivo();
	
};

#endif