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

#include "funcionario.h"

Funcionario::Funcionario(int id_,
						std::string funcao_,
						std::string nome_,
						std::string cpf_,
						short idade_,
						std::string tipo_sanguineo_,
						char fator_rh_,
						std::string especialidade_):
	m_id(id_),
	m_funcao(funcao_),
	m_nome(nome_),
	m_cpf(cpf_),
	m_idade(idade_),
	m_tipo_sanguineo(tipo_sanguineo_),
	m_fator_rh(fator_rh_),
	m_especialidade(especialidade_){}

Funcionario::~Funcionario(){}

/*
====================================
MÉTODOS GETTERS
====================================
*/

int
Funcionario::getId(){
	return this->m_id;
}

std::string
Funcionario::getFuncao(){
	return this->m_funcao;
}

std::string
Funcionario::getNome(){
	return this->m_nome;
}

std::string
Funcionario::getCpf(){
	return this->m_cpf;
}

short
Funcionario::getIdade(){
	return this->m_idade;
}

std::string
Funcionario::getTipo_sanguineo(){
	return this->m_tipo_sanguineo;
}

char
Funcionario::getFator_rh(){
	return this->m_fator_rh;
}

std::string
Funcionario::getEspecialidade(){
	return this->m_especialidade;
}


/*
====================================
MÉTODOS SETTERS
====================================
*/

void
Funcionario::setId(int id_){
	this->m_id = id_;
}

void
Funcionario::setNome(std::string nome_){
	this->m_nome = nome_;
}

void
Funcionario::setCpf(std::string cpf_){
	this->m_cpf = cpf_;
}

void
Funcionario::setIdade(short idade_){
	this->m_idade = idade_;
}

void
Funcionario::setTipo_sanguineo(std::string tipo_sanguineo_){
	this->m_tipo_sanguineo = tipo_sanguineo_;
}

void
Funcionario::setFator_rh(char fator_rh_){
	this->m_fator_rh = fator_rh_;
}

void
Funcionario::setEspecialidade(std::string especialidade_){
	this->m_especialidade = especialidade_;
}


/*
====================================
MÉTODOS DE IMPRESSAO
====================================
*/
