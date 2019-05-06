# Disciplina: Linguagem de Programação I
# Professor: Silvio Sampaio
# Alunos:
# ANDRE VITOR MACEDO SOARES
# LETICIA MOURA PINHEIRO
# ODILON JULIO DOS SANTOS
# Makefile do Projeto Final "PetFera"


# >>>>>>> FALTA EDITAR ABAIXO!!!!!! <<<<<<<<

CC = g++
PROG = $(BIN)/PetFera

OBJ = ./build
SRC = ./src
BIN = ./bin
INC = ./include

CPPFLAGS = -Wall -O0 -g -pedantic -std=c++11 -I$(INC)

OBJS = 	$(OBJ)/anfibio.o $(OBJ)/anfibioExotico.o $(OBJ)/anfibioNativo.o \
	   	$(OBJ)/ave.o $(OBJ)/aveExotico.o $(OBJ)/aveNativo.o \
		$(OBJ)/mamifero.o $(OBJ)/mamiferioExotico.o $(OBJ)/mamiferioNativo.o \
		$(OBJ)/reptil.o $(OBJ)/reptilExotico.o $(OBJ)/reptilNativo.o \
		$(OBJ)/animal.o $(OBJ)/animalExotico.o $(OBJ)/animalNativo.o $(OBJ)/animalSilvestre.o \
	   	$(OBJ)/data.o $(OBJ)/funcionario.o $(OBJ)/tratador.o $(OBJ)/veterinario.o \
	   	$(OBJ)/main.o

all: $(PROG)
	 $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/anfibio.o:$(INC)/anfibio.h
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibio.cpp -o $(OBJ)/anfibio.o

$(OBJ)/anfibioExotico.o:$(INC)/anfibioExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibioExotico.cpp -o $(OBJ)/anfibioExotico.o

$(OBJ)/anfibioNativo.o:$(INC)/anfibioNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/anfibioNativo.cpp -o $(OBJ)/anfibioNativo.o

$(OBJ)/ave.o:$(INC)/ave.h
	$(CC) $(CPPFLAGS) -c $(SRC)/ave.cpp -o $(OBJ)/ave.o

$(OBJ)/aveExotico.o:$(INC)/aveExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/aveExotico.cpp -o $(OBJ)/aveExotico.o

$(OBJ)/aveNativo.o:$(INC)/aveNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/aveNativo.cpp -o $(OBJ)/aveNativo.o

$(OBJ)/mamifero.o:$(INC)/mamifero.h
	$(CC) $(CPPFLAGS) -c $(SRC)/mamifero.cpp -o $(OBJ)/mamifero.o

$(OBJ)/mamiferioExotico.o:$(INC)/mamiferioExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/mamiferioExotico.cpp -o $(OBJ)/mamiferioExotico.o

$(OBJ)/mamiferioNativo.o:$(INC)/mamiferioNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/mamiferioNativo.cpp -o $(OBJ)/mamiferioNativo.o

$(OBJ)/reptil.o:$(INC)/reptil.h
	$(CC) $(CPPFLAGS) -c $(SRC)/reptil.cpp -o $(OBJ)/reptil.o

$(OBJ)/reptilExotico.o:$(INC)/reptilExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/reptilExotico.cpp -o $(OBJ)/reptilExotico.o

$(OBJ)/reptilNativo.o:$(INC)/reptilNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/reptilNativo.cpp -o $(OBJ)/reptilNativo.o

$(OBJ)/animal.o:$(INC)/animal.h
	$(CC) $(CPPFLAGS) -c $(SRC)/animal.cpp -o $(OBJ)/animal.o

$(OBJ)/animalExotico.o:$(INC)/animalExotico.h
	$(CC) $(CPPFLAGS) -c $(SRC)/animalExotico.cpp -o $(OBJ)/animalExotico.o

$(OBJ)/animalNativo.o:$(INC)/animalNativo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/animalNativo.cpp -o $(OBJ)/animalNativo.o

$(OBJ)/animalSilvestre.o:$(INC)/animalSilvestre.h
	$(CC) $(CPPFLAGS) -c $(SRC)/animalSilvestre.cpp -o $(OBJ)/animalSilvestre.o

$(OBJ)/data.o:$(INC)/data.h
	$(CC) $(CPPFLAGS) -c $(SRC)/data.cpp -o $(OBJ)/data.o

$(OBJ)/funcionario.o:$(INC)/funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $(OBJ)/funcionario.o

$(OBJ)/tratador.o:$(INC)/tratador.h
	$(CC) $(CPPFLAGS) -c $(SRC)/tratador.cpp -o $(OBJ)/tratador.o

$(OBJ)/veterinario.o:$(INC)/veterinario.h
	$(CC) $(CPPFLAGS) -c $(SRC)/veterinario.cpp -o $(OBJ)/veterinario.o

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*