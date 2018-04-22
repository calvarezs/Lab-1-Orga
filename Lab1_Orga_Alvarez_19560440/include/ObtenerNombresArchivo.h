#ifndef OBTENER_NOMBRES_ARCHIVO_H
#define OBTENER_NOMBRES_ARCHIVO_H 
#include "Includes.h"

//Procedimiento que obtiene los nombres para los cuatro archivos a procesar del programa 
//Entrada:  -La direccion de memoria de los archivos sobre los que se va a trabajar 
void ObtenerNombresArchivo( char* archivoInstrucciones, 
                            char* archivoControl, 
                            char* archivoTraza,
	                        char* archivoEjecucion);

//Procedimiento que anula todos los nombres para archivos utilizados en el programa
void AnularNombresArchivo(  char* archivoInstrucciones, 
                            char* archivoControl, 
                            char* archivoTraza,
	                        char* archivoEjecucion);

#endif