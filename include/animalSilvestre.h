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

#ifndef _ANIMAL_SILVESTRE_H_
#define _ANIMAL_SILVESTRE_H_

#include <string>

using namespace std;

class AnimalSilv{
	private:

	protected:
		string m_autorizacao_ibama;

	public:
		AnimalSilv(std::string auto_ibama_);
		~AnimalSilv();
};

#endif // _ANIMAL_SILVESTRE_H_
