#include "Hac.h"
using namespace std;

Hac::Hac(){}

Lista * Hac::agrupar( Lista * lista ){
	Lista * agrupada = lista;
	int size = size( lista ); //ojo que es variable local!!!
	
	while( size > 1 ){
		agrupada = agruparNivel( lista );
		size--;
	}
	
	return agrupada;
}

Lista Hac::agruparNivel( Lista * lista ){
	Lista agrupada();
	vector<double> distancias = calcularDistancias( lista );
	int distSize = distancias.size();
	int listSize = size( lista );
	double min = 1.1;
	int pos = 0;
	
	for( int i = 0; i < distSize; i++ ){
		if( distancias[i] < min ){
			min = distancias[i];
			pos = i;
		}
	}
	return agrupada;
}

Coordenada Hac::menorDistancia( Lista * lista ){
	double min = 1.1;
	Coordenada actual();
	Coordenada minima();
	Lista::Iterator i = lista->begin();
	Lista::Iterator j();
	Lista::Iterator end = lista->end();
	
	for( i; i != end; i++ ){
		for( j = i+1; j != end; j++ ){
			if( (*i).distancia( *j ) < min ){
				min = (*i).distancia( *j );
				minima = actual;
			}
		}
		actual++;
	}
	return minima;
}

int Hac::size( Lista * lista ){
	Lista::Iterator i = lista->begin();
	Lista::Iterator j = lista->end();
	int size = 0;
	for( i; i != j; i++ )
		size++;
	return size;
}