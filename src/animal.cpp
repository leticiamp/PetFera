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

Animal::Animal():
	m_id(0),
	m_classe("Empty"),
	m_nome_cientifico("Empty"),
	m_sexo(NONE),
	m_tamanho(0),
	m_dieta("Empty"){
//	m_veterinario(Veterinario(m_veterinario)),
//	m_tratador(Tratador(m_tratador))
//	Cadatro::m_totalDeAnimais++;
}

Animal::Animal( size_t id_,
				std::string classe_,
				std::string nome_cientifico_,
				Gender sexo_,
				double tamanho_,
				std::string dieta_):
	m_id(id_),
	m_classe(classe_),
	m_nome_cientifico(nome_cientifico_),
	m_sexo(sexo_),
	m_tamanho(tamanho_),
	m_dieta(dieta_){
//	m_veterinario(Veterinario(veterinario_)),
//	m_tratador(Tratador(tratador_))
//	m_totalDeAnimais++;
}

Animal::~Animal(){}
/*
====================================
MÉTODOS GETTERS
====================================
*/
size_t
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

Gender
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
Animal::setId(size_t id_){
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
Animal::setSexo(Gender sexo_){
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

std::ostream& operator<< ( std::ostream& output, const Animal& animalTal){
	output 	<< animalTal.m_id << ";"
			<< animalTal.m_classe << ";"
			<< animalTal.m_nome_cientifico << ";"
			<< animalTal.m_sexo << ";"
			<< animalTal.m_tamanho << ";"
			<< animalTal.m_dieta << ";"
//			<< animalTal.m_veterinario << ";"
//			<< animalTal.m_tratador << ";"
			<< std::endl;
	return output;
}

/*
std::istream& operator>> ( std::istream& input, Animal& animalTal){
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
