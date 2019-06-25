/**
* @file system.h
* @brief Classe responsável por controlar todo o programa
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 24/06/2019
*//

#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <iostream>
#include <map>
#include <string>

#include "petfera.h"

/**
* @details Nesta classe, o usuário pode controlar todo o programa PetFera, inserindo e imprimindo
*         animais, funcionários (tratadores e veterinários)
*/

class System{
  private:
    std::map<int,Funcionario*> mymapF;
    std::map<int,Animal*> mymapA;

  public:
    System(); /**< Construtor padrão*/
    ~System(); /**< Destrutor padrão*/

    //Metodos de Listagem
    void Print_MyMapA_Tela();
    void Print_MyMapF_Tela();

    void Print_MyMapA_Func_Tela(int Id); /**<Imprime todos os animais pelo Id do funcionario */

    void Print_MyMapA_CSV(std::string nomeArquivo); /**<Imprime os animais em um arquivo csv */
    void Print_MyMapF_CSV(std::string nomeArquivo); /**<Imprime os funcionarios em um arquivo csv */

    /** @brief Metodos de Importação Inicial dos Dados para o Banco. */
    void Import_CSV_To_MyMapF(std::string nomeArquivo);
    void Import_CSV_To_MyMapA(std::string nomeArquivo);

    /** @brief Metodos de instanciação de objetos */
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


    /** @brief Metodos de inserção no MyMapF */
    template<typename T>
    void inserirFuncionarioMyMapF(T * funcionario){
      if( this->mymapF.find(funcionario->getId()) != mymapF.end()){
        std::cout << "\nErro. Id já existe! " << std::endl;
        delete funcionario;
        return;
      }
      this->mymapF.insert(std::pair<int, T*>(funcionario->getId(),funcionario));
    }

    /** @brief Metodos de inserção no MyMapA */
    template<typename T>
    void inserirAnimalMyMapA(T * animal){
      if(animal->getTratador() == nullptr
         && animal->getVeterinario( ) == nullptr){
           std::cerr << "\nErro. Animal sem funcionario responsável" << std::endl;
           delete animal->getTratador();
           delete animal->getVeterinario();
           delete animal;
           return;
         }
      if( mymapA.find(animal->getId()) != mymapA.end()){
        std::cerr << "\nErro. Id já existe!" << std::endl;
        delete animal->getTratador();
        delete animal->getVeterinario();
        delete animal;
        return;
      }
      this->mymapA.insert(std::pair<int, T*>(animal->getId(),animal));
    }

    /** @brief Metodos de remoção do MyMap */
    void RemoverAnimal(int &id_);
    void RemoverFuncionario(int &id_);

    /** @brief Metodos com os tratamentos utilizados para "set" atributos */

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
    void setFuncIdade(T * funcionario){
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
      funcionario->setFator_rh(fator_rh_);
    }

    template <typename T>
    void setFuncEspecialidade(T * funcionario){
      system("clear");
      std::string especialidade_;
      std::cout <<  "Qual é a especialidade do Funcionario?" << std::endl;
      std::cin >> especialidade_;
      std::cin.ignore();
      funcionario->setEspecialidade(especialidade_);
    }

    template <typename T>
    void setFuncNivDeSeguranca(T * funcionario){
      system("clear");

      if (FlagNivDeSeguranca(funcionario) == false){
        std::cerr << "O funcionario não possue esse atributo" << std::endl;
        return;
      }

      int nivel_de_seguranca_;
      std::cout << "Qual o nivel de segurança do funcionario? (0, 1 ou 2)"  << std::endl;
      std::cin >> nivel_de_seguranca_;
      std::cin.ignore();

      while(nivel_de_seguranca_ != 0 &&
            nivel_de_seguranca_ != 1 &&
            nivel_de_seguranca_ != 2)
      {
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                  << "Qual o nivel de segurança do funcionario? (0, 1 ou 2)" << std::endl;
        std::cin >> nivel_de_seguranca_;
        std::cin.ignore();
      }
      funcionario->setNivel_de_Seguranca(nivel_de_seguranca_);
    }


