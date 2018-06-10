#include <iostream>
#include <string>
#include <fstream>
#include "Lista.h"
#include "Elemento.h"
#include "kmeans.h"
#include "XML.h"
#include "Palabra.h"
#include "Vector.h"
#include "Coordenada.h"
using namespace std;

int main(){
	
	// Elemento * palabra = new Palabra( "banano" );
	// Elemento * palabra1 = new Palabra( "guanabana" );
	// cout << "La distancia entre: " << palabra << " y " << palabra1
		// << " es de: " << palabra->distancia( palabra1 );
	// delete palabra1;
	// delete palabra;
	
	KMeans * kmeans = new KMeans();
	ifstream grupo( "file.txt" );
	Elemento * e = dynamic_cast<Palabra *>( new Palabra() );
	Lista * lista = new Lista( e, grupo, 6 );
	cout << "Esta es una lista de tamano: " << kmeans->lista_length( lista ) << endl;
	cout << lista << endl;
	cout << "Agrupacion: " << endl;
	Lista * agrupada = kmeans->agrupar( lista );
	cout << agrupada << endl;
	
	XML xml;
	xml.visualizar( agrupada );
	
	delete lista;
	delete kmeans;
	delete e;
	delete agrupada;
	return 0;
}