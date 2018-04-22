#include "Includes.h"

//Funcion constructor
Stack* IniciarStack()
{
    Stack* resultante;
    resultante = (Stack*)malloc(sizeof(Stack));
    resultante->Datos = (int*)calloc(TAMANIO_STACK,sizeof(int));
    return resultante;
}

//Funcion obtener
int ObtenerDeStack(Stack* stack, int pos)
{
	int desfaseStack =  TAMANIO_STACK/2;
	pos = desfaseStack + pos;
	/*DEBUG*/ printf("posicion a leer: %d\n", pos);
	if(pos >= TAMANIO_STACK || pos < 0)
	{
		printf("Valor fuera de stack\n");
		return 0;
	}
    return stack->Datos[pos];
}

//Funcion modificar
void ModificarStack(Stack* stack, int pos, int dato)
{
	int desfaseStack =  TAMANIO_STACK/2;
	pos = desfaseStack + pos;
	/*DEBUG*/ printf("posicion a cambiar: %d\n", pos);
	if(pos >= TAMANIO_STACK || pos < 0)
	{
		printf("Valor fuera de stack\n");
		return;
	}
    stack->Datos[pos] = dato;
    return;
}

//Funcion anular
void AnularStack(Stack* stack)
{
    free(stack->Datos);
    free(stack);
}