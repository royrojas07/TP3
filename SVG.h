#ifndef SVG_H
#define SVG_H
#include "Visualizador.h"
#include "Lista.h"
#include <iostream>
#include <fstream>

class SVG : public Visualizador
{
	public:
	/**Función que imprime cada elemento de la lista en un archivo de formato .svg, para 
	* poder ser visualizados a través de un navegador.
	* @param lista Lista a visualizar.
	*/
		void visualizar(Lista *grupos);
};

#endif