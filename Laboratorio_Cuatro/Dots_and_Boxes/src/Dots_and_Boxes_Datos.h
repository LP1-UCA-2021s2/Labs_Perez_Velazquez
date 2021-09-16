/*
 * Dots_and_Boxes_Datos.h
 *
 *  Created on: 3 sept. 2021
 *      Author: lp1-2021
 */

#ifndef DOTS_AND_BOXES_DATOS_H_
#define DOTS_AND_BOXES_DATOS_H_

#define TAM_TABLERO 	3


#define CASILLA_LIBRE	' '	// Caracter espacio
#define FICHA_A	'A' // jugador A
#define FICHA_B	'B' // Jugador B

#define linea1	'----'
#define lineab	'    '
#define dots	'*'
#define pilar1	'|'
#define pilarb	' '
/*
 * Tablero del Dots
 * Estructura de datos principal del programa.
 */
static char tablero[TAM_TABLERO][TAM_TABLERO];
/*
 * Tablero de punteros
 * cada elemento del tablero_punteros apunta a un array que tiene datos de las arista del elemento
  */

static int *tablero_punteros[TAM_TABLERO][TAM_TABLERO];

/* Se define un Array por cada celda del 'tablero'
 * Arrays de 4 elemntos que tiene datos de las  aristas
 * Ej: A_00{0,1,0,1} --> libre,ocupada,libre, ocupada
 * Ej: A_01{1,1,1,1} --> todas las aristas estas ya ocupadas
 * donde el indice 0 = dato de 'arista Top' 	(valores posibles 0 =libre, 1= ocupado)
 * 			indice 1 = dato de 'arista Bottom' 	(valores posibles 0 =libre, 1= ocupado)
 * 			indice 2 = dato de 'arista Left'	(valores posibles 0 =libre, 1= ocupado)
 * 			indice 3 = dato de 'arista Right'	(valores posibles 0 =libre, 1= ocupado)
 * */

/*variables globales*/
int A_00[4]={0,0,0,0};
 int A_01[4]={0,0,0,0};
int A_02[4]={0,0,0,0};

int A_10[4]={0,0,0,0};
 int A_11[4]={0,0,0,0};
int A_12[4]={0,0,0,0};

int A_20[4]={0,0,0,0};
 int A_21[4]={0,0,0,0};
int A_22[4]={0,0,0,0};

 int *ptr_00;
  int *ptr_01;
 int *ptr_02;

 int *ptr_10;
 int *ptr_11;
 int *ptr_12;

int *ptr_20;
int *ptr_21;
int *ptr_22;

/*
 * Final del juego
 */
static int contJugadas;


/*
 * Si se detecta el fin de la partida esta bandera se activa y en las verificaciones subsiguientes
 * informamos que la partida ya termino.
 */

static int bandFinPartido = 0;













#endif /* DOTS_AND_BOXES_DATOS_H_ */
