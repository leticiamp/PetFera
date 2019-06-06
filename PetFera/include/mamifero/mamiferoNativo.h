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

#ifndef _MAMIFERO_NATIVO_H_
#define _MAMIFERO_NATIVO_H_

#include <string>
#include "mamifero.h"
#include "animalNativo.h"

class MamiferoNat : public Mamifero, AnimalNat{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		MamiferoNat(int id_,
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
								std::string auto_ibama_);
		~MamiferoNat();

};

#endif // _MAMIFERO_NATIVO_H_
