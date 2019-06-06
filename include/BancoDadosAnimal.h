#ifndef _BANCO_DADOS_ANIMAL_H
#define _BANCO_DADOS_ANIMAL_H

#include <map>

#include "animal.h"

class BancoDadosAnimal{
private:
  std::map<int,Animal*> mymapAnimal;
public:

  BancoDadosAnimal();
  ~BancoDadosAnimal();

  void ListMyMap();
};

#endif
