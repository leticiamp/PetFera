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

#ifndef _AVE_H_
#define _AVE_H_

#include <string>
#include "animal.h"

class Ave : public Animal{
	private:

	protected:
		double m_tamanho_do_bico_cm;
		double m_envergadura_das_asas;

	public:
		Ave(int id_,
				std::string classe_,
				std::string nome_cientifico_,
				char sexo_,
				double tamanho_,
				std::string dieta_,
				Veterinario * veterinario_,
				Tratador * tratador_,
				std::string nome_batismo_,
				double tamanho_do_bico_cm_,
				double envergadura_das_asas_);

		~Ave();

		double getTamanhoBicoCm();
		double getEnvergaduraAsas();

		void setTamanhoBicoCm(double tamanho_do_bico_cm_);
		void setEnevergaduraAsas(double envergadura_das_asas_);

};

#endif // _AVE_H_
