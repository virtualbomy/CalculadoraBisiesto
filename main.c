#include <gtk/gtk.h>
#include <stdlib.h>

extern long calcularBisiesto(long numero);  //Declara la función de ensamblador

// Función para mostrar un popup con el resultado del cálculo según el valor de 'result'
void resultadoFinal(int result, GtkBuilder *builder) {
    GtkWidget *popupWindow;
    if (result == 0) {
        //Si el resultado es 0 se muestra la ventana de año bisiesto
        popupWindow = GTK_WIDGET(gtk_builder_get_object(builder, "ventana2"));
    } else if (result == 1) {
        //Si el resultado es 1 se muestra la ventana de año no bisiesto
        popupWindow = GTK_WIDGET(gtk_builder_get_object(builder, "ventana3"));
    } else { return; /*No hace nada si el resultado es diferente a 0 o 1*/ }

    gtk_widget_show_all(popupWindow);
}

//Se llama al hacer clic en el botón principal para visualizar el resultado
void numeroIngresado(GtkButton *button, gpointer user_data) {
	gpointer *data = (gpointer *)user_data;
    GtkEntry *entry = GTK_ENTRY(data[0]);
    GtkBuilder *builder = GTK_BUILDER(data[1]);
    
    //Recibe y guarda el número ingresado en la entrada como caracter 
	//y lo convierte a long
    const gchar *text = gtk_entry_get_text(entry);
    char *fin;
    long entrada = strtol(text, &fin, 10);
    //Número con el que se van a realizar los cálculos
    long numero = 0;
    //Variable que valida el resultado final
    int result = 0;

    //Verifica la conversión del número y valida el dato
    if (*fin != '\0' || entrada < 1581) {
       g_print("Digite un año mayor o igual a 1582.\n");
    } else {
        //Se guarda la entrada del usuario en la variable número después de ser validada
		numero = entrada;

        //Se llama la funcion de ensamblador
        //result = calcularBisiesto(numero);

        // Llamar a la función para mostrar la ventana adecuada
		resultadoFinal(result, builder);
    }
}


void cerrarPopUp(GtkButton *button, gpointer user_data) {
    GtkWidget *popupWindow = GTK_WIDGET(user_data);
    gtk_widget_destroy(popupWindow);
}


int main(int argc, char *argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;

    gtk_init(&argc, &argv);

    //Cargar el archivo .glade
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "Menu.glade", NULL);

    //Ventana principal
    window = GTK_WIDGET(gtk_builder_get_object(builder, "ventana1"));
    
    //Título de la ventana
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora Año Bisiesto");

    //Señal de clic del botón
    GtkButton *button = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    GtkEntry *entry = GTK_ENTRY(gtk_builder_get_object(builder, "entry1"));

    //Usamos un puntero a un arreglo para pasar múltiples datos a la señal
    gpointer data[2] = {entry, builder};
    g_signal_connect(button, "clicked", G_CALLBACK(numeroIngresado), data);

    //Conectar botones de cierre de ventana2 y ventana3
    GtkButton *closeButtonVentana2 = GTK_BUTTON(gtk_builder_get_object(builder, "popup1button1"));
    GtkButton *closeButtonVentana3 = GTK_BUTTON(gtk_builder_get_object(builder, "popup2button1"));

    //Conectar las señales de clic a los botones de cierre
    g_signal_connect(closeButtonVentana2, "clicked", G_CALLBACK(cerrarPopUp), GTK_WIDGET(gtk_builder_get_object(builder, "ventana2")));
    g_signal_connect(closeButtonVentana3, "clicked", G_CALLBACK(cerrarPopUp), GTK_WIDGET(gtk_builder_get_object(builder, "ventana3")));

    //Señal de cerrar la ventana principal
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Mostrar ventana
    gtk_widget_show_all(window);

    gtk_main();

    g_object_unref(builder);
    return 0;
}

