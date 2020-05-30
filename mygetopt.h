#ifndef _MY_GETOPT_H
	#define _MYGETOP_H
 	#include<unistd.h>
 	#include <getopt.h>
	#include<stdio.h>
	#include "myerrors.h"

enum flag{help=0,ayuda=1,leer=2,salida=3,municipio=4,rango=5,otro=6};

static struct option long_options[]={
{"help",      no_argument,  0, 'h'},
{"ayuda",     no_argument,  0, 'a'},
{"leer",      required_argument, 0, 'l'},
{"salida",    required_argument, 0, 's'},
{"municipio", no_argument, 0,  'm'},
{"rango", 	  required_argument,  0,  'R'},
};

int obtainParam(int flag[],char *argv[],int argc,char *str,int indiceFlag[]);

#endif
