#include <fstream>
#include "Fabrica.h"
#include "Vector.h"
#include "Producto.h"
#include "FabricaVectores.h"
#include "Elemento.h"
#include <iostream>
using namespace std;
int main(){
	FabricaVectores* fabricaVectores = new FabricaVectores();
	Elemento *elemento = fabricaVectores->hacer();
	fstream archivo("file.txt");
	archivo >> elemento;
	cout << elemento;
	Elemento *clonado = elemento->clonar();
	archivo >> clonado;
	cout << clonado;
	return 0;
}