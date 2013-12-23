#ifndef SIMPLIFICAR_H_
#define SIMPLIFICAR_H_

	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <sys/types.h>
	#include <regex.h>

	#define MAX_ENCONTRADOS 10	//Cuantos matches por RegEx encuentra

	//Para hacerlo mas ameno
	typedef char* string;
	typedef const string patron;
	typedef struct{
		patron		regex;
		string		nombre;
		int			remplazo;
	} regla;
	typedef regla* reglas;

	void compilar(regla patron, regex_t *salida);
	string remplazar(const string original, const string buscar,const string remplazo);
	string regex(const string original, regla expresion, bool* cambio);
	string simplificar(const string cadena);


#endif
