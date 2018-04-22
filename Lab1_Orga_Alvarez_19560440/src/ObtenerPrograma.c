#include "Includes.h"

//Funcion que extrae las instrucciones de un archivo de texto con instrucciones en MIPS 
//Entrada:  -Un archivo de texto con el nombre de un archivo válido con instrucciones de MIPS
//Salida:   -Un puntero a una estructura de datos tipo programa
void ObtenerPrograma(Programa* programa, char* nombreArchivo, int* ErrorFound)
{ 
    //*DEBUG*/ printf("Inicio obtener programa\n");
    if(*ErrorFound == TRUE)
    {
        return;
    }
    
    //*DEBUG*/ printf("Revisando archivo \n");
    FILE* archivo;
    archivo = fopen(nombreArchivo, "r");
    if(!archivo)
    {
        *ErrorFound = TRUE;
        return;
    }

    char* linea = (char*)malloc(LARGO_MAXIMO_INSTRUCCION * sizeof(char));
    char* fragmentoLinea = (char*)malloc(LARGO_MAXIMO_INSTRUCCION * sizeof(char));
    int i,aux,leerRegistro;

    while(!feof(archivo))
    {
        char* Etiqueta = (char*)malloc(LARGO_MAXIMO_ETIQUETA * sizeof(char));
        char* Procedimiento = (char*)malloc(LARGO_MAXIMO_PROCEDIMIENTO * sizeof(char));
        char* Registro1 = (char*)malloc(LARGO_MAXIMO_REGISTRO * sizeof(char));
        char* Registro2 = (char*)malloc(LARGO_MAXIMO_REGISTRO * sizeof(char));
        char* Registro3 = (char*)malloc(LARGO_MAXIMO_REGISTRO * sizeof(char));

        fgets(linea, LARGO_MAXIMO_INSTRUCCION, archivo);
 
        Etiqueta[0] = '\0';
        Procedimiento[0] = '\0';
        Registro1[0] = '\0';
        Registro2[0] = '\0'; 
        Registro3[0] = '\0';
 

        //Si la linea tiene ":"
        if(strpbrk(linea, ":")!=NULL)
        {
            if(strpbrk(linea, "$")!=NULL)
            {
                fragmentoLinea = strtok( linea, ":" );
                //*DEBUG*/printf("Posible Etiqueta: |%s|\n",fragmentoLinea);
                sscanf(fragmentoLinea," %s ",Etiqueta);

                fragmentoLinea = strtok( NULL, " " );
                //*DEBUG*/printf("Posible Proc: |%s|\n",fragmentoLinea);
                sscanf(fragmentoLinea," %s ",Procedimiento); 

                leerRegistro = TRUE;
            }
            else
            { 
                fragmentoLinea = strtok( linea, ":" );
                //*DEBUG*/printf("Posible Etiqueta: |%s|\n",fragmentoLinea);
                sscanf(fragmentoLinea," %s ",Etiqueta);

                fragmentoLinea = strtok( NULL, " " );
                if(fragmentoLinea!=NULL)
                {
                    //*DEBUG*/printf("Posible Proc: |%s|\n",fragmentoLinea);
                    sscanf(fragmentoLinea," %s ",Procedimiento); 
                    
                    fragmentoLinea = strtok( NULL, " " );
                    if(fragmentoLinea!=NULL)
                    {
                        //*DEBUG*/printf("Posible Reg1: |%s|\n",fragmentoLinea);
                        sscanf(fragmentoLinea," %s ",Registro1);     
                    }  
                } 
                leerRegistro = FALSE;
            }             
        }
        //Si la linea no tiene ":"
        else
        {
            if(strpbrk(linea, "$")!=NULL)
            { 
                fragmentoLinea = strtok( linea, " " );
                //*DEBUG*/printf("Posible Proc: |%s|\n",fragmentoLinea);
                sscanf(fragmentoLinea," %s ",Procedimiento); 

                leerRegistro = TRUE;
            }
            else
            {
                fragmentoLinea = strtok( linea, " " );
                //*DEBUG*/printf("Posible Proc: |%s|\n",fragmentoLinea);
                sscanf(fragmentoLinea," %s ",Procedimiento); 

                fragmentoLinea = strtok( NULL, " " );
                if(fragmentoLinea!=NULL)
                {
                    //*DEBUG*/printf("Posible Reg1: |%s|\n",fragmentoLinea);
                    sscanf(fragmentoLinea," %s ",Registro1); 
                } 
                leerRegistro = FALSE;
            }
        }
         
        if(leerRegistro)
        {
            //Obtener primer registro
            fragmentoLinea = strtok( NULL, "," );
            if(fragmentoLinea!=NULL)
            { 
                //*DEBUG*/printf("Posible Reg1: |%s|\n",fragmentoLinea);
                aux=0;
                for(i=0;i<strlen(fragmentoLinea);i++)
                {
                    if(fragmentoLinea[i] != ' ')
                    {
                        Registro1[aux] = fragmentoLinea[i];
                        aux++;
                    }
                }
                Registro1[aux] = '\0';
            
            //Obtener segundo registro
                fragmentoLinea = strtok( NULL, "," );
                if(fragmentoLinea!=NULL)
                { 
                    //*DEBUG*/printf("Posible Reg2: |%s|\n",fragmentoLinea);
                    aux=0;
                    for(i=0;i<strlen(fragmentoLinea);i++)
                    {
                        if(fragmentoLinea[i] != ' ')
                        {
                            Registro2[aux] = fragmentoLinea[i];
                            aux++;
                        }
                    }
                    Registro2[aux] = '\0';
                
                //obtener 3er registro
                    fragmentoLinea = strtok( NULL, "," ); 
                    if(fragmentoLinea!=NULL)
                    { 
                        //*DEBUG*/printf("Posible Reg3: |%s|\n",fragmentoLinea);
                        aux=0;
                        for(i=0;i<strlen(fragmentoLinea);i++)
                        {
                            if(fragmentoLinea[i] != ' ')
                            {
                                Registro3[aux] = fragmentoLinea[i];
                                aux++;
                            }
                        }
                        Registro3[aux] = '\0';
                    } 
                }
            } 
        }
        /*DEBUG*/printf("|%s|:|%s|%s|%s|%s|\n",Etiqueta, Procedimiento, Registro1, Registro2, Registro3);
        Instruccion* instruccion = CrearInstruccion(Etiqueta, Procedimiento, Registro1, Registro2, Registro3);
        /*DEBUG*/printf("|%s|",instruccion->Etiqueta);
        /*DEBUG*/printf("->|%s|:",instruccion->EtiquetaObjetivo);
        /*DEBUG*/printf("|%d|%d|%d|%d|\n\n", instruccion->Procedimiento, instruccion->Registro1, instruccion->Registro2, instruccion->Registro3);
        InsertarEnPrograma(programa, instruccion);
        free(Etiqueta);
        free(Procedimiento);
        free(Registro1);
        free(Registro2); 
        free(Registro3); 
    } 
    //*DEBUG*/printf("Cerrar archivo\n"); 
    free(linea);
    free(fragmentoLinea);
    fclose(archivo);

    //*DEBUG*/ printf("Fin funcion ObtenerPrograma\n");
    return;
}

//Funcion que extrae componentes de control de un archivo valido
//Entrada:  -Un archivo de texto con el nombre de un archivo válido con un listado logico
//Salida:   -Un puntero a una estructura de datos tipo LineasControl
void ObtenerListadoControl(char* nombreArchivo, LineasControl* lc, int* ErrorFound)
{
    //*DEBUG*/ printf("Iniciando funcion ObtenerListadoControl\n");
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
        //*DEBUG*/ printf("ListaControl:  %s --> %s\n", nombre, estado);
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
    //*DEBUG*/ printf("FIN funcion ObtenerListadoControl\n");
    return;
}