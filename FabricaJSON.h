#ifndef FABRICA_PALABRAS
#define FABRICA_PALABRAS
#include "FabricaVisualizadores.h"

class FabricaJSON : public FabricaVisualizadores
{
	public:
		FabricaJSON()
		: FabricaVisualizadores("Visualizador JSON")
		{
		}
		virtual Producto *producir()
		{
			return new Producto();
		}
};
#endif