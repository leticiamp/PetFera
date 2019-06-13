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

#include "aveExotico.h"

AveExo::AveExo(int id_,
							std::string classe_,
							std::string nome_cientifico_,
							char sexo_,
							double tamanho_,
							std::string dieta_,
							Veterinario * veterinario_,
							Tratador * tratador_,
							std::string nome_batismo_,
							double tamanho_do_bico_cm_,
							double envergadura_das_asas_,
							std::string pais_origem_,
							std::string cidade_origem_,
							std::string auto_ibama_):
					Ave(id_,
							classe_,
							nome_cientifico_,
							sexo_,
							tamanho_,
							dieta_,
							veterinario_,
							tratador_,
							nome_batismo_,
							"Exotico",
							tamanho_do_bico_cm_,
							envergadura_das_asas_),
					AnimalExo(pais_origem_,
										cidade_origem_,
										auto_ibama_)
{}

AveExo::~AveExo(){}


std::ostream& AveExo::print(std::ostream& os)const{
	os << m_id << ";" << m_classe 	 << ";" << m_nome_cientifico << ";"
		 << m_sexo << ";" << m_tamanho << ";" << m_dieta << ";"
		 << m_nome_batismo << ";" << m_naturalidade << ";"
		 << m_tamanho_do_bico_cm	<< ";" << m_envergadura_das_asas << ";";
			
		if(m_veterinario == nullptr){
			os << "Veterinario Responsavel: 0" << std::endl;
		}else{
			os << "Veterinario Responsavel: \n"	<< *m_veterinario << std::endl;
		}

		if(m_tratador == nullptr){
			os << "Tratador Responsavel: 0" << std::endl;
		}else{
			os << "Tratador Responsavel: \n"	<< *m_tratador	<< std::endl;
		}

		os  << m_pais_origem << ";" << m_cidade_origem  << ";"
				<< m_autorizacao_ibama  << ";" << std::endl;
		return os;
}
