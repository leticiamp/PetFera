/*
# Disciplina: Linguagem de Programação I
# Professor: Silvio Sampaio
# Alunos:
# ANDRE VITOR MACEDO SOARES
# LETICIA MOURA PINHEIRO
# ODILON JULIO DOS SANTOS
# Projeto Final "PetFera"
===========================================================================
*/

#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <string>

class Funcionario{
	private:
		virtual std::ostream& print(std::ostream&) const = 0;

	protected:
		int m_id;
		std::string m_funcao;
		std::string m_nome;
		std::string m_cpf;
		short m_idade;
		std::string m_tipo_sanguineo;
		char m_fator_rh;
		std::string m_especialidade;

	public:
		Funcionario(int id_,
								std::string funcao_,
								std::string nome_,
								std::string cpf_,
								short idade_,
								std::string tipo_sanguineo_,
								char fator_rh_,
								std::string especialidade_);
		Funcionario();
	virtual	~Funcionario();

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

#endif // _FUNCIONARIO_H_
