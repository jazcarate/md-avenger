#ifndef PERMUTACIONES_H_
#define PERMUTACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define agregar(A, B) (A.datos[A.puntero++]=B)

typedef struct{
	char **datos;
	int puntero;
	char *original;
} funciones;

void prepararFunciones(funciones* x, const char* str);
void liberarFunciones(funciones *x);

int factorial(int x);
void xor(char *x, char *y);
void permutar(funciones *donde, char *cadena, int inicio);

int buscar(const char aguja, const char* pajar, bool(*criterioIgual)(const char x, const char y));
int buscarPunteros(char* aguja, char** pajar);
char *aplicar(const char* original, const char *x, const char *y);
void imprimirMatriz(const funciones* funciones);

#endif


