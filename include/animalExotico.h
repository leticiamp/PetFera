/**
* @file animalExotico.h
* @brief Classe dos animais exóticos
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/

#ifndef _ANIMAL_EXOTICO_H_
#define _ANIMAL_EXOTICO_H_

#include <string>
#include "animalSilvestre.h"

/**
* @brief Classe dos animais exóticos
* @details Nesta classe, o usuário pode colocar e alterar algumas informações específicas de animais exóticos,
como seu país e cidade de origem.
*/

class AnimalExo : public AnimalSilv{
	private:
		/** Sobrecarga do operador de saída */
		virtual std::ostream& print(std::ostream& os) const = 0;

	protected:
		std::string m_pais_origem; /**< Define o nome do país de origem do animal*/
		std::string m_cidade_origem; /**< Defime o nome da cidade de origem do animal*/

	public:
		/** @brief Construtor parametrizado. */
		AnimalExo(std::string pais_origem_,
							std::string cidade_origem_,
							std::string auto_ibama_);

		~AnimalExo(); /**< Destrutor padrão*/

		std::string getPaisOrigem(); /**< Visualiza o país de origem do animal*/
		std::string getCidadeOrigem(); /**< Visualiza a cidade de origem do animal*/

		void setPaisOrigem(std::string pais_origem_); /**< Altera o país de origem do animal*/
		void setCidadeOrigem(std::string cidade_origem_); /**< Altera a cidade de origem do animal*/
};

#endif
