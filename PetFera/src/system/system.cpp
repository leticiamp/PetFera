#include "system.h"
System::System(){}
System::~System(){}

void System::menuInicial(){
  printMenuInicial();

}

//Metodos de listagem
void System::ListarAnimais(){
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin();
  it!= this->mymapA.end();
  ++it){
    std::cout << "Animal : " <<  it->first << " \n" << *it->second << "\n\n";
  }
}
void System::ListarFuncionarios(){
  for (std::map<int,Funcionario*>::iterator it = this->mymapF.begin();
        it!= this->mymapF.end();
        ++it){
        std::cout << "Funcionario : " <<  it->first << " \n" << *it->second << "\n\n";
    }
}

//Metodos de inserção

void System::InserirFuncionario(Tratador * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "Erro, Id já existe" << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Tratador*>(funcionario->getId(),funcionario));
}

void System::InserirFuncionario(Veterinario * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "Erro, Id já existe" << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Veterinario*>(funcionario->getId(),funcionario));
}

void System::InserirFuncionario(Funcionario * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "Erro, Id já existe" << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Funcionario *>(funcionario->getId(),funcionario));
}

void System::InserirAnimal(Animal * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "Erro, Id já existe" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, Animal*>(animal->getId(), animal));

}

Tratador * System::ConsultaTratador(int Id){
  return (dynamic_cast<Tratador*>(mymapF.find(Id)->second));
}


Veterinario * System::ConsultaVeterinario(int Id){
  return (dynamic_cast<Veterinario*>(mymapF.find(Id)->second));
}

void System::ConsultaAnimaisDoTratador(int Id){
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin();
  it!= this->mymapA.end();
  ++it){
    if( it->second->getTratador()->getId() == Id){
      std::cout << "Animal " << *it->second;
    }

  }
}

//Excluir
void System::ExcluiAnimal(int Id){
  this->mymapA.erase(Id);
}

void System::ExcluiFuncionario(int Id){
  this->mymapF.erase(Id);
}


//Menus
void System::printMenuInicial(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
  << " \n Escolha uma das seguintes alternativas abaixo: \n"
  << " Digite '1' para: Listar dados no banco\n"
  << " Digite '2' para: Fazer um novo Cadastro\n"
  << " Digite '3' para: Remover dados\n"
  << " Digite '4' para: Alteração de Cadastro\n"
  << " Digite '5' para: Pesquisar \n"
  << " Digite '6' para: Cadastrar via arquivo.csv\n"
  << " Digite '9' para: Finalizar Programa\n"
  << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
  << std::endl;
}

void System::printMenuListar1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
  << " \n Você escolheu a alternativa Listar Dados no banco\n"
  << " \n Escolha uma das seguintes alternativas abaixo: \n"
  << " Digite '1' para: Listar dados dos Animais\n"
  << " Digite '2' para: Listar dados dos Funcionarios\n"
  << std::endl;
}

void System::printMenuListar11(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
  << " \n Você escolheu a alternativa Listar dados dos animais :\n"
  << " \n Escolha uma das seguintes alternativas abaixo: \n"
  << " Digite '1' para: Listar todos os animais na tela\n"
  << " Digite '2' para: Listar todos os animais em arquivo csv\n"
  << " Digite '3' para: Listar todos os animais na tela com Filtro\n"
  << " Digite '3' para: Listar todos os animais em arquivo csv com Filtro\n"
  << std::endl;
}

void System::printMenuListar12(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa Listar dados dos Funcionarios :\n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Listar todos os funcionarios na tela\n"
             << " Digite '2' para: Listar todos os funcionarios em arquivo csv\n"
             << " Digite '3' para: Listar todos os funcionarios na tela com Filtro\n"
             << " Digite '3' para: Listar todos os funcionarios em arquivo csv com Filtro\n"
             << std::endl;
}
