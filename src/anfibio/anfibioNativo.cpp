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

#include "anfibioNativo.h"

AnfibioNat::AnfibioNat(int id_,
								std::string classe_,
								std::string nome_cientifico_,
								char sexo_,
								double tamanho_,
								std::string dieta_,
								Veterinario * veterinario_,
								Tratador * tratador_,
								std::string nome_batismo_,
								int mudas_,
								std::string uf_origem_,
								std::string auto_ibama_
								):
          Anfibio(id_,
                  classe_,
  								nome_cientifico_,
  								sexo_,
  								tamanho_,
  								dieta_,
									veterinario_,
									tratador_,
  								nome_batismo_,
									"Nativo",
  								mudas_),
					AnimalNat(uf_origem_,
										auto_ibama_)
{}

AnfibioNat::~AnfibioNat(){}

std::ostream& AnfibioNat::print(std::ostream& os)const{
  	os 	<< m_id << ";" 
      	<< m_classe << ";"
		<< m_nome_cientifico << ";"
		<< m_sexo << ";"
		<< m_tamanho << ";"
		<< m_dieta << ";"
		<< m_nome_batismo << ";"
      	<< m_naturalidade << ";"
		<< m_total_de_mudas << ";";
  	if(m_veterinario == nullptr){
		os	<< "0" << ";"; 
	}else{
		os  << *m_veterinario << ";";
	}
	if(m_tratador == nullptr){
		os  << "0" << ";";
	}else{
		os  << *m_tratador	<< ";";
	}
  	os 	<< m_uf_origem << ";"
		<< m_autorizacao_ibama << ";";
	return os;
}