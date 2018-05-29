#ifndef FABRICA_ELEMENTOS
#define FABRICA_ELEMENTOS
#include "Fabrica.h"

class FabricaVisualizadores : public Fabrica{
	public:
		/*
		* Constructor que inicializa parte del elemento con una tira
		* predeterminada, pues se construyen elementos.
		* @param nombreElemento Nombre específico del elemento a construir.
		**/
		FabricaVisualizadores(const char *nombreElemento)
		: Fabrica("visualizador", nombreElemento)
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