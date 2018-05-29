#ifndef FABRICA_LISTAS
#define FABRICA_LISTAS
#include "FabricaElementos.h"

class FabricaListas : public FabricaElementos
{
	public:
		FabricaListas()
		: FabricaElementos("Lista")
		{
			
		}
		Producto *producir()
		{
			return new Producto();
		}
};
#endif