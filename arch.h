#ifndef _ARCH_H
	#define _ARCH_H

//lee y procesa el archivo csv
int reedArch(char *str,t_list *list);

//escribe el archivo en el seleccionado para salida o en la salida std por defecto
int printArch(char *str,t_m_list *lm,t_list list,int municipio,int range,char *rangeFrom,char *rangeTo);

#endif