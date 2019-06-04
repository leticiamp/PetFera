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


#ifndef _ANFIBIO_H_
#define _ANFIBIO_H_

#include <string>
//#include "data.h"
#include "animal.h"


class Anfibio : public Animal{
	private:

	protected:
		int m_total_de_mudas;
//		Date m_ultima_muda;
	public:
		Anfibio(int id_,
						std::string classe_,
						std::string nome_cientifico_,
						char sexo_,
						double tamanho_,
						std::string dieta_,
						Veterinario * veterinario_,
						Tratador * tratador_,
						std::string nome_batismo_,
						int mudas_);

		~Anfibio();

		//get's
    int get_m_total_de_mudas();
    //set's
    void set_m_total_de_mudas(int mudas);

};

#endif // _ANFIBIO_H_
