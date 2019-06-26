/**
* @file funcionario.h
* @brief Classe responsável pelo controle dos funcionários
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 26/06/2019
*/

#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <string>

/**
* @brief Classe responsável pelo controle dos funcionários
* @details Nesta classe, o usuário pode visualizar e modificar informações a respeito dos funcionários, tais como:
*			Nome, CPF, tipo sanguíneo, especialidade, etc. 
*/

class Funcionario{
	private:
		/** Método virtual de sobrecarga do operador de saída */
		virtual std::ostream& print(std::ostream&) const = 0;

	protected:
		int m_id; /**< Define o número de identificação do funcionário*/
		std::string m_funcao; /**< Define a função do funcionaŕio na empresa*/
		std::string m_nome; /**< Define o nome do funcionário*/
		std::string m_cpf; /**< Define o CPF do funcionário*/
		short m_idade; /**< Define a idade do funcionário*/
		std::string m_tipo_sanguineo; /**< Define o tipo sanguíneo do funcionário*/
		char m_fator_rh; /**< Define o fator rh do funcionário*/
		std::string m_especialidade; /**< Define a especialidade de trabalho do funcionário*/

	public:
		/** @brief Construtor parametrizado. */
		Funcionario(int id_,
								std::string funcao_,
								std::string nome_,
								std::string cpf_,
								short idade_,
								std::string tipo_sanguineo_,
								char fator_rh_,
								std::string especialidade_);
		Funcionario(); /**< Construtor padrão*/
	virtual	~Funcionario(); /**< Destrutor padrão*/

		int getId(); /**< Visualiza o número identificador (ID) do funcionário */
		std::string getFuncao(); /**< Visualiza a função realizada pelo funcionário*/
		std::string getNome(); /**< Visualiza o nome do funcionário*/
		std::string getCpf(); /**< Visualiza o CPF do funcionário*/
		short getIdade(); /**< Visualiza a idade do funcionário*/
		std::string getTipo_sanguineo(); /**< Visualiza o tipo sanguíneo do funcionário*/
		char getFator_rh(); /**< Visualiza o fator rh*/
		std::string getEspecialidade(); /**< Visualiza a especialidade do funcionário*/

		void setId(int id_); /**< Altera o número identificador (ID) do funcionário */
		void setNome(std::string nome_); /**< Altera/insere o nome do funcionário*/
		void setCpf(std::string cpf_); /**< Altera/insere o CPF do funcionário*/
		void setIdade(short idade_); /**< Altera/insere a idade do funcionário*/
		void setTipo_sanguineo(std::string tipo_sanguineo_); /**< Altera/insere o tipo sanguíneo do funcionário*/
		void setFator_rh(char fator_rh_); /**< Altera/insere o fator rh*/
		void setEspecialidade(std::string especialidade_); /**< Altera a especialidade do funcionário*/

		/** Sobrecarga do operador de saída. Imprime um funcionário*/
		friend std::ostream& operator << ( std::ostream& os, const Funcionario& funcionario){
			return funcionario.print(os);
		}
};

#endif
