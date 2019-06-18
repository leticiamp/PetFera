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

#ifndef _MAMIFERO_EXOTICO_H_
#define _MAMIFERO_EXOTICO_H_

#include <string>
#include "mamifero.h"
#include "animalExotico.h"

class MamiferoExo : public Mamifero, AnimalExo{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		MamiferoExo(int id_,
							std::string classe_,
							std::string nome_cientifico_,
							char sexo_,
							double tamanho_,
							std::string dieta_,
							Veterinario * veterinario_,
							Tratador * tratador_,
							std::string nome_batismo_,
							std::string cor_pelo_,
							std::string pais_origem_,
							std::string cidade_origem_,
							std::string auto_ibama_);
		~MamiferoExo();

};

#endif // _MAMIFERO_EXOTICO_H_
