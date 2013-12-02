#include "permutacion.h"

int main(int argc, char* argv[]) {
	if(argc>1){
		funciones f;
		prepararFunciones(&f, argv[1]);
	
		//Cargar el vector con todas las permutaciones
		permutar(&f, argv[1], 0);
	
		//Imprimir la matriz
		imprimirMatriz(&f);
	
		//Liberar la memoria
		liberarFunciones(&f);
	
		return EXIT_SUCCESS;
	} else {
		printf("HELP: La llamada tiene que ser con un CSV de elementos, separados por ''\n");
		return EXIT_FAILURE;
	}
}
