#ifndef FABRICA_APP
#define FABRICA_APP
#include "Fabrica.h"
#include "APP.h"

class FabricaAPP : public Fabrica
{
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
		*/
		FabricaAPP()
		: Fabrica("agrupador", "APP")
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de agrupador APP 
		* en un puntero a Agrupador, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Agrupador APP.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Agrupador *>(new APP()));
		}
};
#endif