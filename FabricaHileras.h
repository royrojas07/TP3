#ifndef FABRICA_HILERAS
#define FABRICA_HILERAS
#include "Fabrica.h"
#include "Hilera.h"

class FabricaHileras : public Fabrica
{
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
		*/
		FabricaHileras()
		: Fabrica("elemento", "hilera")
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de Hilera 
		* en un puntero a Elemento, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Elemento Hilera.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Elemento *>(new Hilera()));
		}
};
#endif