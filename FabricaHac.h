#ifndef FABRICA_HAC
#define FABRICA_HAC
#include "FabricaAgrupador.h"

class FabricaHac : public FabricaAgrupador{
	public:
		FabricaHac()
			:Fabrica( "Agrupador", "Agrupador Hac" ){}
};
#endif