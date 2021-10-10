/*
 ============================================================================
 Name        : GTKTablero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in GTK+
 ============================================================================
 */

 #include <gtk/gtk.h>

#define MAX_FILA 4
#define MAX_COLUMNA 4

//Un vector de Strings, almacena ubicacion de imagenes
char *imagenes[] = {"./IMG/ficha_free.png"};


GtkWidget *label_turno;
GtkWidget *label_estado;
GtkWidget *tablero;

void tablero_cb(GtkWidget *event_box, GdkEventButton *event, gpointer data){
	guint i,j,pos;
	i = (GUINT_FROM_LE(event->y) / 100); //las imagenes tienen son 50x50pixeles
	j = (GUINT_FROM_LE(event->x) / 100);

	pos=(GUINT_FROM_LE(event->x) /4);

	gchar *temp = g_strdup_printf("Presiono la imagen coordenada [%d,%d,%d]", i,j,pos);

	gtk_label_set_text(GTK_LABEL(label_estado), temp);

 	int dado = rand() % 6;
 	temp = g_strdup_printf("Tiramos el dado y obtenemos: %d", dado + 1);
 	gtk_label_set_text(GTK_LABEL(label_turno), temp);

	if(dado + 1 > 3){
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(tablero),j,i)), "IMG/ficha_roja.png");
	}else{
		gtk_image_set_from_file(GTK_IMAGE(gtk_grid_get_child_at(GTK_GRID(tablero),j,i)), "IMG/ficha_negra.png");
	}

	g_free(temp);

}


GtkWidget *crear_tablero(){
	int i, j;
	GtkWidget *imagen; //auxiliar para cargar la imagen

	GtkWidget *eventbox;
	eventbox = gtk_event_box_new();
	tablero = gtk_grid_new();
	for (i = 0; i < MAX_FILA; i++) {
		for (j = 0; j < MAX_COLUMNA; j++) {
				imagen = gtk_image_new_from_file(imagenes[(i+j) % 1]);
				gtk_grid_attach(GTK_GRID(tablero), GTK_WIDGET(imagen), j, i, 1, 1);
			//	imagenPosicion = gtk_image_new_from_file(imagenes[(i+j) % 1]);
		}
	}
	gtk_container_add(GTK_CONTAINER(eventbox), tablero);
	g_signal_connect(eventbox, "button-press-event", G_CALLBACK(tablero_cb), tablero);
	return eventbox;
}


void cerrar (GtkWidget *object, gpointer   user_data){
	 printf("saludo: %s", (char*)user_data);
	 gtk_main_quit();
}

 int main (int argc, char *argv[])
 {
    GtkWidget *window;
    GtkWidget *box_tablero;

    //Para el GtkBuilder
    guint ret;
    GtkBuilder *builder;
    GError *error = NULL;

    gtk_init (&argc, &argv);

	builder = gtk_builder_new();
	//Se carga el builder
	ret = gtk_builder_add_from_file(builder, "tablero.glade", &error);
	if (ret == 0) {
		g_print("Error en la función gtk_builder_add_from_file:\n%s", error->message);
		return 1;
	}

	//Ventana principal
	window = GTK_WIDGET(gtk_builder_get_object(builder, "ventana"));

	//Box donde estara el Tablero
	box_tablero = GTK_WIDGET(gtk_builder_get_object(builder, "box_tablero"));

	//Labels
	label_turno = GTK_WIDGET(gtk_builder_get_object(builder, "label_turno"));
	label_estado = GTK_WIDGET(gtk_builder_get_object(builder, "label_estado"));

	gtk_box_pack_start(GTK_BOX(box_tablero), crear_tablero(), TRUE, FALSE, 20);

    /* Connect the destroy signal of the window to gtk_main_quit
     * When the window is about to be destroyed we get a notification and
     * stop the main GTK+ loop
     */
	char mensaje[20] = "hola que tal";
    g_signal_connect (window, "destroy", G_CALLBACK (cerrar), mensaje);

    /* make sure that everything, window and label, are visible */
    gtk_widget_show_all (window);

    /* start the main loop, and let it rest there until the application is closed */
    gtk_main ();

    return 0;
 }


