#ifndef ELEMENTO_PALABRA
#define ELEMENTO_PALABRA
#include "Elemento.h"
#include <string>
#include <vector>

class Palabra : public Elemento{
    private:
		
		
	protected:
	   virtual std::ostream & imprimir(std::ostream &) override;
	   virtual std::istream & cargar(std::istream &) override;
	
	public:
	   std::string palabra;
	   std::vector<std::string> bigramas;
	   Palabra( std::string );
	   Palabra(const Palabra &);
	   virtual Elemento * clonar();	   
 	   virtual double distancia(Elemento *);
	   std::vector<std::string> bigramasPalabra( std::string );
	   int bigramasComunes( std::vector<std::string> );
	   bool yaEsta( std::string, std::vector<std::string> );
};
#endif