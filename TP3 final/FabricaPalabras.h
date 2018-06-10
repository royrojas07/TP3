#ifndef FABRICA_PALABRAS
#define FABRICA_PALABRAS
#include "Fabrica.h"
#include "Palabra.h"

class FabricaPalabras : public Fabrica
{
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
		*/
		FabricaPalabras()
		: Fabrica("elemento", "palabra")
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de Palabra 
		* en un puntero a Elemento, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Elemento Palabra.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Elemento *>(new Palabra()));
		}
};
#endif