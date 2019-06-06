#include "system.h"

int main(){

  System on;
//  on.menuInicial();
//  Tratador test1(1,"Lorena", "12345678911", 21, "A",'+',"felinos", 2);
//  Tratador test3(3,"Lorena", "12345678911", 21, "A",'+',"felinos", 2);
  Veterinario test(1,"Andre", "12345678922", 23, "A",'+',"Aves e repteis", "test");

//  on.InserirFuncionario(&test);
//  on.InserirFuncionario(&test3);

  AnfibioNat a(1, "AnfibioNat","ASdFA",
              'F' , 2, "casd",
              nullptr,
              nullptr,
               "ASD", 3, "Origem", "ibama sets");
  Animal * a1 = &a;
  on.InserirAnimal(a1);
  on.ListarAnimais();
/*

on.insert(&test3);


//std::cout << t->get_crmv();
//std::cout << *t1;
/*
BancoDadosAnimal mymapA;


mymapA.mymapAnimal.insert(std::pair<int,Animal*>(a.getId(),&a));

AnfibioNat * x = dynamic_cast<AnfibioNat *>(mymapA.mymapAnimal.find(1)->second);
  x->getTratador()->setId(5);

std::cout << *x;
*/
  return 0;
}
