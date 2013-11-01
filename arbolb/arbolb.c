#include "arbolb.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

arbolb nuevo_arbolb(char nodo, arbolb *d, arbolb *i)
{
  arbolb nuevo = {
    .nodo = nodo,
    .arbolizquierdo = d,
    .arbolderecho = i,
  };

  return nuevo;
}

arbolb nueva_hoja(char nodo)
{
  return nuevo_arbolb(nodo, NULL, NULL);
}

void prefijo(arbolb *a)
{
  if (a != NULL) {
    printf("%c ", a->nodo);
    prefijo(a->arbolizquierdo);
    prefijo(a->arbolderecho);
  }
}

void posfijo(arbolb *a)
{
  if (a != NULL) {
    posfijo(a->arbolizquierdo);
    posfijo(a->arbolderecho);
    printf("%c ", a->nodo);
  }
}

void infijo(arbolb *a)
{
  if (a != NULL) {
    infijo(a->arbolizquierdo);
    printf("%c ", a->nodo);
    infijo(a->arbolderecho);
  }
}


bool es_hoja(arbolb *a)
{
  return !a->arbolderecho && !a->arbolizquierdo;
}

double evaluar(arbolb *a)
{
  if (es_hoja(a)) {
    return a->nodo - '0';
  }

  switch (a->nodo) {
    case '+':
      return evaluar(a->arbolizquierdo) + evaluar(a->arbolderecho);
      break;
    case '-':
      return evaluar(a->arbolizquierdo) - evaluar(a->arbolderecho);
      break;
    case '*':
      return evaluar(a->arbolizquierdo) * evaluar(a->arbolderecho);
      break;
    case '/':
      return evaluar(a->arbolizquierdo) / evaluar(a->arbolderecho);
      break;
    default:
      perror("ERROR: Operador invalido");
      return 0;
  }
}
