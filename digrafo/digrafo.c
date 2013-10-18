#include "digrafo.h"
#include <stdio.h>
#include <stdbool.h>

void inicializar_digrafo(digrafo *d){
  d->cantidad_vertices=d->cantidad_aristas=0;
}
arista insertar_nueva_arista(digrafo *d, vertice *desde, vertice *hasta)
{
  arista nueva = {
    .desde	  = desde,
    .hasta	  = hasta,
    .visitada = false,
  };
	return d->aristas[d->cantidad_aristas++]=nueva;
}

vertice insertar_nuevo_vertice(digrafo *d, char nodo)
{
	return d->vertices[d->cantidad_vertices++] = nodo;
}


//FIXME: No me acuerdo si es asi, o estan invertidos los fors :S
void incidencia(digrafo *d)
{
  int i,j;
  printf("  \tA R I S T A S");
  for(i=0; i < d->cantidad_vertices; i++)
  {
	printf("\n%c)\t|", d->vertices[i]);
    for(j=0; j < d->cantidad_aristas; j++)
    {
	  printf("%s | ", (*(d->aristas[j].desde)==d->vertices[i]) ? " 1" : ((*(d->aristas[j].hasta)==d->vertices[i]) ? "-1" : " 0" ) );
    }
  }
}


void adyacencia(digrafo *d)
{
  int i,j;
  	printf("  \t|");
    for(i=0; i < d->cantidad_vertices; i++)
	  printf(" %c |", d->vertices[i]);

  for(i=0; i < d->cantidad_vertices; i++)
  {
	printf("\n%c)\t| ", d->vertices[i]);
    for(j=0; j < d->cantidad_vertices; j++)
    {
	  printf("%d | ", existe_camino_unitario(d, &(d->vertices[i]), &(d->vertices[j])));
    }
  }
}

bool existe_camino_unitario(digrafo *d, vertice *desde, vertice *hasta)
{
  int i=d->cantidad_aristas;
  for(;i>=0; i--)
	if( *(d->aristas[i].desde) == *desde &&
		*(d->aristas[i].hasta) == *hasta
	)
	  return true;
  return false;
}

bool existe_camino_euleriano(digrafo *d, vertice *viajante){

	printf("%c -> ", *viajante);

  int restante = cantidad_no_visitadas(d);
  if(restante == 0)
	return true;
	
  int i;
  for(i=0; i<d->cantidad_aristas; i++)
  {
    if(!d->aristas[i].visitada && d->aristas[i].desde == viajante){
    	d->aristas[i].visitada = true;
    	if( existe_camino_euleriano(d, d->aristas[i].hasta) )
    		return true;

			//  Dibujo  //
    		printf("\n");
			for(restante-=d->cantidad_aristas;restante<=0;restante++)
				printf("     ");
			// /Dibujo  //

			d->aristas[i].visitada = false;
    }
  }
  return false;
}

//Helpers
int cantidad_no_visitadas(digrafo *d)
{
  int resultado=0;
  int i;
  for(i=d->cantidad_aristas-1;i>=0;i--)
	if(!d->aristas[i].visitada)
		resultado++;
  return resultado;
}
