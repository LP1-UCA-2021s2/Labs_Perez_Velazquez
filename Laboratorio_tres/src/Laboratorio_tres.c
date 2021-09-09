/*
 ============================================================================
 Name        : Laboratorio_tres.c
 Author      : Gustavo Pérez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int esPrimo(int num);

int main(void) {
	char array[50], aux[50];

	int len, i, b = 0, a = 0, sum = 0, c,num,contador;

	for (i = 0; i < 50; i++) {
		array[i] = '\0';
		aux[i] = 0;
	}
	printf("Ingrese los numeros");
	scanf("%s", array);
	len = strlen(array);
	b = len;
	printf("%d", b);

	for (i = 0; i < (len / 2)+1; i++) {
		if (a != b - 1) {
			sum = ((array[a] - 48) * 10) + (array[b - 1] - 48);
			aux[i] = sum;
			c++;
			a++;
			b--;
		} else {
			aux[i] = array[a] - 48;
			c++;
			break;
		}

	}
	for (i = 0; i < strlen(aux); i++) {
		printf("%d", aux[i]);
	}

for(i=0;i<c;i++){
	num=aux[i];
	if(esPrimo(num)){
		printf("%d Es primo\n",num);
	}else{
		printf("%d No es primo\n",num);
	}
}
if(c==contador){
	printf("El array es especial");
}
}
int esPrimo(int num) {
	if (num == 0 || num == 1)
		return 0;
	if (num == 4)
		return 0;
	for (int x = 2; x < num / 2; x++) {
		if (num % x == 0)
			return 0;
	}
	return 1;
}
