#include "Vector.h"
#include <iomanip>
using namespace std;

Vector::Vector()
: vector(nullptr)
{
}

double Vector::distancia(Elemento *otro)
{
	return 0; //por el momento
}

Vector::Vector(const Vector &otro) 
: vector(nullptr)
{
	if(vector){
		for(int i = 0; i < otro.size; i++)
			vector[i] = otro.vector[i];
	}
}

Vector::~Vector()
{
	if(vector)
		delete vector;
}
Elemento *Vector::clonar()
{
	return new Vector(*this);
}

int Vector::length() const
{
	return size;
}

istream &Vector::cargar(istream &entrada)
{
	char buffer[LIMIT];
	entrada.getline(buffer, LIMIT);
	size = 1 + contarEspacios(buffer);
	if(vector)
		delete [] vector;
	vector = new double[size];
	rellenar(vector, size, buffer);
	return entrada;
}

ostream &Vector::imprimir(ostream &salida)
{
	salida << "[ ";
	cout << fixed << setprecision(2);
	for(int i = 0; i < size; i++){
		if(i < size-1)
			salida << vector[i] << ", ";
		else
			salida << vector[i];
	}
	salida << " ]";
	return salida;
}

int Vector::contarEspacios(char *tira){
	const char BLANCO = ' ';
	int blancos = 0;
	for(int i = 0; tira[i]; i++){
		blancos += (tira[i] == BLANCO? 1 : 0);
	}
	return blancos;
}

void Vector::rellenar(double *vector, int largo, char* buffer){
	int leidos = 0;
	const char BLANCO = ' ';
	string numero = "";
	for(int i = 0; leidos < largo && i < LIMIT; i++){
		if(buffer[i] != BLANCO && buffer[i]){
			numero += buffer[i];
		}else{
			if(numero != ""){
				vector[leidos] = stod(numero);
				numero = "";
			}
			leidos++;
		}
	}
}