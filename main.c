	#include<stdio.h>
	#include "function.h"
	#include "mygetopt.h"
	#include "list.h"
	#include "arch.h"
	#include <string.h>
	#include <stdlib.h>


int main(int argc,char *argv[]){
t_list list;
int flags[7];
int indiceFlag[7];
int error = 0;
t_m_list lm;
char str[50];

list=list_create();
lm=list_m_create();

//inicializa los vectores para ser usados por el getopt en obtainParam()
initializeArray(flags,7,indiceFlag,7);

//procesa los argumentos del programa devuelve las opciones a realizar y el error si es que hay
error = obtainParam(flags,argv,argc,"haml:R:s:",indiceFlag);

// si un error fue captado en el obtainParam termina la ejecucion retornando el error
if (error) {
	printHelp();
	return error;
}

//ante cualquier aparicion de opcion de ayuda finalizo mostrando la ayuda
if ( (flags[ayuda]==1) || (flags[help]==1) ) {
	printHelp();
	return 0;
}

//lee el archivo y lo carga en la lista ordenado por sitios id
if (error = reedArch(argv[indiceFlag[leer]],&list)) {
	return error;
}

//setea el string de salida
if(indiceFlag[salida]!=0){
	strcpy(str,argv[indiceFlag[salida]]);
}else{
	strcpy(str,"");
}

//imprime el archivo de la forma indicada de a cuerdo a los flags se le pasan los valores de rango ingresados en caso de haberlos
if (error = printArch(str,&lm,list,flags[municipio],flags[rango],argv[indiceFlag[rango]],argv[indiceFlag[rango+1]])) {
		return error;	
}

//elimino las listas y libero la memoria
list_delete(&list);
if(flags[municipio]==1)
	list_m_delete(&lm);

return 0;

}


