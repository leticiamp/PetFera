/**
* @file aveExotico.h
* @brief Classe das aves e nativas
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 18/06/2019
*/
#ifndef _AVE_NATIVO_H_
#define _AVE_NATIVO_H_

#include <string>
#include "ave.h"
#include "animalNativo.h"

class AveNat : public Ave, public AnimalNat{
	private:
		/** Sobrecarga do operador de saída */
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		/** @brief Construtor parametrizado. */
		AveNat(int id_ = 0,
					std::string classe_ = "Ave",
					std::string nome_cientifico_ = "NOTDEF",
					char sexo_ = '-',
					double tamanho_ = 0,
					std::string dieta_ = "NOTDEF",
					Veterinario * veterinario_ = nullptr,
					Tratador * tratador_ = nullptr,
					std::string nome_batismo_ = "NOTDEF",
					std::string naturalidade_ = "Nativo",
					double tamanho_do_bico_cm_ = 0,
					double envergadura_das_asas_ = 0,
					std::string uf_origem_ = "NOTDEF",
					std::string auto_ibama_ = "NOTDEF");

		~AveNat(); /**< Destrutor padrão*/

};

#endif // _AVE_NATIVO_H_
