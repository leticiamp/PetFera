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

#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

#include <string>
#include "anfibio.h"
#include "animalExotico.h"

using namespace std;

class AnfibioExo : public Anfibio, AnimalExo{
	private:
		
	protected:

	public:
		AnfibioExo();
		~AnfibioExo();

};

#endif // _ANFIBIO_EXOTICO_H_