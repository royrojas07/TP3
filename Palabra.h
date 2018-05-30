#ifndef ELEMENTO_PALABRA
#define ELEMENTO_PALABRA
#include "Elemento.h"
#include <string>

class Palabra : public Elemento{
    private:
		string palabra;
	protected:
	   virtual ostream & imprimir(ostream &);
	   virtual istream & cargar(istream &);
	
	public:
	   Palabra();
	   virtual Elemento * clonar();	   
 	   virtual double distancia(Elemento *);	
};
#endif