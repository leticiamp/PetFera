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

AnimalExo::AnimalExo():AnimalSilv()
{}

AnimalExo::~AnimalExo(){}

std::string 
AnimalExo::getPaisOrigem() {
	return m_pais_origem;
}

std::string 
AnimalExo::getCidadeOrigem() {
	return m_cidade_origem;
}