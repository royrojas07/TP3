#ifndef APP_H
#define APP_H
#include "Lista.h"
#include "KMeans.h"
#include "Agrupador.h"

class APP : public Agrupador
{
	private:
		Lista **generarDuplas(Lista *);
		Lista **agruparDuplas(Lista **);
		int lista_length;
		int cantDuplas;
		const int CLASIFICACIONES = 5;
	public:
		APP();
		~APP();
		virtual Lista *agrupar(Lista *);
		
};
#endif