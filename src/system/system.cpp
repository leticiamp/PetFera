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
    std::cout << " Nenhum animal instanciado.\n" << std::endl;
    return;
  }
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
    std::cout << "Animal : " <<  it->first << " \n" << *it->second << "\n\n";
  }
}

void System::listarAnimaisEmArquivoCSV(){ // Salva todos os animais em uma arquivo.
  std::string nomeDoArquivoCSV;
  std::cout << " Qual o nome do arquivo para salvar a lista de animais? " << std::endl;
  std::cin >> nomeDoArquivoCSV; 
  std::cin.ignore();

  ofstream file; // Cria arquivo.
	file.open(nomeDoArquivoCSV); 
	
	file << "\n\n Esse cadastro possui " << mymapA.size() << " animal(is) cadastrado(s)."
		   << "ID;Classe;Nome_Cientifico;Sexo;Tamanho;Dieta;Nome_de_Batismo;Naturalidade;Tamanho_do_Bico;Envergadura_das_Asas;Veterinario_Responsavel;ID;Funcao;Name;CPF;AGE;BLOOD_TYPE;RH_FACTOR;ESPECIALIDADE;CRMV;Tratador_Responsavel;Pais;Ibama_Autorização\n";
	for (std::map<int,Animal*>::iterator it = this->mymapA.begin();it!= this->mymapA.end(); ++it){
      file <<  it->first << ";" << *it->second << std::endl;
  }
	file.close();
}

void System::listarAnimaisComFiltroNaTela(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::listarAnimaisComFiltroEmArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}

void System::listarFuncionariosNaTela(){
  if(this->mymapF.size() == 0){
    std::cout << " Nenhum funcionario instanciado.\n" << std::endl;
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
  std::cout << " Qual o número idenficador do funcionário a ser inserido? " << std::endl;
  std::cin >> id_; std::cin.ignore();

  while(this->mymapF.find(id_) != mymapF.end() && id_ != 0){ // Testando se entrada existe
      std::cout << " Entrada inválida. Digite novamente.\n";
      std::cout << " Qual o número idenficador do funcionário a ser inserido? " << std::endl;
      std::cin >> id_; std::cin.ignore();
  }

  int funcao_;
  std::cout << " Qual a funcao do funcionário? Digite 1 para Veterinário ou 2 para Tratador. " << std::endl;
  std::cin >> funcao_; std::cin.ignore();

  while(funcao_ != 1 && funcao_ != 2){
    std::cout << " Entrada inválida! Digite novamente. \n";
    std::cout << " Qual a funcao do funcionário? Digite 1 para Veterinário ou 2 para Tratador. " << std::endl;
    std::cin >> funcao_; std::cin.ignore();

  }

  std::string nome_;
  std::cout << " Qual o nome do funcionário? " << std::endl;
  std::cin >> nome_; std::cin.ignore();

  std::string cpf_;
  std::cout << " Qual o cpf do funcionario?" << std::endl;
  std::cin >> cpf_; std::cin.ignore();

  short idade_;
  std::cout << " Qual a idade do funcionário? " << std::endl;
  std::cin >> idade_; std::cin.ignore();

  while(idade_ < 0){ // Caso digite um numero negativo
    std::cout << " Entrada inválida. Digite novamente.\n";
    std::cout << " Qual a idade do funcionário? " << std::endl;
    std::cin >> idade_; std::cin.ignore();

  }

  std::string tipo_sanguineo_;
  std::cout << " Qual o tipo sanguíneo do funcionário? " << std::endl;
  std::cin >> tipo_sanguineo_; std::cin.ignore();

  while(tipo_sanguineo_ != "A" &&
        tipo_sanguineo_ != "B" &&
        tipo_sanguineo_ != "O" &&
        tipo_sanguineo_ != "AB")
        {
            std::cout << " Entrada invalida. Digite novamente.\n";
            std::cout << " Qual o tipo_sanguíneo do funcionário? " << std::endl;
            std::cin >> tipo_sanguineo_; std::cin.ignore();
        }

  char fator_rh_;
  std::cout << " Qual o fator rh do funcionário? " << std::endl;
  std::cin >> fator_rh_; std::cin.ignore();

  while(fator_rh_ != '-' &&
        fator_rh_ != '+')
        {
          std::cout << "Entrada inválida. Digite novamente. \n";
          std::cout << " Qual o fator rh do funcionario? " << std::endl;
          std::cin >> fator_rh_; std::cin.ignore();
        }

  std::string especialidade_;
  std::cout << " Qual a especialidade do funcionário? " << std::endl;
  std::cin >> especialidade_; std::cin.ignore();

  if(funcao_ == 1 ){
      std::string crmv_;
      std::cout << " Qual o crmv do funcionario? " << std::endl;
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
    std::cout << " Qual o nível de segurança do funcionário? " << std::endl;
    std::cin >> nivel_de_seguranca_; std::cin.ignore();

    while(nivel_de_seguranca_ != 0 &&
          nivel_de_seguranca_ != 1 &&
         nivel_de_seguranca_ != 2)
         {
           std::cout << " Entrada inválida. Digite novamente. \n";
           std::cout << " Qual o nível de segurança do funcionário? " << std::endl;
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

void System::inserirAnimalMymapA(AveExo * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, AveExo*>(animal->getId(),animal));
}

void System::inserirAnimalMymapA(AveNat * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, AveNat*>(animal->getId(),animal));
}

void System::inserirAnimalMymapA(ReptilExo * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, ReptilExo*>(animal->getId(),animal));
}

void System::inserirAnimalMymapA(ReptilNat * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, ReptilNat*>(animal->getId(),animal));
}

