#include "Includes.h"

//Funcion constructor
Registro* IniciarRegistro()
{
    Registro* registro = (Registro*)malloc(sizeof(Registro));
    registro->Datos = (int*)calloc(34,sizeof(int));
    registro->Nombres = (char**)malloc(34*sizeof(char*));
    int i;
    for(i=1;i<32;i++)
    {
        registro->Nombres[i] = (char*)malloc(4*sizeof(char));
    }
    registro->Nombres[0] = (char*)malloc(6*sizeof(char));
    registro->Nombres[32] = (char*)malloc(5*sizeof(char));
    registro->Nombres[33] = (char*)malloc(4*sizeof(char));

    registro->Nombres[0] = "$zero";
    registro->Nombres[1] = "$at";
    registro->Nombres[2] = "$v0";
    registro->Nombres[3] = "$v1";
    registro->Nombres[4] = "$a0";
    registro->Nombres[5] = "$a1";
    registro->Nombres[6] = "$a2";
    registro->Nombres[7] = "$a3";
    registro->Nombres[8] = "$t0";
    registro->Nombres[9] = "$t1";
    registro->Nombres[10] = "$t2";
    registro->Nombres[11] = "$t3";
    registro->Nombres[12] = "$t4";
    registro->Nombres[13] = "$t5";
    registro->Nombres[14] = "$t6";
    registro->Nombres[15] = "$t7";
    registro->Nombres[16] = "$s0";
    registro->Nombres[17] = "$s1";
    registro->Nombres[18] = "$s2";
    registro->Nombres[19] = "$s3";
    registro->Nombres[20] = "$s4";
    registro->Nombres[21] = "$s5";
    registro->Nombres[22] = "$s6";
    registro->Nombres[23] = "$s7";
    registro->Nombres[24] = "$t8";
    registro->Nombres[25] = "$t9";
    registro->Nombres[26] = "$k0";
    registro->Nombres[27] = "$k1";
    registro->Nombres[28] = "$gp";
    registro->Nombres[29] = "$sp";
    registro->Nombres[30] = "$fp";
    registro->Nombres[31] = "$ra";
    registro->Nombres[32] = "HIGH";
    registro->Nombres[33] = "LOW";  
    return registro;
}

//Funcion modificar
void ModificarRegistro(Registro* registro, int nRegistro, int dato)
{
    registro->Datos[nRegistro] = dato;
    return;
}

void ModificarRegistroHigh(Registro* registro, int dato)
{
    registro->Datos[32] = dato;
    return;
}

void ModificarRegistroLow(Registro* registro, int dato)
{
    registro->Datos[33] = dato;
    return;
}

//Funciones obtener
int ObtenerDatoRegistro(Registro* registro, int nRegistro)
{
    return registro->Datos[nRegistro];
}
int ObtenerDatoRegistroHigh(Registro* registro)
{
    return registro->Datos[32];    
}
int ObtenerDatoRegistroLow(Registro* registro)
{
    return registro->Datos[33];
}
char* ObtenerNombreRegistro(Registro* registro, int nRegistro)
{
    return registro->Nombres[nRegistro];
}

//Funcion verificador
int EsRegistro(char* registro)
{
    if(strstr(registro, "$")!=NULL)
    {
        return TRUE;
    }
    return FALSE;
}
//Funcion imprimir 
void ImprimirRegistroEnArchivo(FILE* archivoSalida, Registro* registro)
{
    //*DEBUG*/ printf("Imprimiendo todos los registros\n");
    int i;
    for(i=0;i<31;i++)
    {  
        //*DEBUG*/ printf("Imprimiendo ");
        fprintf(archivoSalida,"%d;" ,registro->Datos[i]);
    } 
    //*DEBUG*/ printf("Impresion de registros terminada\n");
    return;    
} 

void ImprimirRegistroInstruccion(FILE* archivoSalida, int nRegistro)
{
    switch(nRegistro)
    { 
        case 0:
            fprintf(archivoSalida, "$zero");
            break;
        case 1:
            fprintf(archivoSalida, "$at");
            break;
        case 2:
            fprintf(archivoSalida, "$v0");
            break;
        case 3:
            fprintf(archivoSalida, "$v1");
            break;
        case 4:
            fprintf(archivoSalida, "$a0");
            break;
        case 5:
            fprintf(archivoSalida, "$a1");
            break;
        case 6:
            fprintf(archivoSalida, "$a2");
            break;
        case 7:
            fprintf(archivoSalida, "$a3");
            break;
        case 8:
            fprintf(archivoSalida, "$t0");
            break;
        case 9:
            fprintf(archivoSalida, "$t1");
            break;
        case 10:
            fprintf(archivoSalida, "$t2");
            break;
        case 11:
            fprintf(archivoSalida, "$t3");
            break;
        case 12:
            fprintf(archivoSalida, "$t4");
            break;
        case 13:
            fprintf(archivoSalida, "$t5");
            break;
        case 14:
            fprintf(archivoSalida, "$t6");
            break;
        case 15:
            fprintf(archivoSalida, "$t7");
            break;
        case 16:
            fprintf(archivoSalida, "$s0");
            break;
        case 17:
            fprintf(archivoSalida, "$s1");
            break;
        case 18:
            fprintf(archivoSalida, "$s2");
            break;
        case 19:
            fprintf(archivoSalida, "$s3");
            break;
        case 20:
            fprintf(archivoSalida, "$s4");
            break;
        case 21:
            fprintf(archivoSalida, "$s5");
            break;
        case 22:
            fprintf(archivoSalida, "$s6");
            break;
        case 23:
            fprintf(archivoSalida, "$s7");
            break;
        case 24:
            fprintf(archivoSalida, "$t8");
            break;
        case 25:
            fprintf(archivoSalida, "$t9");
            break;
        case 26:
            fprintf(archivoSalida, "$k0");
            break;
        case 27:
            fprintf(archivoSalida, "$k1");
            break;
        case 28:
            fprintf(archivoSalida, "$gp");
            break;
        case 29:
            fprintf(archivoSalida, "$sp");
            break;
        case 30:
            fprintf(archivoSalida, "$fp");
            break;
        case 31:
            fprintf(archivoSalida, "$ra");
            break;
    }
    return;
}

