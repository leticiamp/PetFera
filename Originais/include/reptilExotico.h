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

#ifndef _REPTIL_EXOTICO_H_
#define _REPTIL_EXOTICO_H_

#include <string>
#include "reptil.h"
#include "animalExotico.h"

using namespace std;

class ReptilExo : public Reptil, AnimalExo{
	private:
		
	protected:

	public:
		ReptilExo();
		~ReptilExo();

};

#endif // _REPTIL_EXOTICO_H_