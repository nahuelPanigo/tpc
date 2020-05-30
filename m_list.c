 #include "m_list.h"
 #include "stdio.h"
 #include <stdlib.h>
#include <string.h>



t_m_list list_m_create(){
	
	return (t_m_list)NULL;
}


int list_m_empty(t_m_list l){

	return (l == NULL);
}

void list_m_addInOrder(t_m_list *l ,municipio_t data){
	t_m_list new =(t_m_list)malloc(sizeof(t_m_node));
	new->data=data;
	t_m_list ant= *l;
	t_m_list act= *l;
	while((!list_m_empty(act))&&(strcmp(((act->data).sitios_id),(data.sitios_id))<0)){
		ant = act;
		act =act->next;
	}
	if(ant == act){
		*l=new;
	}else
		ant->next=new;
	new->next=act;
}


void list_m_addBack(t_m_list *l ,municipio_t data){
	t_m_list new=(t_m_list)malloc(sizeof(t_m_node));
	new->data=data;
	new->next=NULL;
	t_m_list act = *l;
	if(l==NULL){
		*l=new;
	}else{
		while(!list_m_empty(act->next)){
			act =act->next;
		}
		act->next=new;
	}
}




void list_m_delete(t_m_list *l){
	if (!list_m_empty((*l)->next)){
		list_m_delete(&((*l)->next));
	}
	free((*l));
}



int list_m_calculateMax(t_m_list l){
	int max=-1;
	while(!list_m_empty(l)){
		if((l->data).grade_mun > max){
			max=(l->data).grade_mun;
		}
		l=l->next;
	}	
	return max;
}

void list_m_iterate(t_m_list l,float relativeGrade,FILE *arch,void (printFunction)(municipio_t,float,FILE *)){
		while(!list_m_empty(l)){
			printFunction(l->data,relativeGrade,arch);
			l=l->next;
		}
}


void list_m_show(t_m_list l){
	while(!list_m_empty(l)){
		printf("grado: %d  municipio id :%s \n",(l->data).grade_mun,(l->data).sitios_id);
		l=l->next;
	}
}


void list_m_iterateRange(t_m_list l,float relativeGrade,float range1,float range2,FILE *arch,void (printMun)(municipio_t,float,FILE *)){
	while(!list_m_empty(l)){
			if((range1 < (l->data).grade_mun)&&(range2 > (l->data).grade_mun)){
				printMun(l->data,relativeGrade,arch);
			}
			l=l->next;
		}
}