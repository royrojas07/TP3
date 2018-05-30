#ifndef FABRICA_PALABRAS
#define FABRICA_PALABRAS
#include "Fabrica.h"

class FabricaPalabras : public Fabrica
{
	public:
		FabricaPalabras()
		: Fabrica("elemento", "Palabra")
		{
		}
		virtual Producto *producir()
		{
			return new Producto();
		}
};
#endif