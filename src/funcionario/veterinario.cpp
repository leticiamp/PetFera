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


#include <iostream>

#include "veterinario.h"

Veterinario::Veterinario(int id_,
				 std::string nome_,
				 std::string cpf_,
				 short idade_,
				 std::string tipo_sanguineo_,
				 char fator_rh_,
				 std::string especialidade_,
			 	 std::string crmv_):
	Funcionario(id_,
							"Veterinario",
					 		nome_,
					 		cpf_,
					 		idade_,
					  	tipo_sanguineo_,
					 		fator_rh_,
					    especialidade_),
	m_crmv(crmv_){}

Veterinario::~Veterinario(){}

//get
std::string
Veterinario::get_crmv(){
	return this->m_crmv;
}

//set
void
Veterinario::set_crmv(std::string crmv_){
	this->m_crmv = crmv_;
}

//imprime
std::ostream& Veterinario::print(std::ostream& os)const{
		os 	<< m_id << ";" << m_funcao << ";" << m_nome << ";"
	 			<< m_cpf << ";" <<  m_idade	 << ";" << m_tipo_sanguineo << ";"
				<< m_fator_rh << ";"	<< m_especialidade << ";"
				<< m_crmv	<< ";"  << std::endl;

		return os;
}
