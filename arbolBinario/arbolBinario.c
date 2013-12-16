#include "arbolBinario.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

arbolBinario nuevo_arbolBinario(char nodo, arbolBinario *d, arbolBinario *i)
{
  arbolBinario nuevo = {
    .nodo = nodo,
    .arbolizquierdo = d,
    .arbolderecho = i,
  };

  return nuevo;
}

arbolBinario nueva_hoja(char nodo)
{
  return nuevo_arbolBinario(nodo, NULL, NULL);
}

void prefijo(arbolBinario *a)
{
  if (a != NULL) {
    printf("%c ", a->nodo);
    prefijo(a->arbolizquierdo);
    prefijo(a->arbolderecho);
  }
}

void posfijo(arbolBinario *a)
{
  if (a != NULL) {
    posfijo(a->arbolizquierdo);
    posfijo(a->arbolderecho);
    printf("%c ", a->nodo);
  }
}

void infijo(arbolBinario *a)
{
  if (a != NULL) {
    infijo(a->arbolizquierdo);
    printf("%c ", a->nodo);
    infijo(a->arbolderecho);
  }
}


bool es_hoja(arbolBinario *a)
{
  return !a->arbolderecho && !a->arbolizquierdo;
}

double evaluar(arbolBinario *a)
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
