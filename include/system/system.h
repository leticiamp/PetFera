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

#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <iostream>
#include <map>
#include <string>

#include "animal.h"
#include "funcionario.h"

#include "anfibioExotico.h"
#include "anfibioNativo.h"

#include "mamiferoExotico.h"
#include "mamiferoNativo.h"

#include "aveExotico.h"
#include "aveNativo.h"

#include "reptilExotico.h"
#include "reptilNativo.h"

class System{
  private:
    std::map<int,Funcionario*> mymapF;
    std::map<int,Animal*> mymapA;

  public:
    System();
    ~System();

    //Metodos de Listagem
    void Print_MyMapA_Tela();
    void Print_MyMapF_Tela();

    void Print_MyMapA_Func_Tela(int Id); // Imprime todos os animais pelo Id do funcionario

    void Print_MyMapA_CSV(std::string nomeArquivo);
    void Print_MyMapF_CSV(std::string nomeArquivo);

    //Metodos de controle de inserção no MyMap
    void Inserir_Func_MyMapF();
    void Inserir_Animal_MyMapA();

    //Metodos de inserção no MyMapF
    void inserirFuncionarioMyMapF(Tratador * funcionario);
    void inserirFuncionarioMyMapF(Veterinario * funcionario);

    //Metodos de inserção no MyMapA
    void inserirAnimalMyMapA(AveExo * animal);
    void inserirAnimalMyMapA(AveNat * animal);
    void inserirAnimalMyMapA(ReptilExo * animal);
    void inserirAnimalMyMapA(ReptilNat * animal);
    void inserirAnimalMyMapA(MamiferoExo * animal);
    void inserirAnimalMyMapA(MamiferoNat * animal);
    void inserirAnimalMyMapA(AnfibioExo * animal);
    void inserirAnimalMyMapA(AnfibioNat * animal);

    //Metodos de remoção do MyMap
    void RemoverAnimal(int &id_);
    void RemoverFuncionario(int &id_);

    //Metodos com os tratamentos utilizados p/ "set" atributos
    void DefIdFunc(int &id_);
    void DefFuncaoFunc(std::string &funcao_);
    void DefTipoSangueFunc(std::string &tipo_sanguineo_);
    void DefFatorRhFunc(char &fator_rh_);
    void DefNivSecurityFunc(int &nivel_de_seguranca_);

    //Metodos com os tratamentos utilizados p/ "set" atributos de animais
    void DefAnimalId(int &id_);
    void DefAnimalClasse(std::string &classe_);
    void DefAnimalNaturalidade(std::string &naturalidade_);
    void DefAnimalNomeCientifico(string &nome_cientifico_);
    void DefAnimalSexo(char &sexo);

    //Metodo expecifico de tratamento na instanciação da classe Reptil
    void boolReptilVenenoso(bool &venenoso_);

    //Metodos usados para instanciação de atributos sem restrição
    void infoMaiorQZero(double &generico, std::string os);
    void infoMaiorQZero(short &generico, std::string os);
    void infoMaiorQZero(int &generico, std::string os);
    void infoString(std::string &generico, std::string os);


    //Pesquisa
    Tratador * consultaTratador(int Id);
    Veterinario * consultaVeterinario(int Id);





    //Metodos a serem implementados
    void listarAnimaisEmArquivoCSV(); // Odilon deve fazer.
    void listarAnimaisComFiltroNaTela();
    void listarAnimaisComFiltroEmArquivoCSV();

    void listarFuncionariosEmArquivoCSV();
    void listarFuncionariosComFiltroNaTela();
    void listarFuncionariosComFiltroEmArquivoCSV();
    void inserirFuncionarioViaArquivoCSV();
    void inserirAnimalViaArquivoCSV();


    //Menus que controlam as opções do usuario
    void MenuInicial();
    void MenuListar1();
    void MenuListar1_1();
    void MenuListar1_2();
    void MenuInserir1();
    void MenuInserir1_1();
    void MenuInserir1_2();
    void MenuRemover1();
    void MenuRemover1_1();
    void MenuRemover1_2();
    void MenuPesquisar1();
    void MenuPesquisar1_1();
    void MenuPesquisar1_2();
    void MenuEditar1();

    //Cout's das opções dos menus
    void PrintMenuPrincipal();
    void PrintListar1();
    void PrintListar1_1();
    void PrintListar1_2();
    void PrintInserir1();
    void PrintInserir1_1();
    void PrintInserir1_2();
    void PrintRemover1();
    void PrintRemover1_1();
    void PrintRemover1_2();
    void PrintPesquisar1();
    void PrintPesquisar1_1();
    void PrintPesquisar1_2();
    void PrintEditar1();
    void PrintEditar1_1();



    void printMenuInserir1();
    void printMenuInserir1_1();
    void printMenuInserir1_2();
    void printMenuRemover1();
    void printMenuRemover1_1();
    void printMenuRemover1_2();
    void printMenuPesquisar1_1();
    void printMenuPesquisar1_2();
    void printMenuEditar1();
    void printMenuEditar1_1();
    void printMenuEditar1_2();


};
#endif
