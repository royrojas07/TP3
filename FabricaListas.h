#ifndef FABRICA_LISTAS
#define FABRICA_LISTAS
#include "Fabrica.h"

class FabricaListas : public Fabrica
{
	public:
		FabricaListas()
		: Fabrica("elemento", "lista")
		{
		}
		Producto *producir()
		{
			return new Producto();
		}
};
#endif