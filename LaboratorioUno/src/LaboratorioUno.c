/*
 ============================================================================
 Name        : LaboratorioUno.c
 Author      : Gustavo Pérez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
const int N = 5;
int arrayA[]={};
int arrayB[]={};
//indice elementos de arrayB

void entrada() {

	printf("Bienvenido.\n");
	//printf("Ingrese la cantidad de enteros que desea.\n");
	//scanf("%d\n",&N);

	printf("Ingrese los numeros enteros\n");
	for (int i = 0; i < 5; i++) {
		scanf("%i", &arrayA[i]);
	}

	printf("Los numeros ingresados son:");
	for (int x = 0; x < 5; x++) {
		printf("%i \t", arrayA[x]);
	}
	printf("\n\n");

}
void inicializaB(){

	for (int i = 0; i < N; i++) {
		arrayB[i]=0;

	}

}
//recorre y busca en arrayB, si no existe el numero, lo copia
int  buscar(int numero) {
	int retorno = 0;

	for (int j= 0; j < N;j++) {
		if (arrayB[j]==numero) { //ya existe el numero
			retorno = 1;
			break;
			}

	}
	return retorno;


}

int main(void) {
	inicializaB();
	int valorAbsoluto;
	int ret;
	int i;
	entrada();
	int c=0;
	//recorrer arrayA
	for ( i= 0; i < N; i++) {
		valorAbsoluto = abs(arrayA[i]);
		ret= buscar(valorAbsoluto);

		if (ret==0) {
				// copia en arrayB
				arrayB[c] =valorAbsoluto;
				c++;

			}
	}

	for (int x = 0; x < N ; x++) {
		printf("%i\n", arrayB[x]);
	}

}
