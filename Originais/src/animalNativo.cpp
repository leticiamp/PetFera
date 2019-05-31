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

using namespace std;

#include "animalNativo.h"

AnimalNat::AnimalNat():AnimalSilv(){}

AnimalNat::~AnimalNat(){}

std::string 
AnimalNat::getUfOrigem(){
	return m_uf_origem;
}

std::string 
AnimalNat::getAutorizacao() {
	return m_autorizacao;
}