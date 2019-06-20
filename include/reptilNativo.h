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
		ReptilNat(int id_ = 0,
							std::string classe_ = "Reptil",
							std::string nome_cientifico_ = "NOTDEF",
							char sexo_ = '-',
							double tamanho_ = 0,
							std::string dieta_ = "NOTDEF",
							Veterinario * veterinario_ = nullptr,
							Tratador * tratador_ = nullptr,
							std::string nome_batismo_ = "NOTDEF",
							std::string naturalidade_ = "Nativo",
							bool venenoso_ = false,
							std::string tipo_veneno_ = "NOTDEF",
							std::string uf_origem_ = "NOTDEF",
							std::string auto_ibama_ = "NOTDEF");
		~ReptilNat();

};

#endif // _REPTIL_NATIVO_H_
