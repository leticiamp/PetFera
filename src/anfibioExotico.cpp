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
  								nome_batismo_,
  								mudas_),
          AnimalExo(pais_origem_,
                    cidade_origem_,
                    auto_ibama_)
{}

AnfibioExo::~AnfibioExo(){}
