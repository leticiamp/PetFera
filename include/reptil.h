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

#ifndef _REPTIL_H_
#define _REPTIL_H_

#include <string>

using namespace std;

class Reptil{
	private:
		bool m_venenoso;
		string m_tipo_veneno;
		
	protected:

	public:
		Reptil();
		~Reptil();

};

#endif // _REPTIL_H_