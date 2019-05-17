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

Tratador::Tratador():
	Funcionario(),
	m_nivel_de_seguranca(0){}

Tratador::~Tratador(){}

//get's
int Tratador::getNivel_de_Seguranca(){
	return this->m_nivel_de_seguranca;
}

//sets
void Tratador::setNivel_de_Seguranca(int nivel_de_seguranca_){
	this->m_nivel_de_seguranca = nivel_de_seguranca_;
}

/*
====================================
SOBRECARGA DE OPERADORES
====================================
*/

std::ostream& operator<< ( std::ostream& output, const Tratador& tratadorTal){
	output 	<< tratadorTal.m_id << ";"
			<< tratadorTal.m_nome << ";"
			<< tratadorTal.m_cpf << ";"
			<< tratadorTal.m_idade << ";"
			<< tratadorTal.m_tipo_sanguineo << ";"
			<< tratadorTal.m_fator_rh << ";"
			<< tratadorTal.m_especialidade << ";"
			<< std::endl;
	return output;
}
/*
std::istream& operator>> ( std::istream& input, Tratador& tratadorTal){
	cout << " Identificador do Tratador: ";
	getline(tratador.m_id);
	cout << " Nome do Tratador: ";
	getline(tratadorTal.m_nome);
	cout << " CPF do Tratador: ";
	getline(input, tratadorTal.m_cpf );
	cout << " Idade do Tratador: ";
	getline(input, tratadorTal.m_idade);
	cout << " Tipo Sanguíneo do Tratador: ";
	getline(input, tratadorTal.m_tipo_sanguineo);
	cout << " Fator RH do Sangue do Tratador: ";
	getline(input, tratadorTal.m_fator_rh);
	cout << " Especialidade do Tratador: ";
	getline(input, tratadorTal.m_especialidade);

	return input;
}
*/
