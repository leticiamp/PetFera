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
					 		nome_,
					 		cpf_,
					 		idade_,
					  	tipo_sanguineo_,
					 		fator_rh_,
					    especialidade_),
	m_crmv(crmv_){

}

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
		os 	<<"ID : " 						<< m_id 								<< std::endl
				<<"Name : " 					<< m_nome 							<< std::endl
				<<"CPF : " 						<< m_cpf					  		<< std::endl
				<<"AGE : " 						<< m_idade	 						<< std::endl
				<<"BLOOD TYPE : " 		<< m_tipo_sanguineo 		<< std::endl
				<<"RH FACTOR : " 			<< m_fator_rh 					<< std::endl
				<<"ESPECIALIDADE : " 	<< m_especialidade 			<< std::endl
				<<"CRMV: "						<< m_crmv							  << std::endl;

		return os;
}
