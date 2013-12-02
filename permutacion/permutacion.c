#include "permutacion.h"

///Preparar la estructura de funciones
void prepararFunciones(funciones *x, const char * str){
	x->original = strdup(str);
	x->datos = (char**)malloc(factorial(strlen(x->original)) * sizeof(char*));
	x->puntero = 0;
}

///Liberar la estructura
void liberarFunciones(funciones *x){
	int i;
	for(i=0; i<factorial(strlen(x->original)); i++)
		free(x->datos[i]);
	free(x->datos);
}

///Devuelve el factorial del numero
int factorial(int x){
	int rtn=1;
	for(;x>1;rtn*=x--);
	return rtn;
}

///Intercambia los punteros de X el de Y
void xor(char *x, char *y){
	if(x != y){ //Si son diferentes
		*x ^= *y;
		*y ^= *x; //XORealos
		*x ^= *y;
	}
}

///Cargar el vector con las posibles permutaciones
void permutar(funciones *donde, char *cadena, int inicio){
	int j;
	int fin = strlen(cadena);
	if(inicio==fin){ //Si ya diste tod0 vuelta
		donde->datos[donde->puntero++] = strdup(cadena); //el cpy y malloc
	}else{
		for(j=inicio; j<= fin; j++){
			xor((cadena+inicio), (cadena+j));
			permutar(donde, cadena, inicio+1);
			xor((cadena+inicio), (cadena+j)); //rollback
		}
	}
}

int buscar(const char aguja, const char* pajar, bool(*criterioIgual)(const char x, const char y)){
	int i=0;
	while(pajar[i]!='\0')
		if(criterioIgual(pajar[i++], aguja))
			return i-1;
	return -1;
}

int buscarPunteros(char* aguja, char** pajar){
	int i=factorial(strlen(aguja))-1;
	while(i>=0){
		if(strcmp(aguja, pajar[i]) == 0)
			return i;
		i--;
	}
	return -1;
}

char *aplicar(const char* original, const char *x, const char *y){
	int i, tamanio = strlen(original);

	bool igualdadChar(const char x, const char y){
		return x == y;
	}

	char* rtn = malloc(tamanio * sizeof(char));
	for(i=0; i<tamanio; i++)
		rtn[i]=y[buscar(x[i], original, igualdadChar)];
	return rtn;
}

void imprimirMatriz(const funciones* funciones){
	int i, j, fact = factorial(strlen(funciones->original)); //Calcular el tamanio del vector
	printf("\t");
	for(i=0; i<fact; i++){
		printf("\t(%s)f%d", funciones->datos[i], i);
	}
	for(i=0; i<fact; i++){
		printf("\n(%s)f%d)", funciones->datos[i], i);
		for(j=0; j<fact; j++){
			//Armar la matriz
			char* tmp = aplicar(funciones->original, funciones->datos[j], funciones->datos[i]);
			printf("\t(%s)f%d", tmp, buscarPunteros(tmp, funciones->datos));
		}
	}
	printf("\n");
}
