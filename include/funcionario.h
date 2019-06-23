/**
* @file funcionario.h
* @brief Classe responsável pelo controle dos funcionários
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 23/06/2019
*/

#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <string>

/**
* @details Nesta classe, o usuário pode visualizar e modificar informações a respeito dos funcionários, tais como:
*			Nome, CPF, tipo sanguíneo, especialidade, etc. 
*/

class Funcionario{
	private:
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

		//get's
		int getId();
		std::string getFuncao();
		std::string getNome();
		std::string getCpf();
		short getIdade();
		std::string getTipo_sanguineo();
		char getFator_rh();
		std::string getEspecialidade();

		//set's

		void setId(int id_);
		void setNome(std::string nome_);
		void setCpf(std::string cpf_);
		void setIdade(short idade_);
		void setTipo_sanguineo(std::string tipo_sanguineo_);
		void setFator_rh(char fator_rh_);
		void setEspecialidade(std::string especialidade_);

		//Metodos de impressao

		friend std::ostream& operator << ( std::ostream& os, const Funcionario& funcionario){
			return funcionario.print(os);
		}
};

#endif
