#ifndef FABRICA_KMEANS
#define FABRICA_KMEANS
#include "Fabrica.h"
#include "KMeans.h"

class FabricaKmeans : public Fabrica{
	public:
		FabricaKmeans()
		:Fabrica( "Agrupador", "Agrupador K-means")
		{
		}
		virtual Producto *producir()
		{
			return dynamic_cast<Producto *>(dynamic_cast<Elemento *>(new KMeans()));
		}
};
#endif