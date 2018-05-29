#ifndef VECTOR_H
#define VECTOR_H
#include "Elemento.h"
#include <iostream>

class Vector : public Elemento
{
	public:
		Vector();
		double distancia(Elemento *) const;
		Elemento *clonar() const;
	protected:
		std::istream &cargar(std::istream &entrada);
		std::ostream &imprimir(std::ostream &salida);
		
};
#endif