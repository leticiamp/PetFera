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
						"Nativo",
						cor_pelo_),
		AnimalNat(uf_origem_,
							auto_ibama_)
		{}

MamiferoNat::~MamiferoNat(){}


std::ostream& MamiferoNat::print(std::ostream& os)const{
	os  <<"ID : " 						  					<< m_id 								<< std::endl
		<< "Classe : " 										<< m_classe 						<< std::endl
		<< "Nome Cientifico : "						<< m_nome_cientifico 		<< std::endl
		<< "Sexo : " 											<< m_sexo 							<< std::endl
		<< "Tamanho : " 									<< m_tamanho 						<< std::endl
		<< "Dieta : " 										<< m_dieta 							<< std::endl
		<< "Nome de Batismo : " 					<< m_nome_batismo 			<< std::endl
		<< "Naturalidade : " 							<< m_naturalidade 			<< std::endl
		<< "Cor do pelo : " 							<< m_cor_pelo						<< std::endl;

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

		os << "Pais : " 											<< m_uf_origem 					<< std::endl
		<< "Ibama Autorização : " 				<< m_autorizacao_ibama  << std::endl;
		return os;
}
