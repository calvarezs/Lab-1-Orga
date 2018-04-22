#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "Includes.h"
//TDA de la serie de instrucciones en MIPS

//DEFINCION INSTRUCCION
typedef struct Instruccion
{
	char* Etiqueta;
	char* EtiquetaObjetivo;
	int Procedimiento;
	int Registro1;
	int Registro2;
	int Registro3;
	
	struct Instruccion* Anterior;
	struct Instruccion* Siguiente;
}Instruccion;  

//DEFINCION PROGRAMA
typedef struct Programa
{
	Instruccion* Cabeza;
	Instruccion* Cola; 
}Programa;

//FUNCION CONSTRUCTOR
Instruccion* CrearInstruccion(char* Etiqueta, char* Procedimiento, char* Registro1, char* Registro2, char* Registro3);
Programa* CrearPrograma(); 

//FUNCION MODIFICAR
Programa* ModificarUltimaInstruccion(char* Etiqueta, char* Procedimiento, char* Registro1, char* Registro2, char* Registro3);

//FUNCION INSERTAR 
void InsertarEnPrograma(Programa* programa, Instruccion* colaNueva); 

//FUNCION OBTENER 
Instruccion* ObtenerEnPrograma(Programa* programa, char* EtiquetaObjetivo);

//PROCEDIMIENTO ANULAR 
void AnularInstruccion(Instruccion* instruccion);
void AnularPrograma(Programa* programa);
void CortarColaPrograma(Programa* programa);

#endif