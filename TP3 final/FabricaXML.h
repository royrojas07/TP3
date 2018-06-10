#ifndef FABRICA_XML
#define FABRICA_XML
#include "Fabrica.h"
#include "XML.h"

class FabricaXML : public Fabrica
{
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
		*/
		FabricaXML()
		: Fabrica("visualizador", "XML")
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de visualizador XML 
		* en un puntero a Visualizador, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Visualizador XML.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Visualizador *>(new XML()));
		}
};
#endif