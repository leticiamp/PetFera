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

#include "anfibio.h"

//Construtor
Anfibio::Anfibio(): Animal(),
                    m_total_de_mudas(0)
{}

//Destrutor
Anfibio::~Anfibio(){}

//get's
int Anfibio::get_m_total_de_mudas(){
  return m_total_de_mudas;
}
//set's
void Anfibio::set_m_total_de_mudas(int mudas){
  this->m_total_de_mudas = mudas;
}
