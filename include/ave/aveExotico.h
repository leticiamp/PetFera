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

#ifndef _AVE_EXOTICO_H_
#define _AVE_EXOTICO_H_

#include <string>
#include "ave.h"
#include "animalExotico.h"

class AveExo : public Ave, AnimalExo{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		AveExo(int id_,
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
					std::string auto_ibama_);
		~AveExo();

};

#endif // _AVE_EXOTICO_H_
