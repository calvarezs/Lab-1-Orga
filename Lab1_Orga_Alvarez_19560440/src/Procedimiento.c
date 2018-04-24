#include "Includes.h"

//Funciones MIPS
Instruccion* addi(Registro* registro, LineasControl* lineasControl, Instruccion* instruccion)
{
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2);
    int registro3 = instruccion->Registro3;

    if(ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    { 
        ModificarRegistro(registro, instruccion->Registro1, registro2 + registro3);
    }
    return instruccion->Siguiente;   
}
Instruccion* subi(Registro* registro, LineasControl* lineasControl, Instruccion* instruccion) 
{ 
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2);
    int registro3 = instruccion->Registro3;

    if(ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    { 
        ModificarRegistro(registro, instruccion->Registro1, registro2 - registro3);
    }
    return instruccion->Siguiente;
}
Instruccion* lw(Registro* registro, Stack* stack, LineasControl* lineasControl, Instruccion* instruccion)
{
    int valorACargar;
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2) / 4;
    int registro3 = ObtenerDatoRegistro(registro, instruccion->Registro3);
    //*DEBUG*/ printf("En el registro %d hay %d\n",instruccion->Registro2, registro2);
    //*DEBUG*/ printf("En el registro %d hay %d\n",instruccion->Registro3, registro3);

    if(ConsultarLineasControl(lineasControl, MEMREAD)!=0 &&
        ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    {  
        valorACargar = ObtenerDeStack(stack, registro2 + registro3);
        ModificarRegistro(registro, instruccion->Registro1, valorACargar);
    }
    return instruccion->Siguiente;
}
Instruccion* sw(Registro* registro, Stack* stack, LineasControl* lineasControl, Instruccion* instruccion)
{
    int registro1 = ObtenerDatoRegistro(registro, instruccion->Registro1);
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2) / 4;
    int registro3 = ObtenerDatoRegistro(registro, instruccion->Registro3);
    //*DEBUG*/ printf("En el registro %d hay %d\n",instruccion->Registro1, registro1); 
    //*DEBUG*/ printf("En el registro %d hay %d\n",instruccion->Registro2, registro2);
    //*DEBUG*/ printf("En el registro %d hay %d\n",instruccion->Registro3, registro3);


    if(ConsultarLineasControl(lineasControl, MEMWRITE)!=0)
    {  
        ModificarStack(stack, registro2 + registro3, registro1); 
    }
    return instruccion->Siguiente;
}
Instruccion* add(Registro* registro, LineasControl* lineasControl, Instruccion* instruccion)
{
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2);
    int registro3 = ObtenerDatoRegistro(registro, instruccion->Registro3);

    if(ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    { 
        ModificarRegistro(registro, instruccion->Registro1, registro2 + registro3);
    }
    return instruccion->Siguiente;
}
Instruccion* sub(Registro* registro, LineasControl* lineasControl, Instruccion* instruccion)
{
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2);
    int registro3 = ObtenerDatoRegistro(registro, instruccion->Registro3);

    if(ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    { 
        ModificarRegistro(registro, instruccion->Registro1, registro2 - registro3);
    }
    return instruccion->Siguiente;
}
Instruccion* mult(Registro* registro, LineasControl* lineasControl, Instruccion* instruccion)
{
    int registro1 = ObtenerDatoRegistro(registro, instruccion->Registro1);
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2);

    if(ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    {    
        ModificarRegistroHigh(registro, registro1*registro2);
        ModificarRegistroLow(registro, registro1*registro2);
    }
    return instruccion->Siguiente;
}
Instruccion* divi(Registro* registro, LineasControl* lineasControl, Instruccion* instruccion)
{
    int registro1 = ObtenerDatoRegistro(registro, instruccion->Registro1);
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2);

    if(ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    {    
        if(registro2 == 0)
        {
            printf("Dividir por 0 es malo.\n");
            return instruccion->Siguiente;
        }
        ModificarRegistroHigh(registro, registro1/registro2);
        ModificarRegistroLow(registro, registro1%registro2);
    }
    return instruccion->Siguiente;
}
Instruccion* mfhi(Registro* registro, LineasControl* lineasControl, Instruccion* instruccion)
{
    int valorACargar;
    if(ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    {    
        valorACargar = ObtenerDatoRegistroHigh(registro); 
        ModificarRegistro(registro, instruccion->Registro1, valorACargar);
    }
    return instruccion->Siguiente;
}
Instruccion* mflo(Registro* registro, LineasControl* lineasControl, Instruccion* instruccion) 
{
    int valorACargar;
    if(ConsultarLineasControl(lineasControl, REGWRITE)!=0)
    {     
        valorACargar = ObtenerDatoRegistroLow(registro);
        ModificarRegistro(registro, instruccion->Registro1, valorACargar);
    }
    return instruccion->Siguiente;
}
Instruccion* beq(Programa* programa, Registro* registro, LineasControl* lineasControl, Instruccion* instruccion)
{ 
    Instruccion* instruccionASaltar;
    int registro1 = ObtenerDatoRegistro(registro, instruccion->Registro1);
    int registro2 = ObtenerDatoRegistro(registro, instruccion->Registro2);

    if(ConsultarLineasControl(lineasControl, BRANCH)!=0 &&
        ConsultarLineasControl(lineasControl, JUMP)!=0)
    {     
        if(registro1 == registro2)
        {
            instruccionASaltar = ObtenerEnPrograma(programa, instruccion->EtiquetaObjetivo);
            if(instruccionASaltar != NULL)
            {
                //*DEBUG*/printf("beq salta a: |%s|",instruccionASaltar->Etiqueta);
                //*DEBUG*/printf("->|%s|:",instruccionASaltar->EtiquetaObjetivo);
                //*DEBUG*/printf("|%d|%d|%d|%d|\n\n", instruccionASaltar->Procedimiento, instruccionASaltar->Registro1, instruccionASaltar->Registro2, instruccionASaltar->Registro3);
        
                return instruccionASaltar;
            }
        }
    }
    return instruccion->Siguiente;
}
Instruccion* jump(Programa* programa, Registro* registro, LineasControl* lineasControl, Instruccion* instruccion)
{
    Instruccion* instruccionASaltar;
    if(ConsultarLineasControl(lineasControl, BRANCH)!=0 &&
        ConsultarLineasControl(lineasControl, JUMP)!=0)
    {     
        instruccionASaltar = ObtenerEnPrograma(programa, instruccion->EtiquetaObjetivo);
        
        if(instruccionASaltar != NULL)
        {
            //*DEBUG*/printf("jump salta a: |%s|",instruccionASaltar->Etiqueta);
            //*DEBUG*/printf("->|%s|:",instruccionASaltar->EtiquetaObjetivo);
            //*DEBUG*/printf("|%d|%d|%d|%d|\n\n", instruccionASaltar->Procedimiento, instruccionASaltar->Registro1, instruccionASaltar->Registro2, instruccionASaltar->Registro3);
        
            return instruccionASaltar;
        }
    }
    return instruccion->Siguiente;
}

//Funcion que obtiene el código del procedimiento MIPS basado en lo expuesto en un string determinado
int ObtenerNumeroProcedimiento(char* Procedimiento)
{

    int i;
	for(i=0;i<strlen(Procedimiento);i++)
	{
		Procedimiento[i] = tolower(Procedimiento[i]);
	}

    if(strstr(Procedimiento, "addi")!=NULL)
    {
        return ADDI;
    } 
    else if(strstr(Procedimiento, "subi")!=NULL)
    {
        return SUBI;
    }
    else if(strstr(Procedimiento, "beq")!=NULL)
    {
        return BEQ;
    }
    else if(strstr(Procedimiento, "lw")!=NULL)
    {
        return LW;
    }
    else if(strstr(Procedimiento, "sw")!=NULL)
    {
        return SW;
    } 
    else if(strstr(Procedimiento, "add")!=NULL)
    {
        return ADD;
    }
    else if(strstr(Procedimiento, "sub")!=NULL)
    {
        return SUB;
    }
    else if(strstr(Procedimiento, "mult")!=NULL)
    {
        return MULT;
    }
    else if(strstr(Procedimiento, "div")!=NULL)
    {
        return DIV;
    }
    else if(strstr(Procedimiento, "mfhi")!=NULL)
    {
        return MFHI;
    }
    else if(strstr(Procedimiento, "mflo")!=NULL)
    {
        return MFLO;
    }
    else if(strstr(Procedimiento, "j")!=NULL)
    {
        return JUMPTO;
    }
    else if(strstr(Procedimiento, "jump")!=NULL)
    {
        return JUMPTO;
    }
    return -1;
}

//Procedimiento que ejecuta las instrucciones en base a la instruccion en MIPS
Instruccion*  EjecutarProcedimiento(
                            FILE* archivoEjecucion, 
                            FILE* archivoTraza,
                            Registro* registro, 
                            Stack* stack, 
                            LineasControl* lineasControl, 
                            Programa* programa, 
                            Instruccion* instruccionActual,
                            int numeroCiclo)
{
    //*DEBUG*/ printf("Inicio Funcion de Eleccion de procedimiento\n");
    //*DEBUG*/ printf("Imprimir Proc\n");
    ImprimirInstruccion(archivoEjecucion, registro, instruccionActual);
    //*DEBUG*/ printf("Imprimir traza\n");
    ImprimirCicloTraza(archivoTraza,registro,instruccionActual,numeroCiclo);

    switch(instruccionActual->Procedimiento)
    {
        case ADDI:
            return addi(registro, lineasControl, instruccionActual);
        case SUBI:
            return subi(registro, lineasControl, instruccionActual);
        case BEQ:
            return beq(programa, registro, lineasControl, instruccionActual);  
        case JUMPTO:
            return jump(programa, registro, lineasControl, instruccionActual); 
        case LW:
            return lw(registro, stack, lineasControl, instruccionActual);
        case SW:
            return sw(registro, stack, lineasControl, instruccionActual);
        case ADD:
            return add(registro, lineasControl, instruccionActual);
        case SUB:
            return sub(registro, lineasControl, instruccionActual);
        case MULT:
            return mult(registro, lineasControl, instruccionActual);
        case DIV:
            return divi(registro, lineasControl, instruccionActual);
        case MFHI:
            return mfhi(registro, lineasControl, instruccionActual);
        case MFLO:
            return mflo(registro, lineasControl, instruccionActual); 
    }
    //*DEBUG*/ printf("Fin Funcion de Eleccion de procedimiento\n");
    return instruccionActual->Siguiente;
}

