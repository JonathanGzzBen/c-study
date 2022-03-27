#include <ctype.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

GtkTextBuffer *operation_text_buffer;

GtkTextBuffer *prev_operation_text_buffer;

static int operator1;
static int operator2;
static char operand;
static double result;

static void reset_parameters() {
  operator1 = 0;
  operator2 = 0;
  operand = '\0';
  result = 0;
}

static void clear_screen() {
  reset_parameters();
  gtk_text_buffer_set_text(prev_operation_text_buffer, "0", -1);
  gtk_text_buffer_set_text(operation_text_buffer, "0", -1);
}

G_MODULE_EXPORT void on_pressed_button(GtkButton *self, gpointer user_data) {
  const gchar *label = gtk_button_get_label(self);
  if (strncmp(label, "CE", 2) == 0) {
    clear_screen();
    return;
  } else if (strncmp(label, "C", 1) == 0) {
    reset_parameters();
    gtk_text_buffer_set_text(operation_text_buffer, "0", -1);
    return;
  }
  if (strncmp(label, "=", 1) == 0 && operand != '\0') {
    switch (operand) {
      case '+':
        result = operator1 + operator2;
        break;
      case '-':
        result = operator1 - operator2;
        break;
      case '*':
        result = operator1 * operator2;
        break;
      case '/':
        result = (double)operator1 / operator2;
        break;
      case '%':
        result = operator1 % operator2;
        break;
      default:
        clear_screen();
    }
  }
  gtk_text_buffer_set_text(operation_text_buffer, label, -1);
  static char screen[50];
  if (isdigit(label[0])) {
    if (result != 0) {
      gtk_text_buffer_set_text(prev_operation_text_buffer, screen, -1);
      reset_parameters();
    }
    if (operand == '\0') {
      operator1 = atoi(label);
    } else {
      operator2 = atoi(label);
    }
  } else if (label[0] != '=') {
    operand = label[0];
  }
  if (result != 0) {
    sprintf(screen, "%d %c %d = %lf", operator1, operand, operator2, result);

  } else if (operand == '\0') {
    sprintf(screen, "%d", operator1);
  } else {
    sprintf(screen, "%d %c %d", operator1, operand, operator2);
  }
  gtk_text_buffer_set_text(operation_text_buffer, screen, -1);
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkBuilder *builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "ui/calculator.glade", NULL);
  GtkWidget *main_window =
      GTK_WIDGET(gtk_builder_get_object(builder, "main-window"));
  g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  GtkTextView *operation_text_view =
      GTK_TEXT_VIEW(gtk_builder_get_object(builder, "operation"));
  operation_text_buffer = gtk_text_view_get_buffer(operation_text_view);
  clear_screen();

  GtkTextView *prev_operation_text_view =
      GTK_TEXT_VIEW(gtk_builder_get_object(builder, "prev-operation"));
  prev_operation_text_buffer =
      gtk_text_view_get_buffer(prev_operation_text_view);
  gtk_text_buffer_set_text(prev_operation_text_buffer, "000000", -1);

  gtk_builder_connect_signals(builder, NULL);

  GtkCssProvider *css_provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(css_provider, "gtk-calculator.css", NULL);
  GdkScreen *screen = gtk_widget_get_screen(main_window);
  gtk_style_context_add_provider_for_screen(screen,
                                            GTK_STYLE_PROVIDER(css_provider),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);

  gtk_widget_show(main_window);
  gtk_main();
  return 0;
}