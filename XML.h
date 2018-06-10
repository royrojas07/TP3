#ifndef _XML
#define _XML
#include <fstream>
#include <vector>
#include "Lista.h"
#include "Visualizador.h"

class XML: public Visualizador{
	public:
		virtual void visualizar( Lista * lista );
		
	private:
		void label_generator( Lista * lista , fstream &);
};
#endif