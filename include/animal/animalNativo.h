/**
* @file animalNativo.h
* @brief Classe dos animais nativos
* @author Victor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 15/06/2019
*/

#ifndef _ANIMAL_NATIVO_H_
#define _ANIMAL_NATIVO_H_

#include <string>
#include "animalSilvestre.h"

/**
* @brief Classe filha da classe Animal
* @details Nesta classe, o usuário pode colocar e alterar algumas informações específicas de animais nativos,
como seu estado de origem.
*/

class AnimalNat : public AnimalSilv {
	private:

	protected:
		std::string m_uf_origem; /**< Define o nome da UF de origem do animal*/
	public:
		/** @brief Construtor parametrizado. */
		AnimalNat(std::string uf_origem_,
							std::string auto_ibama_);

		~AnimalNat(); /**< Destrutor padrão*/

		std::string getUfOrigem();

		void setUfOrigem(std::string UfOrigem);

};

#endif // _ANIMAL_NATIVO_H_
