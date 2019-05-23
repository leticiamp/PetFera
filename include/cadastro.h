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
#include "animal.h"

using namespace std;

#define MAXIMO_DE_ANIMAIS 100

class Cadastro{
	public:
		map<int, Animal> animais; // 
		char listaOpcaoInicial(string abasOrientacao); // Método que mostra opções iniciais.
//		char listaOpcaoSecundaria(string abasOrientacao); // Método que mostra opções secundárias do pet escolhida.
//		char listaOpcoesDeAlteracao(string abasOrientacao); // Método que apresenta possibilidades de alteracão.
		int pesquisarAnimal(int id); // Método que pesquisa um animal pelo nome.
		void listarTodosOsAnimais(); // Método para listar todas as animais já cadastradas.
		void inserirAnimal(int id, Animal& name_); // Método para cadastrar um novo animal.
		void excluirAnimal(int id); // Método para remover um referido animal.
//		void mostrarFuncionarios();
//		void inserirFuncionario();
//		void excluirFuncionario();
		
		Cadastro(); // Método construtor padrão para instanciar um animal.
		~Cadastro();

	private:
		
		int m_totalDeAnimais;
};

#endif // _CADASTRO_H_