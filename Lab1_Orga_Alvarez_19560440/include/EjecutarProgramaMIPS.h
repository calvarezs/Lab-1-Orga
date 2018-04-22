#ifndef EJECUTAR_PROGRAMA_MIPS_H
#define EJECUTAR_PROGRAMA_MIPS_H
#include "Includes.h"

//Funcion que ejecuta las funciones del programa MIPS
void EjecutarProgramaMIPS(char* archivoSalidaTraza, char* archivoSalidaEjecucion, Programa* programa, Stack* stack, Registro* registro, LineasControl* lineasControl);

#endif