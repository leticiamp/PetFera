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

#ifndef _AVE_NATIVO_H_
#define _AVE_NATIVO_H_

#include <string>
#include "ave.h"
#include "animalNativo.h"

using namespace std;

class AveNat : public Ave, AnimalNat{
	private:
		
	protected:

	public:
		AveNat();
		~AveNat();

};

#endif // _AVE_NATIVO_H_