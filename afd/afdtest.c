#include "afd.h"

#define TAM_ALFABETO 2
#define CANT_ESTADOS 3
#define ESTADO_INICIAL 0

int main(int argc, char* argv[]) {
	//Arma la matriz de estados
	int matriz[CANT_ESTADOS][TAM_ALFABETO] = {
			{1, 0},
			{2, 0},
			{1, 0}
	};
	int esFinal[CANT_ESTADOS] = {false, true, true};

	imprimir_matriz(CANT_ESTADOS, TAM_ALFABETO, matriz);

	int pos=0;
	int estado = ESTADO_INICIAL;
	char c;

	//Leer de a un caracter por vez
	//(hasta que se termine)
	printf("%d: ", ESTADO_INICIAL);
	while((c = argv[1][pos++]) != '\0'){
		estado = matriz[estado][toInt(c)];
		printf("%d > ", estado);
	}

	if(esFinal[estado])
		printf("\nBien!\n");
	else
		printf("\nMAL!\n");

	return EXIT_SUCCESS;
}
