#ifndef FABRICA_HAC
#define FABRICA_HAC
#include "Fabrica.h"
#include "Hac.h"

class FabricaHac : public Fabrica{
	
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
		*/
		FabricaHac()
		:Fabrica( "agrupador", "Hac" )
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de agrupador Hac 
		* en un puntero a Agrupador, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Agrupador Hac.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Agrupador *>(new Hac()));
		}
};
#endif