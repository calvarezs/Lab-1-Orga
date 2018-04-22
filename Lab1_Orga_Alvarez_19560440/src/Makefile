IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib 


_DEPS = Includes.h Registro.h LineasControl.h Programa.h Procedimiento.h Stack.h ObtenerNombresArchivo.h ObtenerPrograma.h EjecutarProgramaMIPS.h ImprimirInstruccion.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Main.o Registro.o LineasControl.o Programa.o Procedimiento.o Stack.o ObtenerNombresArchivo.o ObtenerPrograma.o EjecutarProgramaMIPS.o ImprimirInstruccion.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Para Linux intercambiar a CompiMIPS.out
#Para Windows intercambiar a CompiMIPS.exe
#Ejecucion usando el comando 'make' en terminal o bloque de comandos segun corresponda
CompiMIPS.out: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 

.PHONY: clean

#Ejecutar comando 'make clean' en caso de cambio de código o cambio del sistema operativo usado

clean:
	rm -f $(ODIR)/*.o *.exe *.out