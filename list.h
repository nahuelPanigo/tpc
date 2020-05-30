#ifndef _T_LIST_H
	#define _T_LIST_H

#include "sitio.h"
#include <stdio.h>

typedef struct t_node{
	sitio_t data;
	struct t_node *next;	
}t_node;

typedef struct t_node *t_list;

//crea una lista
t_list list_create();

//devuelve verdadero(>0) si la lista esta vacia falso(0) caso contrario
int list_empty(t_list l);

//agrega elemento en forma ordenada
void list_addInOrder(t_list *l ,sitio_t data);

//elimina las lista y libera los nodos
void list_delete(t_list *l);

//imprime toda la lista con un formato
void list_show(t_list l);

//itera sobre la lista de basurales imprimiendolos en pantalla o en su defecto en el archivo de salida
void list_iterate(t_list l,FILE *arch,void (printLandfill)(sitio_t,FILE *));

#endif