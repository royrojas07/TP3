#include <fstream>
#include "Fabrica.h"
#include "Vector.h"
#include "Producto.h"
#include "FabricaVectores.h"
#include "Elemento.h"
#include <iostream>
using namespace std;
int main(){
	Fabrica* fabricaVectores = new FabricaVectores();
	Elemento *elemento = dynamic_cast<Elemento *>(fabricaVectores->producir());
	fstream archivo("file.txt");
	archivo >> elemento;
	cout << elemento;
	Elemento *clonado = elemento->clonar();
	archivo >> clonado;
	cout << clonado;
	cout << endl << endl;
	cout << "distancia: " << elemento->distancia(clonado) << endl;
	return 0;
}