#include "Carta.h"

//constructor y destructor
Carta::Carta(std::string v, char p) : valor(v), palo(p) {};

Carta::~Carta() {
	valor = " ";
	palo = ' ';
}

//metodos

void Carta::setValor(std::string valor) { this->valor = valor;}

void Carta::setPalo(char palo) { this->palo = palo; }

std::string Carta::getValor() { return valor; }
char Carta::getPalo() { return palo; }
