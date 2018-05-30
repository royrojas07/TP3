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
	cout << "v: " << elemento << endl;
	Elemento *otro = elemento->clonar();
	archivo >> otro;
	cout << "w: " << otro << endl;
	cout << endl << endl;
	cout << "distancia: " << elemento->distancia(otro) << endl;
	return 0;
}