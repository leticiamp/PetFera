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

#include "animalSilvestre.h"

AnimalSilv::AnimalSilv(std::string auto_ibama_):
m_autorizacao_ibama(auto_ibama_)
{}

AnimalSilv::~AnimalSilv(){}

std::string AnimalSilv::getAutoIbama(){
  return this->m_autorizacao_ibama;
}

void AnimalSilv::setAutoIbama(std::string auto_ibama_){
  this->m_autorizacao_ibama = auto_ibama_;
}
