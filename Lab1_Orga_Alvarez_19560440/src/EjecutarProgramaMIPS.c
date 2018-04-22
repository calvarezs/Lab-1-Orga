#include "Includes.h"

void EjecutarProgramaMIPS(  char* archivoSalidaTraza, 
                            char* archivoSalidaEjecucion,
                            Programa* programa, 
                            Stack* stack,
                            Registro* registro, 
                            LineasControl* lineasControl)
{
    /*DEBUG*/ printf("Iniciar ejecucion programa MIPS\n");
    FILE* archivoEjecucion = fopen(archivoSalidaEjecucion, "w");   
    FILE* archivoTraza = fopen(archivoSalidaTraza, "w"); 

    int i;
    for(i=0;i<31;i++)
    {  
        //*DEBUG*/ printf("Imprimiendo ");
        fprintf(archivoTraza,"%s;" ,registro->Nombres[i]);
    } 
    fprintf(archivoTraza,"\n");

    int numeroCiclo = 0;
    Instruccion* instruccionActual = programa->Cabeza; 
    while(instruccionActual != NULL)
    {  
        if(instruccionActual->Procedimiento > -1)
        {  
            numeroCiclo++;
        }
        else
        { 
            instruccionActual = instruccionActual->Siguiente;
            if (instruccionActual == NULL)
            {
                fclose(archivoEjecucion);
                fclose(archivoTraza);
                /*DEBUG*/ printf("Fin ejecucion programa MIPS\n");
                return;            
            } 
        }

        /*DEBUG*/printf("Pos actual: |%s|",instruccionActual->Etiqueta);
        /*DEBUG*/printf("->|%s|:",instruccionActual->EtiquetaObjetivo);
        /*DEBUG*/printf("|%d|%d|%d|%d|\n\n", instruccionActual->Procedimiento, instruccionActual->Registro1, instruccionActual->Registro2, instruccionActual->Registro3);
            
        //*DEBUG*/ printf("Ejecutar procedimiento\n");
        instruccionActual = EjecutarProcedimiento(archivoEjecucion, archivoTraza, registro, stack, lineasControl, programa, instruccionActual, numeroCiclo);
        ImprimirRegistroEnArchivo(archivoTraza, registro);
        fprintf(archivoTraza,"\n\n");
    }
    fclose(archivoEjecucion);
    fclose(archivoTraza);
    /*DEBUG*/ printf("Fin ejecucion programa MIPS\n");
    return;
}
