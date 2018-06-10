#ifndef SVG_H
#define SVG_H
#include "Visualizador.h"
#include "Lista.h"
#include <iostream>
#include <fstream>
#include <array>
#include <ctime>
#include <string>
#include <cstdlib>
#include "KMeans.h"
/**@class SVG 
* En esta clase se implementa una función para visualizar la conformación de los elementos agrupados
* a través de una imagen en formato SVG. Se estableció que cada renglón de elementos conforma un grupo,
* y cada uno tendrá un color distinto para identificarlo más fácilmente.
*/
class SVG : public Visualizador
{
	private:
		/**Array con nueve colores, para colorear las hileras de los grupos.*/
		array<string, 15> colores;
		/**Array que guarda cuáles colores ya se han escogido aleatoriamente, para no repetirlos.*/
		string *s;
		/**Largo de la lista que ingresa para ser visualizada (cantidad de grupos).*/
		int grupos_length;
		/**Función utilitaria para evitar repetir colores en la visualización.
		* @param color Color a comprobar si ya ha salido.
		* @return true si el color se repite, false en caso contrario.
		*/
		bool seRepite(string color);
	public:
		/**Constructor por omisión*/
		SVG();
		/**Destructor*/
		~SVG();	
		/**Función que imprime cada elemento de la lista en un archivo de formato .svg, para 
		* poder ser visualizados a través de un navegador.
		* @param lista Lista a visualizar.
		*/
		void visualizar(Lista *grupos);
};

#endif