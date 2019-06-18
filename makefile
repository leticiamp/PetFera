# Makefile da disciplina Linguagem de Programação I
# Alunos: André Vitor Macedo Soares, Letícia Moura Pinheiro e odilon Júlio dos Santos
# Projeto PetFera

CC = g++
PROG = $(BIN)/Projeto-LPI

OBJ = ./build
SRC = ./src
BIN = ./bin
INC = ./include

CPPFLAGS = -Wall -pedantic -std=c++11 -I $(INC) -g -O0

OBJS = $(OBJ)/anfibio.o $(OBJ)/anfibioExotico.o $(OBJ)/anfibioNativo.o $(OBJ)/animal.o \
	$(OBJ)/animalExotico.o $(OBJ)/animalNativo.o $(OBJ)/animalSilvestre.o $(OBJ)/ave.o $(OBJ)/aveExotico.o \
	$(OBJ)/aveNativo.o $(OBJ)/funcionario.o $(OBJ)/tratador.o $(OBJ)/veterinario.o $(OBJ)/mamifero.o \
	$(OBJ)/mamiferoExotico.o $(OBJ)/mamiferoNativo.o $(OBJ)/reptil.o $(OBJ)/reptilExotico.o $(OBJ)/reptilNativo.o \
	$(OBJ)/system.o $(OBJ)/main.o

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(OBJ)
	mkdir -p $(BIN)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/anfibio.o:$(INC)/anfibio.h
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibio.cpp -o $(OBJ)/anfibio.o

$(OBJ)/anfibioExotico.o: $(INC)/anfibioExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibioExotico.cpp -o $(OBJ)/anfibioExotico.o

$(OBJ)/anfibioNativo.o: $(INC)/anfibioNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibioNativo.cpp -o $(OBJ)/anfibioNativo.o

$(OBJ)/animal.o: $(INC)/animal.h
	$(CC) $(CPPFLAGS) -c $(SRC)/animal.cpp -o $(OBJ)/animal.o

$(OBJ)/animalExotico.o: $(INC)/animalExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/animalExotico.cpp -o $(OBJ)/animalExotico.o

$(OBJ)/animalNativo.o: $(INC)/animalNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/animalNativo.cpp -o $(OBJ)/animalNativo.o

$(OBJ)/animalSilvestre.o: $(INC)/animalSilvestre.h
	$(CC) $(CPPFLAGS) -c $(SRC)/animalSilvestre.cpp -o $(OBJ)/animalSilvestre.o

$(OBJ)/ave.o: $(INC)/ave.h
	$(CC) $(CPPFLAGS) -c $(SRC)/ave.cpp -o $(OBJ)/ave.o

$(OBJ)/aveExotico.o: $(INC)/aveExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/aveExotico.cpp -o $(OBJ)/aveExotico.o

$(OBJ)/aveNativo.o: $(INC)/aveNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/aveNativo.cpp -o $(OBJ)/aveNativo.o

$(OBJ)/funcionario.o: $(INC)/funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $(OBJ)/funcionario.o

$(OBJ)/tratador.o: $(INC)/tratador.h
	$(CC) $(CPPFLAGS) -c $(SRC)/tratador.cpp -o $(OBJ)/tratador.o

$(OBJ)/veterinario.o: $(INC)/veterinario.h
	$(CC) $(CPPFLAGS) -c $(SRC)/veterinario.cpp -o $(OBJ)/veterinario.o

$(OBJ)/mamifero.o: $(INC)/mamifero.h
	$(CC) $(CPPFLAGS) -c $(SRC)/mamifero.cpp -o $(OBJ)/mamifero.o

$(OBJ)/mamiferoExotico.o: $(INC)/mamiferoExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/mamiferoExotico.cpp -o $(OBJ)/mamiferoExotico.o

$(OBJ)/mamiferoNativo.o: $(INC)/mamiferoNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/mamiferoNativo.cpp -o $(OBJ)/mamiferoNativo.o

$(OBJ)/reptil.o: $(INC)/reptil.h
	$(CC) $(CPPFLAGS) -c $(SRC)/reptil.cpp -o $(OBJ)/reptil.o

$(OBJ)/reptilExotico.o: $(INC)/reptilExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/reptilExotico.cpp -o $(OBJ)/reptilExotico.o

$(OBJ)/reptilNativo.o: $(INC)/reptilNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/reptilNativo.cpp -o $(OBJ)/reptilNativo.o

$(OBJ)/system.o: $(INC)/system.h
	$(CC) $(CPPFLAGS) -c $(SRC)/system.cpp -o $(OBJ)/system.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean:
	rm -f $(BIN)/*
	rm -f $(OBJ)/*
