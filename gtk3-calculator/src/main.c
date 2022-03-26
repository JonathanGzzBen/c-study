#include <gtk/gtk.h>
#include <stdio.h>

G_MODULE_EXPORT void print_hello() {
  puts("hello");
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkBuilder *gtkBuilder = gtk_builder_new();
  gtk_builder_add_from_file(gtkBuilder, "ui/calculator.glade", NULL);
  GtkWidget *window =
      GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "main-window"));
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  GtkTextView *operationTextView = GTK_TEXT_VIEW(gtk_builder_get_object(gtkBuilder, "operation"));
  GtkTextBuffer *textBuffer = gtk_text_view_get_buffer(operationTextView);
  gtk_text_buffer_set_text(textBuffer, "000000", -1);

  GtkTextView *prev_operation_text_view = GTK_TEXT_VIEW(gtk_builder_get_object(gtkBuilder, "prev-operation"));
  GtkTextBuffer *prev_operation_text_buffer = gtk_text_view_get_buffer(prev_operation_text_view);
  gtk_text_buffer_set_text(prev_operation_text_buffer, "000000", -1);

  gtk_builder_connect_signals(gtkBuilder, NULL);

  GtkCssProvider *cssProvider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(cssProvider, "gtk-calculator.css", NULL);
  GdkScreen* screen = gtk_widget_get_screen(window);
  gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

  gtk_widget_show(window);
  gtk_main();
  return 0;
}