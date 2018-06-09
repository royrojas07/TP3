#include "KMeans.h"
#include <iomanip>
#include <stdexcept>
using namespace std;

KMeans::Centroide::Centroide(Elemento *elemento)
{
	this->elemento = elemento;	
}

KMeans::Centroide::Centroide(const Centroide &otro)
{
	elemento = otro.elemento;
	elementosCercanos = otro.elementosCercanos;
}

void KMeans::Centroide::asignar(Elemento *elemento)
{
	if(elemento)
		elementosCercanos.push_back(elemento);
}

KMeans::KMeans()
: elementosPorCentroide(0), iteraciones(0)
{
	centroides = new Centroide*[CENTROIDES];
}

KMeans::~KMeans()
{
	if(centroides){
		for(int i = CENTROIDES-1; i > 0; i--){
			if(centroides[i])
				delete centroides[i];
		}
		delete [] centroides;
	}
}

Lista *KMeans::agrupar(Lista *lista)
{
	/*Para que el agrupamiento tenga sentido, la lista debe tener al menos
	seis elementos.*/
	if(lista_length(lista) < 6)
		return lista;
	Lista::Iterator i = lista->begin();
	Lista::Iterator end = lista->end();
	Lista *grupos = new Lista();
	Lista *interna = nullptr;
	int posActual = 0;
	int largo = lista_length(lista);
	for(i; posActual < largo; ++i){
		interna = dynamic_cast<Lista *>(*i);
		if(interna){
			/*Si la lista contiene una lista, agrupa la interna y la agrega al resultado.*/
			KMeans *aux = new KMeans();
			*grupos += aux->agrupar(interna);
			lista->borrar(i);
			largo--;
			delete aux;
		}
		if(posActual == largo / 2){
			centroides[1] = new Centroide(*i);
		}
		interna = nullptr;
		posActual++;
	}
	Lista::Iterator j = lista->begin();
	int copiaLargo = 0;
	for(j; copiaLargo < largo-1; j++){
		copiaLargo++;
	}
	/*Inicialmente se asignan como centroides el primer elemento, 
	el elemento del centro de la lista, y el último elemento de la lista.*/	
	centroides[0] = new Centroide(*(lista->begin()));
	centroides[2] = new Centroide(*j);
	Elemento *elementoCercano = nullptr;
	double distanciaMenor = 1.0;
	/*Cálculo que determina cuántos elemenos máximos puede agrupar cada centroide.*/
	elementosPorCentroide = (int) ceil(largo/3.00-1);	
	/*Se asignan los elementos de la lista más cercanos a cada centroide, verificando que el elemento en cuestión no haya sido
	asignado ya a otro centroide y que este elemento no sea el propio centroide.*/
	for(int j = 0; j < CENTROIDES; j++){
		for(int c = 0; c < elementosPorCentroide; c++){
			for(i = lista->begin(); i != end; i++){
				if(((*i)->distancia(centroides[j]->elemento) <= distanciaMenor) && centroides[j]->elemento != (*i) && !esta(centroides, *i)){
					distanciaMenor = (*i)->distancia(centroides[j]->elemento);
					elementoCercano = *i;
				}
			}
			if(elementoCercano){
				centroides[j]->asignar(elementoCercano);
			}
			elementoCercano = nullptr;
			distanciaMenor = 1.0;
			i = lista->begin();	
		}	
	}
	/*Se hace una nueva lista de centroides para recalcularlos y comparar si los centroides 
	anteriores cambian entre una iteración y otra.*/
	Centroide **nuevosCentroides = new Centroide*[CENTROIDES];
	for(int l = 0; l < CENTROIDES; l++)
		nuevosCentroides[l] = new Centroide(*centroides[l]);
	grupos = generarGrupos(recalcularCentroides(nuevosCentroides), grupos);
	for(int m = CENTROIDES-1; m > 0; m--){
		if(nuevosCentroides[m])
			delete nuevosCentroides[m];
	}
	delete [] nuevosCentroides;
	return grupos;
}

