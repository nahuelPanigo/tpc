#include "list.h"
#include "m_list.h"
#include "function.h"
#include "sitio.h"
#include "municipio.h"
#include <stdlib.h>
#include <string.h>


//lee y procesa el archivo csv
int reedArch(char *strArch,t_list *list){
	FILE *archivo;
	int error=0;
	sitio_t landfill;
	char buffer [1024];

	archivo = fopen(strArch,"r");
	fgets(buffer,1024,archivo);
	
	while((!feof(archivo))&&(!error)){
		fgets (buffer,1024,archivo);
		error=linea_csv_a_sitio_t(buffer,&landfill);
		if(!feof(archivo)){
			list_addInOrder(list,landfill);
		}
	}
	fclose(archivo);
	return error;
}


//escribe el archivo en el seleccionado para salida o en la salida std por defecto
int printArch(char *str,t_m_list *lm,t_list list,int municipio,int range,char *rangeFrom,char *rangeTo){
	float relativeGrade;
	float *range1;
	float *range2;
	range1=malloc(sizeof(float));
	range2=malloc(sizeof(float));
	FILE *arch;
	if((strcmp(str,""))!=0){
		arch= fopen(str,"w");
	}else{	
		arch=stdout;
	}

	if(municipio == 1){
		createListMun(list,lm); 
		relativeGrade = getRelativeGrade(list_m_calculateMax(*lm));
		if(range == 1 ){
			getRangeValues(rangeFrom,rangeTo,range1,range2);
			list_m_iterateRange(*lm,relativeGrade,*range1,*range2,arch,printMun);
		}else
			list_m_iterate(*lm,relativeGrade,arch,printMun);
	}else
		
	list_iterate(list,arch,printLandfill);
	fclose(arch);
	free(range1);
	free(range2);
return 0;
}