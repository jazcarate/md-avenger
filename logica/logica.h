#ifndef LOGICA_H_
#define LOGICA_H_

	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>

	//Para hacerlo mas ameno
	typedef char* string;

	int parentesisQueCierra(string cadena, int posicionActual);
	char* parse(const string cadena, string (*transformar)(const string));

#endif