KMeans::Centroide **KMeans::recalcularCentroides(Centroide **nuevos)
{
	double distanciaMenor = 1.0;
	Elemento *elementoMedio = nullptr;
	/*Calcula el elemento con menor distancia media entre el grupo conformado por el centroide y sus elementos cercanos.*/
	for(int a = 0; nuevos[a] && a < CENTROIDES; a++){
		for(int b = 0; !nuevos[a]->elementosCercanos.empty() && b < nuevos[a]->elementosCercanos.size(); b++){
			if(nuevos[a]->elemento->distancia(nuevos[a]->elementosCercanos[b]) < distanciaMenor){
				distanciaMenor = nuevos[a]->elemento->distancia(nuevos[a]->elementosCercanos[b]);
				elementoMedio = nuevos[a]->elementosCercanos[b]; 	
			}
		}
		/*Reasigna el centroide si y solo si el nuevo elemento medio es diferente del elemento centroide.*/
		if(elementoMedio && nuevos[a]->elemento != elementoMedio){	
			Centroide *nuevo = new Centroide(elementoMedio);
			for(int c = 0; !nuevos[a]->elementosCercanos.empty() && c < nuevos[a]->elementosCercanos.size(); c++){
				/*Evita reasignarse a sí mismo como elemento cercano.*/
				if(nuevos[a]->elementosCercanos[c] != nuevo->elemento)
					nuevo->asignar(nuevos[a]->elementosCercanos[c]);
			}
			/*Asigna como elemento cercano del nuevo centroide al antiguo elemento centroide.*/
			nuevo->asignar(nuevos[a]->elemento);
			delete nuevos[a];
			nuevos[a] = nuevo;
		}
		elementoMedio = nullptr;
		distanciaMenor = 1.0;
	}
	/*Compara el vector anterior de centroides con el actual para verificar la convergencia; de no haber convergido repite 
	el proceso hasta converger o hasta alcanzar el límite de 10 iteraciones (no siempre el algoritmo converge).*/
	if(!convergio(centroides, nuevos) && ++iteraciones < LIMITE_ITERACIONES)
		nuevos = recalcularCentroides(nuevos);	
	return nuevos;
}

Lista *KMeans::generarGrupos(Centroide **nuevos, Lista *grupos){
	/*Crea un array de listas, en donde cada lista contiene los elementos de cada centroide.*/
	Lista **grupoDeGrupos = new Lista*[CENTROIDES];
	for(int d = 0; d < CENTROIDES; d++){
		grupoDeGrupos[d] = new Lista();
		grupoDeGrupos[d]->operator+=(nuevos[d]->elemento);
		for(int e = 0; e < nuevos[d]->elementosCercanos.size(); e++){
			grupoDeGrupos[d]->operator+=(nuevos[d]->elementosCercanos[e]);
		}
	}
	for(int f = 0; f < CENTROIDES; f++){
		grupos->operator+=(grupoDeGrupos[f]);
	}
	/*Reclama la memoria de las variables intermedias.*/
	if(grupoDeGrupos){
		for(int i = CENTROIDES-1; i > 0; i--){
			if(grupoDeGrupos[i])
				delete grupoDeGrupos[i];
		}
		delete [] grupoDeGrupos;
	}
	return grupos;
}

bool KMeans::Centroide::esta(Elemento *elemento) const
{
	for(int i = 0; i < elementosCercanos.size(); i++){
		if(elementosCercanos[i] == elemento)
			return true;
	}
	return false;
}

bool KMeans::convergio(Centroide **anteriores, Centroide **nuevos) const
{
	for(int i = 0; i < CENTROIDES; i++){
		if(anteriores[i]->elemento != nuevos[i]->elemento)
			return false;
	}
	return true;
}

bool KMeans::esta(Centroide **centroides, Elemento *elemento) const
{
	for(int i = 0; i < CENTROIDES; i++){
		if(centroides[i]->esta(elemento) || centroides[i]->elemento == elemento)
			return true;
	}
	return false;
}

int KMeans::lista_length(Lista *lista)
{
	int length = 0;
	if(!lista)
		return 0;
	for(Lista::Iterator i = lista->begin(); i != lista->end(); i++){
		length++;
	}
	return length;
}