    template <typename T>
    void setFuncCrmv(T * funcionario){
      system("clear");

      if (FlagCrmv(funcionario) == false){
        std::cerr << "O funcionario não possue esse atributo" << std::endl;
        return;
      }

      std::string crmv_;
      std::cout << "Qual o crmv do funcionario?"  << std::endl;
      std::cin >> crmv_;
      std::cin.ignore();

      funcionario->set_crmv(crmv_);
    }

    template <typename T>
    bool FlagNivDeSeguranca(T * funcionario){
      if(funcionario->getFuncao() == "Tratador"){
        return true;
      }
      return false;
    }

    template <typename T>
    bool FlagCrmv(T * funcionario){
      if(funcionario->getFuncao() == "Veterinario"){
        return true;
      }
      return false;
    }

    void DefFuncaoFunc(std::string &funcao_);

    /** @brief Metodos com os tratamentos utilizados p/ "set" atributos de animais da classe base */

    /*
      Não vai funcionar para mudar o numero do ID no MyMapA pq tem que mudar a chave também
      Da para melhorar a parte de teste (tratamente de exceção)
    */

    /** @brief Pergunta o ID do animal e teste se já existe no mymapA.*/
    template <typename T>
    void setAnimalId(T * animal){
      system("clear");

      int id_;

      std::cout << "Qual o número idenficador do animal a ser inserido? " << std::endl;
      std::cin >> id_; std::cin.ignore();

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

    template <typename T>
    void setAnimalTamanhoDoBico(T * animal){
      system("clear");

      if (FlagTamanhoDoBico(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      double tamanho_do_bico_cm_;
      std::cout << "Qual o tamanho do bico do animal ? (em cm)"  << std::endl;
      std::cin >> tamanho_do_bico_cm_;
      std::cin.ignore();

      while(tamanho_do_bico_cm_ < 0)
      {
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                  << "Qual o tamanho do bico do animal ? (em cm)"  << std::endl;
        std::cin >> tamanho_do_bico_cm_;
        std::cin.ignore();
      }

      animal->setTamanhoBicoCm(tamanho_do_bico_cm_);
    }

    template <typename T>
    void setAnimalEnvergaduraAsas(T * animal){
      system("clear");

      if (FlagEnvergaduraAsas(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      double envergadura_das_asas_;
      std::cout << "Qual o tamanho das asas do animal ? (em cm)"  << std::endl;
      std::cin >> envergadura_das_asas_;
      std::cin.ignore();

      while(envergadura_das_asas_ < 0)
      {
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                  << "Qual o tamanho das asas do animal ? (em cm)"  << std::endl;
        std::cin >> envergadura_das_asas_;
        std::cin.ignore();
      }

      animal->setEnvergaduraAsas(envergadura_das_asas_);
    }

    template <typename T>
    void setAnimalPaisOrigem(T * animal){
      system("clear");

      if (FlagPaisOrigem(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      std::string pais_origem_;
      std::cout <<  "Qual o pais de origem do animal?" << std::endl;
      std::cin >> pais_origem_;
      std::cin.ignore();
      animal->setPaisOrigem(pais_origem_);
    }

    template <typename T>
    void setAnimalCidadeOrigem(T * animal){
      system("clear");

      if (FlagCidadeOrigem(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      std::string cidade_origem_;
      std::cout <<  "Qual cidade de origem do animal?" << std::endl;
      std::cin >> cidade_origem_;
      std::cin.ignore();
      animal->setCidadeOrigem(cidade_origem_);
    }

    template <typename T>
    void setAnimalAutoIbama(T * animal){
      system("clear");

      if (FlagAutoIbama(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      std::string auto_ibama_;
      std::cout <<  "Qual a autorização do ibama do animal?" << std::endl;
      std::cin >> auto_ibama_;
      std::cin.ignore();
      animal->setAutoIbama(auto_ibama_);
    }

    template <typename T>
    void setAnimalUfOrigem(T * animal){
      system("clear");

      if (FlagUfOrigem(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      std::string uf_origem_;
      std::cout <<  "Qual a Uf de origem do animal?" << std::endl;
      std::cin >> uf_origem_;
      std::cin.ignore();
      animal->setUfOrigem(uf_origem_);
    }

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
      animal->setVenenoso(venenoso_);
    }

    template <typename T>
    void setAnimalTipoVeneno(T * animal){
      system("clear");

      if (FlagTipoVeneno(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      std::string tipo_veneno_;
      std::cout <<  "Qual o tipo do veneno do animal?" << std::endl;
      std::cin >> tipo_veneno_;
      std::cin.ignore();
      animal->setTipoVenenoso(tipo_veneno_);
    }

    template <typename T>
    void setAnimalNumMudas(T * animal){
      system("clear");

      if (FlagNumMudas(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      int mudas_;
      std::cout <<  "Quantas mudas o animal possue?" << std::endl;
      std::cin >> mudas_;
      std::cin.ignore();

      while(mudas_ < 0)
      {
        std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                  << "Quantas mudas o animal possue?"  << std::endl;
        std::cin >> mudas_;
        std::cin.ignore();
      }

      animal->set_m_total_de_mudas(mudas_);
    }

    template <typename T>
    void setAnimalCorDoPelo(T * animal){
      system("clear");

      if (FlagCorDoPelo(animal) == false){
        std::cerr << "O animal não possue esse atributo" << std::endl;
        return;
      }

      std::string CorDoPelo;
      std::cout <<  "Qual a cor do pelo do animal?" << std::endl;
      std::cin >> CorDoPelo;
      std::cin.ignore();
      animal->setCorPelo(CorDoPelo);
    }

    /** @details Metodos com os tratamentos utilizados para "set" atributos de animais
    * das classes Filhos.
    * Caso queira mudar ou utilizar esse metodo em uma classe nova, acrescente o nome
    * da classe a metodos de tratamento.
    */

    template <typename T>
    bool FlagCorDoPelo(T * animal){
      if(animal->getClasse() == "Mamifero"){
        return true;
      }
      return false;
    }

    template <typename T>
    bool FlagNumMudas(T * animal){
      if(animal->getClasse() == "Anfibio"){
        return true;
      }
      return false;
    }

    template <typename T>
    bool FlagTipoVeneno(T * animal){
      if(animal->getClasse() == "Reptil"){
        return true;
      }
      return false;
    }

    template <typename T>
    bool FlagUfOrigem(T * animal){
     if(animal->getNaturalidade() == "Nativo"){
       return true;
     }
     return false;
   }

    template <typename T>
    bool FlagAutoIbama(T * animal){
      if(animal->getNaturalidade() == "Exotico" ||
        animal->getNaturalidade() == "Nativo"){
        return true;
      }
      return false;
    }

    template <typename T>
    bool FlagCidadeOrigem(T * animal){
      if(animal->getNaturalidade() == "Exotico"){
        return true;
      }
      return false;
    }

    template <typename T>
    bool FlagPaisOrigem(T * animal){
      if(animal->getNaturalidade() == "Exotico"){
        return true;
      }
      return false;
    }

    template <typename T>
    bool FlagTamanhoDoBico(T * animal){
      if(animal->getClasse() == "Ave"){
        return true;
      }
      return false;
    }

    template <typename T>
    bool FlagEnvergaduraAsas(T * animal){
      if(animal->getClasse() == "Ave"){
        return true;
      }
      return false;
    }


    template <typename T>
    bool FlagVenenoso(T * animal){
      if(animal->getClasse() == "Reptil"){
        return true;
      }

      return false;
    }

    void DefAnimalClasse(std::string &classe_);
    void DefAnimalNaturalidade(std::string &naturalidade_);


    void infoString(std::string &generico, std::string os);


    Tratador * consultaTratador(int Id); /**< Pesquisa por um tratador através do ID*/
    Veterinario * consultaVeterinario(int Id); /**< Pesquisa por um veterinário através do ID*/







    /** @brief Menus que controlam as opções do usuário */
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
