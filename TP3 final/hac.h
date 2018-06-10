#ifndef _AGRUPADOR_HAC
#define _AGRUPADOR_HAC
#include <vector>
#include "Agrupador.h"
#include "Lista.h"
/**@class Hac Clase creada con el propósito de agrupar objetos
* de tipo Elemento mediante el algoritmo jerárquico aglomerativo.
*/
class Hac : public Agrupador {
	private:
	   /**@class Coordenada Clase creada con el objetivo de guardar las ubicaciones de los elementos
	   * más cercanos en una Lista de elementos.
	   */
	   class Coordenada{
		   public:
			  /**Enteros para guardar ubicaciones.*/
		      int x, y;
			  /**Constructor por omisión.*/
			  Coordenada();
			  /**Constructor con parémtros. Asigna un valor para X y Y.*/
			  Coordenada( int, int );
			  /**Operador de asignación sobrecargado.
			  * @param otra Referencia a Coordenada de la cuál se copiaran
			  * sus atributos.
			  */
			  operator=( Coordenada & otra );
	   };
	   /**Función que agrupa un único nivel de cualquier
	   * Lista con tamaño > 1.
	   * @param lista Puntero a Lista de la cual se agrupará un nivel.
	   * @return Puntero a Lista ya agrupada en un nivel.
	   */
	   Lista * agruparNivel( Lista * lista );
	   /**Método que determina las posiciones ("Coordenada") de los
	   * elementos más cercanos de una Lista.
	   * @param lista Puntero a Lista en la que se buscarán los elementos más cercanos.
	   * @return Una copia de Coordenada que contiene las respectivas
	   * posiciones, contando desde 0. 
	   */
	   Coordenada menorDistancia( Lista * lista );
	   /**Función para conocer el tamaño de cualquier Lista.
	   * Las sub-listas que contenga se cuentan como un sólo Elemento.
	   * @param lista Puntero a Lista.
	   * @return Entero con el tamaño de esa Lista.
	   */
	   int size( Lista * lista );
	   
	public:
	   /**Constructor por omisión.*/
	   Hac();
	   /**Método que agrupa una lista de elementos por algoritmo
	   * jerárquico aglomerativo.
	   * @param lista Puntero a Lista que será agrupada.
	   * @return Puntero a Lista agrupada.
	   */
   	   virtual Lista * agrupar( Lista * lista );
};
#endif