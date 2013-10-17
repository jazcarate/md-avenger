#include <stdio.h>
#include "digrafo.h"

#define tamanio(x) (sizeof(x))/(sizeof(x[0]))

int main(void)
{
  vertice vertices[6];
  vertices[0]	= nuevo_vertice('a');
  vertices[1]	= nuevo_vertice('b');
  vertices[2]	= nuevo_vertice('c');
  vertices[3]	= nuevo_vertice('d');
  vertices[4]	= nuevo_vertice('e');
  vertices[5]	= nuevo_vertice('f');
  
  arista aristas[7];
  aristas[0] = nueva_arista(&vertices[0], &vertices[2]);
  aristas[1] = nueva_arista(&vertices[0], &vertices[1]);
  aristas[2] = nueva_arista(&vertices[2], &vertices[2]);
  aristas[3] = nueva_arista(&vertices[2], &vertices[3]);
  aristas[4] = nueva_arista(&vertices[3], &vertices[1]);
  aristas[5] = nueva_arista(&vertices[4], &vertices[5]);
  aristas[6] = nueva_arista(&vertices[5], &vertices[4]);
  
  /*
   * 
   *    b
   * a<    >d    e <-> f
   *    c)   
   *
  */
  
  
  printf("Matriz de Incidencia: \n");
  incidencia(aristas, 7, vertices, 6);

  printf("\nMatriz de Adyacencia: \n");
  adyacencia(aristas, 7, vertices, 6);
  
  return 0;
}
