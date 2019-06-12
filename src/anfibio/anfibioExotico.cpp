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

#include "anfibioExotico.h"

AnfibioExo::AnfibioExo(int id_,
								std::string classe_,
								std::string nome_cientifico_,
								char sexo_,
								double tamanho_,
								std::string dieta_,
								Veterinario * veterinario_,
								Tratador * tratador_,
								std::string nome_batismo_,
								int mudas_,
								std::string pais_origem_,
								std::string cidade_origem_,
								std::string auto_ibama_):
          Anfibio(id_,
                  classe_,
  								nome_cientifico_,
  								sexo_,
  								tamanho_,
  								dieta_,
									veterinario_,
									tratador_,
  								nome_batismo_,
									"Exotico",
  								mudas_),
					AnimalExo(pais_origem_,
										cidade_origem_,
										auto_ibama_)
{}

AnfibioExo::~AnfibioExo(){}

std::ostream& AnfibioExo::print(std::ostream& os)const{
	os <<"ID : " 						  					<< m_id 								<< std::endl
		<< "Classe : " 										<< m_classe 						<< std::endl
		<< "Nome Cientifico : "						<< m_nome_cientifico 		<< std::endl
		<< "Sexo : " 											<< m_sexo 							<< std::endl
		<< "Tamanho : " 									<< m_tamanho 						<< std::endl
		<< "Dieta : " 										<< m_dieta 							<< std::endl
		<< "Nome de Batismo : " 					<< m_nome_batismo 			<< std::endl
		<< "Naturalidade : " 							<< m_naturalidade 			<< std::endl
		<< "Numero de Mudas : " 					<< m_total_de_mudas			<< std::endl;

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

		os << "Pais : " 											<< m_pais_origem 				<< std::endl
		<< "Cidade : " 										<< m_cidade_origem 			<< std::endl
		<< "Ibama Autorização : " 				<< m_autorizacao_ibama  << std::endl;
		return os;
}
