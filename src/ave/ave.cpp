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

#include "ave.h"

//Construtor
Ave::Ave(int id_,
				std::string classe_,
				std::string nome_cientifico_,
				char sexo_,
				double tamanho_,
				std::string dieta_,
				Veterinario * veterinario_,
				Tratador * tratador_,
				std::string nome_batismo_,
				double tamanho_do_bico_cm_,
				double envergadura_das_asas_) :
	Animal(	id_,
					classe_,
					nome_cientifico_,
					sexo_,
					tamanho_,
					dieta_,
					veterinario_,
					tratador_,
					nome_batismo_),
	m_tamanho_do_bico_cm(tamanho_do_bico_cm_),
	m_envergadura_das_asas(envergadura_das_asas_)
{}

//Destrutor
Ave::~Ave(){}

//get's
double
Ave::getTamanhoBicoCm(){
	return this->m_tamanho_do_bico_cm;
}

double
Ave::getEnvergaduraAsas(){
	return this->m_envergadura_das_asas;
}

//set's
void
Ave::setTamanhoBicoCm(double tamanho_do_bico_cm_){
	this->m_tamanho_do_bico_cm = tamanho_do_bico_cm_;
}

void
Ave::setEnevergaduraAsas(double envergadura_das_asas_){
	this->m_envergadura_das_asas = envergadura_das_asas_;
}
