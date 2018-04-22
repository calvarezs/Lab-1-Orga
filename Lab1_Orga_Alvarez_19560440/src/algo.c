#include "Includes.h"

//Funcion que extrae las instrucciones de un archivo de texto con instrucciones en MIPS 
//Entrada:  -Un archivo de texto con el nombre de un archivo válido con instrucciones de MIPS
//Salida:   -Un puntero a una estructura de datos tipo programa
void ObtenerPrograma(Programa* programa, char* nombreArchivo, int* ErrorFound)
{
    /*DEBUG*/ printf("Iniciando funcion ObtenerPrograma\n");
    //Revisiones de seguridad
    if(*ErrorFound == TRUE)
    {
        return;
    } 
printf("hola?");
    FILE* archivo;
    archivo = fopen(nombreArchivo, "r");
printf("hola?");
    if(archivo == NULL)
    {
        printf("Error de archivo. %s no existe.\n", nombreArchivo);
        *ErrorFound = TRUE;
        return;
    }  
printf("hola?");
    //Inicio de programa
    char linea[LARGO_MAXIMO_INSTRUCCION];
    char* fragmentoLinea; 
    
    char Etiqueta[LARGO_MAXIMO_ETIQUETA];
    char Procedimiento[LARGO_MAXIMO_PROCEDIMIENTO];
    char Registro1[LARGO_MAXIMO_REGISTRO];
    char Registro2[LARGO_MAXIMO_REGISTRO];
    char Registro3[LARGO_MAXIMO_REGISTRO];
    
    int largoLinea;
    int i;
    int finArchivo;
    int nRegistro;
    int verInstruccion;
    printf("hola??");

    fgets(linea, LARGO_MAXIMO_INSTRUCCION, archivo); 
    while(!feof(archivo))
    {
        Etiqueta[0] = '\0';
        Procedimiento[0] = '\0';
        Registro1[0] = '\0';
        Registro2[0] = '\0'; 
        Registro3[0] = '\0';

        printf("%s", Etiqueta);
        printf("%s", Procedimiento); 
        printf("%s", Registro1);
        printf("%s", Registro2);
        printf("%s", Registro3);

        verInstruccion = TRUE;
        //Si la linea es una instruccion con etiqueta 
        if(strpbrk(linea, ":")!=NULL && strpbrk(linea, "$")!=NULL)
        {   
            fragmentoLinea = strtok( linea, ":" );
            sscanf(fragmentoLinea," %s ",Etiqueta);  
            fragmentoLinea = strtok( NULL, " " ); 
            sscanf(fragmentoLinea," %s ",Procedimiento); 
            
        }
        //Si la linea es solo una etiqueta
        else if(strpbrk(linea, ":")!=NULL)
        {   
            verInstruccion = FALSE;
            fragmentoLinea = strtok( linea, ":" );
            sscanf(fragmentoLinea," %s ",Etiqueta);  
        }
        //Si la linea es una instruccion sin etiqueta
        else
        {
            fragmentoLinea = strtok( linea, " " );
            sscanf(fragmentoLinea," %s ",Procedimiento);  
             
        } 
        

        printf("%s", Procedimiento);
        printf("%s", Etiqueta);
        printf("%d", verInstruccion);
        
        nRegistro = 1; 
printf("%d", nRegistro);
        while( (strpbrk( linea, "$" )) != NULL && verInstruccion)
        { 
             
            printf("%d", nRegistro);
            switch(nRegistro)
            {
                case 1: 
                    fragmentoLinea = strtok( Registro1, "$" );
                    sscanf(fragmentoLinea," %s ",Registro1); 
                    break;
                case 2:
                    fragmentoLinea = strtok( Registro2, "$" );
                    sscanf(fragmentoLinea," %s ",Registro2);  
                    break;
                case 3:
                    fragmentoLinea = strtok( Registro3, "$" );
                    sscanf(fragmentoLinea," %s ",Registro3); 
                    break;
            }   
            nRegistro++;
        } 
        printf("hola");        
        InsertarEnPrograma(programa, CrearInstruccion(Etiqueta, Procedimiento, Registro1, Registro2, Registro3));
        printf("chao");

        fgets(linea, LARGO_MAXIMO_INSTRUCCION, archivo); 
    }
    
    fclose(archivo);

    /*DEBUG*/ printf("Fin funcion ObtenerPrograma\n");
    return;
}

//Funcion que extrae componentes de control de un archivo valido
//Entrada:  -Un archivo de texto con el nombre de un archivo válido con un listado logico
//Salida:   -Un puntero a una estructura de datos tipo LineasControl
void ObtenerListadoControl(char* nombreArchivo, LineasControl* lc, int* ErrorFound)
{
    /*DEBUG*/ printf("Iniciando funcion ObtenerListadoControl\n");
    if(*ErrorFound == TRUE)
    {
        return;
    } 
    
   // LineasControl* lc;
    FILE* archivo;
    char linea[LARGO_MAXIMO_INSTRUCCION];
    char nombre[LARGO_MAXIMO_INSTRUCCION];
    char estado[3];
    int intEstado;
    int finArchivo;

    archivo = fopen(nombreArchivo, "r");
    if(!archivo)
    {
        printf("Error de archivo. %s no existe o el nombre es incorrecto.\n", nombreArchivo);
        *ErrorFound = TRUE;
        return;
    }

    do
    {
        finArchivo = fscanf(archivo," %s %s ", nombre, estado );
        /*DEBUG*/ printf("ListaControl:  %s --> %s\n", nombre, estado);
        if(isdigit(estado[0]))
        {
            intEstado = 0;
        }
        else 
        {
            intEstado = 5;
        }
        ActualizarLineasControl(lc, nombre, intEstado);
    }while(finArchivo != EOF);
    
    fclose(archivo);
    /*DEBUG*/ printf("FIN funcion ObtenerListadoControl\n");
    return;
}