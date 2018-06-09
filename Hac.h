#ifndef _AGRUPADOR_HAC
#define _AGRUPADOR_HAC
#include <vector>
#include "Agrupador.h"
#include "Lista.h"
#include "Coordenada.h"

class Hac : public Agrupador {
	public:
	   Hac();
   	   Lista * agrupar( Lista * );
	   Lista * agruparNivel( Lista * );
	   Coordenada menorDistancia( Lista * );
	   int size( Lista * );
};

#endif