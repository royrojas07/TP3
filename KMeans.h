#ifndef KMeans_H
#define KMeans_H
#include "Agrupador.h"
#include <vector>
#include <cmath>
/**@class KMeans
* En esta clase se implementa el algoritmo de agrupamiento K-Means.
*/
class KMeans : public Agrupador
{
	public:
		/*Constructor por omisión.**/
		KMeans();
		/*Destructor.*/
		virtual ~KMeans();
		/*Función heredada de agrupador, la cual recibe una lista de elementos 
		* en orden aleatorio, y mediante el algoritmo de agrupamiento K-Means 
		* agrupa los elementos en función de su distancia.
		* @param lista Lista cuyos elementos se quieren agrupar.
		* @return una lista de listas, en donde cada lista interna representa un 
		* grupo de elementos.
		**/
		virtual Lista *agrupar(Lista *lista);
	private:
		/**@class Centroide
		* Clase mediante la cual se modelan objetos tipo centroide, los cuales guardan 
		* un puntero al Elemento que se escoja como centroide en el proceso de 
		* agrupamiento, y guardan un vector de punteros a Elemento para acoger los 
		* elementos que sean cercanos a ese centroide.
		*/
		class Centroide
		{
			public: 
				/*Constructor de Centroide que recibe como parámetro el Elemento que 
				lo representa.**/
				Centroide(Elemento *);
				/*Constructor de copia.**/
				Centroide(const Centroide &);
				/*Función para asignar un elemento que se considere cercano a ese centroide.**/
				void asignar(Elemento *);
				/*Función que revisa si el elemento que ingresa como argumento ya está dentro 
				del vector de elementos cercanos, para impedir que existan elementos duplicados.**/
				bool esta(Elemento *) const;
				/*Puntero al Element que lo representa.**/
				Elemento *elemento;
				/*Elementos cercanos que se le asignan al centroide.**/
				vector<Elemento *> elementosCercanos;
		};
		/*Por convención se fija la cantidad de centroides en k = 3.**/
		const int CENTROIDES = 3;
		/*Se fijó un límite de iteraciones en 10, en caso de que el algoritmo 
		se encicle cambiando los centroides en todas las iteraciones.**/
		const int LIMITE_ITERACIONES = 10;
		/*Entero que guarda la cantidad de elementos máximos que se le pueden asignar 
		a un centroide.**/
		int elementosPorCentroide;
		/*Entero que guarda la cantidad de iteraciones del algoritmo.**/
		int iteraciones;
		/*Función que compara dos distintos vectores de Centroide para verificar si 
		éstos se mantuvieron o no, entre una iteración y otra.**/
		bool convergio(Centroide **, Centroide **) const;
		/*Función que comprueba la existencia de un determinado Elemento en todos los 
		centroides, para no asignar un elemento a dos centroides distintos.**/
		bool esta(Centroide **, Elemento *) const;
		/*Vector de punteros a Centroide.**/
		Centroide **centroides;
		/*Función que recalcula los centroides, hasta que el algoritmo converja o se 
		alcance el límite de iteraciones.**/
		Centroide **recalcularCentroides(Centroide **);
		/*Función que genera una Lista de Listas, donde cada Lista interna es un grupo 
		de elementos generados por el algoritmo.**/
		Lista *generarGrupos(Centroide **);	
};
#endif