/*
 ============================================================================
 Name        : DotsBoxes_01.c
 Author      : Gustavo Pérez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

char **matriz;
char **matrizAristas;

char *cadena;

int configuracion();
void reservarMemoria(int m);
void imprimirMatriz(int m);
void reIniciaCadena();

int main(void) {
	int m;	// cantidad de dots del juego

	m = configuracion(); // llama a la funcion de configurar el tamaño de la matriz

	if (m > 0) {
		reservarMemoria(m); // reserva memoria para el tamaño indicado
	} else {
		printf("Saliendo...\n");
	}

	imprimirMatriz(m);

}
/*
 * Función que configura el 'numero de puntos' que tiene el juego
 * devuelve un valor entero que se guarda en la variable entera 'm'
 * Este valor determina la cantidad de filas y columnas de la matriz.
 *
*/
int configuracion() {
	int n;
	printf("\n---------------- CONFIGURACION ----------------*\n");
	printf("Ingrese cantidad de puntos en fila y columna \n");
	printf("Ingrese 0: Salir\n");
	printf("\n------------------------------------------------\n");
	scanf("%d", &n);
	return n;

}

/*
 * Función que reserva la cantidad de memoria para las matrices necesarias
 * y una cadena que se utiliza para la impresion de la matriz
 */

void reservarMemoria(int m) {
	int i, j, nfilas, ncols;
	nfilas = m - 1;
	ncols = m - 1;

	// reserva memoria para la MATRIZ PRINCIPAL del juego

	matriz = (char**) malloc(nfilas * sizeof(char*));
	for (i = 0; i < nfilas; i++) {
		matriz[i] = (char*) malloc(ncols * sizeof(char));

	}
	// asigno mientras tanto un valor al elemento de la matriz
	for (i = 0; i < nfilas; i++) {
		for (j = 0; j <= ncols; j++) {
			matriz[i][j] = CASILLA_LIBRE;;
			//matriz[i][j] = ' ';
		}
	}

	/*reservar memoria para MATRIZ DE ARISTAS
	 * caracteres que contiene = '=',' ','|','*'

	 */
	int numfilas, numCol;
	numfilas = (m - 1) * (m - 1); // 1 fila por cada celda de la matriz del juego
	numCol = 4;	// 4 aristas posibles

	matrizAristas = (char**) malloc(numfilas * sizeof(char*));
	for (i = 0; i < numfilas; i++) {
		matrizAristas[i] = (char*) malloc(numCol * sizeof(char));
	}

	for (i = 0; i < numfilas; i++) {
		for (j = 0; j < numCol; j++) {
			matrizAristas[i][j] = CASILLA_LIBRE;
		}
	}

	// reservar memoria para cadena -- ok
	int cant = ncols * 5 + 1; //tamaño de la cadena
	cadena = (char*) malloc(cant * sizeof(char*));

}

/*
 * Función que imprime la matriz y la matrizAristas
 * forma una cadena por cada linea a imprimir
 *
 */
void imprimirMatriz(int m) {
	int i, j, nfilas, ncols, fa, k;
	nfilas = m - 1;
	ncols = m - 1;

	/*fa = fila de la arista
	 * fa = 4 * fila + c   */

	for (i = 0; i < nfilas; i++) {
		k = 0;
		reIniciaCadena();
		cadena[k] = PUNTO; //primer caracter de la cadena
		// forma la cadena de arriba Top
		for (j = 0; j < ncols; j++) {
			fa = 4 * i + j;
			k++;
			cadena[k] = matrizAristas[fa][TOP]; // columna Top imprimo 3 veces para q no sea tan apretado
			k++;
			cadena[k] = matrizAristas[fa][TOP]; // columna Top
			k++;
			cadena[k] = matrizAristas[fa][TOP]; // columna Top
			k++;
			cadena[k] = PUNTO;
		}
		printf("%s", cadena);
		printf("\n");

		// forma la cadena de la matriz Ej: |A|A|B|A|
		k = 0;
		reIniciaCadena();
		for (j = 0; j < ncols; j++) {
			fa = 4 * i + j;
			if (j == 0) {
				cadena[k] = matrizAristas[fa][LEFT];
				k++;
				cadena[k] = matrizAristas[fa][CASILLA_LIBRE];
			}
			k++;
			cadena[k] = matriz[i][j]; // elemento de la matriz
			k++;
			cadena[k] = matrizAristas[fa][CASILLA_LIBRE];
			 k++;
		 	cadena[k] = CASILLA_LIBRE;
			k++;
			cadena[k] = matrizAristas[fa][RIGHT]; // columna[3] = Right

		}

		printf("%s", cadena);
		printf("\n");
		reIniciaCadena();

		// ver si es la ultima linea para imprimir la linea de abajo
		if (i == nfilas - 1) {
			k = 0;
			cadena[k] = PUNTO; //primer caracter de la cadena
			// forma la cadena de arriba Top
			for (j = 0; j < ncols; j++) {
				fa = 4 * i + j;
				k++;
				cadena[k] = matrizAristas[fa][CASILLA_LIBRE];
				k++;
				cadena[k] = matrizAristas[fa][CASILLA_LIBRE];
				k++;
				cadena[k] = matrizAristas[fa][BOTTOM]; // columna[0] = Top
				k++;
				cadena[k] = PUNTO;
			}
			printf("%s", cadena);
			printf("\n");

		}

	}

}
void reIniciaCadena() {
	int l = strlen(cadena);
	for (int i = 0; i < l; i++) {
		cadena[i] = '\0';

	}

}

