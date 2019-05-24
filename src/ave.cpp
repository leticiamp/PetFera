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

#include "ave.h"

Ave::Ave():Animal(){}

Ave::~Ave(){}

double getTamanhoBicoCm() {
	return m_tamanho_do_bico_cm;
}
double getEnvergaduraAsas() {
	return m_envergadura_das_asas;
}

void setTamanhoBicoCm(double tamanho_do_bico_cm_) {
	m_tamanho_do_bico_cm = tamanho_do_bico_cm_;
}

void setEnevergaduraAsas(double envergadura_das_asas_) {
	m_envergadura_das_asas = envergadura_das_asas_;
}