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
#include <fstream>
#include "system.h"


System::System(){}
System::~System(){
  if(this->mymapF.size() != 0){
    for (std::map<int,Funcionario*>::iterator it = this->mymapF.begin();
    it!= this->mymapF.end();
    ++it){
      delete it->second;
    }
  }
}


//Metodos de listagem

void System::listarAnimaisNaTela(){
  if(this->mymapA.size() == 0){
    std::cout << "Nenhum animal instanciado\n" << std::endl;
    return;
  }
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
    std::cout << "Animal : " <<  it->first << " \n" << *it->second << "\n\n";
  }
}

void System::listarAnimaisEmArquivoCSV(){
  //std::cout << " \n FALTA IMPLEMENTAR!\n "<< endl;
  std::string nomeDoArquivo;
  cout << " Qual é o nome do arquivo CSV com os dados dos novos animais? " << endl;
  cin >> nomeDoArquivo; cin.ignore();
  ifstream fileI; // Cria arquivo de entrada da dados.
  string lineAnimal; // Cria linha para armazenar linha-a-linha o texto do arquivo.
  fileI.open(nomeDoArquivo); //Abre o arquivo já existente no diretório.
  /* if(fileI.is_open()){
     while(getline(fileI, lineAnimal){

     }
  }
  */
}

void System::listarAnimaisComFiltroNaTela(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::listarAnimaisComFiltroEmArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::listarFuncionariosNaTela(){
  if(this->mymapF.size() == 0){
    std::cout << "Nenhum funcionario instanciado\n" << std::endl;
    return;
  }

  for (std::map<int,Funcionario*>::iterator it = this->mymapF.begin();
        it!= this->mymapF.end();
        ++it){
        std::cout << "Funcionario : " <<  it->first << " \n" << *it->second << "\n\n";
    }
}

void System::listarFuncionariosEmArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n "<< endl;
}

void System::listarFuncionariosComFiltroNaTela(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::listarFuncionariosComFiltroEmArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}


//Metodos de inserção



void System::inserirFuncionario(Tratador * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "\n Erro. Id já existe! " << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Tratador*>(funcionario->getId(),funcionario));
}

void System::inserirFuncionario(Veterinario * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Veterinario*>(funcionario->getId(),funcionario));
}

void System::inserirFuncionario(Funcionario * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Funcionario *>(funcionario->getId(),funcionario));
}

