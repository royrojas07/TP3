#include "XML.h"
using namespace std;

void XML::visualizar( Lista * lista ){
	ofstream xmlFile;
	xmlFile.open( "visualizacionXML.txt", ios::out );
	//solucionar encabezado
	xmlFile << "<?xml version=""1.0"" encoding=""UTF-8""?>" <<endl;
	xmlFile << "<raiz>" << endl;
	
	label_generator( lista );
	for( int i = 0; i < etiquetas.size(); i++ )
		xmlFile << etiquetas[i] << endl;
	
	xmlFile << "</raiz>" << endl;
}

void XML::label_generator( Lista * lista ){
	//vector<string> etiquetas;
	Lista::Iterator i = lista->begin();
	Lista::Iterator end = lista->end();
	Lista * esLista = 0;
	
	for( i; i != end; i++ ){
		esLista = dynamic_cast<Lista *>( *i );
		if( esLista ){
			etiquetas.push_back( "<lista>" );
			label_generator( esLista );
			etiquetas.push_back( "</lista>" );
		} else {
			etiquetas.push_back( "<elemento>" );
			etiquetas.push_back( "Lo que haya" );
			etiquetas.push_back( "</elemento>" );
		}
	}
	//return etiquetas;
}