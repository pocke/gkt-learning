#include <gtk-2.0/gtk/gtk.h>

static void  cb_button_clicked(GtkWidget *button, gpointer user_data) {
  gtk_main_quit();
}

int main(int argc, char** argv)
{
  GtkWidget *window;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request(window, 300, 200);

  GtkWidget *button;
  button = gtk_button_new_with_label("Quit");
  gtk_container_add(GTK_CONTAINER(window), button);

  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(cb_button_clicked), NULL);


  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

