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


class AnimalNat : public AnimalSilv {
	private:

	protected:
		std::string m_uf_origem;
	public:
		AnimalNat(std::string uf_origem_,
							std::string auto_ibama_);
		~AnimalNat();

		std::string getUfOrigem();

		void setUfOrigem(std::string UfOrigem);

};

#endif // _ANIMAL_NATIVO_H_