void System::inserirAnimalMymapA(MamiferoExo * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, MamiferoExo*>(animal->getId(),animal));
}

void System::inserirAnimalMymapA(MamiferoNat * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, MamiferoNat*>(animal->getId(),animal));
}

void System::inserirAnimalMymapA(AnfibioExo * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, AnfibioExo*>(animal->getId(),animal));
}

void System::inserirAnimalMymapA(AnfibioNat * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, AnfibioNat*>(animal->getId(),animal));
}

void System::infoAnimalId(int &id_){

  //Pergunta o ID do animal
  std::cout << " Qual o número idenficador do animal a ser inserido? " << std::endl;
  std::cin >> id_; std::cin.ignore();

  // Testando se Id existencia no mymapA
  while(this->mymapA.find(id_) != this->mymapA.end()){
      system("clear");
      std::cout << " ++++++++++++ ENTRADA INVÁLIDA. TENTE NOVAMENTE. ++++++++++++++++\n"
                << " Qual o número idenficador do animal a ser inserido? " << std::endl;
      std::cin  >> id_;
      std::cin.ignore();
  }
  system("clear");
}

void System::infoAnimalClasse(std::string &classe_){

  std::cout << " Qual a classe do animal: Ave, Réptil, Mamífero ou Anfíbio? (Digite sem acento)"
            << std::endl;
  std::cin  >> classe_;
  std::cin.ignore();

  while(classe_ != "Ave" && classe_ != "Anfibio"  &&
        classe_ != "Mamifero" && classe_ != "Reptil")
    {
      system("clear");
      std::cout << " ++++++++++++++++ ENTRADA INVÁLIDA. TENTE NOVAMENTE. ++++++++++++++++\n"
                << " Qual a classe do animal: Ave, Réptil, Mamífero ou Anfíbio? (Digite sem acento)"
                << std::endl;
      std::cin  >> classe_;
      std::cin.ignore();
    }
    system("clear");
}

void System::infoAnimalNaturalidade(std::string &naturalidade_){
  std::cout << " Qual a naturalidade do animal? Exótico ou Nativo? (Digite sem acento)"
            << std::endl;
  std::cin  >> naturalidade_;
  std::cin.ignore();

  while(naturalidade_ != "Exotico" && naturalidade_ != "Nativo")
    {
      system("clear");
      std::cout << " ++++++++++++++++ ENTRADA INVÁLIDA. TENTE NOVAMENTE. ++++++++++++++++\n"
                << " Qual a naturalidade do animal: Exótico ou Nativo? (Digite sem acento) "
                << std::endl;
      std::cin  >> naturalidade_;
      std::cin.ignore();
    }
    system("clear");
}

void System::infoAnimalNomeCientifico(string &nome_cientifico_){
  //Pergunta nome Cientifico
  std::cout << " Qual o nome científico do animal? " << std::endl;
  std::cin >> nome_cientifico_; std::cin.ignore();
  system("clear");
}

void System::infoAnimalSexo(char &sexo_){
  //Pergunta sexo do animal
  std::cout << " Qual o sexo do animal? (Digite M para macho e F para fêmea)" << std::endl;
  std::cin  >> sexo_;
  std::cin.ignore();

  //Tratamento de entrada só deixa passar M ou F
  while(sexo_ != 'M' && sexo_ != 'F')
        {
          system("clear");
          std::cout << " ++++++++++++ ENTRADA INVÁLIDA. TENTE NOVAMENTE. ++++++++++++++++\n"
                    << " Qual o sexo do animal? \n"
                    << " Digite M para o macho e F para o fêmea: ";
          std::cin >> sexo_;
          std::cin.ignore();
        }
  system("clear");
}

