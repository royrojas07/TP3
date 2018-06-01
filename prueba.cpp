#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string palabra = "casasola";
	
	//metodo bigramasPalabra
	vector<string> bigramas;
	const char * cadenaPalabra = palabra.c_str();
	string aIngresar;
	for( int i = 0; i < palabra.length()-1; i++ ){
		aIngresar = cadenaPalabra[i];
		aIngresar += cadenaPalabra[i+1];
		bigramas.push_back( aIngresar );
	}
	
	for( int i = 0; i < bigramas.size(); i++ ){
		cout << bigramas[i] << " ";
	}
	cout << endl;
	
	//metodo bigramasUnicos
	vector<int> noUnicos;
	vector<string> unicos;
	
	for( int i = 0; i < bigramas.size(); i++ ){
		for( int j = i+1; j < bigramas.size(); j++ ){
			if( bigramas[i] == bigramas[j] )
				noUnicos.push_back(j);
		}
	}
	
	for( int i = 0; i < bigramas.size(); i++ ){
		bool existe = false;
		for( int j = 0; j < noUnicos.size(); j++ ){
			if( i == noUnicos[j] )
				existe = true;
		}
		
		if( !existe )
			unicos.push_back( bigramas[i] );
	}
	
	//prueba...
	cout << "Los bigramas unicos son: ";
	for( int i = 0; i < unicos.size(); i++ ){
		cout << unicos[i] << " ";
	}
	cout << endl;
	cout << "unicos en total: " << unicos.size() << endl;
	
	return 0;
}