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
#include <iterator>
#include <map>
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
	animais->clear();
}

/*
==========================
MÉTODOS GETTERS E SETTERS.
==========================
*/

int 
Cadastro::listaOpcaoInicial(string abasOrientacao){ // Método que mostra as alternativas iniciais.
	int alternativa = 0;
	do{
		cout << " \n ++++++++++++++++++++++++++++++++++++++++++++++\n" << "\n"
			 << "                   "  << abasOrientacao
			 << " \n Escolha uma das seguintes alternativas abaixo: \n\n" << "\n"
			 << " Digite '1' para: Listar os Animais" << "\n"
			 << " Digite '2' para: Cadastrar um Animal Manualmente" << "\n"
			 << " Digite '3' para: Remover um Animal" << "\n"
			 << " Digite '4' para: Alterar Cadastro de um Animal " << "\n"
			 << " Digite '5' para: Pesquisar Animal" << "\n"
			 << " Digite '6' para: Cadastrar Animais de Arquivo (CSV)" << "\n"
			 << " Digite '9' para: Sair deste Menu" << "\n"
			 << " Alternativa escolhida: "; 
			 cin >> alternativa; cin.ignore();
		switch(alternativa){
			case 1 : listarTodosOsAnimais("\n Menu Inicial >> Listar Animais \n");
				break; 
			case 2 : inserirAnimal("\n Menu Inicial >> Inserir Animal \n");
				break;
			case 3 : excluirAnimal("\n Menu Inicial >> Excluir Animal \n");
				break;
//			case 4 : alterarCadastro("\n Menu Inicial >> Alterar Cadastro \n");
//				break;
			case 5 : pesquisarAnimal("\n Menu Inicial >> Pesquisa de Animal \n");
				break;
			case 9 : // Nenhuma ação. Somente sai do menu.
				break;
			default : cout << " \n\n Alternativa inválida!" << endl;
		}
	} while (alternativa != 9);
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
void
Cadastro::pesquisarAnimal(string abasOrientacao){ // Método que pesquisa um animal pelo nome e retorna sua posição.
	int id;

	cout << " Qual o número idenficador do animal? " << endl;

	cin >> id; cin.ignore();

	map<int, Animal>::iterator it = animais->find(id);
	cout << " Idenficador: " << it->first 
		 << " - Animal: " << it->second << endl;
}

void
Cadastro::listarTodosOsAnimais(string abasOrientacao){ // Método para listar todos os animais já cadastradas.
	cout << "\n\n Esse cadastro possui " << m_totalDeAnimais << " animais cadastrados."
		 << "\n" << "\n=============================================" 
		 << "\n Lista de animais cadastradas: \n\n";
	
	map<int, Animal>::iterator it;
	for (it = animais->begin(); it != animais->end(); ++it) // Impressao dos valores no mapa
	cout << it->first << ";" << it->second << endl;
}	

void 
Cadastro::inserirAnimal(string abasOrientacao){ // Método para criar uma novo animal.
	if (m_totalDeAnimais < MAXIMO_DE_ANIMAIS){
		int id_;
		cout << " Qual o número idenficador do animal a ser inserido? " << endl;
		cin >> id_; cin.ignore();

		std::string classe_;
		cout << " Qual a classe do animal (Ave, Reptil, Mamifero ou Anfíbio)? " << endl;
		cin >> classe_; cin.ignore();

		std::string nome_cientifico_;
		cout << " Qual o nome científico do animal? " << endl;
		cin >> nome_cientifico_; cin.ignore();

		char sexo_;
		cout << " Qual o sexo do animal? (Digite 1 para macho e 2 para fêmea)" << endl;
		cin >> sexo_; cin.ignore();

		double tamanho_;
		cout << " Qual o tamanho do animal? (em centímentros)" << endl;
		cin >> tamanho_; cin.ignore();

		std::string dieta_;
		cout << " Qual a dieta do animal? " << endl;
		cin >> dieta_; cin.ignore();

	
		animais->insert(pair<int, Animal>(id_, Animal(
													id_,
													classe_,
													nome_cientifico_,
													sexo_,
													tamanho_,
													dieta_)));
	}
	else{
		cout << " Não é possível adicionar um novo animal a este cadastro." << endl;
	}
	cout << " Animal adicionado com sucesso!" << endl;
}

void 
Cadastro::excluirAnimal(string abasOrientacao){ // Método para remover um referido animal.
	int id;
	cout << " Qual o número idenficador do animal a ser removido? " << endl;
	cin >> id; cin.ignore();
	animais->erase(id);
	cout << " Animal excluído com sucesso!" << endl;
}
