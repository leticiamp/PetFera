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
#include "data.h"

using namespace std;

class Anfibio{
	private:
		
	protected:
		int m_total_de_mudas;
		Date m_ultima_muda;
	public:
		Anfibio();
		~Anfibio();

};

#endif // _ANFIBIO_H_