#include "Fabrica.h"
#define MAXIMO 100  // SOLO PUEDEN CAMBIAR 
#include "ZonaFranca.h"
#include "FabricaPalabras.h"
#include "FabricaVectores.h"
#include "FabricaHileras.h"
#include "FabricaKmeans.h"
#include "FabricaHac.h"
#include "FabricaAPP.h"
#include "FabricaSVG.h"
#include "FabricaJSON.h"
#include "FabricaXML.h"

void ZonaFranca::agregar(Fabrica * fabrica){
	if(cantidadDeFabricas < MAXIMO){
       fabricas[cantidadDeFabricas++]= fabrica;	   
	}
}

ZonaFranca::ZonaFranca(){
	fabricas = new Fabrica * [MAXIMO];
	for(int i=0;i<MAXIMO; ++i){
		fabricas[i]=0;
	}
	cantidadDeFabricas=0;
	// SI HAY MAS QUE LO QUE INDICA EL VALOR "MAXIMO" DEBE AUMENTARLO EN EL .H
    // USTED AGREGAR INSTANCIAS DE FABRICA ESPECIFICAS 
	agregar(new FabricaPalabras());
	agregar(new FabricaVectores());
	agregar(new FabricaHileras());
	agregar(new FabricaKmeans());
	agregar(new FabricaHac());
	agregar(new FabricaAPP());
	agregar(new FabricaSVG());
	agregar(new FabricaJSON());
	agregar(new FabricaXML());
	// 3 Fabricas de Elemento
	// 3 Fabricas de Agrupador
	// 3 Fabricas de Visualizador
	
}

ZonaFranca::~ZonaFranca(){
	for(int i=0; i< cantidadDeFabricas;++i){
		delete fabricas[i];
	}
	delete [] fabricas;
}

Fabrica * ZonaFranca::getFabrica(const char * tipo, const char * nombre){
	int i=0;
	Fabrica * fabricaRetornada = 0;
	while(!fabricaRetornada && i< cantidadDeFabricas){
		if(fabricas[i]->esTipo(tipo) && fabricas[i]->produce(nombre)){
			fabricaRetornada = fabricas[i];			
		}
        ++i;
	}	
	return fabricaRetornada;
}
