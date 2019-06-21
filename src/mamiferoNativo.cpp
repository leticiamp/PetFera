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

#include "mamiferoNativo.h"

MamiferoNat::MamiferoNat(int id_,
												std::string classe_,
												std::string nome_cientifico_,
												char sexo_,
												double tamanho_,
												std::string dieta_,
												Veterinario * veterinario_,
												Tratador * tratador_,
												std::string nome_batismo_,
												std::string naturalidade_,
												std::string cor_pelo_,
												std::string uf_origem_,
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
						naturalidade_,
						cor_pelo_),
		AnimalNat(uf_origem_,
							auto_ibama_)
		{}

MamiferoNat::~MamiferoNat(){}


std::ostream& MamiferoNat::print(std::ostream& os)const{
	os << m_id << ";" << m_classe 	 << ";" << m_nome_cientifico << ";"
		 << m_sexo << ";" << m_tamanho << ";" << m_dieta << ";"
		 << m_nome_batismo << ";" << m_naturalidade << ";"
		 << m_cor_pelo	<<";";


	 if(m_veterinario == nullptr){
	 	os << "0" << ";";
	 }else{
	 	os << m_veterinario->getId() << ";";
	 }

	 if(m_tratador == nullptr){
	 	os << "0" << ";";
	 }else{
	 	os << m_tratador->getId()	<< ";";
	 }

	os  << m_uf_origem << ";"<< m_autorizacao_ibama << std::endl;
	return os;
}