void System::infoMaiorQZero(double &generico, std::string os){
  std::cout << os << std::endl;
  std::cin >> generico;
  std::cin.ignore();

  while(generico < 0)
        {
          std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                    << os << std::endl;
          std::cin >> generico;
          std::cin.ignore();
        }
  system("clear");
}

void System::infoMaiorQZero(int &generico, std::string os){
  std::cout << os << std::endl;
  std::cin >> generico;
  std::cin.ignore();

  while(generico < 0)
        {
          std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
                    << os << std::endl;
          std::cin >> generico;
          std::cin.ignore();
        }
  system("clear");
}

void System::infoString(std::string &generico, std::string os){
  // Função genérica que recebe dois parametros string
  // onde "os" está com a pergunta a ser respondida no
  // genericos.
  std::cout << os << std::endl;
  std::cin >> generico;
  std::cin.ignore();

  system("clear");
}

void System::boolReptilVenenoso(bool &venenoso_){
  //Pergunta se o animal é venenoso ou não
  int aux;
  std::cout << " O animal é venenoso? Digite 1 para 'sim' e 0 para 'não'. "
            << std::endl;
  std::cin  >> aux;
  std::cin.ignore();

  while(aux != 1 && aux != 0)
        {
          system("clear");
          std::cout << " ++++++++++++ ENTRADA INVÁLIDA. TENTE NOVAMENTE ++++++++++++++++\n"
                    << " O animal é venenoso? Digite 1 para 'sim' e 0 para 'não'. "
                    << std::endl;
          std::cin >> aux;
          std::cin.ignore();
        }
  venenoso_ = aux;
  system("clear");
}

