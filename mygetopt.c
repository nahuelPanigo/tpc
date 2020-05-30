	#include "mygetopt.h"
	#include <stdio.h>
	#include "function.h"
	#include <string.h>


//abre el archivo fijandose que tenga permisos para ejecutar la accion que llega como parametro
int checkArch(char *archName, char *param){
	FILE *archL;
	archL=fopen(archName,param);
	if(archL==NULL){
		puts("error en la apertura del archivo");
		return NO_ABRE_ARCH_L;
	}
	fclose(archL);
	return 0;
}


//se fija si el argumento que llega como parametro no es una de las opciones valida de ayuda
int isHelp(char *option){
	if(((strcmp(option,"-h"))==0)||((strcmp(option,"-a"))==0)||((strcmp(option,"--help"))==0)||((strcmp(option,"--ayuda"))==0))
		return 1;	
	return 0;	
}


//si los valores de rango ingresados no son numeros o estan fuera de los permitidos devuelve error
int checkValRange (char *rangeFrom,char *rangeTo){
	float num1,num2;

	int error1=0,error2=0;
	
	error1=sscanf(rangeFrom,"%f",&num1);
	error2=sscanf(rangeTo,"%f",&num2);
	if((error1 != 1)||(error2 != 1)){
		printf("error en la conversion de rango\n\n");
		return ERR_EN_LA_CONV_RANGO;
	}
	if((num1>num2)||(num1<0)){
		printf("valores de rango no permitido");
		return VAL_RANG_NO_PERM;
	}
	return 0;
}


//si algun argumento fue ingresado mas de una vez devuelve error por argumento repetido
int checkRepeated(int flag[]){
	for (int i=0;i<6;i++){
		if(flag[i]>1){
			printf("argumento repetido\n\n");
			return OP_REPEAT;
		}
	}
return 0;
}


//chekea que se hayan ingresado las opciones obligatorias para la ejecucion del programa
int checkRequired(int flag[]){
	if (flag[leer] == 0){
		printf("argumento requerido no ingresado\n\n");
		return FALT_OPC_REQ;
	}

	if((flag[rango] == 1)&&(flag[municipio] == 0)){
		printf("argumento requerido no ingresado\n\n");
		return FALT_OPC_REQ;
	}
	return 0;
}


//realiza el procesamiento de las opciones busca errores de argumentos opciones  no validas repetidas y no ingresadas 
//y chequea la posicion de los argumentos de cada opcion
int obtainParam(int flag[],char *argv[],int argc,char *str,int indiceFlag[]){
	int opt=0;
	int index=0;
	int error=1;
	extern char *optarg;
	extern int optind;

	while((opt=getopt_long(argc,argv,str,long_options,&index))!=-1){
		if(opt==-1){
			break;	
		}
		switch (opt){
			
			case 'a':
						flag[ayuda]=1;	
						return 0;
						break;
			
			case 'h':
						flag[help]=1;
						return 0;
						break;
			
			case 'l':
						if(!isHelp(optarg)){
							if(optarg == NULL)
								return FALT_ARG;

							flag[leer]=flag[leer]+1;
							if(error=checkArch(optarg,"r"))
								return error;

							indiceFlag[leer]=optind-1;
						}else
							flag[ayuda]=1;
						break;
			
			case 's':
						if(!isHelp(optarg)){
							if((optarg != NULL)&&(optarg[0] != '-')){
								flag[salida]=flag[salida]+1;
								if(error=checkArch(optarg,"w"))
									return NO_ABRE_ARCH_E;
								indiceFlag[salida]=optind-1;
							}
						}else
							flag[ayuda]=1;
						break;
					
			case 'm':
						flag[municipio]=flag[municipio]+1;
						break;
			
			case 'R':
						if(optind<argc){
							if((!isHelp(optarg))||(!isHelp(argv[optind]))){
								flag[rango]=flag[rango]+1;
								indiceFlag[rango]=optind-1;
								indiceFlag[rango+1]=optind;

								if(optind<argc-1){
									optind++;
								}

								float range1,range2;
								if(error=checkValRange(argv[indiceFlag[rango]],argv[indiceFlag[rango+1]]))
									return error;
							}else
								flag[ayuda]=1;
						
						}else{
							if((isHelp(optarg)))
								flag[ayuda]=1;
							else{
								puts("debe ingresar 2 valores junto con la opcion rango\n");
								return FALT_ARG;
							}
							}
						break;
			
			default:
						flag[otro]=1;
						return ARG_DESC_O_EXTRA;
						break;
		}
	}
	if(error=checkRepeated(flag))
		return error;
	if(error=checkRequired(flag))
		return error;
	error;
	}
