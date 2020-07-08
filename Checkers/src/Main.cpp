//Estudiante:Hilary Granados Álvarez
//Profesora: Karol Leitón
//Segundo Proyecto- Programación II

#include "Controladora.h"

int main() {
	setlocale(LC_CTYPE, "Spanish");
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	Controladora* c = new Controladora();
	c->inicio();

	system("pause");
	return 0;
}