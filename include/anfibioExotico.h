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

#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

#include <string>
#include "anfibio.h"
#include "animalExotico.h"

class AnfibioExo : public Anfibio, AnimalExo{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		AnfibioExo(int id_ = 0,
							std::string classe_ = "Anfibio",
							std::string nome_cientifico_ = "NOTDEF",
							char sexo_ = '-',
							double tamanho_ = 0,
							std::string dieta_ = "NOTDEF",
							Veterinario * veterinario_ = nullptr,
							Tratador * tratador_ = nullptr,
							std::string nome_batismo_ = "NOTDEF",
							std::string naturalidade_ = "Exotico",
							int mudas_ = 0,
							std::string pais_origem_ = "NOTDEF",
							std::string cidade_origem_ = "NOTDEF",
							std::string auto_ibama_ = "NOTDEF");

		~AnfibioExo();
};

#endif // _ANFIBIO_EXOTICO_H_
