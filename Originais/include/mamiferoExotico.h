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

#ifndef _MAMIFERO_EXOTICO_H_
#define _MAMIFERO_EXOTICO_H_

#include <string>
#include "mamifero.h"
#include "animalExotico.h"

using namespace std;

class MamiferoExo : public Mamifero, AnimalExo{
	private:
		
	protected:

	public:
		MamiferoExo();
		~MamiferoExo();

};

#endif // _MAMIFERO_EXOTICO_H_