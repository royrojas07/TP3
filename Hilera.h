#ifndef _Hilera
#define _Hilera
#include "Elemento.h"
#include<iostream>
using namespace std;

class Hilera : public Elemento {
    private:
	   char tira[100];
    public:
	   ostream & imprimir(ostream &);
	   istream & cargar(istream &);	   
 	   int comparable(Elemento & );
};
#endif