#include "Hilera.h"
#include "Elemento.h"
#include<iostream>
#include<cstring>
using namespace std;
	   
ostream & Hilera::imprimir(ostream & salida){
	salida << this->tira;
	return salida;
}

istream & Hilera::cargar(istream & entrada){
	entrada >> this->tira;
	return entrada;
}	   

int Hilera::comparable(Elemento & otro){
	int respuesta = -9;
	Hilera * ptr = dynamic_cast<Hilera *>(&otro);
	if(ptr){
	   respuesta = strcmp(this->tira,ptr->tira);                                               
	}
	else {
		cerr << "Hilera no es comparable con ese elemento Se retorna -9 por omisión "<< endl;
	}
	return respuesta;
}
