/**
* @file aveExotico.h
* @brief Classe das aves exóticas
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santosos
* @since 25/04/2019
* @date 16/06/2019
*/

#ifndef _AVE_EXOTICO_H_
#define _AVE_EXOTICO_H_

#include <string>
#include "ave.h"
#include "animalExotico.h"

class AveExo : public Ave, AnimalExo{
	private:
		/** Sobrecarga do operador de saída */
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		/** @brief Construtor parametrizado. */
		AveExo(int id_ = 0,
					std::string classe_ = "Ave",
					std::string nome_cientifico_ = "NO",
					char sexo_ = '-',
					double tamanho_ = 0,
					std::string dieta_ = "NOTDEF",
					Veterinario * veterinario_ = nullptr,
					Tratador * tratador_ = nullptr,
					std::string nome_batismo_ = "NOTDEF",
					std::string naturalidade_ = "Exotico",
					double tamanho_do_bico_cm_ = 0,
					double envergadura_das_asas_ = 0,
					std::string pais_origem_ = "NOTDEF",
					std::string cidade_origem_ = "NOTDEF",
					std::string auto_ibama_ = "NOTDEF");

		~AveExo(); /**< Destrutor padrão*/

};

#endif // _AVE_EXOTICO_H_
