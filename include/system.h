#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <iostream>
#include <map>

#include "BancoDadosAnimal.h"
#include "BancoDadosFuncionario.h"

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
    BancoDadosFuncionario mymapF;
    BancoDadosAnimal mymapA;
  public:
    System();
    ~System();

    void menuInicial();
    void printMenuInicial();
    void ListarAnimais();
    void ListarFuncionarios();
};
#endif
