#include "SVG.H"
using namespace std;

SVG::SVG()
: grupos_length(0)
{
	colores[0] = "red";
	colores[1] = "green";
	colores[2] = "blue";
	colores[3] = "silver";
	colores[4] = "lime";
	colores[5] = "maroon";
	colores[6] = "orange";
	colores[7] = "aqua";
	colores[8] = "purple";
	colores[9] = "lightsalmon";
	colores[10] = "tomato";
	colores[11] = "gold";
	colores[12] = "plum";
	colores[13] = "fuchsia";
	colores[14] = "olive";
}

SVG::~SVG()
{
	if(s)
		delete [] s;
}
void SVG::visualizar(Lista *grupos)
{
	if(!grupos)
		return;
	grupos_length = KMeans::lista_length(grupos);
	int height = 200 * grupos_length;
	fstream archivo("visualizacion.svg", ios::out);
	archivo << "<?xml version='1.0' encoding='UTF-8' ?>\n<svg xmlns='http://www.w3.org/2000/svg' version='1.1' width='1366px' height='" << height <<"px'>\n";
	int x = 1366/2; 
	int y = 120;
	archivo << "<text x=\"" << x << "\" y=\"" << y/2 <<"\" text-anchor=\"middle\" style=\"font-family: arial; font-size: 30px; font-weight: bold;\">Visualización en SVG</text>\n" << endl;
	srand(static_cast<unsigned int>(time(0)));
	s = new string[grupos_length];
	int contador = 0;
	string colorAleatorio = "black";
	for(Lista::Iterator i = grupos->begin(); i != grupos->end(); ++i, contador++){
		
		colorAleatorio = colores[rand() % 15];
		if(i != grupos->begin()){	
			while(seRepite(colorAleatorio)){ 
				colorAleatorio = colores[rand() % 15];
			}
		}	
		s[contador] = colorAleatorio;
		archivo << "<text x=\"" << x << "\" y=\"" << y << "\" textLength=\"1366\" lengthAdjust=\"spacingAndGlyphs\" text-anchor=\"middle\" style=\"font-weight: bold; font-family: courier; font-size: 40px; fill: " << colorAleatorio << ";\">" << *i << "</text>" << endl;
		y += 50;
	}
	archivo << "</svg>";
	archivo.close();
}

bool SVG::seRepite(string color)
{
	for(int i = 0; i < grupos_length; i++){
		if(s[i] == color)
			return true;
	}
	return false;
}