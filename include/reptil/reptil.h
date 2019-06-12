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

#ifndef _REPTIL_H_
#define _REPTIL_H_

#include <string>
#include "animal.h"

class Reptil : public Animal{
	private:

	protected:
		bool m_venenoso;
		std::string m_tipo_veneno;
	public:
		Reptil(int id_,
						std::string classe_,
						std::string nome_cientifico_,
						char sexo_,
						double tamanho_,
						std::string dieta_,
						Veterinario * veterinario_,
						Tratador * tratador_,
						std::string nome_batismo_,
						std::string naturalidade_,
					  bool venenoso_,
						std::string tipo_veneno_);
		~Reptil();

		bool getVenenoso();
		std::string getTipoVenenoso();

		void setVenenoso(bool venenoso_);
		void setTipoVenenoso(std::string tipo_veneno_);

};

#endif // _REPTIL_H_
