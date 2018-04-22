#ifndef PROCEDIMIENTO
#define PROCEDIMIENTO
#include "Includes.h"

//Funcion que obtiene el código del procedimiento MIPS basado en lo expuesto en un string determinado
int ObtenerNumeroProcedimiento(char* Procedimiento);
 
//Procedimiento que ejecuta las instrucciones en base a la instruccion en MIPS
Instruccion*  EjecutarProcedimiento(FILE* archivoEjecucion, FILE* archivoTraza, Registro* registro, Stack* stack, LineasControl* lineasControl, Programa* programa, Instruccion* instruccionActual,int numeroCiclo);

//Instrucciones MIPS definidas en procedimiento.c

#endif