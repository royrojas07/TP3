#ifndef FABRICA_K-MEANS
#define FABRICA_K-MEANS
#include "FabricaAgrupador.h"

class FabricaKmeans : public FabricaAgrupador{
	public:
		FabricaKmeans()
			:Fabrica( "Agrupador", "Agrupador K-means" ){}
};
#endif