#ifndef JSON_H
#define JSON_H
#include "Visualizador.h"
#include "Lista.h"
#include "KMeans.h"
#include <fstream>
/**@class JSON 
* En esta clase se implementa el visualizador en formato JSON. la salida es un archivo de texto que 
* debe ser ejecutado en un visualizador en línea de este formato, para visualizar las ramas de 
* elementos que simulan cada grupo.
*/
class JSON : public Visualizador
{
	public:
		/**Función que genera un archivo de texto en formato .json donde se 
		* visualizan los grupos generados por el agrupador escogido.
		* @param grupos Lista que se desea visualizar.
		*/
		virtual void visualizar(Lista *grupos);
};

#endif