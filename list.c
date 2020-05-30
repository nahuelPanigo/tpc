 #include "list.h"
 #include "stdio.h"
 #include <stdlib.h>
 #include <string.h>


t_list list_create(){

	return (t_list )NULL;
}


int list_empty(t_list l){

	return (l == NULL);
}


void list_addInOrder(t_list *l ,sitio_t data){
	t_list new =(t_list)malloc(sizeof(t_node));
	new->data=data;
	t_list ant= *l;
	t_list act= *l;
	while((!list_empty(act))&&(strcmp(act->data.sitios_id,data.sitios_id))<0){
		ant = act;
		act =act->next;
	}
	if(ant == act){
		*l=new;
	}else
		ant->next=new;
	new->next=act;
}

void list_show(t_list l){
	sitio_t landfill;
	while((!list_empty(l))){
		landfill= l->data;
		printf("%s,%s{%s}\n",landfill.sitios_latitud,landfill.sitios_longitud,landfill.sitios_denominacion);
		l=l->next;
	}
}


void list_delete(t_list *l){
	if (!list_empty((*l)->next)){
		list_delete(&((*l)->next));
	}
	free((*l));
}

void list_iterate(t_list l,FILE * arch,void (printLandfill)(sitio_t,FILE *)){
	while(!list_empty(l)){
		printLandfill(l->data,arch);
		l=l->next;
	}
}
