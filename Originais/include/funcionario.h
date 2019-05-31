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

	protected:
		size_t m_id;
		std::string m_nome;
		std::string m_cpf;
		short m_idade;
		std::string m_tipo_sanguineo;
		char m_fator_rh;
		std::string m_especialidade;
	public:
		Funcionario();
		~Funcionario();

		// type method(type);
		// type method(type);

		//get's
		size_t getId();
		std::string getNome();
		std::string getCpf();
		short getIdade();
		std::string getTipo_sanguineo();
		char getFator_rh();
		std::string getEspecialidade();

		//set's

		void setId(size_t id_);
		void setNome(std::string nome_);
		void setCpf(std::string cpf_);
		void setIdade(short idade_);
		void setTipo_sanguineo(std::string tipo_sanguineo_);
		void setFator_rh(char fator_rh_);
		void setEspecialidade(std::string especialidade_);

};

#endif // _FUNCIONARIO_H_
