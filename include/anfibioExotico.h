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
//		std::ostream& print(std::ostream& os){
//			return os << "Funcionou" << std::endl;
//		}

	protected:

	public:
		AnfibioExo(int id_,
							std::string classe_,
							std::string nome_cientifico_,
							char sexo_,
							double tamanho_,
							std::string dieta_,
							std::string nome_batismo_,
							int mudas_,
		          std::string pais_origem_,
		          std::string cidade_origem_,
		          std::string auto_ibama_);

		~AnfibioExo();

};

#endif // _ANFIBIO_EXOTICO_H_
