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

#define MAXIMO_DE_ANIMAIS 50
#define MAXIMO_DE_FUNCIONARIOS 50 


class System{
  private:
    std::map<int,Funcionario*> mymapF;
    std::map<int,Animal*> mymapA;

    int m_totalDeAnimais = 0;
    int m_totalDeEmpresas = 0;
  public:
    System();
    ~System();

    void menuInicial(string guia_);
    void printMenuInicial(string guia_);

    void listarAnimais(string guia_);
    void listarAnimaisNaTela(string guia_);
    void listarAnimaisEmArquivoCSV(string guia_);
    void listarAnimaisComFiltroNaTela(string guia_);
    void listarAnimaisComFiltroEmArquivoCSV(string guia_);

    void listarFuncionarios(string guia_);
    void listarFuncionariosNaTela(string guia_);
    void listarFuncionariosEmArquivoCSV(string guia_);
    void listarFuncionariosComFiltroNaTela(string guia_);
    void listarFuncionariosComFiltroEmArquivoCSV(string guia_);

    void inserirFuncionario(Tratador * funcionario);
    void inserirFuncionario(Veterinario * funcionario);
    void inserirFuncionario(Funcionario * funcionario);
    void inserirFuncionarioDigitando(string guia_);
    void inserirFuncionarioViaArquivoCSV(string guia_);

    void inserirAnimal(/*Animal * animal*/);
    void inserirAnimalDigitando(string guia_);
    void inserirAnimalViaArquivoCSV(string guia_);


    Tratador * consultaTratador(int Id);
    Veterinario * consultaVeterinario(int Id);
    void consultaAnimaisDoTratador(int Id);

    void excluiAnimal(int Id);
    void excluiFuncionario(int Id);

    void printMenuListar1(string guia_);
    void printMenuListar12(string guia_);
    void printMenuListar13(string guia_);

    void printMenuInserir1(string guia_);
    void printMenuInserir12(string guia_);
    void printMenuInserir13(string guia_);

    void printMenuRemover1(string guia_);
    void printMenuRemover12(string guia_);
    void printMenuRemover13(string guia_);

    void printMenuPesquisar1(string guia_);
    void printMenuPesquisar12(string guia_);
    void printMenuPesquisar13(string guia_);

    void printMenuEditar1(string guia_);
    void printMenuEditar12(string guia_);
    void printMenuEditar13(string guia_);


};
#endif
