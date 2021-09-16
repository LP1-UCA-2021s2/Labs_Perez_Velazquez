/*
 ============================================================================
 Name        : Dots_and_Boxes.c
 Author      : Gustavo Pérez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Dots_and_Boxes_Datos.h"

 #include <gtk/gtk.h>


void inicializar_tablero(void);
void inicializar_tablero_punteros(void);
void imprimir_tablero(void);
int validar(char ficha,int f,int c);
void jugar(void);
// void colocaFicha(ficha, f, c);
 void mostrarResultado();
 int finPartido();


 int main(int argc, char *argv[]) {
//	inicializar_tablero();
//	inicializar_arrays();
//	inicializar_tablero_punteros();
//	imprimir_tablero();
	//jugar();

	 GtkWidget *window;
		 GtkBuilder *builder;
		 GError *error = NULL;

		 gtk_init (&argc, &argv);

		 builder = gtk_builder_new();
		 //Se carga el builder
		 if (gtk_builder_add_from_file(builder, "juego.glade", &error) == 0) {
			g_print("Error en la función gtk_builder_add_from_file:\n%s", error->message);
			return 1;
		 }

		 //Ventana principal
		 window = GTK_WIDGET(gtk_builder_get_object(builder, "win_principal"));
		 g_signal_connect (window, "destroy", gtk_main_quit, NULL);

		 gtk_widget_show_all (window);
		 gtk_main();

		 return 0;
}

void inicializar_tablero(void) {
	int i, j;

	for (i = 0; i < TAM_TABLERO; i++)
		for (j = 0; j < TAM_TABLERO; j++) {
			tablero[i][j] = CASILLA_LIBRE;
		}
}

void inicializar_arrays(void) {
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++) {

			ptr_00= A_00;


			ptr_01= A_01;


			ptr_02= A_02;


			ptr_10= A_10;


			ptr_11= A_11;

			ptr_12= A_12;


			ptr_20= A_20;


			ptr_21= A_21;


			ptr_22= A_22;
		}
}

void inicializar_tablero_punteros(void) {
	int i, j;

	for (i = 0; i < TAM_TABLERO; i++)
		for (j = 0; j < TAM_TABLERO; j++) {




		}
}

void imprimir_tablero(void) {

	printf("\n   \n");
	printf("\n    \n");


			printf("%s\n","*    *    *    *");
			printf("%s\n","*    *    *    *");
			printf("%s\n","*    *    *    *");


}

void jugar(void){

    // Primer juego para el jugador de FICHA_A
    char ficha = FICHA_A;
    /* mientras la FUNCION finPartido sea 0 =FALSE */
    while (!finPartido())   {
    	  // variables para posición de la ficha
		  int fila = 0;
		  int col = 0;

		  // variable validaCasilla (0= Posicion Incorrecta, o 1=Posicion correcta) que verifica si la ficha ingresada esta en posicion correcta
		  int valido = 0;

		  // Ciclo que pide ingresar la fila y la columna de la ficha
		  do{
			  printf("\nJUEGA FICHA  %c, Ingrese Fila,Columna:" ,ficha);
			  scanf("%d, %d",&fila,&col);
			   	  //valida lo ingresado 0 falso, 1 posicion valida
			  	  valido = validar(ficha, fila, col);

		  }while(valido==0);


		  //   coloca la ficha en la fila, columna
		//  colocaFicha(ficha, fila, col);
		  imprimir_tablero();

		  //juega la computadora
		//  jugarComputadora();

		  // cambia el jugador
		 if (ficha == FICHA_A) {
			   ficha= FICHA_B;
		 } else {
				ficha= FICHA_A;
		 }

		} //fin while finPartido

		// muestra resultado Final
		mostrarResultado();

  }

int finPartido(){
	return 0;
}
int validar(char ficha,int f,int c){
return 0;
}
 /*void colocaFicha(ficha, f, c){

	}*/
 void mostrarResultado(){

 }

