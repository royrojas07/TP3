#ifndef FABRICA_ELEMENTOS
#define FABRICA_ELEMENTOS
#include "Fabrica.h"

class FabricaElementos : public Fabrica{
	public:
		/*
		* Constructor que inicializa parte del elemento con una tira
		* predeterminada, pues se construyen elementos.
		* @param nombreElemento Nombre específico del elemento a construir.
		**/
		FabricaElementos(const char *nombreElemento)
		: Fabrica("elemento", nombreElemento)
		{
		}
		/*
		* Producto vacío, solamente para utilizar el procesamiento polimórfico.
		**/
		virtual Producto *producir(){ 
			return new Producto();
		}
};
#endif