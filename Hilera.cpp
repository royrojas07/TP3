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
	Hilera *otra = dynamic_cast<Hilera *>(elemento);
	string otraTira = otra->tira;
	int largoTira = 1 + Vector::contarEspacios(tira.c_str());
	int largoOtraTira = 1 + Vector::contarEspacios(otraTira.c_str());
	double * u = new double[largoTira]();
	double * v = new double[largoOtraTira]();
	u = calcularFrecuencia(tira, u, tira.length(), largoTira);
	v = calcularFrecuencia(otraTira, v, otraTira.length(), largoOtraTira);
	cout << "U*V: " << Vector::productoPunto(u, v, largoTira, largoOtraTira) << endl;
	double normaU = Vector::norma(u, largoTira);
	double normaV = Vector::norma(v, largoOtraTira);
	double productoPunto = Vector::productoPunto(u, v, largoTira, largoOtraTira);
	if(productoPunto > normaU * normaV){
		productoPunto /= normaU * normaV;
	}
	cout << acos(1) << endl;
	long double arccos = acos(productoPunto / (normaU * normaV));
	return arccos;
}

double *Hilera::calcularFrecuencia(string &tira, double *v, int largo, int cantPalabras)
{
	const char BLANCO = ' ';
	string buffer = "";
	vector<string> container;
	int pos = 0;
	for(int i = 0; i < largo; i++){
		if(tira[i] != BLANCO){
			buffer += tira[i];
		}else{
			container.push_back(buffer);
			buffer = "";
		}
		if(i == largo-1)
			container.push_back(buffer);
	}
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