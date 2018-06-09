#include "Hac.h"
using namespace std;

Hac::Hac(){}

Lista * Hac::agrupar( Lista * lista ){
	Lista * aAgrupar = lista;
	
	while( size( aAgrupar ) > 1 ){
		aAgrupar = agruparNivel( aAgrupar );
	}
	return aAgrupar;
}

Lista * Hac::agruparNivel( Lista * lista ){
	Lista * agrupada = lista;
	if( size( lista ) > 1 ){
		Lista masCercanos;
		Coordenada cercanos = menorDistancia( lista );
		Lista::Iterator pos1 = lista->begin();
		Lista::Iterator pos2 = lista->begin();
		
		for( int i = 0; i < cercanos.x; i++ )
			pos1++;
		for( int j = 0; j < cercanos.y; j++ )
			pos2++;
		
		masCercanos += *(pos1);
		masCercanos += *(pos2);
		agrupada->borrar( pos1 );
		agrupada->borrar( pos2 );
		agrupada->push_front( &masCercanos );
	}
	return agrupada;
}

Coordenada Hac::menorDistancia( Lista * lista ){
	double min = 1.1;
	Lista::Iterator i = lista->begin();
	Lista::Iterator j;
	Lista::Iterator c;
	Lista::Iterator end = lista->end();
	Coordenada actual( 0, 1 );
	Coordenada minima;
	
	for( i; i != end; i++ ){
		c = i;
		for( j = ++c; j != end; j++ ){
			if( (*i)->distancia( *j ) < min ){
				min = (*i)->distancia( *j );
				minima = actual;
			}
			actual.y++;
		}
		actual.x++;
		actual.y = actual.x+1;
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