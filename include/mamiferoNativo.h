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

class MamiferoNat : public Mamifero, public AnimalNat{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		MamiferoNat(int id_ = 0,
								std::string classe_ = "Mamifero",
								std::string nome_cientifico_ = "NOTDEF",
								char sexo_ = '-',
								double tamanho_ = 0,
								std::string dieta_ = "NOTDEF",
								Veterinario * veterinario_ = nullptr,
								Tratador * tratador_ = nullptr,
								std::string nome_batismo_ = "NOTDEF",
								std::string naturalidade_ = "Nativo",
								std::string cor_pelo_ = "NOTDEF",
								std::string uf_origem_ = "NOTDEF",
								std::string auto_ibama_ = "NOTDEF");
		~MamiferoNat();

};

#endif // _MAMIFERO_NATIVO_H_
