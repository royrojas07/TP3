#include <fstream>
#include "Fabrica.h"
#include "Vector.h"
#include "Producto.h"
#include "FabricaVectores.h"
#include "Elemento.h"
#include <iostream>
#include "Lista.h"
using namespace std;
int main(){
	Fabrica* fabricaVectores = new FabricaVectores();
	Elemento *elemento = dynamic_cast<Elemento *>(fabricaVectores->producir());
	fstream archivo("file.txt");
	Lista *lista = new Lista(elemento, archivo, 2);
	cout << lista << endl;
	return 0;
}