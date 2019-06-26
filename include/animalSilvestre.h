/**
* @file animalSilvestre.h
* @brief Classe dos animais silvestres
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/

#ifndef _ANIMAL_SILVESTRE_H_
#define _ANIMAL_SILVESTRE_H_

#include <string>

/**
* @brief Classe dos animais silvestres
* @details Nesta classe, o usuário pode visualizar e alterar a autorização do IBAMA sobre o animal silvestre.
*/

class AnimalSilv{
	private:
		/** Sobrecarga do operador de saída */
		virtual std::ostream& print(std::ostream& os) const = 0;

	protected:
		std::string m_autorizacao_ibama; /**< Define qual a autorização do IBAMA*/

	public:
		AnimalSilv(std::string auto_ibama_); /**< Construtor parametrizado*/
		~AnimalSilv(); /**< Destrutor padrão*/

		std::string getAutoIbama(); /**< Visualiza a autorização do IBAMA sobre o animal silvestre */
		void setAutoIbama(std::string auto_ibama_); /**< Altera a autorização do IBAMA sobre o animal silvestre */
};

#endif
