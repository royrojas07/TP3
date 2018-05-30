#ifndef FABRICA_VECTORES
#define FABRICA_VECTORES
#include "Fabrica.h"
#include "Vector.h"

class FabricaVectores: public Fabrica
{
	public:
		FabricaVectores()
		: Fabrica("elemento", "vector")
		{
		}
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Elemento *>(new Vector()));
		}
		Elemento *hacer()
		{
			return dynamic_cast<Elemento *>(new Vector());
		}
};
#endif