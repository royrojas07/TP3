#ifndef FABRICA_JSON
#define FABRICA_JSON
#include "Fabrica.h"
#include "JSON.h"

class FabricaJSON : public Fabrica
{
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
		*/
		FabricaJSON()
		: Fabrica("visualizador", "JSON")
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de visualizador JSON 
		* en un puntero a Visualizador, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Visualizador JSON.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Visualizador *>(new JSON()));
		}
};
#endif