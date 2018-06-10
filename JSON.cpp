#include "JSON.h"

using namespace std;

void JSON::visualizar(Lista *grupos)
{
	if(!grupos)
		return;
	fstream archivo("visualizacion.json", ios::out);
	archivo << "{\n\"grupos\":[";
	int contador = 0;
	for(Lista::Iterator i = grupos->begin(); i != grupos->end(); ++i, contador++){
		archivo << "{\"string\":\"" << *i << "\"}";
	if(contador != KMeans::lista_length(grupos) - 1)
		archivo << ", ";
	}
	archivo << "]}" << endl;
}