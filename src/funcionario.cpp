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

#include "funcionario.h"

Funcionario::Funcionario():
	m_id(0),
	m_nome("Empty"),
	m_cpf("Empty"),
	m_idade(0),
	m_tipo_sanguineo(0),
	m_fator_rh("Empty"),
	m_especialidade("Empty"){

}

Funcionario::~Funcionario(){}