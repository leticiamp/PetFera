/**
* @file mamifero.h
* @brief Classe dos mamíferos
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 24/06/2019
*/

#ifndef _MAMIFERO_H_
#define _MAMIFERO_H_

#include <string>
#include "animal.h"

class Mamifero : public Animal{
	private :
		/** Transforma a classe em abstrata, impedindo a instanciação de um objeto */
		virtual std::ostream& print(std::ostream& os) const = 0;

	protected:
		std::string m_cor_pelo; /**< Define a cor do pêlo do mamífero*/
	public:
		/** @brief Construtor parametrizado. */
		Mamifero(int id_,
						std::string classe_,
						std::string nome_cientifico_,
						char sexo_,
						double tamanho_,
						std::string dieta_,
						Veterinario * veterinario_,
						Tratador * tratador_,
						std::string nome_batismo_,
						std::string naturalidade_,
					  std::string cor_pelo_);

		~Mamifero(); /**< Destrutor padrão*/

		std::string getCorPelo();

		void setCorPelo(std::string cor_pelo_);


};

#endif
