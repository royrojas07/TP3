#ifndef FABRICA_SVG
#define FABRICA_SVG
#include "Fabrica.h"
#include "SVG.h"

class FabricaSVG : public Fabrica
{
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
		*/
		FabricaSVG()
		: Fabrica("visualizador", "SVG")
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de visualizador SVG 
		* en un puntero a Visualizador, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Visualizador SVG.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Visualizador *>(new SVG()));
		}
};
#endif