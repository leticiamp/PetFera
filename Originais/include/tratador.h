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

class Tratador : public Funcionario{
	private:
		int m_nivel_de_seguranca;

	protected:

	public:
		Tratador();
		~Tratador();

		//get's
		int getNivel_de_Seguranca();

		//set's
		void setNivel_de_Seguranca(int nivel_de_seguranca_);

		friend std::ostream& operator<< ( std::ostream& output, const Tratador& tratadorTal);
//		friend istream& operator>> ( istream& input, Tratador& tratadorTal);

};

#endif // _TRATADOR_H_
