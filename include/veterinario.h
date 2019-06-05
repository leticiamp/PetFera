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

#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include <string>
#include "funcionario.h"

class Veterinario : public Funcionario{
	private:
		std::string m_crmv;
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		//Construtores
		Veterinario(int id_ = 0,
						 std::string nome_ = "NOTDEF",
						 std::string cpf_ = "NOTDEF",
						 short idade_ = -1,
				 		 std::string tipo_sanguineo_ = " NOTDEF",
						 char fator_rh_ = 'N',
						 std::string especialidade_= "NOTDEF",
					 	 std::string crmv_ = "NOTDEF");

	//Destrutor
		~Veterinario();

		//get
		std::string get_crmv();
		//set
		void set_crmv(std::string crmv_);


};

#endif // _VETERINARIO_H_
