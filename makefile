# Disciplina: Linguagem de Programação I
# Professor: Silvio Sampaio
# Alunos:
# ANDRE VITOR MACEDO SOARES
# LETICIA MOURA PINHEIRO
# ODILON JULIO DOS SANTOS
# Projeto Final "PetFera"
# =============================== MAKEFILE ===============================

CC = g++
PROG = superPet

OBJ = ./build
SRC = ./src
BIN = ./bin
INC = ./include
LIB = ./lib

CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC) -g -O0
ARCHIEVE = ar

OBJS = $(OBJ)/anfibio.o $(OBJ)/anfibioExotico.o $(OBJ)/anfibioNativo.o $(OBJ)/animal.o \
	$(OBJ)/animalExotico.o $(OBJ)/animalNativo.o $(OBJ)/animalSilvestre.o $(OBJ)/ave.o \
	$(OBJ)/aveExotico.o $(OBJ)/aveNativo.o $(OBJ)/funcionario.o $(OBJ)/tratador.o \
	$(OBJ)/veterinario.o $(OBJ)/mamifero.o $(OBJ)/mamiferoExotico.o $(OBJ)/mamiferoNativo.o \
	$(OBJ)/reptil.o $(OBJ)/reptilExotico.o $(OBJ)/reptilNativo.o \
	$(OBJ)/arquivoNaoAberto.o $(OBJ)/system.o $(OBJ)/main.o

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(OBJ)
	mkdir -p $(BIN)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

linux: petfera.so prog_dinamico

petfera.so: $(SRC)/anfibio.cpp $(SRC)/anfibioExotico.cpp $(SRC)/anfibioNativo.cpp \
$(SRC)/animal.cpp $(SRC)/animalExotico.cpp $(SRC)/animalNativo.cpp $(SRC)/animalSilvestre.cpp \
$(SRC)/ave.cpp $(SRC)/aveExotico.cpp $(SRC)/aveNativo.cpp $(SRC)/funcionario.cpp $(SRC)/tratador.cpp \
$(SRC)/veterinario.cpp $(SRC)/mamifero.cpp $(SRC)/mamiferoExotico.cpp $(SRC)/mamiferoNativo.cpp \
$(SRC)/reptil.cpp $(SRC)/reptilExotico.cpp $(SRC)/reptilNativo.cpp $(INC)/petfera.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/anfibio.cpp -o $(OBJ)/anfibio.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/anfibioExotico.cpp -o $(OBJ)/anfibioExotico.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/anfibioNativo.cpp -o $(OBJ)/anfibioNativo.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/animal.cpp -o $(OBJ)/animal.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/animalExotico.cpp -o $(OBJ)/animalExotico.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/animalNativo.cpp -o $(OBJ)/animalNativo.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/animalSilvestre.cpp -o $(OBJ)/animalSilvestre.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/ave.cpp -o $(OBJ)/ave.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/aveExotico.cpp -o $(OBJ)/aveExotico.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/aveNativo.cpp -o $(OBJ)/aveNativo.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/funcionario.cpp -o $(OBJ)/funcionario.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/tratador.cpp -o $(OBJ)/tratador.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/veterinario.cpp -o $(OBJ)/veterinario.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/mamifero.cpp -o $(OBJ)/mamifero.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/mamiferoExotico.cpp -o $(OBJ)/mamiferoExotico.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/mamiferoNativo.cpp -o $(OBJ)/mamiferoNativo.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/reptil.cpp -o $(OBJ)/reptil.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/reptilExotico.cpp -o $(OBJ)/reptilExotico.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/reptilNativo.cpp -o $(OBJ)/reptilNativo.o

	$(CC) -shared -fPIC -o $(LIB)/$@ $(OBJ)/anfibio.o $(OBJ)anfibioExotico.o $(OBJ)/anfibioNativo.o \
	$(OBJ)/animal.o $(OBJ)/animalExotico.o $(OBJ)/animalNativo.o $(OBJ)/animalSilvestre.o $(OBJ)/ave.o \
	$(OBJ)/aveExotico.o $(OBJ)/aveNativo.o $(OBJ)/funcionario.o $(OBJ)/tratador.o $(OBJ)/veterinario.o \
	$(OBJ)/mamifero.o $(OBJ)/mamiferoExotico.o $(OBJ)/mamiferoNativo.o $(OBJ)/reptil.o $(OBJ)/reptilExotico.o \
	$(OBJ)/reptilNativo.o 

$(OBJ)/arquivoNaoAberto.o:$(INC)/arquivoNaoAberto.h
	$(CC) $(CPPFLAGS) -c $(SRC)/arquivoNaoAberto.cpp -o $(OBJ)/arquivoNaoAberto.o

$(OBJ)/system.o: $(INC)/system.h
	$(CC) $(CPPFLAGS) -c $(SRC)/system.cpp -o $(OBJ)/system.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o


prog_dinamico:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/petfera.so -o $(OBJ)/$@

clean:
	rm -f $(BIN)/*
	rm -f $(OBJ)/*