#ifndef OBTENER_PROGRAMA_H
#define OBTENER_PROGRAMA_H
#include "Includes.h"

//Funcion que extrae las instrucciones de un archivo de texto con instrucciones en MIPS 
//Entrada:  -Un archivo de texto con el nombre de un archivo válido con instrucciones de MIPS
//Salida:   -Un puntero a una estructura de datos tipo programa
void ObtenerPrograma(Programa* programa, char* nombreArchivo, int* ErrorFound);

//Funcion que extrae componentes de control de un archivo valido
//Entrada:  -Un archivo de texto con el nombre de un archivo válido con un listado logico
void ObtenerListadoControl(char* nombreArchivo, LineasControl* lc, int* ErrorFound);

#endif