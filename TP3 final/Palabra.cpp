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

Palabra::Palabra(): palabra(""){}

Elemento * Palabra::clonar(){
	return new Palabra( *this );
}

double Palabra::distancia(Elemento * otro){
	double distancia = 1.0;
	Palabra * p = dynamic_cast<Palabra *>(otro);
	
	if( palabra.length() > 1 && p->palabra.length() > 1 ){
		bigramas = bigramasPalabra( palabra );
		vector<string> bigramasOtro = bigramasPalabra( p->palabra );
	
		distancia = 1.0 - (2.0 * bigramasComunes( bigramasOtro ))/
			(bigramas.size() + bigramasOtro.size());
	} else 
		if( palabra.length() == 1 && p->palabra.length() > 1 ){
			vector<string> aBuscar;
			const char * c = p->palabra.c_str();
			string s;
			for( int i = 0; i < p->palabra.length(); i++ ){
				s = c[i];
				aBuscar.push_back( s );
			}
			if( esta( palabra, aBuscar ) )
				distancia = 1.0 - ( 1.0/(p->palabra.length()) );
	} else 
		if( palabra.length() > 1 && p->palabra.length() == 1 ){
			vector<string> aBuscar;
			const char * c = palabra.c_str();
			string s;
			for( int i = 0; i < palabra.length(); i++ ){
				s = c[i];
				aBuscar.push_back( s );
			}
			if( esta( p->palabra, aBuscar ) )
				distancia = 1.0 - ( 1.0/(palabra.length()) );
	} else 
		if( palabra.length() == 1 && p->palabra.length() == 1 ){
			if( palabra == p->palabra )
				distancia = 0;
	} else
		if( palabra.length() == 0 && p->palabra.length() == 0 ){
			distancia = 0;
		}
	
	return distancia;
}

vector<string> Palabra::bigramasPalabra( string palabra ){
	vector<string> bigramas;
	const char * cadenaPalabra = palabra.c_str();
	int largoPalabra = palabra.length();
	string aIngresar;
	
	for( int i = 0; i < largoPalabra-1; i++ ){
		aIngresar = cadenaPalabra[i];
		aIngresar += cadenaPalabra[i+1];
		if( !esta( aIngresar, bigramas ) )
			bigramas.push_back( aIngresar );
	}
	return bigramas;
}

bool Palabra::esta( string porBuscar, vector<string> aBuscar ){
	bool esta = false;
	for( int i = 0; i < aBuscar.size(); i++ )
		if( porBuscar == aBuscar[i] )
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