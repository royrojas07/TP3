#include <iostream>
#include <string>
#include <fstream>
#include "Lista.h"
#include "Elemento.h"
#include "Hac.h"
#include "Palabra.h"
#include "Vector.h"
#include "Coordenada.h"
using namespace std;

int main(){
	
	// Elemento * palabra = new Palabra( "adios" );
	// Elemento * palabra1 = new Palabra( "solacasa" );
	// cout << "La distancia entre: " << palabra << " y " << palabra1
		// << " es de: " << palabra->distancia( palabra1 );
	// delete palabra1;
	// delete palabra;
	
	Hac * hac = new Hac();
	ifstream grupo( "file.txt" );
	Elemento * e = dynamic_cast<Palabra *>( new Palabra() );
	Lista * lista = new Lista( e, grupo, 18 );
	cout << "Esta es una lista de tamano: " << hac->size( lista ) << endl;
	cout << lista << endl;
	cout << "Voy a agrupar un nivel" << endl;
	Lista * semiAgrupada = hac->agruparNivel( lista );
	cout << semiAgrupada << endl;
	cout << "Voy a agrupar otro nivel" << endl;
	semiAgrupada = hac->agruparNivel( semiAgrupada );
	cout << semiAgrupada << endl;
	cout << "Uno mas" << endl;
	semiAgrupada = hac->agruparNivel( semiAgrupada );
	cout << semiAgrupada << endl;
	cout << "El ultimo ya" << endl;
	semiAgrupada = hac->agruparNivel( semiAgrupada );
	cout << semiAgrupada << endl;
	
	delete semiAgrupada;
	delete hac;
	delete e;
	
	return 0;
}