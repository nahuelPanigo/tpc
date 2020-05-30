#ifndef _MUNICIPIO_H
	#define _MUNICIPIO_H
	#include<stdio.h>

typedef struct {
int grade_mun;
char sitios_id[9];
int municipios_id;
char sitios_latitud[20];
int sitios_tipologia;
char sitios_longitud[20];
char sitios_denominacion[200];
}municipio_t;


//devuelve el tipo de punto que es segun el grado relativo del municipio
char  *getMarkerMun(float relativeGrade,float munGrade);

//devuelve el grado relativo 
float getRelativeGrade (int maxValue);

//escribe en una linea el basural a ser cargado en el archivo con el formato correspondiente con el parametro municipio 
void printMun(municipio_t mun,float gradeRelative,FILE * arch);

#endif