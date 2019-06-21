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

    void Print_MyMapA_CSV(std::string nomeArquivo); //Imprime os animais em um arquivo csv
    void Print_MyMapF_CSV(std::string nomeArquivo); //Imprime os funcionarios em um arquivo csv

    //Metodos de Importação Inicial da Dados para o Banco. 
    void Import_CSV_To_MyMapF(std::string nomeArquivo);
    void Import_CSV_To_MyMapA(std::string nomeArquivo);

    //Metodos de instanciação de objetos
    void Inserir_Func_MyMapF();
    void Inserir_Animal_MyMapA();

    Tratador * NewTratador();
    Veterinario * NewVeterinario();

    AveExo * NewAveExo();
    AveNat * NewAveNat();
    ReptilExo * NewReptilExo();
    ReptilNat * NewReptilNat();
    MamiferoExo * NewMamiferoExo();
    MamiferoNat * NewMamiferoNat();
    AnfibioExo * NewAnfibioExo();
    AnfibioNat * NewAnfibioNat();


    //Metodos de inserção no MyMapF
    template<typename T>
    void inserirFuncionarioMyMapF(T * funcionario){
      if( this->mymapF.find(funcionario->getId()) != mymapF.end()){
        std::cout << "\n Erro. Id já existe! " << std::endl;
        return;
      }
      this->mymapF.insert(std::pair<int, T*>(funcionario->getId(),funcionario));
    }

    //Metodos de inserção no MyMapA
    template<typename T>
    void inserirAnimalMyMapA(T * animal){
      if( mymapA.find(animal->getId()) != mymapA.end()){
        std::cout << "\n Erro. Id já existe!" << std::endl;
        return;
      }
      this->mymapA.insert(std::pair<int, T*>(animal->getId(),animal));
    }

    //Metodos de remoção do MyMap
    void RemoverAnimal(int &id_);
    void RemoverFuncionario(int &id_);

    //Metodos com os tratamentos utilizados p/ "set" atributos

    template <typename T>
    void setFuncId(T * funcionario){
      system("clear");
      int id_;
      std::cout << "Qual o número idenficador do Funcionario a ser inserido?" << std::endl;
      std::cin >> id_;
      std::cin.ignore();

      while(this->mymapF.find(id_) != mymapF.end() && id_ != 0){ // Testando se entrada existe
        system("clear");
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                  << "Qual o número idenficador do Funcionario a ser inserido? " << std::endl;
        std::cin >> id_; std::cin.ignore();
      }
      funcionario->setId(id_);
    }

    template <typename T>
    void setFuncNome(T * funcionario){
      system("clear");
      std::string nome_;
      std::cout <<  "Qual o nome do Funcionario?" << std::endl;
      std::cin >> nome_;
      std::cin.ignore();
      funcionario->setNome(nome_);
    }

    template <typename T>
    void setFuncCpf(T * funcionario){
      system("clear");
      std::string cpf_;
      std::cout <<  "Qual é o cpf do Funcionario?" << std::endl;
      std::cin >> cpf_;
      std::cin.ignore();
      funcionario->setCpf(cpf_);
    }

    template <typename T>
    void setIdade(T * funcionario){
      system("clear");
      short idade_;
      std::cout << "Qual a idade do funcionario?" << std::endl;
      std::cin >> idade_;
      std::cin.ignore();

      while(idade_ < 0)
      {
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
        << "Qual a idade do funcionario?" << std::endl;
        std::cin >> idade_;
        std::cin.ignore();
      }
      funcionario->setIdade(idade_);
    }

    template <typename T>
    void setFuncTipoSanguineo(T * funcionario){
      system("clear");
      std::string tipo_sanguineo_;
      std::cout << "Qual o tipo sanguineo do funcionario?" << std::endl;
      std::cin >> tipo_sanguineo_;
      std::cin.ignore();

      while(tipo_sanguineo_ != "A" &&
      tipo_sanguineo_ != "B" &&
      tipo_sanguineo_ != "O" &&
      tipo_sanguineo_ != "AB")
      {
        system("clear");
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                  << "Qual o tipo sanguineo do funcionario?" << std::endl;
        std::cin >> tipo_sanguineo_; std::cin.ignore();
      }
      funcionario->setTipo_sanguineo(tipo_sanguineo_);
    }

    template <typename T>
    void setFuncFatorRh(T * funcionario){
      system("clear");
      char fator_rh_;
      std::cout << "Qual o fator rh do funcionario?" << std::endl;
      std::cin >> fator_rh_;
      std::cin.ignore();

      while(fator_rh_ != '-' &&
      fator_rh_ != '+')
      {
        system("clear");
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                  << "Qual o fator rh do funcionario?" << std::endl;
        std::cin >> fator_rh_; std::cin.ignore();
      }
    }

    template <typename T>
    void setEspecialidade(T * funcionario){
      system("clear");
      std::string especialidade_;
      std::cout <<  "Qual é a especialidade do Funcionario?" << std::endl;
      std::cin >> especialidade_;
      std::cin.ignore();
      funcionario->setEspecialidade(especialidade_);
    }


    void DefIdFunc(int &id_);
    void DefFuncaoFunc(std::string &funcao_);
    void DefTipoSangueFunc(std::string &tipo_sanguineo_);
    void DefFatorRhFunc(char &fator_rh_);
    void DefNivSecurityFunc(int &nivel_de_seguranca_);

    //Metodos com os tratamentos utilizados p/ "set" atributos de animais da classe base

    /*
      Não vai funcionar para mudar o numero do ID no MyMapA pq tem que mudar a chave também
      Da para melhorar a parte de teste (tratamente de exceção)
    */
    template <typename T>
    void setAnimalId(T * animal){
      system("clear");

      int id_;
      //Pergunta o ID do animal
      std::cout << "Qual o número idenficador do animal a ser inserido? " << std::endl;
      std::cin >> id_; std::cin.ignore();

      // Testando se Id existencia no mymapA
      while(this->mymapA.find(id_) != this->mymapA.end()){
        system("clear");
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
        << " Qual o número idenficador do animal a ser inserido?" << std::endl;
        std::cin  >> id_;
        std::cin.ignore();
      }

      animal->setId(id_);
    }

    template <typename T>
    void setAnimalNomeCientifico(T * animal){
      system("clear");
      std::string nome_cientifico_;
      //Pergunta nome Cientifico
      std::cout << " Qual o nome científico do animal? " << std::endl;
      std::cin >> nome_cientifico_; std::cin.ignore();

      animal->setNome(nome_cientifico_);
    }

    template <typename T> // Melhorar a parte de tratamento M e F com try e catch
    void setAnimalSexo(T * animal){
      system("clear");
      char sexo_;
      //Pergunta sexo do animal
      std::cout << " Qual o sexo do animal? (Digite M para macho e F para fêmea)" << std::endl;
      std::cin  >> sexo_;
      std::cin.ignore();

      //Tratamento de entrada só deixa passar M ou F
      while(sexo_ != 'M' && sexo_ != 'F')
      {
        system("clear");
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
        << "Qual o sexo do animal ? \n"
        << "Digite M para o sexo Masculino e F para o sexo Feminino : ";
        std::cin >> sexo_;
        std::cin.ignore();
      }

      animal->setSexo(sexo_);
    }

    template <typename T>
    void setAnimalTamanho(T * animal){
      system("clear");
      double tamanho_;
      std::cout << "Qual o tamanho do animal? " << std::endl;
      std::cin >> tamanho_;
      std::cin.ignore();

      while(tamanho_ < 0)
      {
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
        << "Qual o tamanho do animal? " << std::endl;
        std::cin >> tamanho_;
        std::cin.ignore();
      }
      animal->setTamanho(tamanho_);
    }

    template <typename T>
    void setAnimalDieta(T * animal){
      system("clear");
      std::string dieta_;
      std::cout <<  "Qual a dieta do animal?" << std::endl;
      std::cin >> dieta_;
      std::cin.ignore();
      animal->setDieta(dieta_);
    }

    template <typename T>
    void setAnimalNomeBatismo(T * animal){
      system("clear");
      std::string nome_batismo_;
      std::cout <<  "Qual o nome de batismo do animal?" << std::endl;
      std::cin >> nome_batismo_;
      std::cin.ignore();
      animal->setNomeBatismo(nome_batismo_);
    }

    template <typename T>
    void setAnimalVeterinario(T * animal){
      system("clear");

      int id_;
      int aux1 = 1;
      do{
        std::cout << "Digite o id do Veterinario, caso o animal não tenha, digite 0 : \n";
        std::cin >> id_;
        std::cin.ignore();

        if(this->mymapF.find(id_) != this->mymapF.end() && id_ != 0
          && this->mymapF.find(id_)->second->getFuncao() == "Veterinario")
        {
              animal->setVeterinario(dynamic_cast<Veterinario*> (mymapF.find(id_)->second));
              aux1 = 0;
        }else if(id_ == 0){
          aux1 = 0;
          animal->setVeterinario(nullptr);
        }else{
          system("clear");
          std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n" << std::endl;
        }
      }while(aux1 != 0);

    }

    template <typename T>
    void setAnimalTratador(T * animal){
      system("clear");

      int id_;
      int aux1 = 1;
      do{
        std::cout << "Digite o id do Tratador, caso o animal não tenha, digite 0 : \n";
        std::cin >> id_;
        std::cin.ignore();

        if(this->mymapF.find(id_) != this->mymapF.end() && id_ != 0
          && this->mymapF.find(id_)->second->getFuncao() == "Tratador")
        {
              animal->setTratador(dynamic_cast<Tratador*> (mymapF.find(id_)->second));
              aux1 = 0;
        }else if(id_ == 0){
          aux1 = 0;
          animal->setTratador(nullptr);
        }else{
          system("clear");
          std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n" << std::endl;
        }
      }while(aux1 != 0);

    }

    /*
      Metodos com os tratamentos utilizados p/ "set" atributos de animais das classes Filhos
      Caso queira mudar ou utilizar esse metodo em uma classe nova
      acrescente o nome da classe a metodos de tratamento
    */
    //tem que botar um ponteiro de função que passe o Cast para qual Tipo de animal vai ser
    //Lembrar de implementar
    template <typename T>
    void setAnimalVenenoso(T * animal){
      system("clear");

      if (FlagVenenoso(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      bool venenoso_;

      //Pergunta se o animal é venenoso ou não
      int aux;
      std::cout << "O animal é venenoso ? Digite 1 para sim e 0 para não" << std::endl;
      std::cin  >> aux;
      std::cin.ignore();

      while(aux != 1 && aux != 0)
      {
        system("clear");
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                  << "O animal é venenoso ? Digite 1 para sim e 0 para não" << std::endl;
        std::cin >> aux;
        std::cin.ignore();
      }

      venenoso_ = aux;

    }

    //Metodos de tratamento
    template <typename T>
    bool FlagVenenoso(T * animal){
      if(animal->getFuncao() == "Reptil"){
        return true;
      }

      return false;
    }

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


};
#endif
