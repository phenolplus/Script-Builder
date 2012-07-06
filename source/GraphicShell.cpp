#include <iostream>
#include <gtk/gtk.h>

#include "GraphicShell.h"

GraphicShell::GraphicShell(int argc, char** argv) {
    GtkWidget *window;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello！ GTK+！");
    g_signal_connect(GTK_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(window);
    gtk_main();

}
