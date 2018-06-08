#include "Coordenada.h"

Coordenada::Coordenada(): x(0), y(0){}

Coordenada::Coordenada( int x, int y ){
	this->x = x;
	this->y = y;
}

Coordenada & Coordenada::operator=( Coordenada & otra ){
	x = otra.x;
	y = otra.y;
	return *this;
}