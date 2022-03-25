#include <gtk/gtk.h>
#include <stdio.h>

G_MODULE_EXPORT void print_hello(GtkButton *self, gpointer user_data) {
  puts("hello");
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkBuilder *gtkBuilder = gtk_builder_new();
  gtk_builder_add_from_file(gtkBuilder, "ui/calculator.glade", NULL);
  GtkWidget *window =
      GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "mywindow"));
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(gtkBuilder, NULL);
  gtk_widget_show(window);
  gtk_main();
  return 0;
}