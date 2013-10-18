#ifndef __DIGRAFO_H__
#define __DIGRAFO_H__

#include <stdbool.h>
#define MAXIMO 20


typedef char vertice;

typedef struct arista{
	vertice* desde;
	vertice* hasta;
	bool	 visitada;
} arista;

typedef struct digrafo{
	arista aristas[MAXIMO];
	int cantidad_aristas;
	vertice vertices[MAXIMO];
	int cantidad_vertices;
} digrafo;

void inicializar_digrafo(digrafo *d);
arista insertar_nueva_arista(digrafo *d, vertice *desde, vertice *hasta);
vertice insertar_nuevo_vertice(digrafo *d, char nodo);

void incidencia(digrafo *d);
void adyacencia(digrafo *d);

bool existe_camino_unitario(digrafo *d, vertice *desde, vertice *hasta);
bool existe_camino_euleriano(digrafo *d, vertice *viajante);

int cantidad_no_visitadas(digrafo *d);

#endif
