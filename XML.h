#ifndef _XML
#define _XML
#include <fstream>
#include <vector>
#include "Lista.h"
#include "Visualizador.h"

class XML: public Visualizador{
	public:
		vector<string> etiquetas;
		virtual void visualizar( Lista * lista );
		void label_generator( Lista * lista );
};
#endif