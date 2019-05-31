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
		std::string m_autorizacao;
	public:
		AnimalNat();
		~AnimalNat();

		std::string getUfOrigem();
		std::string getAutorizacao();

};

#endif // _ANIMAL_NATIVO_H_