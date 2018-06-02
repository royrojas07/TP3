#include "Hilera.h"
using namespace std;

Hilera::Hilera()
: tira("")
{
}
	   
Hilera::Hilera(const Hilera &otra)
{
	tira = otra.tira;
}
ostream & Hilera::imprimir(ostream & salida)
{
	salida << tira;
	return salida;
}

istream & Hilera::cargar(istream & entrada)
{
	getline(entrada, tira);
	return entrada;
}	   

Elemento *Hilera::clonar()
{
	Hilera *otra = new Hilera(*this);
	return dynamic_cast<Elemento *>(otra);
}

double Hilera::distancia(Elemento *elemento)
{
	double distancia = 1.0;
	Hilera *otra = dynamic_cast<Hilera *>(elemento);
	string otraTira = otra->tira;
	int largoTira = 1 + Vector::contarEspacios(tira.c_str());
	int largoOtraTira = 1 + Vector::contarEspacios(otraTira.c_str());
	/*Vectores de frecuencia de palabras en cada hilera. Se cuenta la cantidad de veces que sale cada palabra 
	en una determinada hilera y se almacena el número en el vector.*/
	double * u = new double[largoTira]();	
	double * v = new double[largoOtraTira]();
	u = calcularFrecuencia(tira, u, tira.length(), largoTira);
	v = calcularFrecuencia(otraTira, v, otraTira.length(), largoOtraTira);
	double normaU = Vector::norma(u, largoTira);
	double normaV = Vector::norma(v, largoOtraTira);
	double productoPunto = Vector::productoPunto(u, v, largoTira, largoOtraTira);
	/*El coseno del ángulo entre un vector y otro está dado por el producto punto entre el vector U y el 
	vector V, dividido por el producto de sus normas. Para obtener el valor en grados, se obtiene el arcocoseno de 
	este cálculo, que es el que se retorna como distancia.*/
	distancia = (acos(productoPunto / (normaU * normaV)) > 1? 1.0 : acos(productoPunto / (normaU * normaV)));
	delete [] u;
	delete [] v;
	return distancia;
}

double *Hilera::calcularFrecuencia(string &tira, double *v, int largo, int cantPalabras)
{
	const char BLANCO = ' ';
	string buffer = "";
	vector<string> container;
	int pos = 0;
	for(int i = 0; i < largo; i++){
		/*Divide la hilera en palabras individuales y las agrega a un contenedor.*/
		if(tira[i] != BLANCO){
			buffer += tira[i];
		}else{
			container.push_back(buffer);
			buffer = "";
		}
		if(i == largo-1)
			container.push_back(buffer);
	}
	/*Cuenta la cantidad de ocurrencias de cada palabra en la hilera.*/
	for(int j = 0; j < cantPalabras; j++){
		for(int l = j; l < largo; l++){
			pos = tira.find(container[j], l);
			if(pos != -1){
				v[j]++;
				l += pos;			
			}
		}
	}
	return v;
}