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

#ifndef _ANIMAL_NATIVO_H_
#define _ANIMAL_NATIVO_H_

#include <string>
#include "animalSilvestre.h"

using namespace std;

class AnimalNat : public AnimalSilv {
	private:

	protected:
		string m_uf_origem;
		string m_autorizacao;
	public:
		AnimalNat();
		~AnimalNat();

};

#endif // _ANIMAL_NATIVO_H_