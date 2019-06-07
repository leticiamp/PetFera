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

#ifndef _MAMIFERO_H_
#define _MAMIFERO_H_

#include <string>
#include "animal.h"

class Mamifero : public Animal{
	private :
	
	protected:
		std::string m_cor_pelo;
	public:
		Mamifero(int id_,
						std::string classe_,
						std::string nome_cientifico_,
						char sexo_,
						double tamanho_,
						std::string dieta_,
						Veterinario * veterinario_,
						Tratador * tratador_,
						std::string nome_batismo_,
					  std::string cor_pelo_);

		~Mamifero();

		std::string getCorPelo();

		void setCorPelo(std::string cor_pelo_);


};

#endif // _MAMIFERO_H_
