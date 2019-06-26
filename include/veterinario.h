/**
* @file veterinario.h
* @brief Classe responsável pelo veterinário dos animais
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/


#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include <string>
#include "funcionario.h"

/**
* @brief Classe responsável pelo veterinário dos animais
* @details Nesta classe, o usuário pode definir características especíificas
*			dos veterinários, como o conselho regional à qual ele pertence.
*/

class Veterinario : public Funcionario{
	private:
		std::string m_crmv; /**< Define o conselho regional de medicina veterinária à qual o veterinário pertence*/
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

		std::string get_crmv(); /**< Visualiza o conselho regional de medicina veterinária à qual o veterinário pertence */

		void set_crmv(std::string crmv_); /**< Altera o conselho regional de medicina veterinária à qual o veterinário pertence */


};

#endif