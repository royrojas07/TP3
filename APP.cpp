#include "APP.h"

APP::APP()
: lista_length(0), cantDuplas(0)
{
}

APP::~APP()
{	
}

Lista **APP::generarDuplas(Lista *original)
{
	Lista *lista = original->clonar();
	cantDuplas = lista_length/2;
	Lista **duplas = new Lista*[cantDuplas];
	for(int i = 0; i < cantDuplas; i++)
		duplas[i] = new Lista();
	double distanciaMenor = 1.0;
	Elemento *elementoCercano = nullptr;
	Lista::Iterator j = lista->begin();
	Lista::Iterator k = lista->begin();
	Lista::Iterator r;
	int borrados = 0;
	for(int f = 0; f < cantDuplas && j != lista->end(); ){	
		for(int i = 0; i < lista_length-borrados; i++){	
			k = lista->begin();
			++k;
			for(k; k != lista->end(); ++k){
				if((*j)->distancia(*k) <= distanciaMenor){		
					distanciaMenor = (*j)->distancia(*k);
					r = k;
					elementoCercano = *k;
				}
			}
			
			if(elementoCercano && elementoCercano != *j){
				*duplas[f] += *j;				
				*duplas[f] += elementoCercano;
				
				lista->borrar(r);
				lista->borrar(j);
				borrados++;
				f++;
			}
			if(lista_length % 2 != 0 && i == lista_length - 1 - borrados){
				*duplas[f-1] += *j;				
			}
			k = lista->begin();
			distanciaMenor = 1.0;
			elementoCercano = nullptr;			
		}
		++j;
	}
	return duplas;
}

Lista **APP::agruparDuplas(Lista **duplas)
{
	Lista **grupitos = new Lista*[CLASIFICACIONES];
	for(int i = 0; i < CLASIFICACIONES; i++)
		grupitos[i] = new Lista();
	Lista *listaCercana = nullptr;
	Lista *j;
	Lista *k;
	Lista *pareja;
	double distancia = 0.0;
	double distanciaMenor = 1.0;
	int borrados = 0;
	for(int i = 0; i < cantDuplas-borrados; i++){
		if(duplas[i])
			j = duplas[i];
		else
			continue;
		for(int l = i+1; l < cantDuplas-borrados; l++){
			if(duplas[l])
				k = duplas[l];
			else
				continue;
			distancia = j->distancia(k);
			if(distancia <= distanciaMenor){
				listaCercana = &*k;
				distanciaMenor = distancia;
			}
		}
		if(listaCercana){
			pareja = new Lista();
			*pareja += j;
			*pareja += k;
			*grupitos[(int)(distancia/0.2-1)] += pareja;
			delete pareja;			
			delete j;
			delete k;
			borrados++;
		}
		distanciaMenor = 1.0;
		listaCercana = nullptr;
		if(i == cantDuplas - 1 - borrados && cantDuplas % 2 != 0){
			for(int t = 0; t < CLASIFICACIONES; t++){
				distancia = duplas[i]->distancia(grupitos[t]);
				if(distancia <= distanciaMenor){
					distanciaMenor = distancia;
					listaCercana = &*grupitos[t];
				}	
			}
			if(listaCercana){
				*listaCercana += duplas[i];
			}
		}		
	}
	return grupitos;
}

Lista *APP::agrupar(Lista *lista)
{
	lista_length = KMeans::lista_length(lista);
	Lista **clasificada = agruparDuplas(generarDuplas(lista));
	Lista *agrupada = new Lista();
	for(int i = 0; i < CLASIFICACIONES; i++){
		if(clasificada[i] && clasificada[i]->begin() != clasificada[i]->end())
			*agrupada += clasificada[i];
	}
	return agrupada;
}
