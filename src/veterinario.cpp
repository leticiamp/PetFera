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

#include "veterinario.h"

Veterinario::Veterinario():
	m_crmv("Empty"),
	m_id(0),
	m_nome("Empty"),
	m_cpf("Empty"),
	m_idade(0),
	m_tipo_sanguineo(0),
	m_fator_rh("Empty"),
	m_especialidade("Empty"){

}

Veterinario::~Veterinario(){}