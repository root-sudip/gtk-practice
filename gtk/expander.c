#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
	GtkWidget *window,*expander,*label;
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"DEmo");
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_widget_set_size_request(window,200,100);

	expander = gtk_expander_new_with_mnemonic("click here");
	label = gtk_label_new("Sudip is a gtk Developer.");

	
	gtk_container_add(GTK_CONTAINER(expander),label);
	gtk_expander_set_expanded(GTK_EXPANDER(expander),FALSE);	
	gtk_container_add(GTK_CONTAINER(window),expander);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}


//gcc entries.c $(pkg-config --cflags --libs gtk+-3.0) -o entries