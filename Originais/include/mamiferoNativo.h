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

#ifndef _MAMIFERO_NATIVO_H_
#define _MAMIFERO_NATIVO_H_

#include <string>
#include "mamifero.h"
#include "animalNativo.h"

using namespace std;

class MamiferoNat : public Mamifero, AnimalNat{
	private:
		
	protected:

	public:
		MamiferoNat();
		~MamiferoNat();

};

#endif // _MAMIFERO_NATIVO_H_