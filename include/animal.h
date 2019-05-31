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

class Animal{

	private:
//		virtual std::ostream& print(std::ostream& os) const = 0;

	protected:
		int m_id;
		std::string m_classe;
		std::string m_nome_cientifico;
		char m_sexo;
		double m_tamanho;
		std::string m_dieta;
//		Veterinario m_veterinario;
//		Tratador m_tratador;
		std::string m_nome_batismo;

	public:

		Animal(	int id_,
				std::string classe_,
				std::string nome_cientifico_,
				char sexo_,
				double tamanho_,
				std::string dieta_,
				std::string nome_batismo_);

		~Animal();

		int getId();
		std::string getClasse();
		std::string getNome();
		char getSexo();
		double getTamanho();
		std::string getDieta();
		std::string getNomeBatismo();

//		Veterinario getVeterinario();
//		Tratador getTratador();

		void setId(int id_);
		void setClasse(std::string classe_);
		void setNome(std::string nome_);
		void setSexo(char sexo_);
		void setTamanho(double tamanho_);
		void setDieta(std::string dieta_);
		void setNomeBatismo(std::string nome_batismo_);

//		void setVeterinario(Veterinario& veterinario_);
//		void setTratador(Tratador& tratador_);

//		virtual void imprime() = 0;
//		friend std::ostream& operator<< ( std::ostream& output, const Animal& animalTal);
//		friend std::istream& operator>> ( std::istream& input, Animal& animalTal);
};


#endif // _ANIMAL_H_
