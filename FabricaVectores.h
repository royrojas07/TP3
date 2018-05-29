#ifndef FABRICA_PALABRAS
#define FABRICA_PALABRAS
#include "FabricaElementos.h"

class FabricaPalabras : public FabricaElementos
{
	public:
		FabricaPalabras()
		: FabricaElementos("Vector")
		{
		}
		virtual Producto *producir()
		{
			return new Producto();
		}
};
#endif