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

#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>
#include "veterinario.h"
#include "tratador.h"

using namespace std;



class Animal{
	private:
		
	protected:
		int m_id;
		string m_classe;
		string m_nome_cientifico;
		char m_sexo;
		double m_tamanho;
		string m_dieta;
//		Veterinario m_veterinario;
//		Tratador m_tratador;
	public:
		//Animal();
		Animal(/*parâmetros*/);
		~Animal();

		int getId();
		string getClasse();
		string getNome();
		char getSexo();
		double getTamanho();
		string getDieta();

//		Veterinario getVeterinario();
//		Tratador getTratador();

		void setId(int id_);
		void setClasse(string classe_);
		void setNome(string nome_);
		void setSexo(char sexo_);
		void setTamanho(double tamanho_);
		void setDieta(string dieta_);
//		void setVeterinario(Veterinario& veterinario_);
//		void setTratador(Tratador& tratador_);

		friend ostream& operator<< ( ostream& output, const Animal& animalTal);
		friend istream& operator>> ( istream& input, Animal& animalTal);
};


#endif // _ANIMAL_H_