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

class AveNat : public Ave, AnimalNat{
	private:
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		/** @brief Construtor parametrizado. */
		AveNat(int id_,
					std::string classe_,
					std::string nome_cientifico_,
					char sexo_,
					double tamanho_,
					std::string dieta_,
					Veterinario * veterinario_,
					Tratador * tratador_,
					std::string nome_batismo_,
					double tamanho_do_bico_cm_,
					double envergadura_das_asas_,
					std::string uf_origem_,
					std::string auto_ibama_);

		~AveNat(); /**< Destrutor padrão*/

};

#endif // _AVE_NATIVO_H_
