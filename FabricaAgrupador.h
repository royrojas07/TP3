#ifndef FABRICA_AGRUPADOR
#define FABRICA_AGRUPADOR
#include "Fabrica.h"

class FabricaAgrupador : public Fabrica{
	public:
		FabricaAgrupador( const char * nombreProducto )
			:Fabrica( "Agrupador", nombreProducto ){}

		virtual Producto * producir(){
			return new Producto();
		}
};
#endif