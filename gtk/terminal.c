#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <error.h>

const gchar *txt;
const gchar *op;
char cwd[1024];
GtkTextBuffer *buff;
GtkTextIter ei;
void g_text(GtkWidget *ent,GtkWidget *view){
	txt = gtk_entry_get_text(GTK_ENTRY(ent));
	int rv;
	
	if((strcmp(txt,"pwd"))==0){
		
		
		if((getcwd(cwd,sizeof(cwd)))!= NULL){
			/*op = cwd;*/
			op = getcwd(cwd,sizeof(cwd));
			printf("%s\n", op);
		}
	}
	else{
		printf("Error:command not found\n");
		op = "Error: command not found";
	}
}

void s_text(GtkWidget *txtv, GtkWidget *sig){
	gtk_text_buffer_get_end_iter(buff, &ei);
	gtk_text_buffer_insert(buff, &ei,op, -1);
	gtk_text_buffer_insert(buff, &ei,"\n", -1);
}


int main(int argc,char *argv[]){

	GtkWidget *window,*fixed,*button,*entries,*txtview,*scrolledwindow;
	//GtkTextBuffer *buff;
	gchar *sample = "This is textview";
	
	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Terminal");
	gtk_widget_set_size_request(window,400,400);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	fixed = gtk_fixed_new();
	button = gtk_button_new_with_mnemonic("CLick");
	entries = gtk_entry_new();
	txtview = gtk_text_view_new();
	scrolledwindow = gtk_scrolled_window_new(NULL,NULL);
	buff = gtk_text_view_get_buffer(GTK_TEXT_VIEW(txtview));
	/*gtk_text_buffer_set_text(buff,sample,-1);
	*/
	//
		/*gtk_text_buffer_get_end_iter(buff, &ei);
  		gtk_text_buffer_insert(buff, &ei,sample, -1);
  		gtk_text_buffer_insert(buff, &ei,"\n", -1);
  		gtk_text_buffer_insert(buff, &ei,sample, -1);
*/
	//


  	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(g_text),entries);
  	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(s_text),NULL);


	gtk_widget_set_size_request(entries,250,20);

	gtk_fixed_put(GTK_FIXED(fixed),button,300,10);
	gtk_fixed_put(GTK_FIXED(fixed),entries,50,10);

	gtk_container_add(GTK_CONTAINER(scrolledwindow),txtview);
	gtk_widget_set_size_request(scrolledwindow,300,250);

	gtk_fixed_put(GTK_FIXED(fixed),scrolledwindow,50,100);

	gtk_container_add(GTK_CONTAINER(window),fixed);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}

// gcc terminal.c $(pkg-config --cflags --libs gtk+-3.0) -o terminal
