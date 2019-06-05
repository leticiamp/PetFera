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

#ifndef _REPTIL_EXOTICO_H_
#define _REPTIL_EXOTICO_H_

#include <string>
#include "reptil.h"
#include "animalExotico.h"

class ReptilExo : public Reptil, AnimalExo{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		ReptilExo(int id_,
							std::string classe_,
							std::string nome_cientifico_,
							char sexo_,
							double tamanho_,
							std::string dieta_,
							Veterinario * veterinario_,
							Tratador * tratador_,
							std::string nome_batismo_,
							bool venenoso_,
							std::string tipo_veneno_,
							std::string pais_origem_,
							std::string cidade_origem_,
							std::string auto_ibama_);
		~ReptilExo();

};

#endif // _REPTIL_EXOTICO_H_
