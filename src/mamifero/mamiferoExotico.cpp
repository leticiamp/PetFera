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

#include "mamiferoExotico.h"

MamiferoExo::MamiferoExo(int id_,
												std::string classe_,
												std::string nome_cientifico_,
												char sexo_,
												double tamanho_,
												std::string dieta_,
												Veterinario * veterinario_,
												Tratador * tratador_,
												std::string nome_batismo_,
												std::string cor_pelo_,
												std::string pais_origem_,
												std::string cidade_origem_,
												std::string auto_ibama_):
		Mamifero(id_,
						classe_,
						nome_cientifico_,
						sexo_,
						tamanho_,
						dieta_,
						veterinario_,
						tratador_,
						nome_batismo_,
						"Exotico",
						cor_pelo_),
		AnimalExo(pais_origem_,
							cidade_origem_,
							auto_ibama_){}

MamiferoExo::~MamiferoExo(){}



std::ostream& MamiferoExo::print(std::ostream& os)const{
	os	<< m_id << ";" 
    	<< m_classe << ";"
		<< m_nome_cientifico << ";"
		<< m_sexo << ";"
		<< m_tamanho << ";"
		<< m_dieta << ";"
		<< m_nome_batismo << ";"
     	<< m_naturalidade << ";"
		<< m_cor_pelo << ";";
	if(m_veterinario == nullptr){
		os << "0" << ";";
	}else{
		os << *m_veterinario << ";";
	}
	if(m_tratador == nullptr){
		os << "0" << ";";
	}else{
		os << *m_tratador	<< ";";
	}
  	os 	<< m_pais_origem << ";"
		<< m_cidade_origem << ";"
		<< m_autorizacao_ibama << ";";
	return os;
  
}
