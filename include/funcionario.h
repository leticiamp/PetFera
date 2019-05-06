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

#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <string>

using namespace std;

class Funcionario{
	private:
	
	protected:
		int m_id;
		string m_nome;
		string m_cpf;
		short m_idade;
		short m_tipo_sanguineo;
		char m_fator_rh;
		string m_especialidade;
	public:
		Funcionario();
		~Funcionario();

		// type method(type);
		// type method(type);

};

#endif // _FUNCIONARIO_H_