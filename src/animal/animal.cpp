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
#include <string>

#include "animal.h"


Animal::Animal( int id_,
				std::string classe_,
				std::string nome_cientifico_,
				char sexo_,
				double tamanho_,
				std::string dieta_,
				Veterinario * veterinario_,
				Tratador * tratador_,
				std::string nome_batismo_,
				std::string naturalidade_):
	m_id(id_),
	m_classe(classe_),
	m_nome_cientifico(nome_cientifico_),
	m_sexo(sexo_),
	m_tamanho(tamanho_),
	m_dieta(dieta_),
	m_veterinario(veterinario_),
	m_tratador(tratador_),
	m_nome_batismo(nome_batismo_),
	m_naturalidade(naturalidade_)
{}

Animal::~Animal(){}


/*
====================================
MÉTODOS GETTERS
====================================
*/

int
Animal::getId(){
	return this->m_id;
}

std::string
Animal::getClasse(){
	return this->m_classe;
}

std::string
Animal::getNome(){
	return this->m_nome_cientifico;
}

char
Animal::getSexo(){
	return this->m_sexo;
}

double
Animal::getTamanho(){
	return this->m_tamanho;
}

std::string
Animal::getDieta(){
	return this->m_dieta;
}

std::string
Animal::getNomeBatismo(){
	return this->m_nome_batismo;
}


std::string
Animal::getNaturalidade(){
	return this->m_naturalidade;
}


Veterinario *
Animal::getVeterinario(){
	return this->m_veterinario;
}

Tratador *
Animal::getTratador(){
	return this->m_tratador;
}



/*
====================================
MÉTODOS SETTERS
====================================
*/

void
Animal::setId(int id_){
	this->m_id = id_;
}

void
Animal::setClasse(std::string classe_){
	this->m_classe = classe_;
}

void
Animal::setNome(std::string nome_){
	this->m_nome_cientifico = nome_;
}

void
Animal::setSexo(char sexo_){
	this->m_sexo = sexo_;
}

void
Animal::setTamanho(double tamanho_){
	this->m_tamanho = tamanho_;
}

void
Animal::setDieta(std::string dieta_){
	this->m_dieta = dieta_;
}


void
Animal::setNomeBatismo(std::string nomeBatismo_){
	this->m_nome_batismo = nomeBatismo_;
}

void
Animal::setNaturalidade(std::string naturalidade_){
	this->m_naturalidade = naturalidade_;
}


void
Animal::setVeterinario(Veterinario* veterinario_){
	this->m_veterinario = veterinario_;
}

void
Animal::setTratador(Tratador* tratador_){
	this->m_tratador = tratador_;
}
