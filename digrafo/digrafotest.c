#include <stdio.h>
#include "digrafo.h"

#define tamanio(x) (sizeof(x))/(sizeof(x[0]))

int main(void)
{
  digrafo ejemplo;
  inicializar_digrafo(&ejemplo);
  
  vertice a = insertar_nuevo_vertice(&ejemplo, 'a');
  vertice b = insertar_nuevo_vertice(&ejemplo, 'b');
  vertice c = insertar_nuevo_vertice(&ejemplo, 'c');
  vertice d = insertar_nuevo_vertice(&ejemplo, 'd');
  vertice e = insertar_nuevo_vertice(&ejemplo, 'e');
  vertice f = insertar_nuevo_vertice(&ejemplo, 'f');

  insertar_nueva_arista(&ejemplo, &a, &b);
  insertar_nueva_arista(&ejemplo, &c, &c);
  insertar_nueva_arista(&ejemplo, &d, &b);
  //insertar_nueva_arista(&ejemplo, &e, &f);
  insertar_nueva_arista(&ejemplo, &a, &c);
  insertar_nueva_arista(&ejemplo, &b, &f);
  insertar_nueva_arista(&ejemplo, &c, &d);
  insertar_nueva_arista(&ejemplo, &b, &e);
  insertar_nueva_arista(&ejemplo, &e, &a);

  printf("Matriz de Incidencia: \n");
  incidencia(&ejemplo);

  getchar();
  printf("\n\nMatriz de Adyacencia: \n");
  adyacencia(&ejemplo);
  
  getchar();
  printf("\n\nAlgun ciclo:\n");
  printf("\n%s", existe_camino_euleriano(&ejemplo, &a) ? "Si" : "No" );
    
  return 0;
}
