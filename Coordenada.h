#ifndef COORDENADA
#define COORDENADA
class Coordenada{
	private:
		int x, y;
	public:
		Coordenada();
		Coordenada( int, int );
		Coordenada & operator++(); //necesario retorno?
		Coordenada & operator=( Coordenada ); //referencia o copia?
		int getX();
		int getY();
};
#endif