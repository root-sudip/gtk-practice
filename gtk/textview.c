#include<gtk/gtk.h>

int main(int argc, char* argv[])
{
    GtkWidget *textview, *window, *scrolledwindow,*fixed,*button;
    GtkTextBuffer *buffer;

    gtk_init(&argc, &argv); /*void gtk_init (int *argc,char ***argv);*/
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    gchar* sample_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,\n" \
        "sed do eiusmod tempor incididunt ut labore et dolore magna\n" \
        "aliqua. Ut enim ad minim veniam, quis nostrud exercitation\n" \
        "ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"\
        "Duis aute irure dolor in reprehenderit in voluptate velit\n"\
        "esse cillum dolore eu fugiat nulla pariatur. Excepteur sint\n"\
        "occaecat cupidatat non proident, sunt in culpa qui officia\n"\
        "deserunt mollit anim id est laborum.";
        fixed = gtk_fixed_new();
        button = gtk_button_new_with_mnemonic("Click");

    textview = gtk_text_view_new();
    //gtk_widget_set_size_request(textview, 400, 200); // This is but a request. The sizes are not guaranteed.
    scrolledwindow = gtk_scrolled_window_new(NULL, NULL); 

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
    gtk_text_buffer_set_text(buffer, sample_text, -1);

    gtk_container_add(GTK_CONTAINER(scrolledwindow), textview);
    gtk_fixed_put(GTK_FIXED(fixed),scrolledwindow,0,0);
    gtk_widget_set_size_request(scrolledwindow, 100, 100);
    gtk_fixed_put(GTK_FIXED(fixed),button,100,100);
    gtk_container_add(GTK_CONTAINER(window), fixed);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}