#ifndef _FUNCTION_H
	#define _FUNCTION_H
	#include "list.h"
	#include "m_list.h"

//transforma los rangos de string a flotante
void getRangeValues(char *rangeFrom,char *rangeTo,float *range1,float *range2);

//imprime la ayuda en pantalla
void printHelp();

//crea la lista de municipios a traves de la lista de basurales
void createListMun(t_list l,t_m_list *lm);

//inicializa el vector de flags y el vector de indice flags
void initializeArray(int vect1[],int dim1, int vect2[],int dim2);

#endif

