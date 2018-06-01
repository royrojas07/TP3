#ifndef _Hilera
#define _Hilera
#include "Elemento.h"
#include "Vector.h"
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Hilera : public Elemento {
    private:
		string tira;
		double *calcularFrecuencia(string &, double *, int, int);
    protected:
		virtual ostream & imprimir(ostream &);
		virtual istream & cargar(istream &);
	public:
		Hilera();
		Hilera(const Hilera &);
		virtual Elemento *clonar();
		virtual double distancia(Elemento *);
};
#endif