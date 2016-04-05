#include <gtk/gtk.h>

static GtkWidget 
    *main_window, 
    *scrolled_window, 
    *text_view;

static int count = 0;

gint
add_text(gpointer data)
{
    GtkTextBuffer *text_buffer = gtk_text_view_get_buffer(
            GTK_TEXT_VIEW(text_view));

    GtkTextIter text_iter;
    gtk_text_buffer_get_end_iter(text_buffer, &text_iter);

    if (count == 0) {
        gtk_text_buffer_insert(text_buffer, &text_iter, "First line\n", -1);
    }
    else if (count % 5 == 0) {
        gtk_text_buffer_insert(text_buffer, &text_iter, "world\n", -1);
    }
    else {
        gtk_text_buffer_insert(text_buffer, &text_iter, "hello\n", -1);
    }

    count++;

    /* - - DOES NOT WORK LIKE I EXPECT */
    GtkTextMark *mark = gtk_text_buffer_get_insert(text_buffer);
    gtk_text_buffer_move_mark(text_buffer, mark, &text_iter);
    gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(text_view), mark, 0.0,
        FALSE, 0, 0);
    /* - - */

    return TRUE;
}

int
main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(main_window), 200, 200);
    gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
            GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);

    text_view = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);

    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window),
            text_view);

    gtk_container_add(GTK_CONTAINER(main_window), scrolled_window);

    g_signal_connect(G_OBJECT(main_window), "delete_event",
            G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(G_OBJECT(main_window), "destroy",
            G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(main_window);

    g_timeout_add(500, add_text, NULL);

    gtk_main();

    return 0;
}
