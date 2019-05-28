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

Funcionario::Funcionario():
	m_id(0),
	m_nome("Empty"),
	m_cpf("Empty"),
	m_idade(0),
	m_tipo_sanguineo(0),
	m_fator_rh('-'),
	m_especialidade("Empty"){}

Funcionario::~Funcionario(){}

//get's
size_t Funcionario::getId(){
	return this->m_id;
}

std::string Funcionario::getNome(){
	return this->m_nome;
}

std::string Funcionario::getCpf(){
	return this->m_cpf;
}

short Funcionario::getIdade(){
	return this->m_idade;
}

std::string Funcionario::getTipo_sanguineo(){
	return this->m_tipo_sanguineo;
}
char Funcionario::getFator_rh(){
	return this->m_fator_rh;
}

std::string Funcionario::getEspecialidade(){
	return this->m_especialidade;
}

//set's

void Funcionario::setId(size_t id_){
	this->m_id = id_;
}
void Funcionario::setNome(std::string nome_){
	this->m_nome = nome_;
}
void Funcionario::setCpf(std::string cpf_){
	this->m_cpf = cpf_;
}
void Funcionario::setIdade(short idade_){
	this->m_idade = idade_;
}
void Funcionario::setTipo_sanguineo(std::string tipo_sanguineo_){
	this->m_tipo_sanguineo = tipo_sanguineo_;
}
void Funcionario::setFator_rh(char fator_rh_){
	this->m_fator_rh = fator_rh_;
}
void Funcionario::setEspecialidade(std::string especialidade_){
	this->m_especialidade = especialidade_;
}
