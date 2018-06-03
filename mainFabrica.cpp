#include <fstream>
#include "Fabrica.h"
#include "Vector.h"
#include "Producto.h"
#include "FabricaVectores.h"
#include "Elemento.h"
#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "Hilera.h"
#include "KMeans.h"
using namespace std;
int main(){
	Elemento *elemento = dynamic_cast<Vector *>(new Vector());
	fstream archivo("file.txt");
	Lista *lista = new Lista(elemento, archivo, 6);
	KMeans *agrupador = new KMeans();
	Lista *grupos = agrupador->agrupar(lista);
	cout << "Lista inicial" << endl;
	cout << lista << endl << endl;
	cout << "Lista agrupada" << endl;
	cout << grupos << endl;
	delete lista;
	delete grupos;
	return 0;
}