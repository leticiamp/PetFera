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
		std::ostream& print(std::ostream& os)const;
	protected:

	public:

		//Metodos Construtor
		Tratador(int id_ = 0,
						 std::string funcao_ = "Tratador",
						 std::string nome_ = "NOTDEF",
						 std::string cpf_ = "NOTDEF",
						 short idade_ = -1,
				 		 std::string tipo_sanguineo_ = "NOTDEF",
						 char fator_rh_ = 'N',
						 std::string especialidade_= "NOTDEF",
						 int nivel_de_seguranca_ = 0);

		//Metodo Destrutor
		~Tratador();

		//get's
		int getNivel_de_Seguranca();

		//set's
		void setNivel_de_Seguranca(int nivel_de_seguranca_);

};

#endif // _TRATADOR_H_
