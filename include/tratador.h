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

#ifndef _TRATADOR_H_
#define _TRATADOR_H_

#include <string>
#include "funcionario.h"

using namespace std;

class Tratador : public Funcionario{
	private:
		int m_nivel_de_seguranca;
		
	protected:

	public:
		Tratador();
		~Tratador();

};

#endif // _TRATADOR_H_