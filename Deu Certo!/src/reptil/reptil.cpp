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

#include "reptil.h"

Reptil::Reptil(int id_,
        std::string classe_,
        std::string nome_cientifico_,
        char sexo_,
        double tamanho_,
        std::string dieta_,
        Veterinario * veterinario_,
        Tratador * tratador_,
        std::string nome_batismo_,
        bool venenoso_,
        std::string tipo_veneno_):
      Animal(	id_,
                classe_,
                nome_cientifico_,
                sexo_,
                tamanho_,
                dieta_,
                veterinario_,
                tratador_,
                nome_batismo_),
      m_venenoso(venenoso_),
      m_tipo_veneno(tipo_veneno_)
{}

Reptil::~Reptil(){}

bool
Reptil::getVenenoso(){
    return this->m_venenoso;
}

std::string
Reptil::getTipoVenenoso(){
  return this->m_tipo_veneno;
}

void
Reptil::setVenenoso(bool venenoso_){
  this->m_venenoso = venenoso_;
}

void
Reptil::setTipoVenenoso(std::string tipo_veneno_){
  this->m_tipo_veneno = tipo_veneno_;
}
