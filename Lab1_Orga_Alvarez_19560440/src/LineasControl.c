#ifndef REGISTRO_H
#define REGISTRO_H
#include "Includes.h"
//TDA de las lineas de control 

//PROCEDIMIENTO CONTRUCTOR
LineasControl* IniciarLineasControl()
{
	LineasControl* resultado;
	resultado = (LineasControl*)malloc(sizeof(LineasControl)); 
	resultado->Nombres = (char**)malloc(9*sizeof(char*)); 
	resultado->Estados = (int*)calloc(9, sizeof(int));  

	resultado->Nombres[0] = "REGDST"; 
	resultado->Nombres[1] = "JUMP";
	resultado->Nombres[2] = "BRANCH"; 
	resultado->Nombres[3] = "MEMREAD"; 
	resultado->Nombres[4] = "MEMTOREG"; 
	resultado->Nombres[5] = "ALUOP"; 
	resultado->Nombres[6] = "MEMWRITE"; 
	resultado->Nombres[7] = "ALUSRC"; 
	resultado->Nombres[8] = "REGWRITE";
	
	return resultado;
}

//PROCEDIMIENTO MODIFICAR
void ActualizarLineasControl(LineasControl* lc, char* nombre, int estado)
{
	//Parsear nombre a mayusculas 
	int largoNombre = strlen(nombre);
	int i;
	for(i=0;i<largoNombre;i++)
	{
		nombre[i] = toupper(nombre[i]);
	}
	
	//buscar coincidencias
	if(strcmp("REGDST",nombre)==0)
	{
		lc->Estados[REGDST] = estado;
	} 
	else if(strcmp("JUMP",nombre)==0)
	{
		lc->Estados[JUMP] = estado;
	} 
	else if(strcmp("BRANCH",nombre)==0)
	{
		lc->Estados[BRANCH] = estado;
	}  
	else if(strcmp("MEMREAD",nombre)==0)
	{
		lc->Estados[MEMREAD] = estado;
	}  
	else if(strcmp("MEMTOREG",nombre)==0)
	{
		lc->Estados[MEMTOREG] = estado;
	}  
	else if(strcmp("ALUOP",nombre)==0)
	{
		lc->Estados[ALUOP] = estado;
	}  
	else if(strcmp("MEMWRITE",nombre)==0)
	{
		lc->Estados[MEMWRITE] = estado;
	}  
	else if(strcmp("ALUSRC",nombre)==0)
	{
		lc->Estados[ALUSRC] = estado;
	}  
	else if(strcmp("REGWRITE",nombre)==0)
	{
		lc->Estados[REGWRITE] = estado;
	} 
	return;
}

//PROCEDIMIENTO CONSULTA
int ConsultarLineasControl(LineasControl* lc, int nombre)
{
	return lc->Estados[nombre];
}

//PROCEDIMIENTO MOSTRAR
void MostrarLineasControl(LineasControl* lc)
{
	int i;
	printf("Lineas de Control\n");
	for(i=0;i<9;i++)
	{
		printf("|%s|: |%d|\n", lc->Nombres[i], lc->Estados[i]);
	}
	return;
}

//FUNCION ELIMINAR
void AnularLineasControl(LineasControl* lc)
{
	free(lc->Nombres);
	free(lc->Estados);
	free(lc);
	return;
}

#endif