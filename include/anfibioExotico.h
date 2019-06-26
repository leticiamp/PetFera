/**
* @file anfibioExotico.h
* @brief Classe dos Anfíbios Exóticos
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26 /06/2019
*/

#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

#include <string>
#include "anfibio.h"
#include "animalExotico.h"

/**
* @brief Classe dos anfíbios exóticos
* @details Nesta classe o usuário pode inicializar os dados do anfíbio exótico.
*/

class AnfibioExo : public Anfibio, public AnimalExo{
	private:
		/** Sobrecarga do operador de saída */
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		/** @brief Construtor parametrizado. */
		AnfibioExo(int id_ = 0,
							std::string classe_ = "Anfibio",
							std::string nome_cientifico_ = "NOTDEF",
							char sexo_ = '-',
							double tamanho_ = 0,
							std::string dieta_ = "NOTDEF",
							Veterinario * veterinario_ = nullptr,
							Tratador * tratador_ = nullptr,
							std::string nome_batismo_ = "NOTDEF",
							std::string naturalidade_ = "Exotico",
							int mudas_ = 0,
							std::string pais_origem_ = "NOTDEF",
							std::string cidade_origem_ = "NOTDEF",
							std::string auto_ibama_ = "NOTDEF");

		~AnfibioExo(); /**< Destrutor padrão*/
};

#endif
