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
#include <string>

#include "animal.h"
//#include "veterinario.h"
//#include "tratador.h"
//#include "cadastro.h"

Animal::Animal( int id_,
				std::string classe_,
				std::string nome_cientifico_,
				char sexo_,
				double tamanho_,
				std::string dieta_,
			std::string nome_batismo_):
	m_id(id_),
	m_classe(classe_),
	m_nome_cientifico(nome_cientifico_),
	m_sexo(sexo_),
	m_tamanho(tamanho_),
	m_dieta(dieta_),
	m_nome_batismo(nome_batismo_)

//	m_veterinario(Veterinario(veterinario_)),
//	m_tratador(Tratador(tratador_))
//	m_totalDeAnimais++;
{}

Animal::~Animal(){}

`
/*
====================================
MÉTODOS GETTERS
====================================
*/`

int
Animal::getId(){
	return this->m_id;
}

std::string
Animal::getClasse(){
	return this->m_classe;
}

std::string
Animal::getNome(){
	return this->m_nome_cientifico;
}

char
Animal::getSexo(){
	return this->m_sexo;
}

double
Animal::getTamanho(){
	return this->m_tamanho;
}

std::string
Animal::getDieta(){
	return this->m_dieta;
}

std::string
Animal::getNomeBatismo(){
	return this->m_nome_batismo;
}

/*
Veterinario
Animal::getVeterinario(){
	return m_veterinario;
}

*/
/*
Tratador
Animal::getTratador(){
	return m_tratador;
}
*/


/*
====================================
MÉTODOS SETTERS
====================================
*/

void
Animal::setId(int id_){
	this->m_id = id_;
}

void
Animal::setClasse(std::string classe_){
	this->m_classe = classe_;
}

void
Animal::setNome(std::string nome_){
	this->m_nome_cientifico = nome_;
}

void
Animal::setSexo(char sexo_){
	this->m_sexo = sexo_;
}

void
Animal::setTamanho(double tamanho_){
	this->m_tamanho = tamanho_;
}

void
Animal::setDieta(std::string dieta_){
	this->m_dieta = dieta_;
}


void
Animal::setNomeBatismo(std::string nomeBatismo_){
	this->m_nome_batismo = nomeBatismo_;
}

/*
void
Animal::setVeterinario(Veterinario& veterinario_){
	this->m_veterinario = veterinario_;
}

*/
/*
void
Animal::setTratador(Tratador& tratador_){
	this->m_tratador = tratador_;
}
*/

/*
====================================
SOBRECARGA DE OPERADORES
====================================
*/

std::ostream&
Animal::operator<< ( std::ostream& output, const Animal& animalTal){
	return animalTal.print(output);
}

/*
std::istream&
operator>> ( std::istream& input, Animal& animalTal){
	std::cout << " Identificador do Animal: ";
	std::getline(input, animalTal.m_id);
	std::cout << " Nome da Classe do Animal: ";
	std::getline(input, animalTal.m_classe);
	std::cout << " Nome do Animal: ";
	std::getline(input, animalTal.m_nome_cientifico);
	std::cout << " Sexo do Animal: ";
	std::getline(input, animalTal.m_sexo);
	std::cout << " Tamanho do Animal: ";
	std::getline(input, animalTal.m_tamanho);
	std::cout << " Dieta do Animal: ";
	std::getline(input, animalTal.m_dieta);
//	std::cout << " Veterinário do Animal: ";
//	std::getline(input, animalTal.m_veterinario);
//	std::cout << " Tratador do Animal: ";
//	std::getline(input, animalTal.m_tratador);

	return input;
}
*/
