# Disciplina: Linguagem de Programação I
# Professor: Silvio Sampaio
# Alunos:
# ANDRE VITOR MACEDO SOARES
# LETICIA MOURA PINHEIRO
# ODILON JULIO DOS SANTOS
# Makefile do Projeto Final "PetFera"


# >>>>>>> FALTA EDITAR ABAIXO!!!!!! <<<<<<<<

CC = g++
PROG = $(BIN)/Jogo

OBJ = ./build
SRC = ./src
BIN = ./bin
INC = ./include

CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

OBJS = $(OBJ)/dado.o $(OBJ)/jogador.o $(OBJ)/jogo.o $(OBJ)/main.o

all: $(PROG)
	$(PROG)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/dado.o: $(INC)/dado.h
	$(CC) $(CPPFLAGS) -c $(SRC)/dado.cpp -o $(OBJ)/dado.o

$(OBJ)/jogador.o: $(INC)/jogador.h
	$(CC) $(CPPFLAGS) -c $(SRC)/jogador.cpp -o $(OBJ)/jogador.o

$(OBJ)/jogo.o: $(INC)/jogo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/jogo.cpp -o $(OBJ)/jogo.o


$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*