#include <gtk/gtk.h>

//Guarda el texto ingresaado en una variable, (lo imprime en la terminal)
void textoIngresado(GtkButton *button, gpointer user_data) {
    GtkEntry *entry = GTK_ENTRY(user_data);
    const gchar *text = gtk_entry_get_text(entry);
    g_print("Número ingresado: %s\n", text);
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

    //Señal de clic del botón
    GtkButton *button = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    GtkEntry *entry = GTK_ENTRY(gtk_builder_get_object(builder, "entry1"));
    g_signal_connect(button, "clicked", G_CALLBACK(textoIngresado), entry);

    //Señal de cerrar la ventana
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Mostrar ventana
    gtk_widget_show_all(window);

    gtk_main();

    g_object_unref(builder);
    return 0;
}

