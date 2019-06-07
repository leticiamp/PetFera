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

#include <string>
#include "system.h"


System::System(){}
System::~System(){}

void System::menuInicial(string guia_){
  printMenuInicial("");

}

//Metodos de listagem
void System::listarAnimais(string guia_){
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
    std::cout << "Animal : " <<  it->first << " \n" << *it->second << "\n\n";
  }
}
void System::listarFuncionarios(string guia_){
  for (std::map<int,Funcionario*>::iterator it = this->mymapF.begin();
        it!= this->mymapF.end();
        ++it){
        std::cout << "Funcionario : " <<  it->first << " \n" << *it->second << "\n\n";
    }
}
void System::listarAnimaisNaTela(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::listarAnimaisEmArquivoCSV(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}
    
void System::listarAnimaisComFiltroNaTela(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}
    
void System::listarAnimaisComFiltroEmArquivoCSV(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::listarFuncionariosNaTela(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::listarFuncionariosEmArquivoCSV(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n "<< endl;
}
    
void System::listarFuncionariosComFiltroNaTela(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}
    
void System::listarFuncionariosComFiltroEmArquivoCSV(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}


//Metodos de inserção

void System::inserirFuncionario(Tratador * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "\n Erro. Id já existe! " << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Tratador*>(funcionario->getId(),funcionario));
}

void System::inserirFuncionario(Veterinario * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Veterinario*>(funcionario->getId(),funcionario));
}

void System::inserirFuncionario(Funcionario * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Funcionario *>(funcionario->getId(),funcionario));
}

void System::inserirAnimal(Animal * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, Animal*>(animal->getId(), animal));

}

