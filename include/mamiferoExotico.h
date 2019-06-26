/**
* @file mamiferoExotico.h
* @brief Classe dos mamíferos exóticos
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/


#ifndef _MAMIFERO_EXOTICO_H_
#define _MAMIFERO_EXOTICO_H_

#include <string>
#include "mamifero.h"
#include "animalExotico.h"

/**
* @brief Classe dos mamíferos exóticos
*/

class MamiferoExo : public Mamifero, public AnimalExo{
	private:
		/** Método virtual de sobrecarga do operador de saída */
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		/** @brief Construtor parametrizado. */
		MamiferoExo(int id_ = 0,
							std::string classe_ = "Mamifero",
							std::string nome_cientifico_ = "NOTDEF",
							char sexo_ = '-',
							double tamanho_ = 0,
							std::string dieta_ = "NOTDEF",
							Veterinario * veterinario_ = nullptr,
							Tratador * tratador_ = nullptr,
							std::string nome_batismo_ = "NOTDEF",
							std::string naturalidade_ = "Exotico",
							std::string cor_pelo_ = "NOTDEF",
							std::string pais_origem_ = "NOTDEF",
							std::string cidade_origem_ = "NOTDEF",
							std::string auto_ibama_ = "NOTDEF");

		~MamiferoExo(); /**< Destrutor padrão*/
};

#endif