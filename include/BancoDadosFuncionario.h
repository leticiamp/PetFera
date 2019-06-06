#ifndef _BANCO_DADOS_FUNCIONARIO_H
#define _BANCO_DADOS_FUNCIONARIO_H

#include <map>

#include "funcionario.h"
#include "tratador.h"
#include "veterinario.h"

class BancoDadosFuncionario{
private:
  std::map<int,Funcionario*> mymapFuncionario;
public:

  BancoDadosFuncionario();
  ~BancoDadosFuncionario();

  void ListMyMap();
};

#endif
