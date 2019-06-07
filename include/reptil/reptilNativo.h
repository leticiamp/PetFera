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

#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

#include <string>
#include "reptil.h"
#include "animalNativo.h"

using namespace std;

class ReptilNat : public Reptil, AnimalNat{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		ReptilNat(int id_,
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
							std::string uf_origem_,
							std::string auto_ibama_);
		~ReptilNat();

};

#endif // _REPTIL_NATIVO_H_
