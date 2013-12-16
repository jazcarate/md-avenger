#ifndef __arbolBinario_H__
#define __arbolBinario_H__

typedef struct arbolBinario arbolBinario;

struct arbolBinario {
	char nodo;
	arbolBinario *arbolderecho;
	arbolBinario *arbolizquierdo;
};

// Inicializacion
arbolBinario nuevo_arbolBinario(char nodo, arbolBinario *arbolderecho, arbolBinario *arbolizquierdo);
arbolBinario nueva_hoja(char nodo);

// Recorridos
void prefijo(arbolBinario *a);
void posfijo(arbolBinario *a);
void infijo(arbolBinario *a);

double evaluar(arbolBinario *a);

#endif
