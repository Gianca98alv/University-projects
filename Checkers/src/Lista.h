#pragma once
#include <string>
#include <sstream>

using namespace std;

#include "Iterador.h"
#include "Partida.h"

class Lista;
class Nodo;
class IteradorLista;

//------------------------------------------LISTA--------------------------------------------------
class Lista {
private:
	int n;
	Nodo* primero;
	Nodo* ultimo;
public:
	Lista();
	Lista(const Lista&);
	virtual ~Lista();
	virtual Lista& operator=(const Lista&);

	virtual bool vacia() const;
	virtual int numElementos() const;
	virtual Partida* obtener(int) const;

	//virtual Puesto* getPuesto();

	virtual void agregar(const Partida*);
	virtual Partida* eliminar(int = -1);
	virtual void eliminar(Partida*);
	virtual void eliminarTodos(bool = false);

	virtual IteradorLista* obtenerIterador() const;
	virtual Nodo* getPrimero();
	virtual string toStringLista();

};
//---------------------------------------------------------------------------------------------------

//------------------------------------------NODO--------------------------------------------------
class Nodo {
private:
	Nodo* sig;
	Partida* info;
public:
	Nodo(const Partida*, Nodo* = NULL);

	virtual Partida* getInfo() const;
	virtual Nodo* getSig() const;
	virtual void setSig(Nodo*);

	virtual string toString() const;
};
//---------------------------------------------------------------------------------------------------------

//------------------------------------------ITERADOR LISTA--------------------------------------------------
class IteradorLista : public Iterador {
private:
	Nodo* actual;
public:
	IteradorLista(Nodo*);
	virtual bool masElementos() const;
	virtual Partida* proximoElemento();
	virtual Partida* ElementoActual();
	virtual void Siguiente();
};
//---------------------------------------------------------------------------------------------------------