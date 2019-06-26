/**
* @file reptil.h
* @brief Classe dos répteis
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/

#ifndef _REPTIL_H_
#define _REPTIL_H_

#include <string>
#include "animal.h"

/**
* @brief Classe dos répteis
* @details Nesta classe, o usuário pode inicializar um réptil, além de definir características como
*			o veneno do animal e o seu tipo.
*/

class Reptil : public Animal{
	private:
		/** Transforma a classe em abstrata, impedindo a instanciação de um objeto */
		virtual std::ostream& print(std::ostream& os) const = 0;

	protected:
		bool m_venenoso; /**< Define se o réptil é venenoso ou não*/
		std::string m_tipo_veneno; /**< Define o tipo de veneno do réptil*/
	public:
		/** @brief Construtor parametrizado. */
		Reptil(int id_,
						std::string classe_,
						std::string nome_cientifico_,
						char sexo_,
						double tamanho_,
						std::string dieta_,
						Veterinario * veterinario_,
						Tratador * tratador_,
						std::string nome_batismo_,
						std::string naturalidade_,
					  bool venenoso_,
						std::string tipo_veneno_);

		~Reptil(); /**< Destrutor padrão*/

		bool getVenenoso(); /**< Visualiza se o animal é venenoso ou não */
		std::string getTipoVenenoso(); /**< Visualizar o tipo de veneno do réptil */

		void setVenenoso(bool venenoso_); /**< Altera se o animal é venenoso ou não */
		void setTipoVenenoso(std::string tipo_veneno_); /**< Alterar o tipo de veneno do réptil */

};

#endif