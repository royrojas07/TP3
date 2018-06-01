#include <fstream>
#include "Fabrica.h"
#include "Vector.h"
#include "Producto.h"
#include "FabricaVectores.h"
#include "Elemento.h"
#include <iostream>
#include "Lista.h"
#include "Hilera.h"
#include <iomanip>
using namespace std;
int main(){/*
	Fabrica* fabricaVectores = new FabricaVectores();
	Elemento *elemento = dynamic_cast<Elemento *>(fabricaVectores->producir());
	fstream archivo("file.txt");
	Lista *lista = new Lista(elemento, archivo, 2);
	cout << lista << endl;
	Lista::	Iterator i = lista->begin();
	cout << "distancia: " << (*i++)->distancia(*i) << endl;*/
	Elemento *elemento = dynamic_cast<Elemento *>(new Hilera());
	Elemento *otro = dynamic_cast<Elemento *>(new Hilera());
	fstream archivo("file.txt");
	archivo >> elemento;
	archivo >> otro;
	cout << elemento->distancia(otro);
	
	return 0;
}
