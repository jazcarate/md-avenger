#ifndef __ARBOLB_H__
#define __ARBOLB_H__

typedef struct arbolb arbolb;

struct arbolb {
	char nodo;
	arbolb *arbolderecho;
	arbolb *arbolizquierdo;
};

arbolb nuevo_arbolb(char nodo, arbolb *arbolderecho, arbolb *arbolizquierdo);
arbolb nueva_hoja(char nodo);

//Recorridos
void prefijo(arbolb *a);
void posfijo(arbolb *a);
void infijo(arbolb *a);

double evaluar(arbolb *a);

#endif
