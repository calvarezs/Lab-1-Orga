#include "Includes.h"

//Procedimiento que obtiene los nombres para los cuatro archivos a procesar del programa 
//Entrada:  -La direccion de memoria de los archivos sobre los que se va a trabajar 
void ObtenerNombresArchivo( char* archivoInstrucciones, 
                            char* archivoControl, 
                            char* archivoTraza,
	                        char* archivoEjecucion)
{
    FILE* fp;

    //*DEBUG*/ printf("Iniciando funcion ObtenerNombresArchivo\n");
    //*DEBUG*/ printf("Estado de Error: %d\n",*ErrorFound);

    //Obtener nombre archivo instrucciones MIPS
    printf("\n");
    do
    {
        printf("Nombre el archivo con las instrucciones a leer:\n");
        scanf("%s",archivoInstrucciones); 
        fp = fopen(archivoInstrucciones, "r");

        if(fp)
        {
            printf("Has seleccionado el archivo: \'%s\'\n", archivoInstrucciones);
        }
        else
        {
            printf("Archivo invalido. Por favor intente nuevamente.\n");
        }

    }while(fp == NULL);
    fclose(fp);

    //Obtener nombre archivo lineas de control
    printf("\n");
    do
    {
        printf("Nombre el archivo con las lineas de control:\n");
        scanf("%s",archivoControl);
        fp = fopen(archivoControl, "r");

        if(fp)
        {
            printf("Has seleccionado el archivo: \'%s\'\n", archivoControl);
        }
        else
        {
            printf("Archivo invalido. Por favor intente nuevamente.\n");
        }

    }while(fp == NULL);
    fclose(fp);

    //Obtener nombre archivo de salida de traza  
    printf("\n");
    printf("Nombre el archivo para la salida de traza:\n");
    scanf("%s",archivoTraza); 

    if(strlen(archivoTraza)==0)
    {
        archivoTraza = "archivoTraza.csv";
        printf("Nombre vacio no soportado. Optando por nombre generico \'%s\'\n", archivoTraza);
    } 
    else
    {
        printf("Has seleccionado el archivo: %s\n", archivoTraza);
    }

    //Obtener nombre archivo de salida de ejecucion
    printf("\n");
    printf("Nombre el archivo para la salida de instrucciones ejecutadas:\n");
    scanf("%s",archivoEjecucion); 

    if(strlen(archivoEjecucion)==0)
    {
        archivoEjecucion = "archivoEjecucion.csv";
        printf("Nombre vacio no soportado. Optando por nombre generico \'%s\'\n", archivoEjecucion);
    } 
    else if(strcmp(archivoTraza, archivoEjecucion)==0)
    {
        archivoEjecucion = "archivoEjecucion.csv";
        printf("Nombre repetido detectado. Optando por nombre generico \'%s\'\n", archivoEjecucion);
    }
    else
    {
        printf("Has seleccionado el archivo: %s\n", archivoEjecucion);
    }
    printf("\n");

     //*DEBUG*/ printf("Fin funcion ObtenerNombresArchivo\n");
    return;
}

//Procedimiento que anula todos los nombres para archivos utilizados en el programa
void AnularNombresArchivo(  char* archivoInstrucciones, 
                            char* archivoControl, 
                            char* archivoTraza,
	                        char* archivoEjecucion)
{
    free(archivoInstrucciones); 
    free(archivoControl); 
    free(archivoTraza);
	free(archivoEjecucion);
    return;
}