#include "function.h"
	#include <string.h>
	#include <stdio.h>
	#include "list.h"
	#include "m_list.h"
	#include "sitio.h"

void initializeArray(int vect1[],int dim1,int vect2[],int dim2){
for (int i=0;i<dim1;i++){
	vect1[i]=0;
}
for (int i=0;i<dim2;i++){
	vect2[i]=0;
}
}

void getRangeValues(char *rangeFrom,char *rangeTo,float *range1,float *range2){
	sscanf(rangeFrom,"%f",range1);
	sscanf(rangeTo,"%f",range2);
}

void printHelp(){
	printf("-h|-a|--help|--ayuda:Muestra que argumentos admite el programa con una ayuda breve para cada uno.\n");
	printf("-l|--leer archivo:Carga el archivo CSV de nombre “archivo”.\n");
	printf ("-s|--salida archivo:Indica el nombre del archivo donde se generar  la secuencia de puntos.\n");
	printf ("-m|--municipio:Indica que se generara un unico punto por cada municipio.\n");
	printf("-R|--rango:debe haberse ingresado la opcion -m e indicara los municpios que se imprimiran de acuerdo al rango ingresado.\n");
	printf("\n");
}

//setea el municipio con los datos del basural que llega como parametro
void setMun(sitio_t landfill,municipio_t *mun){
	mun->municipios_id=landfill.municipios_id;
	mun->sitios_tipologia=landfill.sitios_tipologia;
	strcpy((mun->sitios_id),(landfill.sitios_id));
	strcpy((mun->sitios_denominacion),(landfill.sitios_denominacion));
	strcpy((mun->sitios_latitud),(landfill.sitios_latitud));
	strcpy((mun->sitios_longitud),(landfill.sitios_longitud));
	mun->grade_mun=0;
}


void createListMun(t_list l,t_m_list *lm){
	while(!list_empty(l)){
		municipio_t mun;
		setMun((l->data),&mun);
		while((!list_empty(l))&&(mun.municipios_id == (l->data).municipios_id)){
			mun.grade_mun=mun.grade_mun+((l->data).sitios_tipologia)+1;
			l=l->next;
		}
		list_m_addInOrder(lm,mun);
	}
}


