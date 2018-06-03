#include <iostream>
#include <vector>
#include <string>
#include "Palabra.h"
using namespace std;

int main(){
	// string palabra = "paralogralo";
	// string otra = "lograremos";
	
	//metodo bigramasPalabra
	// vector<string> bigramas;
	// vector<string> bigramas1;
	// const char * cadenaPalabra = palabra.c_str();
	// string aIngresar;
	// for( int i = 0; i < palabra.length()-1; i++ ){
		// aIngresar = cadenaPalabra[i];
		// aIngresar += cadenaPalabra[i+1];
		// bigramas.push_back( aIngresar );
	// }
	
	// for( int i = 0; i < bigramas.size(); i++ ){
		// cout << bigramas[i] << " ";
	// }
	// cout << endl;
	
	// cadenaPalabra = otra.c_str();
	// for( int i = 0; i < otra.length()-1; i++ ){
		// aIngresar = cadenaPalabra[i];
		// aIngresar += cadenaPalabra[i+1];
		// bigramas1.push_back( aIngresar );
	// }
	
	// for( int i = 0; i < bigramas1.size(); i++ ){
		// cout << bigramas1[i] << " ";
	// }
	// cout << endl;
	
	//metodo bigramasUnicos
	// vector<int> noUnicos;
	// vector<string> unicos;
	
	// for( int i = 0; i < bigramas.size(); i++ ){
		// for( int j = i+1; j < bigramas.size(); j++ ){
			// if( bigramas[i] == bigramas[j] )
				// noUnicos.push_back(j);
		// }
	// }
	
	// for( int i = 0; i < bigramas.size(); i++ ){
		// bool existe = false;
		// for( int j = 0; j < noUnicos.size(); j++ ){
			// if( i == noUnicos[j] )
				// existe = true;
		// }
		
		// if( !existe )
			// unicos.push_back( bigramas[i] );
	// }
	
	// for( int i = 0; i < unicos.size(); i++ )
		// cout << unicos[i] << " ";
	// cout << endl;
	
	// vector<int> noUnicos1;
	// vector<string> unicos1;
	
	// for( int i = 0; i < bigramas1.size(); i++ ){
		// for( int j = i+1; j < bigramas1.size(); j++ ){
			// if( bigramas1[i] == bigramas1[j] )
				// noUnicos1.push_back(j);
		// }
	// }
	
	// for( int i = 0; i < bigramas1.size(); i++ ){
		// bool existe = false;
		// for( int j = 0; j < noUnicos1.size(); j++ ){
			// if( i == noUnicos1[j] )
				// existe = true;
		// }
		
		// if( !existe )
			// unicos1.push_back( bigramas1[i] );
	// }
	
	// for( int i = 0; i < unicos1.size(); i++ )
		// cout << unicos1[i] << " ";
	// cout << endl;
	
	//metodo bigramasComunes
	// int comunes = 0;
	// for( int i = 0; i < unicos.size(); i++ ){
		// for( int j = 0; j < unicos1.size(); j++ ){
			// if( bigramas[i] == bigramas1[j] ){
				// j = bigramas1.size();
				// comunes++;
			// }
		// }
	// }
	// cout << "los bigramas comunes son:  " << comunes << endl;
	
	//distancia
	// double distancia = (2 * comunes)/
		// (unicos.size() + unicos1.size());
	// cout << distancia;
	
	Palabra palabra( "casita" );
	
	// vector<string> bigramas = palabra.bigramasPalabra( palabra.palabra );
	// vector<string> bigramas1 = palabra1.bigramasPalabra( palabra1.palabra );
	
	// for( int i = 0; i < bigramas.size(); i++ ){
		// cout << bigramas[i] << " ";
	// }
	// cout << endl;
	// for( int i = 0; i < bigramas1.size(); i++ ){
		// cout << bigramas1[i] << " ";
	// }
	
	Elemento * palabra1 = new Palabra( "casasola" );
	cout << palabra.distancia( palabra1 );
	delete palabra1;
	return 0;
}