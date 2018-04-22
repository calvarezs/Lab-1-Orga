#ifndef LINEAS_CONTROL_H
#define LINEAS_CONTROL_H
#include "Includes.h"
//TDA de las lineas de control

//DEFINCION LINEAS DE CONTROL
typedef struct LineasControl
{
	char** Nombres;
	int* Estados; 
}LineasControl;  

//FUNCION CONTRUCTOR
LineasControl* IniciarLineasControl();

//FUNCION MODIFICAR
void ActualizarLineasControl(LineasControl* lc, char* nombre, int estado);

//FUNCION CONSULTA
int ConsultarLineasControl(LineasControl* lc, int nombre);

//PROCEDIMIENTO MOSTRAR
void MostrarLineasControl(LineasControl* lc);

//PROCEDIMIENTO ELIMINAR
void AnularLineasControl(LineasControl* lc);

#endif