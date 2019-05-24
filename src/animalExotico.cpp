/*
# Disciplina: Linguagem de Programação I
# Professor: Silvio Sampaio
# Alunos:
# ANDRE VITOR MACEDO SOARES
# LETICIA MOURA PINHEIRO
# ODILON JULIO DOS SANTOS
# Projeto Final "PetFera"
===========================================================================
*/

#include <iostream>

#include "animalExotico.h"

AnimalExo::AnimalExo(){}

AnimalExo::~AnimalExo(){}

std::string getPaisOrigem() {
	return m_pais_origem;
}

std::string getCidadeOrigem() {
	return m_cidade_origem;
}