void System::inserirFuncionarioDigitando(){

  int id_;
  std::cout << " Qual o número idenficador do Funcionario a ser inserido? " << std::endl;
  std::cin >> id_; std::cin.ignore();

  while(this->mymapF.find(id_) != mymapF.end() && id_ != 0){ // Testando se entrada existe
      std::cout << "Entrada invalida, digite novamente\n";
      std::cout << " Qual o número idenficador do Funcionario a ser inserido? " << std::endl;
      std::cin >> id_; std::cin.ignore();
  }

  int funcao_;
  std::cout << " Qual a funcao do Funcionario: 1 para Veterinario e 2 para Tratador " << std::endl;
  std::cin >> funcao_; std::cin.ignore();

  while(funcao_ != 1 && funcao_ != 2){
    std::cout << "Entrada invalida, digite novamente\n";
    std::cout << " Qual a funcao do Funcionario: 1 para Veterinario e 2 para Tratador " << std::endl;
    std::cin >> funcao_; std::cin.ignore();

  }

  std::string nome_;
  std::cout << " Qual o nome do funcionario" << std::endl;
  std::cin >> nome_; std::cin.ignore();

  std::string cpf_;
  std::cout << " Qual o cpf do funcionario" << std::endl;
  std::cin >> cpf_; std::cin.ignore();

  short idade_;
  std::cout << " Qual a idade do funcionario" << std::endl;
  std::cin >> idade_; std::cin.ignore();

  while(idade_ < 0){ // Caso digite um numero negativo
    std::cout << "Entrada invalida, digite novamente\n";
    std::cout << " Qual a idade do funcionario" << std::endl;
    std::cin >> idade_; std::cin.ignore();

  }

  std::string tipo_sanguineo_;
  std::cout << " Qual o tipo_sanguineo do funcionario" << std::endl;
  std::cin >> tipo_sanguineo_; std::cin.ignore();

  while(tipo_sanguineo_ != "A" &&
        tipo_sanguineo_ != "B" &&
        tipo_sanguineo_ != "O" &&
        tipo_sanguineo_ != "AB")
        {
            std::cout << "Entrada invalida, digite novamente\n";
            std::cout << " Qual o tipo_sanguineo do funcionario" << std::endl;
            std::cin >> tipo_sanguineo_; std::cin.ignore();
        }

  char fator_rh_;
  std::cout << " Qual o fator rh do funcionario" << std::endl;
  std::cin >> fator_rh_; std::cin.ignore();

  while(fator_rh_ != '-' &&
        fator_rh_ != '+')
        {
          std::cout << "Entrada invalida, digite novamente\n";
          std::cout << " Qual o fator rh do funcionario" << std::endl;
          std::cin >> fator_rh_; std::cin.ignore();
        }

  std::string especialidade_;
  std::cout << " Qual a especialidade do funcionario" << std::endl;
  std::cin >> especialidade_; std::cin.ignore();

  if(funcao_ == 1 ){
      std::string crmv_;
      std::cout << " Qual o crmv do funcionario" << std::endl;
      std::cin >> crmv_; std::cin.ignore();
      Veterinario * funcionario = new Veterinario(  id_,
                                                    nome_,
                                                    cpf_,
                                                    idade_,
                                                    tipo_sanguineo_,
                                                    fator_rh_,
                                                    especialidade_,
                                                    crmv_);
    inserirFuncionario(funcionario);
  }

  if(funcao_ == 2){
    int nivel_de_seguranca_;
    std::cout << " Qual o nivel de segurança do funcionario" << std::endl;
    std::cin >> nivel_de_seguranca_; std::cin.ignore();

    while(nivel_de_seguranca_ != 0 &&
          nivel_de_seguranca_ != 1 &&
         nivel_de_seguranca_ != 2)
         {
           std::cout << "Entrada invalida, digite novamente\n";
           std::cout << " Qual o nivel de segurança do funcionario" << std::endl;
           std::cin >> nivel_de_seguranca_; std::cin.ignore();
          }
    Tratador * funcionario = new Tratador(  id_,
                                            nome_,
                                            cpf_,
                                            idade_,
                                            tipo_sanguineo_,
                                            fator_rh_,
                                            especialidade_,
                                            nivel_de_seguranca_);
    inserirFuncionario(funcionario);
  }

}


void System::inserirAnimal(){

//    if (m_totalDeAnimais < MAXIMO_DE_ANIMAIS){
    std::string nomeDoArquivo;
    cout << " Qual é o nome do arquivo CSV com os dados dos novos animais? " << endl;
    cin >> nomeDoArquivo; cin.ignore();

    ifstream fileI; // Cria arquivo de entrada da dados.
    string lineAnimal; // Cria linha para armazenar linha-a-linha o texto do arquivo.
    fileI.open(nomeDoArquivo); //Abre o arquivo já existente no diretório.

    if(fileI.is_open()){//Verifica se o arquivo está aberto.
      while(getline(fileI, lineAnimal)){
        /*
        if( mymapA.find(animal->getId()) != mymapA.end()){
          std::cout << "\n Erro. Id já existe!" << std::endl;
          return;
        }
        //this->mymapA.insert(std::pair<int, Animal*>(arquivo->begin(), animal));
        /*
        mymapA.insert(std::pair<int, Animal*>(animal->getId(), Animal(
                          id_,
                          classe_,
                          nome_cientifico_,
                          sexo_,
                          tamanho_,
                          dieta_,
                          veterinario_,
                          tratador_,
                          nome_batismo_,
                          mudas_,
                          pais_origem_,
                          cidade_origem_,
                          auto_ibama_)));
        */
        cout << lineAnimal << endl;
      }
      fileI.close();
    }else{
      cout << " Não foi possível abrir o arquivo! " << endl;
    }
//    }

}

void System::inserirAnimalDigitando(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;

  /*
      int id_;
    cout << " Qual o número idenficador do animal a ser inserido? " << endl;
    cin >> id_; cin.ignore();

    std::string classe_;
    cout << " Qual a classe do animal (Ave, Reptil, Mamifero ou Anfíbio)? " << endl;
    cin >> classe_; cin.ignore();

    std::string nome_cientifico_;
    cout << " Qual o nome científico do animal? " << endl;
    cin >> nome_cientifico_; cin.ignore();

    char sexo_;
    cout << " Qual o sexo do animal? (Digite 1 para macho e 2 para fêmea)" << endl;
    cin >> sexo_; cin.ignore();

    double tamanho_;
    cout << " Qual o tamanho do animal? (em centímentros)" << endl;
    cin >> tamanho_; cin.ignore();

    std::string dieta_;
    cout << " Qual a dieta do animal? " << endl;
    cin >> dieta_; cin.ignore();


    animais->insert(pair<int, Animal>(id_, Animal(
                          id_,
                          classe_,
                          nome_cientifico_,
                          sexo_,
                          tamanho_,
                          dieta_)));
  }
  */

}


