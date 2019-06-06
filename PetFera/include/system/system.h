#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <iostream>
#include <map>

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
    std::map<int, Animal*> mymapA;
  public:
    System();
    ~System();

    void menuInicial();
    void printMenuInicial();

    void ListarAnimais();
    void ListarFuncionarios();

    void InserirFuncionario(Tratador * funcionario);
    void InserirFuncionario(Veterinario * funcionario);
    void InserirFuncionario(Funcionario * funcionario);

    void InserirAnimal(Animal * animal);

    Tratador * ConsultaTratador(int Id);
    Veterinario * ConsultaVeterinario(int Id);
    void ConsultaAnimaisDoTratador(int Id);

    void ExcluiAnimal(int Id);
    void ExcluiFuncionario(int Id);

    void printMenuListar1();
    void printMenuListar11();
    void printMenuListar12();


};
#endif
