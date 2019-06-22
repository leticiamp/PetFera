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
			/** Sobrecarga do operador de saída */
			std::ostream& print(std::ostream& os)const;
	protected:

	public:
		AnfibioNat( int id_ = 0,
								std::string classe_ = "Anfibio",
								std::string nome_cientifico_ = "NOTDEF",
								char sexo_ = '-',
								double tamanho_  = 0,
								std::string dieta_ = "NOTDEF",
								Veterinario * veterinario_ = nullptr,
								Tratador * tratador_ = nullptr,
								std::string nome_batismo_ = "NOTDEF",
								std::string naturalidade = "Nativo",
								int mudas_ = 0,
								std::string uf_origem_ = "NOTDEF",
								std::string auto_ibama_ = "NOTDEF"
							);
		~AnfibioNat();

};

#endif // _ANFIBIO_NATIVO_H_
