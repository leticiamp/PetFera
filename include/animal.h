/**
* @file animal.h
* @brief Classe base dos animais
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 15/06/2019
*/

#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>
#include <string>
#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"

/**
* @brief Classe base para todos os grupos de animais
* @details Nesta classe o usuário pode fazer o controle geral de todos os animais. Ela permite a criação de animais de diferentes
subclasses, assim como suas configurações específicas (dieta, nome científico, veterinário e tratador responsável, etc.)
*/

class Animal{

	private:
		virtual std::ostream& print(std::ostream& os) const = 0;

	protected:
		int m_id; /**< Define o número de identificação do animal */
		std::string m_classe; /**< Define a classe à qual o animal pertence */
		std::string m_nome_cientifico; /**< Define o nome científico do animal */
		char m_sexo; /**< Define o sexo do animal */
		double m_tamanho; /**< Define o tamanho médio (em metros) do animal */
		std::string m_dieta; /**< Define a dieta predominante do animal */
		Veterinario * m_veterinario; /**< Define o veterinário associado ao animal */
		Tratador * m_tratador; /**< Define o tratador associado ao animal */
		std::string m_nome_batismo; /**< Define o nome de batismo (nome pelo qual o animal atende) */
		std::string m_naturalidade;
	public:
		/** @brief Construtor parametrizado. */
		Animal(	int id_,
				std::string classe_,
				std::string nome_cientifico_,
				char sexo_,
				double tamanho_,
				std::string dieta_,
				Veterinario * veterinario_,
				Tratador * tratador_,
				std::string nome_batismo_,
				std::string naturalidade_);

	virtual	~Animal(); /**< Destrutor padrão*/

		int getId();
		std::string getClasse();
		std::string getNome();
		char getSexo();
		double getTamanho();
		std::string getDieta();
		std::string getNomeBatismo();
		std::string getNaturalidade();

	 	Veterinario * getVeterinario();
		Tratador * getTratador();

		void setId(int id_);
		void setClasse(std::string classe_);
		void setNome(std::string nome_);
		void setSexo(char sexo_);
		void setTamanho(double tamanho_);
		void setDieta(std::string dieta_);
		void setNomeBatismo(std::string nome_batismo_);
		void setNaturalidade(std::string naturalidade_);


		void setVeterinario(Veterinario* veterinario_);
		void setTratador(Tratador* tratador_);

		/** @brief Sobrecarga do operador de inserção*/
		friend std::ostream& operator << ( std::ostream& os, const Animal& animal){
			return animal.print(os);
		}
};


#endif // _ANIMAL_H_
