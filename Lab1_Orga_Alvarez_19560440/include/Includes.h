#ifndef INCLUDES_H
#define INCLUDES_H

//Definicion de librerias ANSI utilizadas
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>  
#include <string.h>

//Definicion de librerias propias utilizadas
#include "Registro.h"
#include "LineasControl.h"
#include "Programa.h"
#include "Stack.h"
#include "Procedimiento.h"

#include "ObtenerNombresArchivo.h"
#include "ObtenerPrograma.h"
#include "EjecutarProgramaMIPS.h" 
#include "ImprimirInstruccion.h"  

//Definicion de tipo de dato bool
#define TRUE 1
#define FALSE 0  

//Definicion posiciones lineas control
#define REGDST 0
#define JUMP 1
#define BRANCH 2
#define MEMREAD 3
#define MEMTOREG 4
#define ALUOP 5
#define MEMWRITE 6
#define ALUSRC 7
#define REGWRITE 8

//Definicion constantes instrucciones
    //Instrucciones tipo I
#define ADDI 101
#define SUBI 102
#define BEQ  121
#define LW   131
#define SW   132
    //Instrucciones tipo R
#define ADD  201
#define SUB  202
#define MULT 203
#define DIV  204
#define MFHI 205
#define MFLO 206
    //Instrucciones tipo J
#define JUMPTO 300   

//Definicion constantes
#define LARGO_MAXIMO_INSTRUCCION 40
#define LARGO_MAXIMO_ETIQUETA 15
#define LARGO_MAXIMO_PROCEDIMIENTO 5
#define LARGO_MAXIMO_REGISTRO 4
#define LARGO_MAXIMO_NOMBRE 20 
#define TAMANIO_STACK 3000

#endif