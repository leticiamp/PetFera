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

#include <iostream>
#include <string>
//#include "veterinario.h"
//#include "tratador.h"

//enum Gender{M, F, MF, NONE}; 
/*
Vitor, tive que tirar e trocar por "char" TEMPORARIAMENTE, pois teria que
fazer sobrecarga do operador >> e não consegui fazer... Quando conseguir, 
botamos o Gender outra vez. 
*/

class Animal{
	private:
//		static int m_totalDeAnimais;
	protected:
		size_t m_id;
		std::string m_classe;
		std::string m_nome_cientifico;
		std::string m_sexo;
		double m_tamanho;
		std::string m_dieta;
//		Veterinario m_veterinario;
//		Tratador m_tratador;
	public:
		Animal(	size_t m_id=0,
				std::string m_classe="Empty",
				std::string m_nome_cientifico="Empty",
				std::string m_sexo="Empty",
				double m_tamanho=0,
				std::string m_dieta="Empty" );
/*		Animal(	size_t id_,
				std::string classe_,
				std::string nome_cientifico_,
				char sexo_,
				double tamanho_,
				std::string dieta_);
*/
		~Animal();

		size_t getId();
		std::string getClasse();
		std::string getNome();
		std::string getSexo();
		double getTamanho();
		std::string getDieta();

//		Veterinario getVeterinario();
//		Tratador getTratador();

		void setId(size_t id_);
		void setClasse(std::string classe_);
		void setNome(std::string nome_);
		void setSexo(std::string sexo_);
		void setTamanho(double tamanho_);
		void setDieta(std::string dieta_);
//		void setVeterinario(Veterinario& veterinario_);
//		void setTratador(Tratador& tratador_);

		friend std::ostream& operator<< ( std::ostream& output, const Animal& animalTal);
//		friend std::istream& operator>> ( std::istream& input, Animal& animalTal);
};


#endif // _ANIMAL_H_
