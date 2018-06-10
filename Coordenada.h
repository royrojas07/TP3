#ifndef COORDENADA
#define COORDENADA
/**@class Coordenada Clase que funciona para guardar
* ubicaciones en par.
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
#endif