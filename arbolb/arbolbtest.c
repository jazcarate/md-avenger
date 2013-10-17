#include <stdio.h>
#include "arbolb.h"

int main(void)
{
  arbolb tres	= nueva_hoja('3');
  arbolb cuatro	= nueva_hoja('4');
  arbolb cinco	= nueva_hoja('5');
  arbolb seis	= nueva_hoja('6');
  arbolb ocho	= nueva_hoja('8');
  
  arbolb mid1 = nuevo_arbolb('-', &ocho, &seis);
  arbolb mid2 = nuevo_arbolb('*', &mid1, &tres);
  arbolb mid3 = nuevo_arbolb('+', &cuatro, &cinco);
  arbolb raiz = nuevo_arbolb('/', &mid3, &mid2);

  /* 
   *         / 
   *    +        *
   *  4   5     -  3
   *           8 6
   * 
   */
	

  prefijo(&raiz);
  putchar('\n');

  posfijo(&raiz);
  putchar('\n');

  infijo(&raiz);
  putchar('\n');

  printf("Resultado: %g\n", evaluar(&raiz));

  return 0;
}
