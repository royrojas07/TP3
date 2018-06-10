#ifndef AGRUPADORKMEANS_H
#define AGRUPADORKMEANS_H
#include "Agupador.h"
#include <vector>
class AgrupadorKMeans
{
	public:
		AgrupadorKMeans();
		virtual ~AgrupadorKMeans();
		virtual Lista *agrupar(Lista *);
	private:
		class Centroide
		{
			public: 
				Centroide();
				~Centroide();
				void asignar(Elemento *);
			private:
				vector<Elemento *> elementosCercanos;
		};
};
#endif