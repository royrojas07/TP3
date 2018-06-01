#include "Palabra.h"
#include "Elemento.h"
using namespace std;

virtual ostream & Palabra::imprimir(ostream & salida){
	salida << palabra;
	return salida;
}

virtual istream & Palabra::cargar(istream & entrada){
	entrada >> palabra;
	return entrada;
}

Palabra::Palabra( string palabra ){
	this->palabra = palabra;
}

Palabra::Palabra(const Palabra & otra){
	this->palabra = otra.palabra;
}

virtual Elemento * Palabra::clonar(){
	return new Elemento( *this );
}

virtual double Palabra::distancia(Elemento * otro){
	double distancia;
	bigramas = bigramasUnicos( bigramasPalabra(palabra) );
	vector<string> bigramasOtro = bigramasUnicos( bigramasPalabra(otro->palabra) );
	
	distancia = 1 - (2 * bigramasComunes( bigramasOtro ))/
		(misBigramas.size() + bigramasOtro.size());
	
	return distancia;
}

vector<string> Palabra::bigramasPalabra( string palabra ){
	vector<string> bigramas;
	const char * cadenaPalabra = palabra.c_str();
	string aIngresar;
	
	for( int i = 0; i < palabra.length()-1; i++ ){
		aIngresar = cadenaPalabra[i];
		aIngresar += cadenaPalabra[i+1];
		if( !yaEsta( aIngresar ) )
			bigramas.push_back( aIngresar );
	}
	
	return bigramas;
}

bool Palabra::yaEsta( string a, vector<string> b ){
	bool esta = false;
	for( int i = 0; i < b.size(); i++ )
		if( a == b[i] )
			esta = true;
	return esta;
}

vector<string> Palabra::bigramasUnicos( vector<string> bigrama ){
	vector<int> noUnicos;
	vector<string> unicos;
	
	for( int i = 0; i < bigrama.size(); i++ ){
		for( int j = i+1; j < bigrama.size(); j++ ){
			if( bigrama[i] == bigrama[j] )
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
	
	return unicos;
}

int Palabra::bigramasComunes( vector<string> bigrama ){
	int comunes = 0;
	for( int i = 0; i < bigramas.size(); i++ ){
		for( int j = 0; j < bigrama.size(); j++ ){
			if( bigramas[i] == bigrama[j] ){
				j = bigrama.size();
				comunes++;
			}
		}
	}
	
	return comunes;
}