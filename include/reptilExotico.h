/**
* @file reptilExotico.h
* @brief Classe dos répteis exóticos
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 24/06/2019
*/

#ifndef _REPTIL_EXOTICO_H_
#define _REPTIL_EXOTICO_H_

#include <string>
#include "reptil.h"
#include "animalExotico.h"

class ReptilExo : public Reptil, public AnimalExo{
	private:
		/** Sobrecarga do operador de saída */
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		/** @brief Construtor parametrizado. */
		ReptilExo(int id_ = 0,
							std::string classe_ = "Reptil",
							std::string nome_cientifico_ = "NOTDEF",
							char sexo_ = '-',
							double tamanho_ = 0,
							std::string dieta_ = "NOTDEF",
							Veterinario * veterinario_ = nullptr,
							Tratador * tratador_ = nullptr,
							std::string nome_batismo_ = "NOTDEF",
							std::string naturalidade_ = "Exotico",
							bool venenoso_ = false,
							std::string tipo_veneno_ = "NOTDEF",
							std::string pais_origem_ = "NOTDEF",
							std::string cidade_origem_ = "NOTDEF",
							std::string auto_ibama_ = "NOTDEF");

		~ReptilExo(); /**< Destrutor padrão*/

};

#endif