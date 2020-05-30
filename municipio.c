	#include "sitio.h"
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>
	#include "municipio.h"

char  *getMarkerMun(float relativeGrade,float munGrade){
	char *dotMarker;
	dotMarker=malloc(50*sizeof(char));
	
	//para setear el punto del municipio se fija a que grado relativo es menor
	if( munGrade < relativeGrade ){
		dotMarker=strcpy(dotMarker,"tan-dot");
		return dotMarker;
	}
	if( munGrade < (relativeGrade * 2) ){
		dotMarker=strcpy(dotMarker,"yellow-dot");
		return dotMarker;
	}
	if( munGrade < (relativeGrade * 3)){
		dotMarker=strcpy(dotMarker,"orange-dot");
		return dotMarker;
	}
		dotMarker=strcpy(dotMarker,"default-dot");
		return dotMarker;
}
 
float getRelativeGrade (int maxValue){
	return maxValue / 4;
}


void printMun(municipio_t mun,float gradeRelative,FILE *arch){
	char *dotMarker;
	char *strTipologia;

	//setea el string de tipologia
	strTipologia=getTipologia(mun.sitios_tipologia);
	//setea el punto de acuerdo al grado relaitvo del municipio
	dotMarker=getMarkerMun(gradeRelative,mun.grade_mun);
	//imprime en natalla o en un archivo de acuero a la string recibida
	fprintf(arch,"%s,%s{%s: %s}<%s>\n",mun.sitios_latitud,mun.sitios_longitud,strTipologia,mun.sitios_denominacion,dotMarker);
	free(dotMarker);
	free(strTipologia);
}
