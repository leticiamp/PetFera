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

#ifndef _ANFIBIO_NATIVO_H_
#define _ANFIBIO_NATIVO_H_

#include <string>
#include "anfibio.h"
#include "animalNativo.h"

using namespace std;

class AnfibioNat : public Anfibio, AnimalNat{
	private:
		
	protected:

	public:
		AnfibioNat();
		~AnfibioNat();

};

#endif // _ANFIBIO_NATIVO_H_