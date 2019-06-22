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
#include <string>
#include "system.h"

int main(){

  	System on;
  	//on.MenuInicial();
    on.Import_CSV_To_MyMapF("testingF.csv");
    on.Print_MyMapF_Tela();
  return 0;
}
