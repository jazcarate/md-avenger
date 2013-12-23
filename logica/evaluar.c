#include "evaluar.h"

//Flag para debugear paso a paso
#define DEBUG

//Base de conocimiento
#define TABLAS 22
//Tablas de verdad
tabla tablasDeVerdad[TABLAS] = {
		{ .espera = "v y v", .devuelve = "v", },
		{ .espera = "v y f", .devuelve = "f", },
		{ .espera = "f y v", .devuelve = "f", },
		{ .espera = "f y f", .devuelve = "f", },

		{ .espera = "v o v", .devuelve = "v", },
		{ .espera = "v o f", .devuelve = "v", },
		{ .espera = "f o v", .devuelve = "v", },
		{ .espera = "f o f", .devuelve = "f", },

		{ .espera = "v > v", .devuelve = "v", },
		{ .espera = "v > f", .devuelve = "f", },
		{ .espera = "f > v", .devuelve = "v", },
		{ .espera = "f > f", .devuelve = "v", },

		{ .espera = "v = v", .devuelve = "v", },
		{ .espera = "v = f", .devuelve = "f", },
		{ .espera = "f = v", .devuelve = "f", },
		{ .espera = "f = f", .devuelve = "v", },

		{ .espera = "~v", .devuelve = "f", },
		{ .espera = "~f", .devuelve = "v", },

		{ .espera = "v O v", .devuelve = "f", },
		{ .espera = "v O f", .devuelve = "v", },
		{ .espera = "f O v", .devuelve = "v", },
		{ .espera = "f O f", .devuelve = "f", },
};

//Funciones
string evaluar(const string original){
	int tablaActual;
	for(tablaActual=0; tablaActual<TABLAS; tablaActual++){
		if( !strcmp(tablasDeVerdad[tablaActual].espera, original) ){
				#ifdef DEBUG
					printf(">> %s\t->\t%s\n", tablasDeVerdad[tablaActual].espera, tablasDeVerdad[tablaActual].devuelve);
				#endif
				return tablasDeVerdad[tablaActual].devuelve;
		}
	}
	return original;
}

string resolver(const string cadena){
		string retorno = strdup(cadena);
		string cmp = evaluar(cadena);
		if( strlen(cmp)!=1 && !strcmp(cmp, cadena))
			sprintf(retorno, "\(%s)", cmp);
		else{
			free(retorno);
			retorno=cmp;
		}
	return retorno;
}
