#ifndef EVALUAR_H_
#define EVALUAR_H_

	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>

	//Para hacerlo mas ameno
	typedef char* string;
	typedef struct{
		string	espera;
		string	devuelve;
	} tabla;

	string evaluar(const string original);
	string resolver(const string cadena);

#endif
