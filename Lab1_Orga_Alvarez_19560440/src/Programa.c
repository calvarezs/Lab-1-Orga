#include "Includes.h"  

//CONSTRUCTOR 
Instruccion* CrearInstruccion(char* Etiqueta, char* Procedimiento, char* Registro1, char* Registro2, char* Registro3)
{
	//*DEBUG*/ printf("Creando nueva instruccion\n");
	Instruccion* Nueva;
	Nueva = (Instruccion*)malloc(sizeof(Instruccion)); 
	Nueva->Etiqueta = (char*)malloc(LARGO_MAXIMO_ETIQUETA * sizeof(char)); 
	Nueva->EtiquetaObjetivo = (char*)malloc(LARGO_MAXIMO_ETIQUETA * sizeof(char));

	Nueva->Anterior = NULL;
	Nueva->Siguiente = NULL;

	Nueva->Registro1 = -1;
	Nueva->Registro2 = -1; 
	Nueva->Registro3 = -1;

	strcpy(Nueva->Etiqueta, Etiqueta);

	Nueva->Procedimiento = ObtenerNumeroProcedimiento(Procedimiento);
	//*DEBUG*/ printf("Procedimiento:%d\n",Nueva->Procedimiento);
	if(Nueva->Procedimiento == LW || Nueva->Procedimiento == SW)
	{
		//*DEBUG*/ printf("Instruccion especial ls o lw encontrado\n");
		Nueva->Registro1 = ObtenerNumeroRegistro(Registro1);
		//*DEBUG*/ printf("Registro1:%d\n",Nueva->Registro1);
		ObtenerRegistroEspecialLwSw(Registro2, &(Nueva->Registro2), &(Nueva->Registro3));
	}
	else if(Nueva->Procedimiento == BEQ)
	{
		//*DEBUG*/ printf("Instruccion tipo branch detectado\n");
		Nueva->Registro1 = ObtenerNumeroRegistro(Registro1);
		//*DEBUG*/ printf("Registro1:%d\n",Nueva->Registro1);
		Nueva->Registro2 = ObtenerNumeroRegistro(Registro2);
		//*DEBUG*/ printf("Registro2:%d\n",Nueva->Registro2);
		//*DEBUG*/ printf("Registro3:%s\n",Registro3);
		strcpy(Nueva->EtiquetaObjetivo, Registro3); 
		//*DEBUG*/ printf("Etiqueta:|%s|\n",Nueva->EtiquetaObjetivo);
	}
	else if(EsRegistro(Registro1)==TRUE)
	{
		//*DEBUG*/ printf("Instruccion comun encontrado\n");
		Nueva->Registro1 = ObtenerNumeroRegistro(Registro1);
		//*DEBUG*/ printf("Registro1:%d\n",Nueva->Registro1);
		Nueva->Registro2 = ObtenerNumeroRegistro(Registro2);
		//*DEBUG*/ printf("Registro2:%d\n",Nueva->Registro2);
		Nueva->Registro3 = ObtenerNumeroRegistro(Registro3);
		//*DEBUG*/ printf("Registro3:%d\n",Nueva->Registro3);
	}
	else
	{
		//*DEBUG*/ printf("Instruccion de salto encontrado\n");
		strcpy(Nueva->EtiquetaObjetivo, Registro1); 
	}
	
	//*DEBUG*/ printf("Instruccion creada\n");
	return Nueva;
}
 
Programa* CrearPrograma() 
{
	Programa* Nuevo; 
	Nuevo = (Programa*)malloc(sizeof(Programa)); 
	Nuevo->Cabeza = NULL;  
	Nuevo->Cola = NULL;
	return Nuevo;
}  

//FUNCION INSERTAR 
void InsertarEnPrograma(Programa* programa, Instruccion* colaNueva)
{ 
	if(programa->Cabeza == NULL)
	{
		programa->Cabeza = colaNueva;
		programa->Cola = colaNueva;
	} 
	else
	{
		programa->Cola->Siguiente = colaNueva;
		colaNueva->Anterior = programa->Cola;
		programa->Cola = colaNueva;
	} 
	return;
}

//FUNCION OBTENER 
Instruccion* ObtenerEnPrograma(Programa* programa, char* etiquetaObjetivo)
{
	Instruccion* InstruccionActual; 
	InstruccionActual = programa->Cabeza; 
	
	//*DEBUG*/printf("En busqueda: %s\n", etiquetaObjetivo);

	while(InstruccionActual != NULL)
	{
		//*DEBUG*/printf("|%s|",InstruccionActual->Etiqueta);
        //*DEBUG*/printf("->|%s|:",InstruccionActual->EtiquetaObjetivo);
        //*DEBUG*/printf("|%d|%d|%d|%d|\n\n", InstruccionActual->Procedimiento, InstruccionActual->Registro1, InstruccionActual->Registro2, InstruccionActual->Registro3);
        
		//*DEBUG*/printf("strcmp (%s, %s) = %d\n", etiquetaObjetivo, InstruccionActual->Etiqueta, strcmp(etiquetaObjetivo, InstruccionActual->Etiqueta));
		if(strcmp(etiquetaObjetivo, InstruccionActual->Etiqueta) == 0 ||
			strcmp(etiquetaObjetivo, InstruccionActual->Etiqueta) == 13)
		{
			//*DEBUG*/printf("%s\n", InstruccionActual->Etiqueta);
			return InstruccionActual;
		}
		InstruccionActual = InstruccionActual->Siguiente;
	}
	return NULL;
} 

//PROCEDIMIENTO ANULAR 
void AnularInstruccion(Instruccion* instruccion)
{
	free(instruccion->Etiqueta);
	free(instruccion);
	return;
}

void AnularPrograma(Programa* programa)
{ 
	if(programa->Cabeza==NULL)
	{
		free(programa);
		return;
	}
	while(programa->Cola!=programa->Cabeza)
	{   
		programa->Cola = programa->Cola->Anterior; 
		AnularInstruccion(programa->Cola->Siguiente);
	} 
	AnularInstruccion(programa->Cabeza);
	free(programa);
	return;
} 

void CortarColaPrograma(Programa* programa)
{
	programa->Cola = programa->Cola->Anterior;
	AnularInstruccion(programa->Cola->Siguiente);
	programa->Cola->Siguiente = NULL;
}