void System::inserirAnimalViaArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::inserirFuncionarioViaArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

//Consulta

Tratador * System::consultaTratador(int Id){
  return (dynamic_cast<Tratador*>(mymapF.find(Id)->second));
}


Veterinario * System::consultaVeterinario(int Id){
  return (dynamic_cast<Veterinario*>(mymapF.find(Id)->second));
}

void System::consultaAnimaisDoTratador(int Id){
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin();
  it!= this->mymapA.end();
  ++it){
    if( it->second->getTratador()->getId() == Id){
      std::cout << "Animal " << *it->second;
    }

  }
}

//Excluir

void System::excluiAnimal(int Id){
  this->mymapA.erase(Id);
  /*  int id;
  cout << " Qual o número idenficador do animal a ser removido? " << endl;
  cin >> id; cin.ignore();

  fstream file;
  std::string lineAnimal;
  file.open("Lista_De_Animais.csv", fstream::in|fstream::out|fstream::trunc);

  if(file.is_open()){ // Verifica se está aberto.
    animais->erase(id);
    file << "\n\n Esse cadastro possui " << m_totalDeAnimais << " animais cadastrados."
     << "\n" << "\n============================================="
     << "\n Lista de animais cadastradas: \n\n";
  }else{
    cout << "Não foi possível abrir o arquivo!";
  }
  map<int, Animal>::iterator it;
  for (it = animais->begin(); it != animais->end(); ++it) // Impressao dos valores no mapa
  file << it->first << ";" << it->second << endl;
  }

  m_totalDeAnimais--;
  cout << " Animal excluído com sucesso!" << endl;
*/
}

void System::excluiFuncionario(int Id){
  this->mymapF.erase(Id);
}


//Menus

void System::MenuInicial(){
  int alternativa = -1;
  do{
      std::cout  << "\n\n"
                 << " ++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " ++++++++++ BEM-VINDO AO PETFERA ++++++++++++ \n"
                 << " ++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << "\n\n"
                 << " +++++++++++++ MENU PRINCIPAL++++++++++++++++ \n"
                 << "\n\n"
                 << " Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: LISTAR Dados do Banco\n"
                 << " Digite '2' para: INSERIR Dados do Banco\n"
                 << " Digite '3' para: REMOVER Dados do Banco\n"
                 << " Digite '4' para: PESQUISAR Dados do Banco\n"
                 << " Digite '5' para: EDITAR Dados do Banco \n"
                 << " Digite '0' para: SAIR do Programa\n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          system("clear");
          printMenuListar1(); // Menu Inicial >> Listar
          break;
        case 2 :
          system("clear");
          printMenuInserir1(); // Menu Inicial >> Inserir
          break;
        case 3 :
          system("clear");
          printMenuRemover1(); // Menu Inicial >> Remover
          break;
        case 4 :
          system("clear");
          printMenuPesquisar1(); // Menu Inicial >> Pesquisar
          break;
        case 5 :
          system("clear");
          printMenuEditar1(); // Menu Inicial >> Editar
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
      }
  } while (alternativa != 0);
}

