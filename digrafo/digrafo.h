#ifndef __DIGRAFO_H__
#define __DIGRAFO_H__

#include <stdbool.h>


typedef char vertice;

typedef struct arista{
	vertice* desde;
	vertice* hasta;
} arista;

arista nueva_arista(vertice *d, vertice *h);
vertice nuevo_vertice(char nodo);

void incidencia(arista* aristas, int tamanioAristas, vertice* vertices, int tamanioVertices);
void adyacencia(arista* aristas, int tamanioAristas, vertice* vertices, int tamanioVertices);

bool existe_camino_unitario(arista* aristas, int tamanioAristas, vertice* desde, vertice* hasta);

#endif