void System::inserirAnimalDigitando(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::inserirAnimalViaArquivoCSV(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::inserirFuncionarioDigitando(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::inserirFuncionarioViaArquivoCSV(string guia_){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

//Consulta

Tratador * System::consultaTratador(int Id){
  return (dynamic_cast<Tratador*>(mymapF.find(Id)->second));
}


Veterinario * System::consultaVeterinario(int Id){
  return (dynamic_cast<Veterinario*>(mymapF.find(Id)->second));
}

void System::consultaAnimaisDoTratador(int Id){
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin();
  it!= this->mymapA.end();
  ++it){
    if( it->second->getTratador()->getId() == Id){
      std::cout << "Animal " << *it->second;
    }

  }
}

//Excluir

void System::excluiAnimal(int Id){
  this->mymapA.erase(Id);
}

void System::excluiFuncionario(int Id){
  this->mymapF.erase(Id);
}


//Menus

void System::printMenuInicial(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n\n ++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
      std::cout  << " ++++++++++ BEM-VINDO AO PETFERA ++++++++++++ " << std::endl;
      std::cout  << " ++++++++++++++++++++++++++++++++++++++++++++ \n " << std::endl;
      std::cout  << " \n +++++++++++++ MENU PRINCIPAL++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n" << endl
                 << " Digite '1' para: LISTAR Dados no Banco\n"
                 << " Digite '2' para: INSERIR Dados no Banco\n"
                 << " Digite '3' para: REMOVER Dados no Banco\n"
                 << " Digite '4' para: PESQUISAR Dados no Banco\n"
                 << " Digite '5' para: EDITAR Dados no Banco \n"
                 << " Digite '0' para: SAIR do Programa\n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << std::endl
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 : printMenuListar1("\n Menu Inicial >> Listar  \n");
          break; 
        case 2 : printMenuInserir1("\n Menu Inicial >> Inserir \n");
          break;
        case 3 : printMenuRemover1("\n Menu Inicial >> Remover \n");
          break;
        case 4 : printMenuPesquisar1("\n Menu Inicial >> Pesquisar\n");
          break;
        case 5 : printMenuEditar1("\n Menu Inicial >> Editar \n");
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default: std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuListar1(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Listar Dados no Banco \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Listar Dados dos Animais\n"
                 << " Digite '2' para: Listar Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 : printMenuListar12("\n Menu Inicial >> Listar >> Animais  \n");
          break; 
        case 2 : printMenuListar13("\n Menu Inicial >> Listar >> Funcionários \n");
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default: std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuListar12(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Listar Dados de Animais \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Listar todos os animais na tela\n"
                 << " Digite '2' para: Listar todos os animais em arquivo csv\n"
                 << " Digite '3' para: Listar todos os animais na tela com Filtro\n"
                 << " Digite '4' para: Listar todos os animais em arquivo csv com Filtro\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 : listarAnimaisNaTela("\n Menu Inicial >> Listar >> Animais >> Tela \n");
          break; 
        case 2 : listarAnimaisEmArquivoCSV("\n Menu Inicial >> Listar >> Animais >> Arquivo CSV \n");
          break;
        case 3 : listarAnimaisComFiltroNaTela("\n Menu Inicial >> Listar >> Animais >> Tela & Filtro \n");
          break;
        case 4 : listarAnimaisComFiltroEmArquivoCSV("\n Menu Inicial >> Listar >> Animais >> Arquivo CSV & Filtro \n");
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default: std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuListar13(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Listar Dados de Funcionários \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Listar todos os funcionários na tela\n"
                 << " Digite '2' para: Listar todos os funcionários em arquivo csv\n"
                 << " Digite '3' para: Listar todos os funcionários na tela com Filtro\n"
                 << " Digite '4' para: Listar todos os funcionários em arquivo csv com Filtro\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 : listarFuncionariosNaTela("\n Menu Inicial >> Listar >> Funcionários >> Tela  \n");
          break; 
        case 2 : listarFuncionariosEmArquivoCSV("\n Menu Inicial >> Listar >> Funcionários >> Arquivo CSV \n");
          break;
        case 3 : listarFuncionariosComFiltroNaTela("\n Menu Inicial >> Listar >> Funcionários >> Tela & Filtro \n");
          break;
        case 4 : listarFuncionariosComFiltroEmArquivoCSV("\n Menu Inicial >> Listar >> Funcionários >> Arquivo CSV & Filtro \n");
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default: std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuInserir1(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Inserir Dados no Banco \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Inserir Dados dos Animais\n"
                 << " Digite '2' para: Inserir Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 : printMenuInserir12("\n Menu Inicial >> Inserir >> Animais  \n");
          break; 
        case 2 : printMenuInserir13("\n Menu Inicial >> Inserir >> Funcionários \n");
          break;
        case 0: // Nenhuma ação. Somente sai do menu.
          break;
        default: std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuInserir12(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Inserir Dados de Animal \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Inserir Dados de Animal Item a Item (Digitando)\n"
                 << " Digite '2' para: Inserir Dados de Animal Via Arquivo CSV\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 : inserirAnimalDigitando("\n Menu Inicial >> Inserir >> Animais >> Digitando\n");
          break; 
        case 2 : inserirAnimalViaArquivoCSV("\n Menu Inicial >> Inserir >> Animais >> Arquivo CSV \n");
          break;
        case 9 : // Nenhuma ação. Somente sai do menu.
          break;
        default: std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuInserir13(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Inserir Dados de Funcionário \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Inserir Dados de Funcionário Item a Item (Digitando)\n"
                 << " Digite '2' para: Inserir Dados de Funcionário Via Arquivo CSV\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 : inserirFuncionarioDigitando("\n Menu Inicial >> Inserir >> Funcionário >> Digitando \n");
          break; 
        case 2 : inserirFuncionarioViaArquivoCSV("\n Menu Inicial >> Listar >> Funcionário >> Arquivo CSV \n");
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default: std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuRemover1(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Remover Dados no Banco \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Remover Dados dos Animais\n"
                 << " Digite '2' para: Remover Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 : printMenuRemover12("\n Menu Inicial >> Remover >> Animais  \n");
          break; 
        case 2 : printMenuRemover13("\n Menu Inicial >> Remover >> Funcionários \n");
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default: std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuRemover12(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Remover Dados de Animal \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite o ID do animal"
                 << " ou digite '0' para voltar ao menu anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      excluiAnimal(alternativa);
  } while (alternativa != 0);
}

void System::printMenuRemover13(string guia_){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Remover Dados de Funcionário \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite o ID do funcionário"
                 << " ou digite '0' para voltar ao menu anterior \n"
                 << std::endl 
                 << " Alternativa escolhida: "; 
      std::cin   >> alternativa; std::cin.ignore();
      excluiFuncionario(alternativa);
  } while (alternativa != 0);
}

void System::printMenuPesquisar1(string guia_){

}

void System::printMenuPesquisar12(string guia_){

}

void System::printMenuPesquisar13(string guia_){

}

void System::printMenuEditar1(string guia_){

}

void System::printMenuEditar12(string guia_){

}

void System::printMenuEditar13(string guia_){

}
