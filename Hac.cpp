#include "Hac.h"
using namespace std;

Hac::Hac(){}

Lista * Hac::agrupar( Lista * lista ){
	Lista * aAgrupar = lista;
	int size = size( lista ); //ojo que es variable local!!!
	
	while( size > 1 ){
		aAgrupar = agruparNivel( aAgrupar );
		size--;
	}
	return agrupada;
}

Lista * Hac::agruparNivel( Lista * lista ){
	Lista * agrupada = new Lista();
	Coordenada cercanos = menorDistancia( lista );
	Lista::Iterator pos1;
	Lista::Iterator pos2;
	
	for( int i = 0; i < cercanos.x; i++ ){
		pos1++;
		for( int j = 0; j < cercanos.y; j++ )
			pos2++;
	}
	
	// Agregar masCercanos a una Sublista y meterla en
	// aAgrupar, eliminar esos elementos de aAgrupar
	return agrupada;
}

Coordenada Hac::menorDistancia( Lista * lista ){
	double min = 1.1;
	Lista::Iterator i = lista->begin();
	Lista::Iterator j;
	Lista::Iterator end = lista->end();
	Coordenada actual( 1, 2 );
	Coordenada minima();
	
	for( i; i != end; i++ ){
		for( j = ++i; j != end; j++ ){
			if( (*i).distancia( *j ) < min ){
				min = (*i).distancia( *j );
				minima = actual;
			}
			actual.y++;
		}
		actual.x++;
		actual.y = 0;
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