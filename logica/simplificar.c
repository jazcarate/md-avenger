#include "simplificar.h"

//Flag para debugear paso a paso
#define dDEBUG

//Base de conocimiento
#define REGLAS 3
//Reglas
regla conocimiento[REGLAS] = {

		{
				.regex = "^\\((.+) o (.+)\\) y (\\1|\\2)",
				.nombre = "Absorcion",
				.remplazo = 3,
		},
		{
				.regex = "(.+) (y|o) \\1",
				.nombre = "Idempotencia",
				.remplazo = 1,
		},
		{
				.regex = "^\\((.+) y (.+)\\) o (\\1|\\2)",
				.nombre = "Absorcion2",
				.remplazo = 3,
		},
};


//Devuelve el compilado en *salida
void compilar(regla patron, regex_t *salida){
	char err_buf[BUFSIZ];		//Preparar los errores
	int errCod;					//Por si las dudas

	if( (errCod = regcomp(salida, patron.regex, REG_ICASE | REG_EXTENDED)) != 0)	{
								//Compilar el patron
		regerror(errCod, salida, err_buf, BUFSIZ);
								//Si erro, generar errores
		printf("regcomp: %s\n", err_buf);
		exit(errCod);			//Salir;
	}
}

string remplazar(const string original, const string buscar,const string remplazo){
  static char buffer[4096];
  string p;

  if(!(p = strstr(original, buscar)))  								// Esta lo que buscamos?
    return original;

  strncpy(buffer, original, p-original);							//Copiar de un lado al otro
  buffer[p-original] = '\0';										//Finalizarlo
  sprintf(buffer+(p-original), "%s%s", remplazo, p+strlen(buscar));
								//Concatenar
  return buffer;
}

string regex(const string original, regla expresion, bool* cambio){

		string retorno = strdup(original);
		regex_t testCompilado;
		compilar(expresion, &testCompilado);

		regmatch_t encontrados[MAX_ENCONTRADOS];



		if(regexec(&testCompilado, retorno, MAX_ENCONTRADOS, encontrados, REG_NOTBOL) != REG_NOMATCH){
								//Mientras encuentre la expresion
			*cambio = true;
								//Avisa encontraste algo
			#ifdef DEBUG
				int i;
				for (i = 0; encontrados[i].rm_so != -1; i++)
								//Por cada vez que la encuentre
						printf("num %d: %.*s\n", i, encontrados[i].rm_eo - encontrados[i].rm_so, retorno+encontrados[i].rm_so);
								//Remplaza
			#endif

			string buscar	= calloc(1, sizeof(char) * (encontrados[0].rm_eo-encontrados[0].rm_so));
								//Calloc setea t0do en 0,
			string remplazo	= calloc(1, sizeof(char) * (encontrados[expresion.remplazo].rm_eo-encontrados[expresion.remplazo].rm_so));
								//Es mas rapido que malloc + memset

			memcpy(buscar, retorno+encontrados[0].rm_so, encontrados[0].rm_eo-encontrados[0].rm_so);
								//Arma las variables que necesita
			memcpy(remplazo, retorno+encontrados[expresion.remplazo].rm_so, encontrados[expresion.remplazo].rm_eo-encontrados[expresion.remplazo].rm_so);

			printf("(%s)\t%s\t->\t%s\n", expresion.nombre, buscar, remplazo);

			retorno = remplazar(retorno, buscar, remplazo);
								//Remplaza


			free(buscar);		//Libera memoria
			free(remplazo);		//x2
			regfree(&testCompilado);
			return retorno;
		} else {
			free(retorno);
			return original;
		}
}

string simplificar(const string cadena){
	int reglaActual;
	string retorno = strdup(cadena);
	bool cambio=false;


	for(reglaActual=0; reglaActual<REGLAS; reglaActual++){
		char* retorno = regex(retorno, conocimiento[reglaActual], &cambio);
	}

	return retorno;
}
