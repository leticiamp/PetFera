/**
* @file anfibio.h
* @brief Classe dos Anfíbios
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 23/06/2019
*/

#ifndef _ANFIBIO_H_
#define _ANFIBIO_H_

#include <string>
//#include "data.h"
#include "animal.h"


class Anfibio : public Animal{
	private:
		/** Transforma a classe em abstrata, impedindo a instanciação de um objeto */
		virtual std::ostream& print(std::ostream& os) const = 0;
	protected:
		int m_total_de_mudas; /**< Define o total de mudas (trocas de pele) */
//		Date m_ultima_muda;
	public:
		/** @brief Construtor parametrizado. */
		Anfibio(int id_,
						std::string classe_,
						std::string nome_cientifico_,
						char sexo_,
						double tamanho_,
						std::string dieta_,
						Veterinario * veterinario_,
						Tratador * tratador_,
						std::string nome_batismo_,
						std::string naturalidade_,
						int mudas_);

		~Anfibio(); /**< Destrutor padrão*/

		//get's
    int get_m_total_de_mudas();
    //set's
    void set_m_total_de_mudas(int mudas);

};

#endif