#ifndef STACK
#define STACK
#include "Includes.h"
//TDA del stack de MIPS

//DEFINCION INSTRUCCION
typedef struct Stack
{
	int* Datos; 
}Stack;  

//Funcion constructor
Stack* IniciarStack();

//Funcion obtener
int ObtenerDeStack(Stack* stack, int pos);

//Funcion modificar
void ModificarStack(Stack* stack, int pos, int dato);

//Funcion anular
void AnularStack(Stack* stack);

#endif