#include <fstream>
#include "Elemento.h"
#include <iostream>
#include "Lista.h"
#include "KMeans.h"
#include "Palabra.h"
using namespace std;
int main(){
	Elemento *elemento = dynamic_cast<Palabra *>(new Palabra());
	fstream archivo2("archivo2.txt");
	fstream archivo("file.txt");
	Lista *lista = new Lista(elemento, archivo, 6);
	KMeans *agrupador = new KMeans();
	Lista *interna = new Lista(elemento, archivo2, 6);
	*lista += dynamic_cast<Elemento *>(interna);
	cout << "Lista inicial" << endl;
	cout << lista << endl << endl;
	Lista *grupos = agrupador->agrupar(lista);
	cout << "Lista agrupada" << endl;
	cout << grupos << endl;
	delete lista;
	delete grupos;
	return 0;
}