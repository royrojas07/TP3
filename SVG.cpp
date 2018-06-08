#include "SVG.H"
#include <string>
using namespace std;

void SVG::visualizar(Lista *grupos)
{
	if(!grupos)
		return;
	fstream archivo("visualizacion.html", ios::out);
	string header = "<!DOCTYPE html>\n<html>\n<body>\n<h3>Visualización en SVG</h3>\n\n<svg width=\"2000\" height=\"2000\">";
	string footer = "</svg>\n</body>\n</html>";
	string textStyle = "<style>\n\ttext{\n\tfont-size: 1rem;\nfont-weight: bold\n}\nalign:center\n</style>\n";
	/*string tabla = ""; //puede servir para algo
	array<string, 3> colores;
	colores[0] = "red";
	colores[1] = "green";
	colores[2] = "blue";
	int cxx, cxy, cyx, cyy, czx, czy= 0;
	int r = 100;
	cxx = 1366/2;
	cxy = 768/2;
	cyx = cxx + 2*r;
	cyy = cxy;
	czx = (cxx + cyx)/2;
	czy = (cyy + 2*r) - (double)(r/4);
	int **coordenadas = new int*[3];
	for(int j = 0; j < 3; j++)
		coordenadas[j] = new int[2]();
	coordenadas[0][0] = cxx;
	coordenadas[0][1] = cxy;
	coordenadas[1][0] = cyx;
	coordenadas[1][1] = cyy;
	coordenadas[2][0] = czx;
	coordenadas[2][1] = czy;
	archivo << header << textStyle << endl;
	for(int i = 0; i < 3; i++){
		archivo << "<circle cx=\"" << coordenadas[i][0] << "\" cy=\"" << coordenadas[i][1] <<"\" r=\"" << r << "\" stroke=\"black\" fill=\""<< colores[i] << "\"/>\n";
	}
	int largoL1, largoL2, largoL3 = 0;
	archivo << "<text x=\""<< cxx << "\" y=\"" << cyy << "\"" << " length=\"20\">1</text>" << endl;
	archivo << footer;
	archivo.close();
	for(int i = 0; i < 3; i++)
		delete [] coordenadas[i];
	delete [] coordenadas;
	delete grupos;
	*/
	archivo << header << endl;
	archivo << "<text x=\"100\" y=\"100\" style=\"text-align: center; fill: #ff0000; font-weight: bold;\">" << grupos << "</text>" << endl;
	archivo << footer;
	archivo.close();
}