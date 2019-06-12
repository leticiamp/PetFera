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

    void listarAnimaisNaTela();
    void listarAnimaisEmArquivoCSV(); // Odilon deve fazer.
    void listarAnimaisComFiltroNaTela();
    void listarAnimaisComFiltroEmArquivoCSV();

    void listarFuncionariosNaTela();
    void listarFuncionariosEmArquivoCSV();
    void listarFuncionariosComFiltroNaTela();
    void listarFuncionariosComFiltroEmArquivoCSV();

    void inserirFuncionario(Tratador * funcionario);
    void inserirFuncionario(Veterinario * funcionario);
    void inserirFuncionario(Funcionario * funcionario);
    void inserirFuncionarioDigitando();
    void inserirFuncionarioViaArquivoCSV();

    void inserirAnimalMymapA(AveExo * animal);
    void inserirAnimalMymapA(AveNat * animal);
    void inserirAnimalMymapA(ReptilExo * animal);
    void inserirAnimalMymapA(ReptilNat * animal);
    void inserirAnimalMymapA(MamiferoExo * animal);
    void inserirAnimalMymapA(MamiferoNat * animal);
    void inserirAnimalMymapA(AnfibioExo * animal);
    void inserirAnimalMymapA(AnfibioNat * animal);

    void infoAnimalId(int &id_);
    void infoAnimalClasse(std::string &classe_);
    void infoAnimalNaturalidade(std::string &naturalidade_);
    void infoAnimalNomeCientifico(string &nome_cientifico_);
    void infoAnimalSexo(char &sexo);

    void infoMaiorQZero(double &generico, std::string os);
    void infoMaiorQZero(int &generico, std::string os);
    void infoString(std::string &generico, std::string os);
    void boolReptilVenenoso(bool &venenoso_);

    void inserirAnimalDigitando();
    void inserirAnimalViaArquivoCSV();


    Tratador * consultaTratador(int Id);
    Veterinario * consultaVeterinario(int Id);
    void consultaAnimaisDoTratador(int Id);

    void excluiAnimal(int Id);
    void excluiFuncionario(int Id);

    void MenuInicial();

    void printMenuListar1();
    void printMenuListar1_1();
    void printMenuListar1_2();

    void printMenuInserir1();
    void printMenuInserir1_1();
    void printMenuInserir1_2();

    void printMenuRemover1();
    void printMenuRemover1_1();
    void printMenuRemover1_2();

    void printMenuPesquisar1();
    void printMenuPesquisar1_1();
    void printMenuPesquisar1_2();

    void printMenuEditar1();
    void printMenuEditar1_1();
    void printMenuEditar1_2();


};
#endif
