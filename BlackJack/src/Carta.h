#ifndef CARTA_H
#define CARTA_H
#include <string>

class Carta {
	std::string valor;
	char palo;
public:
	//constructor y destructor
	Carta(std::string, char);
	~Carta();

	

	//metodos
	std::string getValor();
	char getPalo();
	void setValor(std::string);
	void setPalo(char);
	



};
#endif
