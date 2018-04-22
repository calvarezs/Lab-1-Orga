#ifndef REGISTRO
#define REGISTRO
#include "Includes.h"

//TDA de la serie de registros en MIPS

//DEFINCION REGISTRO
typedef struct Registro
{ 
	char** Nombres;
	int* Datos;  
}Registro;  

//Funcion constructor
Registro* IniciarRegistro();

//Funcion verificador
int EsRegistro(char* registro);

//Funcion modificar
void ModificarRegistro(Registro* registro, int nRegistro, int dato);
void ModificarRegistroHigh(Registro* registro, int dato);
void ModificarRegistroLow(Registro* registro, int dato);

//Funciones obtener
int ObtenerDatoRegistro(Registro* registro, int nRegistro);
int ObtenerDatoRegistroHigh(Registro* registro);
int ObtenerDatoRegistroLow(Registro* registro);
char* ObtenerNombreRegistro(Registro* registro, int nRegistro);

//Funcion imprimir 
void ImprimirRegistroEnArchivo(FILE* archivoSalida, Registro* registro);
void ImprimirRegistroInstruccion(FILE* archivoSalida, int nRegistro); 

//Funcion Anular
void AnularRegistros(Registro* registro);

//////////////Fin de TDA registro////////////////

//Funcion que obtiene el código del registro MIPS basado en lo expuesto en un string determinado
int ObtenerNumeroRegistro(char* Registro);
void ObtenerRegistroEspecialLwSw(char* Registro, int* registro2, int* registro3);
  
#endif