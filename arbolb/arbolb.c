#include "arbolb.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

arbolb nuevo_arbolb(char nodo, arbolb *d, arbolb *i)
{
  arbolb nuevo = {
    .nodo = nodo,
    .arbolderecho = d,
    .arbolizquierdo = i,
  };

  return nuevo;
}

arbolb nueva_hoja(char nodo)
{
  arbolb nuevo = {
    .nodo = nodo,
    .arbolderecho = NULL,
    .arbolizquierdo = NULL,   
  };

  return nuevo;
}

void prefijo(arbolb *a)
{
  if (a != NULL) {
    printf("%c ", a->nodo);
    prefijo(a->arbolderecho);
    prefijo(a->arbolizquierdo);
  }
}

void posfijo(arbolb *a)
{
  if (a != NULL) {
    posfijo(a->arbolderecho);
    posfijo(a->arbolizquierdo);
    printf("%c ", a->nodo);
  }
}

void infijo(arbolb *a)
{
  if (a != NULL) {
    infijo(a->arbolderecho);
    printf("%c ", a->nodo);
    infijo(a->arbolizquierdo);
  }
}


bool es_hoja(arbolb *a)
{
  return !a->arbolderecho && !a->arbolizquierdo;
}

double evaluar(arbolb *a)
{
  if (es_hoja(a)) {
    return a->nodo - '0';	//Pasar de char a int (solo valores de 0 a 9)
  }

  switch (a->nodo) {
    case '+':
      return evaluar(a->arbolderecho) + evaluar(a->arbolizquierdo);
      break;
    case '-':
      return evaluar(a->arbolderecho) - evaluar(a->arbolizquierdo);
      break;
    case '*':
      return evaluar(a->arbolderecho) * evaluar(a->arbolizquierdo);
      break;
    case '/':
      return evaluar(a->arbolderecho) / evaluar(a->arbolizquierdo);
      break;
    default:
      perror("ERROR: Operador invalido");
      return 0;
  }
}
