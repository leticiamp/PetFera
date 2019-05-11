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

using namespace std;

#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

Animal::Animal():
	m_id(0),
	m_classe("Empty"),
	m_nome_cientifico("Empty"),
	m_sexo("Empty"),
	m_tamanho(0.0),
	m_dieta("Empty"){
//	m_veterinario(Veterinario(m_veterinario)),
//	m_tratador(Tratador(m_tratador))
}

//Animal::Animal(/* parametrizado */){}

Animal::~Animal(){}
/*
====================================
MÉTODOS GETTERS
====================================
*/
int 
Animal::getId(){
	return m_id;
}
string 
Animal::getClasse(){
	return m_classe;
}
string 
Animal::getNome(){
	return m_nome_cientifico;
}
char 
Animal::getSexo(){
	return m_sexo;
}
double 
Animal::getTamanho(){
	return m_tamanho;
}
string 
Animal::getDieta(){
	return m_dieta;
}
/*
Veterinario
Animal::getVeterinario(){
	return m_veterinario;
}
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
	m_id = id_;
}
void 
Animal::setClasse(string classe_){
	m_classe = classe_;
}
void 
Animal::setNome(string nome_){
	m_nome_cientifico = nome_;
}
void 
Animal::setSexo(char sexo_){
	m_sexo = sexo_;
}
void 
Animal::setTamanho(double tamanho_){
	m_tamanho = tamanho_;
}
void 
Animal::setDieta(string dieta_){
	m_dieta = dieta_;
}
/*
void 
Animal::setVeterinario(Veterinario& veterinario_){
	m_veterinario = veterinario_;
}
void 
Animal::setTratador(Tratador& tratador_){
	m_tratador = tratador_;
}
*/

/*
====================================
SOBRECARGA DE OPERADORES
====================================
*/

ostream& operator<< ( ostream& output, const Animal& animalTal){
	output 	<< animalTal.m_id << ";"
			<< animalTal.m_classe << ";"
			<< animalTal.m_nome_cientifico << ";"
			<< animalTal.m_sexo << ";"
			<< animalTal.m_tamanho << ";"
			<< animalTal.m_dieta << ";"
//			<< animalTal.m_veterinario << ";"
//			<< animalTal.m_tratador << ";"
			<< endl;
	return output;
}

istream& operator>> ( istream& input, Animal& animalTal){
	cout << " Identificador do Animal: ";
	getline(input, animalTal.m_id);
	cout << " Nome da Classe do Animal: ";
	getline(input, animalTal.m_classe);
	cout << " Nome do Animal: ";
	getline(input, animalTal.m_nome_cientifico);
	cout << " Sexo do Animal: ";
	getline(input, animalTal.m_sexo);
	cout << " Tamanho do Animal: ";
	getline(input, animalTal.m_tamanho);	
	cout << " Dieta do Animal: ";
	getline(input, animalTal.m_dieta);
//	cout << " Veterinário do Animal: ";
//	getline(input, animalTal.m_veterinario);
//	cout << " Tratador do Animal: ";
//	getline(input, animalTal.m_tratador);	

	return input;
}

