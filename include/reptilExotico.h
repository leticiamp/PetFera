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
		/** Sobrecarga do operador de saída */
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		ReptilExo(int id_ = 0,
							std::string classe_ = "Reptil",
							std::string nome_cientifico_ = "NOTDEF",
							char sexo_ = '-',
							double tamanho_ = 0,
							std::string dieta_ = "NOTDEF",
							Veterinario * veterinario_ = nullptr,
							Tratador * tratador_ = nullptr,
							std::string nome_batismo_ = "NOTDEF",
							std::string naturalidade_ = "Exotico",
							bool venenoso_ = false,
							std::string tipo_veneno_ = "NOTDEF",
							std::string pais_origem_ = "NOTDEF",
							std::string cidade_origem_ = "NOTDEF",
							std::string auto_ibama_ = "NOTDEF");
		~ReptilExo();

};

#endif // _REPTIL_EXOTICO_H_
