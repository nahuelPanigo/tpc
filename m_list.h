#ifndef _T_M_LIST_H
	#define _T_M_LIST_H
	#include "municipio.h"
	#include <stdio.h>

typedef struct t_m_node{
	municipio_t data;
	struct t_m_node *next;	
}t_m_node;

typedef struct t_m_node *t_m_list;

//crea una lista
t_m_list list_m_create();

//devuelve verdadero(>0) si la lista esta vacia falso(0) caso contrario
int list_m_empty(t_m_list l);

//agreaga atras en la lista
void list_m_addBack(t_m_list *l,municipio_t data);

//elimina las lista y libera los nodos
void list_m_delete(t_m_list *l);

//muestra el contenido de toda la lista
void list_m_show(t_m_list l);

//agrega municipio por orden
void list_m_addInOrder(t_m_list *l ,municipio_t data);

//calcula el municipio con mayor grado
int list_m_calculateMax(t_m_list l);

//itera sobre la lista con una funcion de imprimir determinada.
void list_m_iterate(t_m_list l,float relativeGrade,FILE *,void (printFunction)(municipio_t,float,FILE *));

//itera sobre la lista con una funcion de imprimir que solo imprimira los que esten dentro del rango 
void list_m_iterateRange(t_m_list l,float relativeGrade,float range1,float range2,FILE *arch,void (printMun)(municipio_t,float,FILE *));

#endif