#include <gtk/gtk.h>
int main(int argc,char *argv[]){
	GtkWidget *window,*label;
	gtk_init(&argc,&argv);
	//initialized the resource or lib
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//create window
	gtk_window_set_title(GTK_WINDOW(window),"DEMO");
	//set tittle
	gtk_widget_set_size_request(window,400,200);
	//set window size
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	
	label = gtk_label_new("First name");
	//set label
	gtk_label_set_selectable(GTK_LABEL(label),FALSE);
	gtk_widget_set_size_request(label,100,100);
	gtk_container_add(GTK_CONTAINER(window),label);
	//set label size
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}


//gcc entries.c $(pkg-config --cflags --libs gtk+-3.0) -o entries
