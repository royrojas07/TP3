#ifndef FABRICA_PALABRAS
#define FABRICA_PALABRAS
#include "FabricaVisualizadores.h"

class FabricaXML : public FabricaVisualizadores
{
	public:
		FabricaXML()
		: FabricaVisualizadores("Visualizador XML")
		{
		}
		virtual Producto *producir()
		{
			return new Producto();
		}
};
#endif