void System::inserirAnimalDigitando(){
  //Condição de parada, se nao existir funcionários.
  if(mymapF.size() == 0){
    std::cout << " Não existem funcionários para cuidar dos animais. \n" << std::endl;
    return;
  }

  std::string classe_; // Classe do animal
  infoAnimalClasse(classe_); //Pergunta a classe do animal

  std::string naturalidade_;// naturalidade do animal (Exotico ou Nativo)
  infoAnimalNaturalidade(naturalidade_); // Perguntando a naturalidade do animal

  int id_; //Id do animal
  infoAnimalId(id_); // Perguntando a classe do animal

  std::string nome_cientifico_; //Nome Cientifico do animal
  infoAnimalNomeCientifico(nome_cientifico_); // Perguntando o nome Cienficio do animal

  char sexo_; // Sexo do animal
  infoAnimalSexo(sexo_); // Perguntando o sexo do animal

  double tamanho_; // Tamanho do animal
  //perguntando o tamanho do animal
  infoMaiorQZero(tamanho_, " Qual o tamanho do animal? (em centímentros)");

  std::string dieta_; //Dieta do animal
  infoString(dieta_, " Qual a dieta do animal?" ); // Perguntando a dieta do animal

  std::string nome_batismo_; // Nome do animal
  //Perguntando nome do animal
  infoString(nome_batismo_, " Qual o nome de batismo do animal? " );

  std::string auto_ibama_; // autorização do ibama do animal
  //perguntando autorização do ibama do animal
  infoString(auto_ibama_, " Qual a autorização do ibama do animal? ");

  Veterinario * veterinario_ = nullptr;
  Tratador * tratador_ = nullptr;
  int aux;

  std::cout << " Digite o id do Veterinário. Caso o animal não tenha, digite 0: \n";
  std::cin >> aux;
  std::cin.ignore();

  while(this->mymapF.find(aux) == this->mymapF.end() && aux != 0){
    std::cout << " Digite o id do Veterinário. Caso o animal não tenha, digite 0.";
    std::cin >> aux;
    std::cin.ignore();
  }

  if(aux != 0){
    veterinario_ = dynamic_cast<Veterinario*> (mymapF.find(aux)->second);
  }

  std::cout << " Digite o id do Tratador. Caso o animal não tenha, digite 0: \n";
  std::cin >> aux;
  std::cin.ignore();

  while(this->mymapF.find(aux) == this->mymapF.end() && aux != 0){
    std::cout << " Digite o id do Tratador. Caso o animal não tenha, digite 0: \n";
    std::cin >> aux;
    std::cin.ignore();
  }

  if(aux != 0){
    tratador_ = dynamic_cast<Tratador*> (mymapF.find(aux)->second);
  }

  //Condição de parada sem funcionario cuidador
    if(veterinario_ == nullptr && tratador_ == nullptr){
    std::cout << "Erro: Não foram atrelados funcionários para cuidar dos animais. \n" << std::endl;
    delete veterinario_;
    delete tratador_;
    return;
  }

  //Declaração das variaveis
  double tamanho_do_bico_cm_; // Caracteristica de Ave
  double envergadura_das_asas_; // Caracteristica de Ave
  int mudas_; // Caracteristica de Anfibio
  std::string cor_pelo_; //Caracteristica de Mamifero
  bool venenoso_; // Caracteristica de Reptil
  std::string tipo_veneno_; // Caracteristica de Reptil
  std::string pais_origem_; // Caracteristica de animal exotico
  std::string cidade_origem_; // Caracteristica de animal exotico
  std::string uf_origem_; //Caracteristica de animal nativo

  if(classe_ == "Ave"){
    infoMaiorQZero(tamanho_do_bico_cm_,
        "Qual o tamanho do bico do animal? (em centímentros)");
    infoMaiorQZero(envergadura_das_asas_,
        "Qual o tamanho da envergadura das asas do animal? (em centímentros)");
  }
  else if(classe_ == "Mamifero"){
    infoString(cor_pelo_,"Qual a cor do pelo do animal?");
  }
  else if(classe_ == "Reptil"){
    boolReptilVenenoso(venenoso_);
    if(venenoso_){
      infoString(tipo_veneno_, "Qual o tipo de veneno do animal?");
    }
    else{
      tipo_veneno_ = "Não venenoso";
    }
  }else if(classe_ == "Anfibio"){
    infoMaiorQZero(mudas_, "Qual a quantidade de mudas do animal?");
  }

  if(naturalidade_ == "Exotico"){
    infoString(pais_origem_, "Qual o pais de origem do animal?");
    infoString(cidade_origem_, "Qual a cidade de origem do animal?");
  }
  else if( naturalidade_ == "Nativo"){
    infoString(uf_origem_, "Qual o Uf origem do animal?");
  }

  if(classe_ == "Ave" && naturalidade_ == "Exotico"){
    AveExo * animal = new AveExo(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  tamanho_do_bico_cm_,
                                  envergadura_das_asas_,
                                  pais_origem_,
                                  cidade_origem_,
                                  auto_ibama_);
    inserirAnimalMymapA(animal);
  }
  if(classe_ == "Mamifero" && naturalidade_ == "Exotico"){
    MamiferoExo * animal = new MamiferoExo(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  cor_pelo_,
                                  pais_origem_,
                                  cidade_origem_,
                                  auto_ibama_);
    inserirAnimalMymapA(animal);
  }
  if(classe_ == "Reptil" && naturalidade_ == "Exotico"){
    ReptilExo * animal = new ReptilExo(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  venenoso_,
                                  tipo_veneno_,
                                  pais_origem_,
                                  cidade_origem_,
                                  auto_ibama_);
    inserirAnimalMymapA(animal);
  }
  if(classe_ == "Anfibio" && naturalidade_ == "Exotico"){
    AnfibioExo * animal = new AnfibioExo(id_,
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
                                  auto_ibama_);
    inserirAnimalMymapA(animal);
  }


  if(classe_ == "Ave" && naturalidade_ == "Nativo"){
    AveNat * animal = new AveNat  (id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  tamanho_do_bico_cm_,
                                  envergadura_das_asas_,
                                  uf_origem_,
                                  auto_ibama_);
    inserirAnimalMymapA(animal);
  }
  if(classe_ == "Mamifero" && naturalidade_ == "Nativo"){
    MamiferoNat * animal = new MamiferoNat(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  cor_pelo_,
                                  uf_origem_,
                                  auto_ibama_);
    inserirAnimalMymapA(animal);
  }
  if(classe_ == "Reptil" && naturalidade_ == "Nativo"){
    ReptilNat * animal = new ReptilNat(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  venenoso_,
                                  tipo_veneno_,
                                  uf_origem_,
                                  auto_ibama_);
    inserirAnimalMymapA(animal);
  }
  if(classe_ == "Anfibio" && naturalidade_ == "Nativo"){
    AnfibioNat * animal = new AnfibioNat(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  mudas_,
                                  uf_origem_,
                                  auto_ibama_);
    inserirAnimalMymapA(animal);
  }

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
}

void System::excluiFuncionario(int Id){
  this->mymapF.erase(Id);
}

//Menus

void System::MenuInicial(){
  int alternativa = -1;
  do{
      std::cout  << "\n\n"
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
        case 0 : // Salva em arquivo CSV e sai do menu.
          //Função a implementar
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
} // ok

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
} // ok

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
        case 0 : // Nenhuma ação. Somente sai do menu.
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
} // ok

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
} // ok

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
} // ok

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
