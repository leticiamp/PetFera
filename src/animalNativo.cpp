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

AnimalNat::AnimalNat(){}

AnimalNat::~AnimalNat(){}

std::string getUfOrigem() {
	return m_uf_origem;
}

std::string getAutorizacao() {
	return m_autorizacao;
}