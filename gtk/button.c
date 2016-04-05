#include <gtk/gtk.h>

void destroy(GtkWidget* label,GtkWidget *labelo,GtkWidget *labela){
	/*gtk_main_quit();*/
	g_print ("hide\n");
	gtk_widget_show(label);
}

int main(int argc, char *argv[])
{
	GtkWidget *window,*button,*label,*fixed,*fixednew;

	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Demo");
	gtk_widget_set_size_request(window,200,400);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	
	fixed = gtk_fixed_new();
	/*fixednew=gtk_fixed_new();*/

	button = gtk_button_new_with_mnemonic("Click");
	gtk_widget_set_size_request(button,20,20);

	label = gtk_label_new("BOOM!!");
	

	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(destroy),label);

	gtk_fixed_put(GTK_FIXED(fixed),button,0,0);
	gtk_fixed_put(GTK_FIXED(fixed),label,30,30);

	gtk_container_add(GTK_CONTAINER(window),fixed);
	/*gtk_container_add(GTK_CONTAINER(window),fixednew);*/
	
	gtk_widget_show_all(window);
	gtk_widget_hide(label);
	
	gtk_main();
	return 0;
}


///gcc entries.c $(pkg-config --cflags --libs gtk+-3.0) -o entries