#ifndef FABRICA_KMEANS
#define FABRICA_KMEANS
#include "Fabrica.h"
#include "KMeans.h"

class FabricaKmeans : public Fabrica{
	public:
		/** Constructor por omisión. Llama al constructor de la clase base 
		* con los argumentos correspondientes al tipo y nombre de elemento que produce.
		*/
		FabricaKmeans()
		:Fabrica( "agrupador", "KMeans")
		{
		}
		/** Función polimórfica que envuelve el tipo subyacente de agrupador KMeans 
		* en un puntero a Agrupador, que a su vez es envuelto en un puntero a 
		* Producto, gracias a la relación "es un" de las clases derivadas hacia 
		* clases base.
		* @return Puntero a producto, que por debajo es un Agrupador KMeans.
		*/
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Agrupador *>(new KMeans()));
		}
};
#endif