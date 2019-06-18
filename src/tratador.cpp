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
#include "tratador.h"

Tratador::Tratador(int id_,
			   std::string nome_,
				 std::string cpf_,
				 short idade_,
				 std::string tipo_sanguineo_,
				 char fator_rh_,
				 std::string especialidade_,
				 int nivel_de_seguranca_):
	Funcionario(id_,
							"Tratador",
					 		nome_,
					 		cpf_,
					 		idade_,
					  	tipo_sanguineo_,
					 		fator_rh_,
					    especialidade_),
	m_nivel_de_seguranca(nivel_de_seguranca_){}

Tratador::~Tratador(){}

//get's
int Tratador::getNivel_de_Seguranca(){
	return this->m_nivel_de_seguranca;
}

//sets
void Tratador::setNivel_de_Seguranca(int nivel_de_seguranca_){
	this->m_nivel_de_seguranca = nivel_de_seguranca_;
}

// Imprime
std::ostream& Tratador::print(std::ostream& os)const{
		os 	<< m_id << ";" << m_funcao << ";" << m_nome << ";"
	 			<< m_cpf << ";" <<  m_idade	 << ";" << m_tipo_sanguineo << ";"
				<< m_fator_rh << ";"	<< m_especialidade << ";"
				<< m_nivel_de_seguranca << ";" << std::endl;

		return os;
}
