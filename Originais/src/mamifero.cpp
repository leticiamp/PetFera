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

#include "mamifero.h"

Mamifero::Mamifero(){}

Mamifero::Mamifero(string m_classe, int m_id) {
	cout << "Cor do pêlo: ";
	cin >> m_cor_pelo;
}

string Mamifero::getCorPelo(){
	return m_cor_pelo;
}

void Mamifero::setCorPelo(string cor_pelo_) {
	m_cor_pelo = cor_pelo_;
}

Mamifero::~Mamifero(){}