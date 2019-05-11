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


//		friend ostream& operator<< ( ostream& output, const Tratador& tratadorTal);
//		friend istream& operator>> ( istream& input, Tratador& tratadorTal);

};

#endif // _TRATADOR_H_