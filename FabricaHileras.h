#ifndef FABRICA_HILERAS
#define FABRICA_HILERAS
#include "Fabrica.h"

class FabricaHileras : public Fabrica
{
	public:
		FabricaHileras()
		: Fabrica("elemento", "hilera")
		{
		}
		virtual Producto *producir()
		{
			return new Producto();
		}
};
#endif