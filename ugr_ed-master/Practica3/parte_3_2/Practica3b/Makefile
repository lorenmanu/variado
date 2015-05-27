SHELL = /bin/bash
SRC = .
BIN = .
OBJ = .
INC = .
LIB = .
RM = rm -Rf
GCC = g++
GCCFLAG= -m32 -g -L$(LIB) -I$(INC) -O0 -c #-Wall
BINFLAGS = -m32 -g -L$(LIB) -I$(INC) -O0 #-Wall

.SECONDARY:

all: touch diccionario_V1 diccionario_V2

doc:
	doxygen dox_diccionario

diccionario_V1.o: 
	$(GCC) -D DICC_V1 $(GCCFLAG) $(SRC)/prueba.cpp -o $(OBJ)/$@ 

diccionario_V2.o: 
	$(GCC) -D DICC_V2 $(GCCFLAG) $(SRC)/prueba.cpp -o $(OBJ)/$@
	
diccionario_V1: diccionario_V1.o
	$(GCC) $(BINFLAGS) $(OBJ)/$^ -o $(BIN)/$@

diccionario_V2: diccionario_V2.o
	$(GCC) $(BINFLAGS) $(OBJ)/$^ -o $(BIN)/$@ 
	
clean:
	$(RM) $(BIN)/diccionario_V? $(OBJ)/*.o doxygen

touch:
	touch $(SRC)/*
	touch $(INC)/*