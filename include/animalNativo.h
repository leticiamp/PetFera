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

using namespace std;

class AnimalNat{
	private:
		string m_uf_origem;
		string m_autorizacao;
	protected:

	public:
		AnimalNat();
		~AnimalNat();

};

#endif // _ANIMAL_NATIVO_H_