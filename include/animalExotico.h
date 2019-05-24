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

class AnimalExo : public AnimalSilv{
	private:

	protected:
		std::string m_pais_origem;
		std::string m_cidade_origem;

	public:
		AnimalExo();
		~AnimalExo();

		std::string getPaisOrigem();
		std::string getCidadeOrigem();
};

#endif // _ANIMAL_EXOTICO_H_