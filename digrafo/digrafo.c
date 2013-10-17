#include "digrafo.h"
#include <stdio.h>
#include <stdbool.h>


arista nueva_arista(vertice *d, vertice *h)
{
  arista nueva = {
    .desde = d,
    .hasta = h,
  };

  return nueva;
}

vertice nuevo_vertice(char nodo)
{
	return nodo;
}


//FIXME: No me acuerdo si es asi, o estan invertidos los fors :S
void incidencia(arista* aristas, int tamanioAristas, vertice* vertices, int tamanioVertices)
{
  int i,j;
  printf("  \tA R I S T A S");
  for(i=0; i < tamanioVertices; i++)
  {
	printf("\n%c)\t", vertices[i]);
    for(j=0; j < tamanioAristas; j++)
    {
	  printf("%d\t", (aristas[j].desde==&vertices[i]) ? 1 : ((aristas[j].hasta==&vertices[i]) ? -1 : 0 ) );
    }
  }
}


void adyacencia(arista* aristas, int tamanioAristas, vertice* vertices, int tamanioVertices)
{
  int i,j;
    for(i=0; i < tamanioVertices; i++)
	  printf("\t%c", vertices[i]);

  for(i=0; i < tamanioVertices; i++)
  {
	printf("\n%c)\t", vertices[i]);
    for(j=0; j < tamanioVertices; j++)
    {
	  printf("%d\t", existe_camino_unitario(aristas, tamanioAristas, &vertices[i], &vertices[j]));
    }
  }
}

bool existe_camino_unitario(arista* aristas, int tamanioAristas, vertice* desde, vertice* hasta)
{
  int i=tamanioAristas;
  for(;i>=0; i--)
	if(aristas[i].desde==desde && aristas[i].hasta==hasta)
	  return 1;
  return 0;
}
