#ifndef ELEMENTO_PALABRA
#define ELEMENTO_PALABRA
#include "Elemento.h"
#include <string>
#include <vector>

class Palabra : public Elemento{
    private:
		std::string palabra;
		std::vector<std::string> bigramas;
		
	protected:
	   virtual ostream & imprimir(ostream &);
	   virtual istream & cargar(istream &);
	
	public:
	   Palabra( std::string );
	   Palabra(const Palabra &);
	   virtual Elemento * clonar();	   
 	   virtual double distancia(Elemento *);
	   std::vector<std::string> bigramasPalabra( std::string );
	   std::vector<std::string> bigramasUnicos( std::vector<std::string> );
	   int bigramasComunes( std::vector<std::string> );
};
#endif