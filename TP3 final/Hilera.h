#ifndef HILERA_H
#define HILERA_H
#include "Elemento.h"
#include "Vector.h"
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Hilera : public Elemento {
    private:
		/*String que guarda el dato de la hilera.**/
		string tira;
		/*Calcula la frecuencia de aparición de cada palabra en la hilera.**/
		double *calcularFrecuencia(string &, double *, int, int);
    protected:
		virtual ostream & imprimir(ostream &);
		virtual istream & cargar(istream &);
	public:
		/**Constructor por omisión.*/
		Hilera();
		/**Constructor por copia.*/
		Hilera(const Hilera &);
		/**Función para clonar una Hilera.
		* @param Elemento Puntero al elemento (hilera) que se quiere clonar.
		* @return Puntero a una copia del elemento que se ingresó como argumento.
		*/
		virtual Elemento *clonar();
		/**Función para calcular la distancia entre dos hileras, entendida como el arcocoseno 
		* del ángulo que forman sus vectores de frecuencia, para lo cual se utiliza la definición 
		* algebráica del coseno del ángulo entre dos vectores en el espacio.
		* @param Elemento elemento contra el que se quiere calcular la distancia (hilera).
		* @return Valor de la distancia entre las hileras.
		*/
		virtual double distancia(Elemento *);
};
#endif