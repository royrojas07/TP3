#include "Palabra.h"
#include "Elemento.h"
using namespace std;

ostream & Palabra::imprimir(ostream & salida){
	salida << palabra;
	return salida;
}

istream & Palabra::cargar(istream & entrada){
	entrada >> palabra;
	return entrada;
}

Palabra::Palabra( string palabra ){
	this->palabra = palabra;
}

Palabra::Palabra(const Palabra & otra){
	this->palabra = otra.palabra;
}

Elemento * Palabra::clonar(){
	return new Palabra( *this );
}

double Palabra::distancia(Elemento * otro){
	double distancia;
	Palabra * p = dynamic_cast<Palabra *>(otro);
	bigramas = bigramasPalabra( palabra );
	vector<string> bigramasOtro = bigramasPalabra( p->palabra );
	
	distancia = 1.0 - (2.0 * bigramasComunes( bigramasOtro ))/
		(bigramas.size() + bigramasOtro.size());
	
	return distancia;
}

vector<string> Palabra::bigramasPalabra( string palabra ){
	vector<string> bigramas;
	const char * cadenaPalabra = palabra.c_str();
	string aIngresar;
	
	for( int i = 0; i < palabra.length()-1; i++ ){
		aIngresar = cadenaPalabra[i];
		aIngresar += cadenaPalabra[i+1];
		if( !yaEsta( aIngresar, bigramas ) )
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