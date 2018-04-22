#ifndef IMPRIMIR_INSTRUCCION_H
#define IMPRIMIR_INSTRUCCION_H
#include "Includes.h" 

//Procedimiento que imprime la instruccion ejecutada en el momento 
//Entradas: -Un puntero tipo FILE con la direccion del archivo abierto a editar
//          -Un puntero tipo instruccion a imprimir
void ImprimirInstruccion(FILE* archivoEjecucion, Registro* registros, Instruccion* instruccion);

//Procedimiento que imprime el resultado de la operacion en forma de traza
//Entradas: -Un puntero tipo FILE con la direccion del archivo abierto a editar
//          -Un puntero que apunta a la estructura de registros
//          -El ciclo actual que se está ejecutando en el momento
void ImprimirCicloTraza(FILE* archivoTraza, Registro* registro, Instruccion* instruccion, int numeroCiclo);
#endif