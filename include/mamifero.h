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

#ifndef _MAMIFERO_H_
#define _MAMIFERO_H_

#include <string>
#include "animal.h"

using namespace std;

class Mamifero : public Animal{
	private:
		
	protected:
		string m_cor_pelo;
	public:
		Mamifero();
		~Mamifero();

};

#endif // _MAMIFERO_H_