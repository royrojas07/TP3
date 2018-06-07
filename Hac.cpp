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

Lista * Hac::agruparNivel( Lista * lista ){
	Lista * agrupada = new Lista();
	
	
	
	return agrupada;
}

vector<double> Hac::calcularDistancias( Lista * lista ){
	vector<double> distancias;
	int size = size( lista );
	Lista::Iterator i = lista->begin();
	Lista::Iterator j = lista->end();
	
	for( i; i < size; i++ ){
		for( j = i+1; j < size; j++ ){
			distancias.push_back();
		}
	}
	
	return distancias;
}

int Hac::size( Lista * lista ){
	Lista::Iterator i = lista->begin();
	Lista::Iterator j = lista->end();
	int size = 0;
	for( i; i != j; i++ )
		size++;
	return size;
}