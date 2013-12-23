#include "logica.h"

int parentesisQueCierra(string cadena, int posicionActual){
								//Se asume que cuando se llama el caracter es '('
	int balance=1;				//Entonces para balancear necesitamos 1 paarentesis ')'
	int posicionParentesis;
	for(posicionParentesis=posicionActual+1; balance; posicionParentesis++){
								//Hasta que no encuentre el balance
		if( cadena[posicionParentesis]=='(' )
			balance++;			//Desplazar el balance hacia el lado oscuro
		else if( cadena[posicionParentesis]==')' )
			balance--;			//Fiuh
	}
	return posicionParentesis;
								//Devolver posicion donde cierra el parentesis que abrio
}

char* parse(const string cadena, string (*transformar)(const string)){
	int posicionActual;
	char caracter;

	string rtn = strdup(cadena);
								//Replica el string
	printf("> %50s\n", cadena);

	for(posicionActual=0; (caracter=rtn[posicionActual]); posicionActual++){
								//Busca hasta el fin de linea
		if( caracter=='(' ){
								//Cada vez que se abre un parentesis
			string transformado = parse(rtn+posicionActual+1, transformar);
								//llamada recursiva con lo que esta dentro del parentesis
			rtn[posicionActual]='\0';
								//Corta el string en ese lugar
			if(strlen(transformado)!=1){
				sprintf(rtn, "%s(%s)%s", rtn, transformado ,rtn+parentesisQueCierra(rtn, posicionActual));
								//Remplazar el string viejo por el nuevo
								//Para eso sacas lo que estaba adentro de los parentesis
			posicionActual= posicionActual + strlen(transformado) + 1;
								//Como el string que cambiaste no tiene el mismo tama~o, se ajusta
			} else {
				sprintf(rtn, "%s%s%s", rtn, transformado ,rtn+parentesisQueCierra(rtn, posicionActual));
								//Remplazar el string viejo por el nuevo
								//Para eso sacas lo que estaba adentro de los parentesis
			posicionActual= posicionActual + strlen(transformado) - 1;
								//Como el string que cambiaste no tiene el mismo tama~o, se ajusta
			}
		}else if( caracter==')' ){
			rtn[posicionActual]='\0';
								//Cuando terminaste de procesar
			return transformar(rtn);
								//Devolve el transformado
		}
	}
	return transformar(rtn);
								//Para evitar el "No return, in function returning non-void"
								//y ademas si dan un string no terminado en ")"
}

//Funcion de prueba
char* cambiarMayu(char* s){
	int i;
	char* rtn = strdup(s);
	for(i=0;rtn[i];i++)
		if(rtn[i]>64 && rtn[i]<91)
			rtn[i] += 32;
		else if(rtn[i]>96 && rtn[i]<123)
			rtn[i] -= 32;
	return rtn;
}
