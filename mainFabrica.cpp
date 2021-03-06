#include "SVG.h"
#include "Lista.h"
#include "Elemento.h"
#include "Palabra.h"
#include <fstream>
#include "KMeans.h"
using namespace std;
int main(){
	Visualizador *v = dynamic_cast<Visualizador *>(new SVG());
	Agrupador *kmeans = dynamic_cast<Agrupador *>(new KMeans());
	Elemento *elemento = dynamic_cast<Elemento *>(new Palabra());
	fstream archivo("file.txt");
	Lista *lista = new Lista(elemento, archivo, 18);
	Lista *grupos = kmeans->agrupar(lista);
	v->visualizar(grupos);
	delete lista;
	delete grupos;
	return 0;
}