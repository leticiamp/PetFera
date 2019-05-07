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

#ifndef _ANIMAL_EXOTICO_H_
#define _ANIMAL_EXOTICO_H_

#include <string>
#include "animalSilvestre.h"

using namespace std;

class AnimalExo : public AnimalSilv{
	private:

	protected:
		string m_pais_origem;
		string m_pais_origem;
		/* Certamente é erro duplicar. Assim, consta
		no PDF. Verificar com o Prof. */
	public:
		AnimalExo();
		~AnimalExo();

};

#endif // _ANIMAL_EXOTICO_H_