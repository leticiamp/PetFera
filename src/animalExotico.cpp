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

AnimalExo::AnimalExo(std::string pais_origem_,
										 std::string cidade_origem_,
										 std::string auto_ibama_):
										 m_pais_origem(pais_origem_),
										 m_cidade_origem(cidade_origem_),
										 AnimalSilv(auto_ibama_)
{}

AnimalExo::~AnimalExo(){}

std::string
AnimalExo::getPaisOrigem() {
	return this->m_pais_origem;
}

std::string
AnimalExo::getCidadeOrigem() {
	return tihs->m_cidade_origem;
}
