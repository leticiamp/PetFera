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

#ifndef _CADASTRO_H_
#define _CADASTRO_H_

#include <map>
#include <string>
#include "animal.h"

using namespace std;

#define MAXIMO_DE_ANIMAIS 100

class Cadastro{
	public:
		map<int, Animal> * animais; // 
		int listaOpcaoInicial(string abasOrientacao); // Método que mostra opções iniciais.
		void pesquisarAnimal(string abasOrientacao); // Método que pesquisa um animal pelo nome.
		void listarTodosOsAnimais(string abasOrientacao); // Método para listar todas as animais já cadastrados.
		void inserirAnimal(string abasOrientacao); // Método para cadastrar um novo animal.
		void excluirAnimal(string abasOrientacao); // Método para remover um referido animal.

//		char listaOpcaoSecundaria(string abasOrientacao); // Método que mostra opções secundárias do pet escolhida.
//		char listaOpcoesDeAlteracao(string abasOrientacao); // Método que apresenta possibilidades de alteracão.
//		void mostrarFuncionarios();
//		void inserirFuncionario();
//		void excluirFuncionario();
		
		Cadastro(); // Método construtor padrão para instanciar um animal.
		~Cadastro();

	private:
		int m_totalDeAnimais;
};

#endif // _CADASTRO_H_