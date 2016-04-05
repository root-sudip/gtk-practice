#include <gtk/gtk.h>
int main(int argc, char const *argv[])
{
	Gtk_window *window,*check;
	gtk_main();
	return 0;
}



///gcc entries.c $(pkg-config --cflags --libs gtk+-3.0) -o entries