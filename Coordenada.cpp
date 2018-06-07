#include "Coordenada.h"

Coordenada::Coordenada(){
	x = 0;
	y = 0;
}

Coordenada::Coordenada( int x, int y ){
	this->x = x;
	this->y = y;
}

Coordenada & Coordenada::operator++(){
	x++;
	y++;
	return *this;
}

Coordenada & Coordenada::operator=( Coordenada otra ){
	x = otra.x;
	y = otra.y;
	return *this;
}

int Coordenada::getX(){
	return x;
}

int Coordenada::getY(){
	return y;
}