#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>


const gchar *txt;
const gchar *temp;
const gchar *para_txt;
const gchar *op;
char cwd[1024];
GtkTextBuffer *buff;
GtkTextIter ei;

struct stat st = {0};

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
	else if((strcmp(txt,"mkdir"))==0){
		if(para_txt != NULL){
			printf("not null\n");
			op = "Error: not null";
			if (stat(para_txt, &st) == -1) {
    			mkdir(para_txt, 0700);
    			op = "Success: Folder successfully created";
			}else{
				op = "Error: File is already exists";
			}
			
		}
		else{
			printf("Null\n");
			op = "Error: Field is blank";
		}
	}
	else if((strcmp(txt,"rm"))==0){
		if(para_txt != NULL){
			int cheack;
			cheack = rmdir(para_txt);
   			if (!cheack){
      			op = "Directory deleted";
   			}
   			else{   
            op ="Unable to remove directory";
   			}
		}else{
			op = "Error: Field is blank";
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

void p_g_text(GtkWidget *para_ent,GtkWidget *nsignal){
	para_txt = txt = gtk_entry_get_text(GTK_ENTRY(para_ent));
}


int main(int argc,char *argv[]){

	GtkWidget *window,*fixed,*button,*entries,*para_entries,*txtview,*scrolledwindow;
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
	para_entries = gtk_entry_new();
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
  	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(p_g_text),para_entries);
  	g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(s_text),NULL);


	gtk_widget_set_size_request(entries,250,20);
	gtk_widget_set_size_request(para_entries,250,20);

	gtk_fixed_put(GTK_FIXED(fixed),button,300,30);
	gtk_fixed_put(GTK_FIXED(fixed),entries,50,10);
	gtk_fixed_put(GTK_FIXED(fixed),para_entries,50,50);

	gtk_container_add(GTK_CONTAINER(scrolledwindow),txtview);
	gtk_widget_set_size_request(scrolledwindow,300,250);

	gtk_fixed_put(GTK_FIXED(fixed),scrolledwindow,50,100);

	gtk_container_add(GTK_CONTAINER(window),fixed);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}

// gcc terminal.c $(pkg-config --cflags --libs gtk+-3.0) -o terminal