//Funcion Anular
void AnularRegistros(Registro* registro)
{
    free(registro->Datos);
    free(registro->Nombres);
    free(registro);
    return;
}


/////Fin Funciones tda registro///////////

//Funcion que obtiene el código del registro MIPS basado en lo expuesto en un string determinado
int ObtenerNumeroRegistro(char* Registro)
{
    //*DEBUG*/ printf("Obtener numero registro con valor: |%s|\n",Registro);
    int nRegistro;
    char* nombreRegistro;
    int i; 
    //COMPARAR EL SEGUNDO ELEMENTO DEL CHAR REGISTRO
    // EJ: $X0
    if (Registro == NULL || strlen(Registro)<3)
    {
        return 0;
    } 
 
    nombreRegistro = strstr(Registro, "$"); 

    //caso $zero
    if(strstr(Registro, "$zero")!=NULL)
    {
        nRegistro = 0;
        return nRegistro;
    }
    //caso $at
    else if(strstr(Registro, "$at")!=NULL)
    {
        nRegistro = 1;
        return nRegistro;
    }
    //caso $gp
    else if(strstr(Registro, "$gp")!=NULL)
    { 
        nRegistro = 28;
        return nRegistro;
    }
    //caso $sp
    else if(strstr(Registro, "$sp")!=NULL)
    { 
        nRegistro = 29;
        return nRegistro;
    }
    //caso $fp
    else if(strstr(Registro, "$fp")!=NULL)
    { 
        nRegistro = 30;
        return nRegistro;
    }
    //caso $ra
    else if(strstr(Registro, "$ra")!=NULL)
    { 
        nRegistro = 31;
        return nRegistro;
    }
    //caso $v0, $v1
    else if(strstr(Registro, "$v")!=NULL)
    { 
        nRegistro = 2 + nombreRegistro[2] - '0';
        return nRegistro;
    }
    //caso $a0 - $a3
    else if(strstr(Registro, "$a")!=NULL)
    { 
        nRegistro = 4 + nombreRegistro[2] - '0';
        return nRegistro;
    }
    //caso $t0-$t9
    else if(strstr(Registro, "$t")!=NULL)
    { 
        //caso $t0-$t7
        if(nombreRegistro[2]-'0' < 8)
        {
            nRegistro = 8 + nombreRegistro[2] - '0';
            return nRegistro;
        }//caso $t8-$t9
        else
        {
            nRegistro = 24 - 8 + nombreRegistro[2] - '0';
            return nRegistro;
        } 
    }
    //caso $s0-$s7 
    else if(strstr(Registro, "$s")!=NULL)
    { 
        nRegistro = 16 + nombreRegistro[2] - '0';
        return nRegistro;
    }
    //caso $k0-$k1
    else if(strstr(Registro, "$k")!=NULL)
    { 
        nRegistro = 26 + nombreRegistro[2] - '0';
        return nRegistro;
    }

    //En el caso de que el valor sea inmediato
    nRegistro = 0;
    if(isdigit(Registro[0]))
    {
        nRegistro = Registro[0] - '0';  
    }
    i = 1;
    while(isdigit(Registro[i]))
    {
        nRegistro = 10*nRegistro + Registro[i] - '0';
        i++;
    }
    if(Registro[0]=='-')
    {
        nRegistro = nRegistro-2*nRegistro;  
    } 

    return nRegistro;
}

//Funcion obtencion de datos caso LW y SW
void ObtenerRegistroEspecialLwSw(char* Registro, int* registro2, int* registro3)
{
    int i;
    i = 0; 
    *registro2 = 0;
    //*DEBUG*/ printf("Buscando valor al lado del parentesis\n");
    while(isdigit(Registro[i]))
    {
        *registro2 = 10 * (*registro2) + Registro[i] - '0';
        i++;
    }
    //*DEBUG*/ printf("Valor encontrado: %d\n",*registro2);
    //*DEBUG*/ printf("Buscando valor dentro del parentesis\n");
    *registro3 = ObtenerNumeroRegistro(Registro);
    //*DEBUG*/ printf("Valor encontrado: %d\n",*registro3);
    return;
}