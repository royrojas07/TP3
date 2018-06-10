#ifndef _XML
#define _XML
#include <fstream>
#include <vector>
#include "Lista.h"
#include "Visualizador.h"
/**@class XML Clase encargada de generar un archivo .XML con el
* que se visualiza una Lista agrupada.
*/
class XML: public Visualizador{
	public:
		/**Función que genera un archivo .XML
		* @param lista Puntero a Lista ya agrupada que será examinada
		* para su visualización.
		*/
		virtual void visualizar( Lista * lista );
		
	private:
		/**Método que genera una serie de etiquetas necesarias para
		* incluir sub-listas y elementos que contenga cierta Lista.
		* @param lista Puntero a Lista de la que se obtendrán todas sus etiquetas.
		* @param xmlFile Flujo de salida al cual se dirigirán las etiquetas.
		*/
		void label_generator( Lista * lista , fstream &xmlFile);
};
#endif