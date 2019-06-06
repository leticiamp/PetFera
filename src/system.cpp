#include "system.h"
System::System(){}
System::~System(){}

void System::menuInicial(){
  printMenuInicial();
}

void System::printMenuInicial(){
std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
           << " \n Escolha uma das seguintes alternativas abaixo: \n"
           << " Digite '1' para: Listar dados\n"
           << " Digite '2' para: Fazer Cadastrar\n"
           << " Digite '3' para: Remover dados\n"
           << " Digite '4' para: Alteração de Cadastro\n"
           << " Digite '5' para: Pesquisar \n"
           << " Digite '6' para: Cadastrar via arquivo.csv\n"
           << " Digite '9' para: Finalizar Programa\n"
           << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
           <<std::endl;
}

void System::ListarAnimais(){
  this->mymapA.ListMyMap();
}

void System::ListarFuncionarios(){
  this->mymapF.ListMyMap();
}
