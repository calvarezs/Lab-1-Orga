#ifndef IMPRIMIR_INSTRUCCION_H
#define IMPRIMIR_INSTRUCCION_H
#include "Includes.h" 

//Procdeimiento que imprime una instruccion en un archivo
void ImprimirComponentesInstruccion(FILE* archivoEjecucion, Registro* registro, Instruccion* instruccion)
{
    //*DEBUG*/printf("Iniciando impresion de instruccion :%d \n", instruccion->Procedimiento); 
	switch(instruccion->Procedimiento)
    {
        case ADDI:
            fprintf(archivoEjecucion, "addi ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro2);
            fprintf(archivoEjecucion, ", %d", instruccion->Registro3);  
            break;
        case SUBI:
            fprintf(archivoEjecucion, "subi ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro2);
            fprintf(archivoEjecucion, ", %d", instruccion->Registro3); 
            break;
        case BEQ:
            fprintf(archivoEjecucion, "beq ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro2);
            fprintf(archivoEjecucion, ", %s", strtok(instruccion->EtiquetaObjetivo,"\n"));  
            break;
        case JUMPTO:
            fprintf(archivoEjecucion, "jump %s", instruccion->EtiquetaObjetivo);  
            break;
        case LW:
            fprintf(archivoEjecucion, "lw ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", %d(", instruccion->Registro2);
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro3);
            fprintf(archivoEjecucion, ")");
            break;
        case SW:
            fprintf(archivoEjecucion, "sw ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", %d(", instruccion->Registro2);
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro3);
            fprintf(archivoEjecucion, ")");
            break;
        case ADD:
            fprintf(archivoEjecucion, "add ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro2);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro3); 
            break;
        case SUB:
            fprintf(archivoEjecucion, "sub ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro2);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro3);  
            break;
        case MULT:
            fprintf(archivoEjecucion, "mult ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro2); 
            break;
        case DIV:
            fprintf(archivoEjecucion, "divi ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);
            fprintf(archivoEjecucion, ", ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro2); 
            break;
        case MFHI:
            fprintf(archivoEjecucion, "mfhi ");
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);  
            break;
        case MFLO:
            fprintf(archivoEjecucion, "mflo "); 
            ImprimirRegistroInstruccion(archivoEjecucion, instruccion->Registro1);  
            break; 
        default:
            return;
    }
    //*DEBUG*/printf("Terminando impresion instruccion\n");
    return;
}



//Procedimiento que imprime la instruccion ejecutada en el momento 
//Entradas: -Un puntero tipo FILE con la direccion del archivo abierto a editar
//          -Un puntero tipo instruccion a imprimir
void ImprimirInstruccion(FILE* archivoEjecucion, Registro* registros, Instruccion* instruccion)
{ 
    if(instruccion->Procedimiento < 0)
    {
        return;
    }
	ImprimirComponentesInstruccion(archivoEjecucion, registros, instruccion);
    fprintf(archivoEjecucion,"\n");
    return;
}

//Procedimiento que imprime el resultado de la operacion en forma de traza
//Entradas: -Un puntero tipo FILE con la direccion del archivo abierto a editar
//          -Un puntero que apunta a la estructura de registros
//          -El ciclo actual que se está ejecutando en el momento
void ImprimirCicloTraza(FILE* archivoTraza, Registro* registro, Instruccion* instruccion, int numeroCiclo)
{
    if(instruccion->Procedimiento < 0)
    {
        return;
    }
    //*DEBUG*/printf("Iniciando impresion de ciclo traza\n"); 
    fprintf(archivoTraza,"N ciclo: %d  Instruccion: ", numeroCiclo);
	ImprimirComponentesInstruccion(archivoTraza, registro, instruccion);
	fprintf(archivoTraza,"\n"); 
    //*DEBUG*/printf("Impresion de ciclo traza terminado\n");
    return;
}

#endif