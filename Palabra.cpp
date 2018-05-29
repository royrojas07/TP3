#include "Palabra.h"
#include "Elemento.h"

virtual ostream & Palabra::imprimir(ostream & salida){
	salida << palabra;
	return salida;
}

virtual istream & Palabra::cargar(istream & entrada){
	entrada >> palabra;
	return entrada;
}

Palabra::Palabra(const Palabra & otra){
	this->palabra = otra.palabra;
}

virtual Elemento * Palabra::clonar(){
	return new Elemento( *this );
}

virtual double Palabra::distancia(Elemento * otro){
	
}	