void System::printMenuListar1(){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Listar Dados no Banco \n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Listar Dados dos Animais\n"
                 << " Digite '2' para: Listar Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          system("clear");
          printMenuListar1_1(); // Menu Inicial >> Listar >> Animais
          break;
        case 2 :
          system("clear");
          printMenuListar1_2(); // Menu Inicial >> Listar >> Funcionários
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuListar1_1(){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Listar Dados de Animais \n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Listar todos os animais na tela\n"
                 << " Digite '2' para: Listar todos os animais em arquivo csv\n"
                 << " Digite '3' para: Listar todos os animais na tela com Filtro\n"
                 << " Digite '4' para: Listar todos os animais em arquivo csv com Filtro\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          system("clear");
          listarAnimaisNaTela(); // Menu Inicial >> Listar >> Animais >> Tela
          break;
        case 2 :
          system("clear");
          listarAnimaisEmArquivoCSV(); // Menu Inicial >> Listar >> Animais >> Arquivo CSV
          break;
        case 3 :
          system("clear");
          listarAnimaisComFiltroNaTela(); // Menu Inicial >> Listar >> Animais >> Tela & Filtro
          break;
        case 4 :
          system("clear");
          listarAnimaisComFiltroEmArquivoCSV(); // Menu Inicial >> Listar >> Animais >> Arquivo CSV & Filtro
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuListar1_2(){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Listar Dados de Funcionários \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Listar todos os funcionários na tela\n"
                 << " Digite '2' para: Listar todos os funcionários em arquivo csv\n"
                 << " Digite '3' para: Listar todos os funcionários na tela com Filtro\n"
                 << " Digite '4' para: Listar todos os funcionários em arquivo csv com Filtro\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 :
          system("clear");
          listarFuncionariosNaTela(); // Menu Inicial >> Listar >> Funcionários >> Tela
          break;
        case 2 :
          system("clear");
          listarFuncionariosEmArquivoCSV(); // Menu Inicial >> Listar >> Funcionários >> Arquivo CSV
          break;
        case 3 :
          system("clear");
          listarFuncionariosComFiltroNaTela(); // Menu Inicial >> Listar >> Funcionários >> Tela & Filtro
          break;
        case 4 :
          system("clear");
          listarFuncionariosComFiltroEmArquivoCSV(); // Menu Inicial >> Listar >> Funcionários >> Arquivo CSV & Filtro
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuInserir1(){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Inserir Dados no Banco \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Inserir Dados dos Animais\n"
                 << " Digite '2' para: Inserir Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 :
          system("clear");
          printMenuInserir1_1(); // Menu Inicial >> Inserir >> Animais
          break;
        case 2 :
          system("clear");
          printMenuInserir1_2(); // Menu Inicial >> Inserir >> Funcionários
          break;
        case 0: // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuInserir1_1(){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Inserir Dados de Animal \n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Inserir Dados de Animal Item a Item (Digitando)\n"
                 << " Digite '2' para: Inserir Dados de Animal Via Arquivo CSV\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 :
          system("clear");
          inserirAnimalDigitando(); // Menu Inicial >> Inserir >> Animais >> Digitando
          break;
        case 2 :
          system("clear");
          inserirAnimalViaArquivoCSV(); // Menu Inicial >> Inserir >> Animais >> Arquivo CSV
          break;
        case 9 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuInserir1_2(){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Inserir Dados de Funcionário \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Inserir Dados de Funcionário Item a Item (Digitando)\n"
                 << " Digite '2' para: Inserir Dados de Funcionário Via Arquivo CSV\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 :
          system("clear");
          inserirFuncionarioDigitando(); // Menu Inicial >> Inserir >> Funcionário >> Digitando
          break;
        case 2 :
          system("clear");
          inserirFuncionarioViaArquivoCSV(); // Menu Inicial >> Listar >> Funcionário >> Arquivo CSV
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuRemover1(){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Remover Dados no Banco \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Remover Dados dos Animais\n"
                 << " Digite '2' para: Remover Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 :
          system("clear");
          printMenuRemover1_1(); // Menu Inicial >> Remover >> Animais
          break;
        case 2 :
          system("clear");
          printMenuRemover1_2(); // Menu Inicial >> Remover >> Funcionários
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}

void System::printMenuRemover1_1(){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Remover Dados de Animal \n"
                 << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite o ID do animal"
                 << " ou digite '0' para voltar ao menu anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      excluiAnimal(alternativa);
      system("clear");

      std::cout << "Caso deseje excluir outro animal -> digite\" 1\""
                << "Caso deseje voltar ao menu anterior digite \"0\"" << std::endl;
      std::cin   >> alternativa; std::cin.ignore();

  } while (alternativa != 0);
}

void System::printMenuRemover1_2(){
  int alternativa = -1;
  do{
      std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Remover Dados de Funcionário \n"
                 << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite o ID do funcionário"
                 << " ou digite '0' para voltar ao menu anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      excluiFuncionario(alternativa);

      system("clear");

      std::cout << "Caso deseje excluir outro funcionario -> digite\" 1\""
                << "Caso deseje voltar ao menu anterior digite \"0\"" << std::endl;
      std::cin   >> alternativa; std::cin.ignore();

  } while (alternativa != 0);
}

void System::printMenuPesquisar1(){

}

void System::printMenuPesquisar1_1(){

}

void System::printMenuPesquisar1_2(){

}

void System::printMenuEditar1(){

}

void System::printMenuEditar1_1(){

}

void System::printMenuEditar1_2(){

}
