#include <stdio.h>
#include "digrafo.h"

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
  vertice g = insertar_nuevo_vertice(&ejemplo, 'g');
  vertice h = insertar_nuevo_vertice(&ejemplo, 'h');

  insertar_nueva_arista(&ejemplo, &b, &g);
  insertar_nueva_arista(&ejemplo, &g, &d);
  insertar_nueva_arista(&ejemplo, &c, &f);
  insertar_nueva_arista(&ejemplo, &f, &e);
  insertar_nueva_arista(&ejemplo, &e, &h);
  insertar_nueva_arista(&ejemplo, &d, &h);
  

  insertar_nueva_arista(&ejemplo, &a, &b);
  insertar_nueva_arista(&ejemplo, &a, &c);
  insertar_nueva_arista(&ejemplo, &b, &c);
  insertar_nueva_arista(&ejemplo, &c, &e);
  insertar_nueva_arista(&ejemplo, &d, &e);
  insertar_nueva_arista(&ejemplo, &d, &b);
  insertar_nueva_arista(&ejemplo, &b, &e);
  insertar_nueva_arista(&ejemplo, &d, &c);



  printf("Matriz de Incidencia: \n");
  incidencia(&ejemplo);

  getchar();
  printf("\n\nMatriz de Adyacencia: \n");
  adyacencia(&ejemplo);
  
  getchar();
  printf("\n\nAlgun ciclo empezando por \"d\"?:\n");
  printf("\n%s", existe_camino_euleriano(&ejemplo, &d, &criterio_digrafo) ? "Si" : "No" );
    
  return 0;
}
