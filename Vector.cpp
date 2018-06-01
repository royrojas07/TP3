double Vector::distancia(Elemento *otro)
{
	Vector *v = dynamic_cast<Vector *>(otro);
	/*La distancia entre dos vectores es la norma del vector diferencia, normalizada para conseguir 
	un valor entre cero y uno.*/
	double distancia = norma((*v-this).vector, (*v-this).size)/max(norma(v->vector, v->size), norma(this->vector, size));
	return distancia;
}

ostream &Vector::imprimir(ostream &salida)
	return salida;
}

int Vector::contarEspacios(char *tira){
int Vector::contarEspacios(const char *tira){
	const char BLANCO = ' ';
	int blancos = 0;
	for(int i = 0; tira[i]; i++){
		blancos += (tira[i] == BLANCO? 1 : 0);
		blancos += (tira[i] == BLANCO? 1 : 0);	
	}
	return blancos;
}
@ -106,11 +107,20 @@ Vector &Vector::operator-(const Vector *otro)
	return *copia;
}

double Vector::norma(Vector &v) const
double Vector::norma(double *v, int largo)
{
	double raiz = 0;
	for(int i = 0; i < size; i++){
		raiz += pow(v.vector[i], 2);
	long double raiz = 0;
	for(int i = 0; i < largo; i++){
		raiz += pow(v[i], 2);
	}
	return sqrt(raiz);
}

double Vector::productoPunto(double *u, double *v, int largoU, int largoV)
{
	double producto = 0;
	for(int i = 0; i < largoU && i < largoV; i++){
		producto += u[i] * v[i]; 
	}
	return producto;
}