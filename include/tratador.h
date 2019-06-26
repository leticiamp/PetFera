/**
* @file tratador.h
* @brief Classe responsável pelo tratador dos animais
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/

#ifndef _TRATADOR_H_
#define _TRATADOR_H_

#include <string>
#include "funcionario.h"

/**
* @brief Classe responsável pelo tratador dos animais
* @details Nesta classe, o usuário pode definir característiccas dos tratadores,
*			como seu nível de segurança.
*/

class Tratador : public Funcionario{
	private:
		int m_nivel_de_seguranca; /**<Define o nível de segurança do tratador */
		std::ostream& print(std::ostream& os)const; /**< Método virtual de sobrecarga do operador de saída */
	protected:

	public:
		/** @brief Construtor parametrizado. */
		Tratador(int id_ = 0,
						 std::string funcao_ = "Tratador",
						 std::string nome_ = "NOTDEF",
						 std::string cpf_ = "NOTDEF",
						 short idade_ = -1,
				 		 std::string tipo_sanguineo_ = "NOTDEF",
						 char fator_rh_ = 'N',
						 std::string especialidade_= "NOTDEF",
						 int nivel_de_seguranca_ = 0);

		~Tratador(); /**< Destrutor padrão*/

		int getNivel_de_Seguranca(); /**< Visualizar o nível de segurança do tratador */

		void setNivel_de_Seguranca(int nivel_de_seguranca_); /**< Alterar o nível de segurança do tratador */

};

#endif