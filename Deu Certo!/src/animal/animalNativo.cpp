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

#include "animalNativo.h"

AnimalNat::AnimalNat(std::string uf_origem_,
											std::string auto_ibama_):
	m_uf_origem(uf_origem_),
	AnimalSilv(auto_ibama_)
{}

AnimalNat::~AnimalNat(){}

std::string
AnimalNat::getUfOrigem(){
	return this->m_uf_origem;
}

void
AnimalNat::setUfOrigem(std::string UfOrigem_) {
	this->m_uf_origem = UfOrigem_;
}
