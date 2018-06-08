#ifndef COORDENADA
#define COORDENADA

class Coordenada{
	public:
		int x, y;
		Coordenada();
		Coordenada( int, int );
		Coordenada & operator=( Coordenada & ); //referencia o copia?
};
#endif