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

#include <iostream>
#include <string>
#include "cadastro.h"
#include "animal.h"
#include "funcionario.h"
using namespace std;

/*
========================================================
MÉTODOS CONSTRUTOR E DESTRUTOR DE CADASTROS DE ANIMAIS.
========================================================
*/

/*
Método Construtor padrão para instanciar objeto da classe Cadastro, 
o qual é inicializado com nenhum animal.
*/
Cadastro::Cadastro():
	m_totalDeAnimais(0){
}

/*
Método Destrutor que exclui um cadastro e, simultaneamente, exclui 
também os respectivos animais cadastradas.
*/
Cadastro::~Cadastro(){
	animais.clear();
}

/*
==========================
MÉTODOS GETTERS E SETTERS.
==========================
*/

char 
Cadastro::listaOpcaoInicial(string abasOrientacao){ // Método que mostra as alternativas iniciais.
	char alternativa = '0';
	do{
		cout << " \n ++++++++++++++++++++++++++++++++++++++++++++++\n" << "\n"
			 << "                   "  << abasOrientacao
			 << " \n Escolha uma das seguintes alternativas abaixo: " << "\n"
			 << " Digite '1' para: Listar os Animais" << "\n"
			 << " Digite '2' para: Cadastrar um Animal" << "\n"
			 << " Digite '3' para: Remover um Animal" << "\n"
			 << " Digite '4' para: Alterar Cadastro de um Animal " << "\n"
			 << " Digite '5' para: Pesquisar Animal" << "\n"
			 << " Digite '9' para: Sair deste Menu" << "\n"
			 << " Alternativa escolhida: "; 
			 cin >> alternativa; cin.ignore();
		switch(alternativa){
			case '1' : listarTodosOsAnimais("\n Menu Inicial >> Listar Animais \n");
				break;
			case '2' : inserirAnimal("\n Menu Inicial >> Inserir Animal \n");
				break;
			case '3' : excluirAnimal("\n Menu Inicial >> Excluir Animal \n");
				break;
//			case '4' : alterarCadastro("\n Menu Inicial >> Alterar Cadastro \n");
//				break;
			case '5' : pesquisarAnimal("\n Menu Inicial >> Pesquisa de Animal \n");
				break;
			case '9' : // Nenhuma ação. Somente sai do menu.
				break;
			default : cout << " \n\n Alternativa inválida!" << endl;
		}
	} while (alternativa != '9');
	return alternativa;
}

/*
char Cadastro::alterarCadastro(string abasOrientacao){ // Método que apresenta possibilidades de edição/mudança.
	char alternativa = '0';
	do{
		cout << " \n ++++++++++++++++++++++++++++++++++++++++++++++\n" << "\n"
			 << "                   " << abasOrientacao
			 << " \n Escolha uma das seguintes alternativas abaixo: " << "\n"
			 << " Digite '1' para: Listar todas os funcionários" << "\n"
			 << " Digite '2' para: Modificar o salário dos funcionários" << "\n"
			 << " Digite '3' para: Adicionar um funcionário " << "\n"
			 << " Digite '4' para: Excluir um funcionário " << "\n"
			 << " Digite '5' para: Listar funcionários em período de experiência " << "\n"
			 << " Digite '6' para: Sair" << "\n"
			 << " Alternativa escolhida: "; cin >> alternativa; cin.ignore();
		switch(alternativa){
			case '1' : mostrarFuncionarios();
				break;
			case '2' : alteraSalario();
				break;
			case '3' : inserirFuncionario();
				break;
			case '4' : excluirFuncionario();
				break;
			case '5' : cout << " \n\n Desculpe! Nosso código não conseguiu comparar as datas." << endl;
				break;
			case '6' : // Nenhuma ação. Somente sai do menu.
				break;
			default : cout << " \n\n Alternativa inválida!" << endl;
		}
	} while (alternativa != '6');
	
	return alternativa;		
}	
*/
int 
Cadastro::pesquisarAnimal(int id){ // Método que pesquisa um animal pelo nome e retorna sua posição.
	map<int, string>::iterator busca = alunos.find(id);
	cout << "Idenficador: " << busca->first << " - Animal: " << busca->second << endl;;
}

void
Cadastro::listarTodosOsAnimais(){ // Método para listar todos os animais já cadastradas.
	cout << "\n\n Esse cadastro possui " << m_totalDeAnimais << " animais cadastrados."
		 << "\n" << "\n=============================================" 
		 << "\n Lista de animais cadastradas: \n\n";
	
	map<int, Animal>::iterator it;
	for (it = animais.begin(); it != animais.end(); ++it) // Impressao dos valores no mapa
	cout << it->first << " ; " << it->second << endl;
	return 0;
}	

void 
Cadastro::inserirAnimal(int id, Animal& name_){ // Método para criar uma novo animal.
	if (m_totalDeAnimais < MAXIMO_DE_ANIMAIS){
		animais.insert(<int, Animal>(id, Animal()));
	}
	else{
		cout << " Não é possível adicionar um novo animal a este cadastro." << endl;
	}
	cout << " Animal adicionado com sucesso!" << endl;
}

void 
Cadastro::excluirAnimal(int id){ // Método para remover um referido animal.
	animais.erase(id);
	cout << " Animal excluído com sucesso!" << endl;
}
