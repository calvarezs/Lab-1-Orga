#include "Includes.h"  

//Bloque Principal del programa 
int main()
{
	printf("**********INICIO DEL PROGRAMA***********\n"); 

//Inicio de componentes
	char* archivoInstrucciones;
	char* archivoControl;
	char* archivoTraza;
	char* archivoEjecucion;
	
	int* ErrorFound = (int*)malloc(sizeof(int)); 
	*ErrorFound = FALSE;
	
	LineasControl* LineasControl;
	Programa* ProgramaMIPS;
	Registro* registro;
	Instruccion* instruccionActual;
	Stack* stack;

//Asignacion de memoria local
	archivoInstrucciones = (char*)malloc(LARGO_MAXIMO_NOMBRE * sizeof(char));  
    archivoControl = (char*)malloc(LARGO_MAXIMO_NOMBRE * sizeof(char));  
    archivoTraza = (char*)malloc(LARGO_MAXIMO_NOMBRE * sizeof(char)); 
    archivoEjecucion = (char*)malloc(LARGO_MAXIMO_NOMBRE * sizeof(char)); 

	LineasControl = IniciarLineasControl();
	ProgramaMIPS = CrearPrograma();
	registro = IniciarRegistro();
	stack = IniciarStack();
	
//INGRESO DE DATOS
	ObtenerNombresArchivo(archivoInstrucciones, archivoControl, archivoTraza, archivoEjecucion);  

//Procesar Lneas de control
	ObtenerListadoControl(archivoControl, LineasControl, ErrorFound);

//Procesar programa mips  
	ObtenerPrograma(ProgramaMIPS, archivoInstrucciones, ErrorFound);
	Instruccion* actual = ProgramaMIPS->Cabeza;
	while(actual!=NULL)
	{ 
		actual=actual->Siguiente;
	}

//Ejecutar funciones MIPS
	EjecutarProgramaMIPS(archivoTraza, archivoEjecucion, ProgramaMIPS, stack, registro, LineasControl);

//Liberando memoria utilizada
	/*DEBUG*/printf("Cerrando programa\n");
	AnularStack(stack);
	AnularRegistros(registro);
	AnularPrograma(ProgramaMIPS);
	AnularLineasControl(LineasControl);
	free(ErrorFound);
	AnularNombresArchivo(archivoInstrucciones, archivoControl, archivoTraza, archivoEjecucion);

//Fin de programa
	printf("Fin de programa. Presione Enter para terminar.\n");
	getchar();
	printf("**********TERMINO DEL PROGRAMA**********\n");
	return 0;
}