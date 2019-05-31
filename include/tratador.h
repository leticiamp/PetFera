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

		//Metodos Construtor
		Tratador(int id_,
							std::string nome_,
							std::string cpf_,
							short idade_,
							std::string tipo_sanguineo_,
							char fator_rh_,
							std::string especialidade_,
							int nivel_de_seguranca_);

		//Metodo Destrutor
		~Tratador();

		//get's
		int getNivel_de_Seguranca();

		//set's
		void setNivel_de_Seguranca(int nivel_de_seguranca_);

		std::ostream& print(std::ostream& os) const;
//		friend istream& operator>> ( istream& input, Tratador& tratadorTal);

};

#endif // _TRATADOR_H_
