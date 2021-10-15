/*
 ============================================================================
 Name        : Palindrono.c
 Author      : Gustavo Pérez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertirMinusculas(char str[100]);
void eliminaTildes(char str[100]);
void eliminaEspacios(char str[100]);
void esPalindromo(char* string);


int main(void) {
	   char str[100] = "Aji traga la lagartija";
	    printf("%s ", str);

	convertirMinusculas(str);
	eliminaTildes(str);
	eliminaEspacios(str);
	esPalindromo(str);

}



void convertirMinusculas(char str[100]){
	int i;
	int l=strlen(str);

	for(i=0;i<l;i++){
		str[i]=tolower(str[i]);
	}

}
void eliminaTildes(char str[100]){
	int L=strlen(str)-1;
	for(int i = 0; i < L; i++)

	{
		const char *string = &str[i];
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

		if((*string == iConAcento)||(*string == IConAcento)){
			str[i] = 'i';
		}else{
			if((*string == aConAcento)||(*string == AConAcento)){
				str[i]='a';
			}else{
				if((*string == eConAcento)||(*string == EConAcento)){
					str[i]='e';
				}else{
					if((*string == oConAcento)||(*string == OConAcento)){
						str[i]='o';
					}else{
						if((*string == uConAcento)||(*string == UConAcento)){
							str[i]='u';
						}
					}
				}
			}
		}

	}
}
void eliminaEspacios(char str[100]){
	int L=strlen(str)-1;
	int a=0, k=0;
	do{
		if(str[a]<'a'||str[a]>'z'){
			for(k=a;k<L;k++){
				str[k]=str[k+1];
			}
			L--;
		}
		a++;
	}while(str[a]!='\0');
	str[L+1]='\0';
}

void esPalindromo(char* string)
{
    char *ptr, *r;
    ptr = string;
    while (*ptr != '\0') {
        ++ptr;
    }
    --ptr;

    for (r = string; ptr >= r;) {
        if (*ptr == *r) {
            --ptr;
            r++;
        }
        else
            break;
    }

    if (r > ptr)
        printf("es Palindromo");
    else
        printf("no es Palindromo");
}
