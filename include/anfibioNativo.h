/**
* @file anfibioNativo.h
* @brief Classe dos Anfíbios Nativos
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 23/06/2019
*/

#ifndef _ANFIBIO_NATIVO_H_
#define _ANFIBIO_NATIVO_H_

#include <string>
#include "anfibio.h"
#include "animalNativo.h"

/**
* @brief Classe dos anfíbios nativos
* @details Nesta classe o usuário pode inicializar os dados do anfíbio, além de visualizar e
*		alterar o número de trocas de pele (mudas) do animal. 
*/

class AnfibioNat : public Anfibio, public AnimalNat{
	private:
		/** Sobrecarga do operador de saída */
		std::ostream& print(std::ostream& os)const;
	protected:

	public:
		/** @brief Construtor parametrizado. */
		AnfibioNat( int id_ = 0,
								std::string classe_ = "Anfibio",
								std::string nome_cientifico_ = "NOTDEF",
								char sexo_ = '-',
								double tamanho_  = 0,
								std::string dieta_ = "NOTDEF",
								Veterinario * veterinario_ = nullptr,
								Tratador * tratador_ = nullptr,
								std::string nome_batismo_ = "NOTDEF",
								std::string naturalidade = "Nativo",
								int mudas_ = 0,
								std::string uf_origem_ = "NOTDEF",
								std::string auto_ibama_ = "NOTDEF"
							);
		~AnfibioNat(); /**< Destrutor padrão*/

};

#endif 
