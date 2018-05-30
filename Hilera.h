#ifndef _Hilera
#define _Hilera
#include "Elemento.h"
using namespace std;

class Hilera : public Elemento {
    private:
		char tira[100];
    public:
		Hilera();
		virtual ostream & imprimir(ostream &);
		virtual istream & cargar(istream &);	   
		int comparable(Elemento & );
};
#endif