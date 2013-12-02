#include "afd.h"

#define TAM_ALFABETO 2
#define CANT_ESTADOS 3
#define ESTADO_INICIAL 0

int toInt(char x){
	return x-'a';
}
void imprimir_matriz(int x, int y, int m[x][y]){
	int i, j;

	//Header
	printf("\t|");
	for(i=0; i<y; i++)
		printf(" %c |", i+'a');

	//Body
	for(i=0; i<x; i++){
		printf("\n%d\t|", i);
		for(j=0; j<y; j++){
			printf(" %d |", m[i][j]);
		}
	}
	printf("\n");
}
