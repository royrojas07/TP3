#include "JSON.h"

using namespace std;

void JSON::visualizar(Lista *grupos)
{
	if(!grupos)
		return;
	fstream archivo("visualizacion.json", ios::out);
	archivo << "{\n\"grupos\":[";
	recorrerArbol(grupos, archivo);
	/*int contador = 0;
	for(Lista::Iterator i = grupos->begin(); i != grupos->end(); ++i, contador++){
		archivo << "{\"elemento\":\"" << *i << "\"}";
	if(contador != KMeans::lista_length(grupos) - 1)
		archivo << ", ";
	*/
	
	archivo << " NULL ]}" << endl;
}

void JSON::recorrerArbol(Lista *lista, fstream &archivo)
{
	Lista::Iterator i = lista->begin();
	Lista::Iterator j;
	Lista *esLista = nullptr;
	int contador = 0;
	for(i; i != lista->end(); ++i, contador++){
		esLista = dynamic_cast<Lista *>(*i);
		if(esLista){
			recorrerArbol(esLista, archivo);		
		}
		else{
			archivo << "{\"elemento\":\"" << *i << "\"}, " << endl;
			j = i;
		}
	}
}