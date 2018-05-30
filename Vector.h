#ifndef VECTOR_H
#define VECTOR_H
#include "Elemento.h"

class Vector : public Elemento
{
	public:
		Vector();
		Vector(const Vector &);
		~Vector();
		double distancia(Elemento *) override;
		Elemento *clonar() override;
		int length() const;
		double *vector;
	protected:
		std::istream &cargar(std::istream &entrada) override;
		std::ostream &imprimir(std::ostream &salida) override;
		int size;
		const int LIMIT = 256;
		int contarEspacios(char *);
		void rellenar(double *, int, char *);
		
};
#endif