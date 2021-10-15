/*
 ============================================================================
 Name        : Palindromo.c
 Author      : Gustavo Pérez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char **matriz;
#define N  5
void reservarMemoria(int n);
void entradaDatos();
void imprimirMatriz();
void limpiarBuffer();

void convertirMinusculas(char  *ptrFila[]);
void eliminaTildes(char str[100]);
void eliminaEspacios(char str[100]);
void esPalindromo(char *string);

int main(void) {
	// reservar memoria para la matriz de 5 filas
	reservarMemoria(N);
	entradaDatos();
	//imprimirMatriz();
	char *ptrFila;
	for (int m = 0; m < 3; m++) {
		ptrFila = matriz[m];
		convertirMinusculas(ptrFila);

		eliminaTildes(matriz[m]);
		eliminaEspacios(matriz[m]);
		esPalindromo(matriz[m]);

	}

	return EXIT_SUCCESS;
}
void reservarMemoria(int filas) {
	int i;
	int cols = 30;
	// reserva memoria para la MATRIZ
	matriz = (char**) malloc(filas * sizeof(char*));

	for (i = 0; i < filas; i++) {
		matriz[i] = (char*) malloc(cols * sizeof(char));
	}

}

void entradaDatos() {
	char *frase[] = { "Ana", "Aji traga la lagartija", "El dulce de leche" };
	//char *frase;
	//char *p;

	for (int i = 0; i < 3; i++) {
		//	limpiarBuffer();
		// no me funciona no se porque
		//printf("\n Ingrese la frase en la fila %d:", i);

		//	scanf("%30[^\n]", frase);
		//	 p=frase[i];

		matriz[i] = frase[i];

	}
}

void imprimirMatriz() {

	for (int f = 0; f < N; f++) {
		printf("%s \n", matriz[f]);

	}
}

void limpiarBuffer() {
	char a;
	while ((a = getchar()) != EOF && a != '\n')
		;
}

void convertirMinusculas(char  *ptrFila[]) {
	int i;
 //	int l = strlen(matriz);
	char *p;
	p = ptrFila;
	for (i = 0; p !=NULL  ; i++) {
		matriz[i] = tolower(matriz[i]);
	}



}
void eliminaTildes(char *matriz) {

	int l = strlen(matriz) - 1;
	for (int i = 0; i < l; i++)

	{
		const char *string = &matriz[i];
		char aConAcento = 'á';
		char AConAcento = 'Á';
		char eConAcento = 'é';
		char EConAcento = 'É';
		char iConAcento = 'í';
		char IConAcento = 'Í';
		char oConAcento = 'ó';
		char OConAcento = 'Ó';
		char uConAcento = 'ú';
		char UConAcento = 'Ú';

		if ((*string == iConAcento) || (*string == IConAcento)) {
			matriz[i] = 'i';
		} else {
			if ((*string == aConAcento) || (*string == AConAcento)) {
				matriz[i] = 'a';
			} else {
				if ((*string == eConAcento) || (*string == EConAcento)) {
					matriz[i] = 'e';
				} else {
					if ((*string == oConAcento) || (*string == OConAcento)) {
						matriz[i] = 'o';
					} else {
						if ((*string == uConAcento)
								|| (*string == UConAcento)) {
							matriz[i] = 'u';
						}
					}
				}
			}
		}

	}
}
void eliminaEspacios(char *matriz) {
	int L = strlen(matriz) - 1;
	int a = 0, k = 0;
	do {
		if (matriz[a] < 'a' || matriz[a] > 'z') {
			for (k = a; k < L; k++) {
				matriz[k] = matriz[k + 1];
			}
			L--;
		}
		a++;
	} while (matriz[a] != '\0');
	matriz[L + 1] = '\0';
}

void esPalindromo(char *matriz) {
	char *ptr, *r;
	ptr = matriz;
	while (*ptr != '\0') {
		++ptr;
	}
	--ptr;

	for (r = matriz; ptr >= r;) {
		if (*ptr == *r) {
			--ptr;
			r++;
		} else
			break;
	}

	if (r > ptr)
		printf("es Palindromo");
	else
		printf("no es Palindromo");
}

