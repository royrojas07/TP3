#include "XML.h"
using namespace std;

void XML::visualizar( Lista * lista ){
	if(!lista)
		return;
	fstream xmlFile("visualizacion.xml", ios::out);
	xmlFile << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>" << endl;
	xmlFile << "<raiz>" << endl;
	label_generator(lista, xmlFile);
	xmlFile << "</raiz>" << endl;
}

void XML::label_generator( Lista * lista , fstream &xmlFile){
	Lista::Iterator i = lista->begin();
	Lista::Iterator end = lista->end();
	Lista * esLista = 0;
	for( i; i != end; i++ ){
		esLista = dynamic_cast<Lista *>( *i );
		if( esLista ){
			xmlFile << "<grupo>" << endl;
			label_generator( esLista , xmlFile);
			xmlFile << "</grupo>" << endl;
		} else {
			xmlFile << "<elemento>" << endl;
			xmlFile << *i << endl;
			xmlFile << "</elemento>" << endl;
		}
	}
}
