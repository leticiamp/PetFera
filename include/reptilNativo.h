/**
* @file reptilNativo.h
* @brief Classe dos répteis nativos
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/

#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

#include <string>
#include "reptil.h"
#include "animalNativo.h"

/**
* @brief Classe dos répteis nativos
*/

using namespace std;

class ReptilNat : public Reptil, public AnimalNat{
	private:
		/** Método virtual de sobrecarga do operador de saída */
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		/** @brief Construtor parametrizado. */
		ReptilNat(int id_ = 0,
							std::string classe_ = "Reptil",
							std::string nome_cientifico_ = "NOTDEF",
							char sexo_ = '-',
							double tamanho_ = 0,
							std::string dieta_ = "NOTDEF",
							Veterinario * veterinario_ = nullptr,
							Tratador * tratador_ = nullptr,
							std::string nome_batismo_ = "NOTDEF",
							std::string naturalidade_ = "Nativo",
							bool venenoso_ = false,
							std::string tipo_veneno_ = "NOTDEF",
							std::string uf_origem_ = "NOTDEF",
							std::string auto_ibama_ = "NOTDEF");

		~ReptilNat(); /**< Destrutor padrão*/

};

#endif 