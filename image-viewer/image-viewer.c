#include <gtk/gtk.h>
#include <stdlib.h>

// on open
static void cb_open(GtkAction *action, gpointer user_data)
{
  g_print("This function is not implemented yet.\n");
}

// on quit
static void cb_quit(GtkAction *action, gpointer user_data) 
{
  GObject *window = G_OBJECT(user_data);

  g_object_unref(g_object_get_data(window, "ui"));
  gtk_main_quit();
}


// menuの構造
static const gchar *menu_info =
  "<ui>"
  "  <menubar name='Menubar'>"
  "    <menu name='File' action='File'>"
  "      <menuitem name='Open' action='Open'/>"
  "      <separator/>"
  "      <menuitem name='Quit' action='Quit'/>"
  "    </menu>"
  "  </menubar>"
  "</ui>";

// menu item detail
static GtkActionEntry entries[] = {
  {"File", NULL, "_File"},
  {"Open", GTK_STOCK_OPEN, "_Open", "<control>O", "Open an image", G_CALLBACK(cb_open)},
  {"Quit", GTK_STOCK_QUIT, "_Quit", "<control>Q", "Quit this program", G_CALLBACK(cb_quit)},
};


// create menu function
static GtkUIManager* create_menu(GtkWidget *parent) {
  GtkUIManager *ui;
  ui = gtk_ui_manager_new();

  // Create Action Group
  GtkActionGroup *actions;
  actions = gtk_action_group_new("menu");

  gtk_action_group_add_actions(actions, entries,
      sizeof(entries) / sizeof(entries[0]),
      parent);
  gtk_ui_manager_insert_action_group(ui, actions, 0);
  gtk_ui_manager_add_ui_from_string(ui, menu_info, -1, NULL);
  // enable shortcut-keys
  gtk_window_add_accel_group(GTK_WINDOW(parent), gtk_ui_manager_get_accel_group(ui));

  return ui;
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
  gtk_widget_set_size_request(window, 400, 300);
  {
    // vbox
    GtkWidget *vbox;
    vbox = gtk_vbox_new(FALSE, 2);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    {
      // menu
      GtkUIManager *ui;
      GtkWidget *menubar;

      ui = create_menu(window);
      g_object_set_data(G_OBJECT(window), "ui", (gpointer)ui);
      menubar = gtk_ui_manager_get_widget(ui, "/Menubar");
      gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    }


    // scroll window
    GtkWidget *scroll_window;
    scroll_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(vbox), scroll_window,  TRUE,  TRUE,  0);

    {
      // image
      GtkWidget *image;
      image = gtk_image_new_from_file(argv[1]);


      gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scroll_window), image);
    }
  }


  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

/* vim: set path+=/usr/include/gtk-2.0,/usr/lib/gtk-2.0/include,/usr/include/pango-1.0,/usr/include/atk-1.0,/usr/include/cairo,/usr/include/pixman-1,/usr/include/libdrm,/usr/include/gdk-pixbuf-2.0,/usr/include/libpng16,/usr/include/pango-1.0,/usr/include/glib-2.0,/usr/lib/glib-2.0/include,/usr/include/freetype2,/usr/include/libpng16,/usr/include/harfbuzz,/usr/include/freetype2,/usr/include/libpng16,/usr/include/harfbuzz: */
