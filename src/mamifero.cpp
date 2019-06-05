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

#include "mamifero.h"

Mamifero::Mamifero(int id_,
									std::string classe_,
									std::string nome_cientifico_,
									char sexo_,
									double tamanho_,
									std::string dieta_,
									Veterinario * veterinario_,
									Tratador * tratador_,
									std::string nome_batismo_,
									std::string cor_pelo_) :
		  Animal(	id_,
							classe_,
							nome_cientifico_,
							sexo_,
							tamanho_,
							dieta_,
							veterinario_,
							tratador_,
							nome_batismo_),
			m_cor_pelo(cor_pelo_)
{}

Mamifero::~Mamifero(){}


std::string Mamifero::getCorPelo(){
	return this->m_cor_pelo;
}

void Mamifero::setCorPelo(std::string cor_pelo_) {
	this->m_cor_pelo = cor_pelo_;
}
