/**
* @file veterinario.h
* @brief Classe responsável pelo veterinário dos animais
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 24/06/2019
*/


#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include <string>
#include "funcionario.h"

class Veterinario : public Funcionario{
	private:
		std::string m_crmv; /**< */
		std::ostream& print(std::ostream& os)const; /**< Método virtual de sobrecarga do operador de saída */
	protected:

	public:
		/** @brief Construtor parametrizado. */
		Veterinario(int id_ = 0,
						 std::string funcao_ = "Veterinario",
						 std::string nome_ = "NOTDEF",
						 std::string cpf_ = "NOTDEF",
						 short idade_ = -1,
				 		 std::string tipo_sanguineo_ = " NOTDEF",
						 char fator_rh_ = 'N',
						 std::string especialidade_= "NOTDEF",
					 	 std::string crmv_ = "NOTDEF");

		~Veterinario(); /**< Destrutor padrão*/

		std::string get_crmv();

		void set_crmv(std::string crmv_);


};

#endif