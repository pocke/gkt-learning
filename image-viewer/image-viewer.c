#include <gtk-2.0/gtk/gtk.h>
#include <stdlib.h>

static void  cb_button_clicked(GtkWidget *button, gpointer user_data) {
  gtk_main_quit();
}

int main(int argc, char** argv)
{

  // check arguments
  if (argc != 2) {
    g_print("Usage: %s image-file\n", argv[0]);
    exit(1);
  }

  gtk_init(&argc, &argv);

  // window
  GtkWidget *window;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request(window, 300, 200);


  // button
  GtkWidget *button;
  button = gtk_button_new_with_label("Quit");

  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(cb_button_clicked), NULL);


  // image
  GtkWidget *image;
  image = gtk_image_new_from_file(argv[1]);


  // vbox
  GtkWidget *vbox;
  vbox = gtk_vbox_new(FALSE, 2);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_box_pack_start(GTK_BOX(vbox), image,  TRUE,  TRUE,  0);
  gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);




  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

/* vim: set path+=/usr/include/gtk-2.0,/usr/lib/gtk-2.0/include,/usr/include/pango-1.0,/usr/include/atk-1.0,/usr/include/cairo,/usr/include/pixman-1,/usr/include/libdrm,/usr/include/gdk-pixbuf-2.0,/usr/include/libpng16,/usr/include/pango-1.0,/usr/include/glib-2.0,/usr/lib/glib-2.0/include,/usr/include/freetype2,/usr/include/libpng16,/usr/include/harfbuzz,/usr/include/freetype2,/usr/include/libpng16,/usr/include/harfbuzz: */
