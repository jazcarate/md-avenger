#include <stdio.h>
#include "arbolBinario.h"

int main(void)
{
  arbolBinario tres   = nueva_hoja('3');
  arbolBinario cuatro = nueva_hoja('4');
  arbolBinario cinco  = nueva_hoja('5');
  arbolBinario seis   = nueva_hoja('6');
  arbolBinario ocho   = nueva_hoja('8');

  arbolBinario mid1 = nuevo_arbolBinario('-', &ocho, &seis);
  arbolBinario mid2 = nuevo_arbolBinario('*', &mid1, &tres);
  arbolBinario mid3 = nuevo_arbolBinario('+', &cuatro, &cinco);
  arbolBinario raiz = nuevo_arbolBinario('/', &mid3, &mid2);

  prefijo(&raiz);
  putchar('\n');

  posfijo(&raiz);
  putchar('\n');

  infijo(&raiz);
  putchar('\n');

  printf("Resultado: %g\n", evaluar(&raiz));

  return 0;
}
