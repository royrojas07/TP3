#ifndef ELEMENTO_PALABRA
#define ELEMENTO_PALABRA
#include "Elemento.h"
#include <string>
#include <vector>
/**@class Palabra Clase para la creación de objetos Palabra.*/
class Palabra : public Elemento{
    private:
	   /**String que guarda la palabra de la instancia.*/
	   std::string palabra;
	   /**Variable tipo vector que almacena los bigramas de la palabra.*/
	   std::vector<std::string> bigramas;
	   /**Función que determina los bigramas únicos de una palabra.
	   * @param palabra Palabra de la cuál se determinan los bigramas únicos.
	   * No se toman en cuenta los repetidos.
	   * @return Vector que almacena todos los bigramas de esa palabra.
	   */
	   std::vector<std::string> bigramasPalabra( std::string palabra );
	   /**Función que calcula la cantidad de bigramas comunes entre dos bigramas.
	   * @param bigrama Vector con los bigramas de cierta palabra.
	   * @return Cantidad de bigramas comunes entre los bigramas de la instancia
	   * que llama al método y los que se pasan por párametro.
	   */
	   int bigramasComunes( std::vector<std::string> bigrama );
	   /**Función booleana para conocer la existencia de un string en un vector de strings.
	   * Utilizada en términos de bigrama en bigramas, o letra en palabras.
	   * @param porBuscar Bigrama o letra que se tratará de encontrar.
	   * @param aBuscar Vector que contiene bigramas o letras de una palabra, el
	   * cual se examinará.
	   * @return true sólo en el caso de que se encuentre.
	   */
	   bool esta( std::string porBuscar, std::vector<std::string> aBuscar );
		
	protected:
	   virtual std::ostream & imprimir(std::ostream &) override;
	   virtual std::istream & cargar(std::istream &) override;
	
	public:
	   /**Constructor por omisión. Crea una palabra vacía.*/
	   Palabra();
	   /**Constructor con parámetro. 
	   * Asigna el string que se pasa por parámetro a la variable palabra.
	   * Constructor creado con fines de prueba.
	   */
	   Palabra( std::string );
	   /**Constructor por copia.*/
	   Palabra(const Palabra &);
	   /**Función para clonar Palabra.
	   * @return Puntero a una copia de la instancia Palabra que llama al método.
	   */
	   virtual Elemento * clonar();
	   /**Función que calcula la distancia entre dos palabras.
	   * Esta distancia se obtiene por el coeficiente de Dice.
	   * Se normaliza para obtener valores entre [0,1].
	   * @param otro Puntero al elemento (Palabra) contra el que se calculará la distancia.
	   * @return double que representa la Distancia entre ambas palabras.
	   */
 	   virtual double distancia(Elemento * otro);
};
#endif