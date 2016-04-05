#include <gtk/gtk.h>
#include <stdio.h>


const gchar *txt;

void get_t(GtkWidget* entry,GtkWidget *newtext){
	/*gtk_main_quit();*/
	
	txt = gtk_entry_get_text(GTK_ENTRY(entry));
	//gtk_entry_set_text(GTK_ENTRY(p_text),txt);
	
	printf("%s \n",txt);
	/*g_print (txt);*/
	
}


void set_t(GtkWidget* entry,GtkWidget *newtext){
	/*gtk_main_quit();*/
	
	/*txt = gtk_entry_get_text(GTK_ENTRY(entry));*/
	gtk_entry_set_text(GTK_ENTRY(entry),txt);
	
	/*printf("%s \n",txt);*/
	/*g_print (txt);*/
	
}



int main(int argc, char *argv[])
{
	GtkWidget *window,*text,*button,*fixed,*p_text,*txtView;
	//

	//

	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window,400,200);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);

	text = gtk_entry_new();
	p_text = gtk_entry_new();
	txtView = gtk_text_view_new();
	//gtk_widget_set_size_request(txtView,80,80);

	//
			

	//



	button = gtk_button_new_with_mnemonic("Click");
	
	gtk_widget_set_size_request(button,40,20);

	
	fixed = gtk_fixed_new();

	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(get_t),text);

	//
	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(set_t),p_text);

	//

	gtk_fixed_put(GTK_FIXED(fixed),text,0,0);
	gtk_fixed_put(GTK_FIXED(fixed),button,180,2);
	gtk_fixed_put(GTK_FIXED(fixed),p_text,50,100);
	gtk_fixed_put(GTK_FIXED(fixed),txtView,50,120);


	gtk_container_add(GTK_CONTAINER(window),fixed);


	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}	



//gcc entries.c $(pkg-config --cflags --libs gtk+-3.0) -o entries