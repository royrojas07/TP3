#ifndef APP_H
#define APP_H
#include "Lista.h"
#include "KMeans.h"
#include "Agrupador.h"
/**@class APP
* Clase mediante la cual se implementa un agrupador propio del grupo de trabajo.
* El Agrupador Por Parejas (APP) inicia creando parejas de elementos estrechamente 
* cercanos, y un trío en caso de que el número de elementos sea impar. Los añade a un 
* vector de listas y luego pasa a la fase donde se agrupan parejas de estas listas,
* usando como criterio de agrupamiento la distancia entre listas. Finalmente, quedan 
* parejas de listas cercanas con parejas de elementos cercanos. Las parejas de listas 
* cercanas pueden clasificarse en 5 rangos: distancia 0.0-0.2, 0.2-0.4, 0.4-0.6, 0.6-0.8, 0.8-1.0.
* De esta manera se insertan estas parejas de listas en el segmento que corresponda según 
* la distancia entre ellas.
*/
class APP : public Agrupador
{
	private:
		/**Función para generar las duplas (pares) de elementos a partir de la lista 
		* original a agrupar.
		* @param original Lista original a organizar en parejas.
		* @return vector de Listas donde cada subíndice contiene una pareja de elementos.
		*/
		Lista **generarDuplas(Lista *original);
		/**Función para agrupar las duplas calculando la distancia entre cada grupo.
		* @param duplas Vector de listas (parejas) de elementos.
		* @return Vector de Listas que contiene las parejas de parejas de elementos clasificadas en 
		* su respectivo ámbito.
		*/
		Lista **agruparDuplas(Lista **duplas);
		/**Largo de la lista.*/
		int lista_length;
		/**Cantidad de duplas igual a la mitad de la cantidad de elementos.*/
		int cantDuplas;
		/**Clasificaciones en las que puede caer una pareja de parejas de elementos.*/
		const int CLASIFICACIONES = 5;
	public:
		/**Constructor por omisión.*/
		APP();
		/**Función que agrupa los elementos utilizando las funciones utilitarias privadas.*/
		virtual Lista *agrupar(Lista *);
		
};
#endif