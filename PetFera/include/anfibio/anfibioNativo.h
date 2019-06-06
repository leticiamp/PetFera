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

#ifndef _ANFIBIO_NATIVO_H_
#define _ANFIBIO_NATIVO_H_

#include <string>
#include "anfibio.h"
#include "animalNativo.h"

class AnfibioNat : public Anfibio, AnimalNat{
	private:
			std::ostream& print(std::ostream& os)const;
	protected:

	public:
		AnfibioNat( int id_,
								std::string classe_,
								std::string nome_cientifico_,
								char sexo_,
								double tamanho_,
								std::string dieta_,
								Veterinario * veterinario_,
								Tratador * tratador_,
								std::string nome_batismo_,
								int mudas_,
								std::string uf_origem_,
								std::string auto_ibama_
							);
		~AnfibioNat();

};

#endif // _ANFIBIO_NATIVO_H_
