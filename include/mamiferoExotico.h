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

class MamiferoExo : public Mamifero, public AnimalExo{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		MamiferoExo(int id_ = 0,
							std::string classe_ = "Mamifero",
							std::string nome_cientifico_ = "NOTDEF",
							char sexo_ = '-',
							double tamanho_ = 0,
							std::string dieta_ = "NOTDEF",
							Veterinario * veterinario_ = nullptr,
							Tratador * tratador_ = nullptr,
							std::string nome_batismo_ = "NOTDEF",
							std::string naturalidade_ = "Exotico",
							std::string cor_pelo_ = "NOTDEF",
							std::string pais_origem_ = "NOTDEF",
							std::string cidade_origem_ = "NOTDEF",
							std::string auto_ibama_ = "NOTDEF");
		~MamiferoExo();

};

#endif // _MAMIFERO_EXOTICO_H_
