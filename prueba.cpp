#include <iostream>
#include <string>
#include <fstream>
#include "Lista.h"
#include "Elemento.h"
#include "Hac.h"
#include "Palabra.h"
#include "Vector.h"
using namespace std;

int main(){
	
	Palabra * palabra = new Palabra( "casasola" );
	Elemento * palabra1 = new Palabra( "casallena" );
	cout << "La distancia entre: " << palabra << " y " << palabra1
		<< " es de: " << palabra->distancia( palabra1 );
	delete palabra1;
	delete palabra;
	
	// Hac * hac = new Hac();
	// ifstream grupo( "file.txt" );
	// Elemento * e = dynamic_cast<Vector *>( new Vector() );
	// Lista * lista = new Lista( e, grupo, 2 );
	// cout << hac->size( lista );
	
	// delete lista;
	// delete hac;
	// delete e;
	return 0;
}