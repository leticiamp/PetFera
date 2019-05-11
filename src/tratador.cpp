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

using namespace std;

#include "tratador.h"

Tratador::Tratador():
	m_nivel_de_seguranca(0),
	m_id(0),
	m_nome("Empty"),
	m_cpf("Empty"),
	m_idade(0),
	m_tipo_sanguineo(0),
	m_fator_rh("Empty"),
	m_especialidade("Empty"){

}

Tratador::~Tratador(){}

/*
====================================
SOBRECARGA DE OPERADORES
====================================
*/
/*
ostream& operator<< ( ostream& output, const Tratador& tratadorTal){
	output 	<< tratador.m_id << ";"
			<< tratadorTal.m_nome << ";"
			<< tratadorTal.m_cpf << ";"
			<< tratadorTal.m_idade << ";"
			<< tratadorTal.m_tipo_sanguineo << ";"
			<< tratadorTal.m_fator_rh << ";"
			<< tratadorTal.m_especialidade << ";"
			<< endl;
	return output;
}

istream& operator>> ( istream& input, Tratador& tratadorTal){
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