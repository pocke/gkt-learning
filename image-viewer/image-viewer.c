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

/* vim: set path+=/usr/include/gtk-2.0,/usr/lib/gtk-2.0/include,/usr/include/pango-1.0,/usr/include/atk-1.0,/usr/include/cairo,/usr/include/pixman-1,/usr/include/libdrm,/usr/include/gdk-pixbuf-2.0,/usr/include/libpng16,/usr/include/pango-1.0,/usr/include/glib-2.0,/usr/lib/glib-2.0/include,/usr/include/freetype2,/usr/include/libpng16,/usr/include/harfbuzz,/usr/include/freetype2,/usr/include/libpng16,/usr/include/harfbuzz: */
