/**
* @file ave.h
* @brief Classe das aves
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/

#ifndef _AVE_H_
#define _AVE_H_

#include <string>
#include "animal.h"

/**
* @brief Classe responsável pelo controle das aves
* @details Nesta classe, o usuário pode definir características específicas das aves,
* 			como o tamanho do bico e a envergadura das asas.
*/

class Ave : public Animal{
	private:
		/** Transforma a classe em abstrata, impedindo a instanciação de um objeto */
		virtual std::ostream& print(std::ostream& os) const = 0;

	protected:
		double m_tamanho_do_bico_cm; /**< Define o tamanho do bico em centímetros*/
		double m_envergadura_das_asas; /**< Define a envergadura das asas da ave*/

	public:
		/** @brief Construtor parametrizado. */
		Ave(int id_,
				std::string classe_,
				std::string nome_cientifico_,
				char sexo_,
				double tamanho_,
				std::string dieta_,
				Veterinario * veterinario_,
				Tratador * tratador_,
				std::string nome_batismo_,
				std::string naturalidade_,
				double tamanho_do_bico_cm_,
				double envergadura_das_asas_);

		~Ave(); /**< Destrutor padrão*/

		double getTamanhoBicoCm(); /**< Visualiza o tamanho do bico (em cm) das aves */
		double getEnvergaduraAsas(); /**< Visualiza a envergadura das asas */

		void setTamanhoBicoCm(double tamanho_do_bico_cm_); /**< Altera o tamanho do bico (em cm) das aves */
		void setEnvergaduraAsas(double envergadura_das_asas_); /**< Altera a envergadura das asas */


};

#endif