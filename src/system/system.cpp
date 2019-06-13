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

  if(this->mymapA.size() != 0){
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin();
    it!= this->mymapA.end();
    ++it){
      delete it->second;
    }
  }
}


//Metodos de listagem
void System::Print_MyMapA_Tela(){
  if(this->mymapA.size() == 0){
    std::cout << "Nenhum animal instanciado\n" << std::endl;
    return;
  }
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
    std::cout << "Animal : " <<  it->first << " \n" << *it->second << "\n\n";
  }
}
void System::Print_MyMapF_Tela(){
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
void System::Print_MyMapA_Func_Tela(int Id){
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin();
  it!= this->mymapA.end();
  ++it){
    if( it->second->getTratador()->getId() == Id){
      std::cout << "Animal " << *it->second;
    }

  }
}


//Falta implementar
void System::Print_MyMapA_CSV(std::string nomeArquivo){
  ofstream file; // Cria arquivo.
	file.open(nomeArquivo);

	for (std::map<int,Animal*>::iterator it = this->mymapA.begin();it!= this->mymapA.end(); ++it){
      file <<  *it->second;
  }
	file.close();
}

void System::Print_MyMapF_CSV(std::string nomeArquivo){

  ofstream file; // Cria arquivo.
	file.open(nomeArquivo);

	for (std::map<int,Funcionario*>::iterator it = this->mymapF.begin();it!= this->mymapF.end(); ++it){
      file <<  *it->second;
  }
	file.close();
}

//Metodos de constrole de inserção no MyMap
void System::Inserir_Func_MyMapF(){

  int id_;
  DefIdFunc(id_);
  system("clear");

  std::string funcao_;
  DefFuncaoFunc(funcao_);
  system("clear");

  std::string nome_;
  infoString(nome_,"Qual o nome do funcionario?");
  system("clear");

  std::string cpf_;
  infoString(cpf_,"Qual o cpf do funcionario");
  system("clear");

  short idade_;
  infoMaiorQZero(idade_, "Qual a idade do funcionario?");
  system("clear");

  std::string tipo_sanguineo_;
  DefTipoSangueFunc(tipo_sanguineo_);
  system("clear");

  char fator_rh_;
  DefFatorRhFunc(fator_rh_);
  system("clear");

  std::string especialidade_;
  infoString(especialidade_, "Qual a especialidade do funcionario?");
  system("clear");


  if(funcao_ == "Veterinario" ){
      std::string crmv_;
      infoString(crmv_, "Qual o crmv do funcionario?");
      system("clear");

      Veterinario * funcionario = new Veterinario(  id_,
                                                    nome_,
                                                    cpf_,
                                                    idade_,
                                                    tipo_sanguineo_,
                                                    fator_rh_,
                                                    especialidade_,
                                                    crmv_);
    inserirFuncionarioMyMapF(funcionario);
  }

  if(funcao_ == "Tratador"){
    int nivel_de_seguranca_;
    DefNivSecurityFunc(nivel_de_seguranca_);
    system("clear");

    Tratador * funcionario = new Tratador(  id_,
                                            nome_,
                                            cpf_,
                                            idade_,
                                            tipo_sanguineo_,
                                            fator_rh_,
                                            especialidade_,
                                            nivel_de_seguranca_);
    inserirFuncionarioMyMapF(funcionario);
  }
}
void System::Inserir_Animal_MyMapA(){
  //Condição de parada, se nao existir funcionarios
  if(mymapF.size() == 0){
    std::cout << " Não existem funcionarios para cuidar dos animais\n" << std::endl;
    return;
  }

  std::string classe_; // Classe do animal
  DefAnimalClasse(classe_); //Pergunta a classe do animal

  std::string naturalidade_;// naturalidade do animal (Exotico ou Nativo)
  DefAnimalNaturalidade(naturalidade_); // Perguntando a naturalidade do animal

  int id_; //Id do animal
  DefAnimalId(id_); // Perguntando a classe do animal

  std::string nome_cientifico_; //Nome Cientifico do animal
  DefAnimalNomeCientifico(nome_cientifico_); // Perguntando o nome Cienficio do animal

  char sexo_; // Sexo do animal
  DefAnimalSexo(sexo_); // Perguntando o sexo do animal

  double tamanho_; // Tamanho do animal
  //perguntando o tamanho do animal
  infoMaiorQZero(tamanho_, "Qual o tamanho do animal? (em centímentros)");

  std::string dieta_; //Dieta do animal
  infoString(dieta_, "Qual a dieta do animal?" ); // Perguntando a dieta do animal

  std::string nome_batismo_; // Nome do animal
  //Perguntando nome do animal
  infoString(nome_batismo_, "Qual o nome de batismo do animal?" );

  std::string auto_ibama_; // autorização do ibama do animal
  //perguntando autorização do ibama do animal
  infoString(auto_ibama_, "Qual a autorização do ibama do animal?");

  Veterinario * veterinario_ = nullptr;
  Tratador * tratador_ = nullptr;
  int aux;
  int aux1 = 1;

  do{
    std::cout << "Digite o id do Veterinario, caso o animal não tenha, digite 0 : \n";
    std::cin >> aux;
    std::cin.ignore();

    if(this->mymapF.find(aux) != this->mymapF.end() && aux != 0
      && this->mymapF.find(aux)->second->getFuncao() == "Veterinario")
    {
          veterinario_ = dynamic_cast<Veterinario*> (mymapF.find(aux)->second);
          aux1 = 0;
    }else if(aux == 0){
      aux1 = 0;
    }else{
      system("clear");
      std::cout << " Id invalido \n";
    }
  }while(aux1 != 0);

  aux1 = 1;
  do{
    std::cout << "Digite o id do Tratador, caso o animal não tenha, digite 0 : \n";
    std::cin >> aux;
    std::cin.ignore();

    if(this->mymapF.find(aux) != this->mymapF.end() && aux != 0
      && this->mymapF.find(aux)->second->getFuncao() == "Tratador")
    {
          tratador_ = dynamic_cast<Tratador*> (mymapF.find(aux)->second);
          aux1 = 0;
    }else if(aux == 0){
      aux1 = 0;
    }else{
      system("clear");
      std::cout << " Id invalido \n";
    }
  }while(aux1 != 0);


  //Condição de parada sem funcionario cuidador
    if(veterinario_ == nullptr && tratador_ == nullptr){
    std::cout << "Erro: Não foram atrelados funcionarios para cuidar dos animais\n" << std::endl;
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
    inserirAnimalMyMapA(animal);
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
    inserirAnimalMyMapA(animal);
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
    inserirAnimalMyMapA(animal);
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
    inserirAnimalMyMapA(animal);
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
    inserirAnimalMyMapA(animal);
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
    inserirAnimalMyMapA(animal);
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
    inserirAnimalMyMapA(animal);
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
    inserirAnimalMyMapA(animal);
  }
}


//Metodos de inserção no MyMapF
void System::inserirFuncionarioMyMapF(Tratador * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "\n Erro. Id já existe! " << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Tratador*>(funcionario->getId(),funcionario));
}
void System::inserirFuncionarioMyMapF(Veterinario * funcionario){
  if( mymapF.find(funcionario->getId()) != mymapF.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapF.insert(std::pair<int, Veterinario*>(funcionario->getId(),funcionario));
}


//Metodos de inserção no MyMapA
void System::inserirAnimalMyMapA(AveExo * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, AveExo*>(animal->getId(),animal));
}
void System::inserirAnimalMyMapA(AveNat * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, AveNat*>(animal->getId(),animal));
}
void System::inserirAnimalMyMapA(ReptilExo * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, ReptilExo*>(animal->getId(),animal));
}
void System::inserirAnimalMyMapA(ReptilNat * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, ReptilNat*>(animal->getId(),animal));
}
void System::inserirAnimalMyMapA(MamiferoExo * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, MamiferoExo*>(animal->getId(),animal));

}
void System::inserirAnimalMyMapA(MamiferoNat * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, MamiferoNat*>(animal->getId(),animal));

}
void System::inserirAnimalMyMapA(AnfibioExo * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, AnfibioExo*>(animal->getId(),animal));

}
void System::inserirAnimalMyMapA(AnfibioNat * animal){
  if( mymapA.find(animal->getId()) != mymapA.end()){
    std::cout << "\n Erro. Id já existe!" << std::endl;
    return;
  }
  this->mymapA.insert(std::pair<int, AnfibioNat*>(animal->getId(),animal));

}


//Metodos de remoção do MyMap
void System::RemoverAnimal(int &id_){
  this->mymapA.erase(id_);
}
void System::RemoverFuncionario(int &id_){
  this->mymapF.erase(id_);
}


//Metodos com os tratamentos utilizados p/ "set" atributos  de funcionaris
void System::DefIdFunc(int &id_){
  system("clear");
  std::cout << "Qual o número idenficador do Funcionario a ser inserido?" << std::endl;
  std::cin >> id_;
  std::cin.ignore();

  while(this->mymapF.find(id_) != mymapF.end() && id_ != 0){ // Testando se entrada existe
    system("clear");
    std::cout << "Entrada invalida, digite novamente\n";
    std::cout << "Qual o número idenficador do Funcionario a ser inserido? " << std::endl;
    std::cin >> id_; std::cin.ignore();
  }
}
void System::DefFuncaoFunc(std::string &funcao_){
  system("clear");
  std::cout << "Qual a funcao do Funcionario: (Veterinario) ou (Tratador)" << std::endl;
  std::cin >> funcao_;
  std::cin.ignore();

  while(funcao_ != "Veterinario" && funcao_ != "Tratador"){
    system("clear");
    std::cout << "Entrada invalida, digite novamente\n";
    std::cout << "Qual a funcao do Funcionario: (Veterinario) ou (Tratador)" << std::endl;
    std::cin >> funcao_;
    std::cin.ignore();
  }
}
void System::DefTipoSangueFunc(std::string &tipo_sanguineo_){
  system("clear");
  std::cout << "Qual o tipo_sanguineo do funcionario?" << std::endl;
  std::cin >> tipo_sanguineo_;
  std::cin.ignore();

  while(tipo_sanguineo_ != "A" &&
  tipo_sanguineo_ != "B" &&
  tipo_sanguineo_ != "O" &&
  tipo_sanguineo_ != "AB")
  {
    system("clear");
    std::cout << "Entrada invalida, digite novamente\n";
    std::cout << "Qual o tipo_sanguineo do funcionario?" << std::endl;
    std::cin >> tipo_sanguineo_; std::cin.ignore();
  }

}
void System::DefFatorRhFunc(char &fator_rh_){
  system("clear");
  std::cout << "Qual o fator rh do funcionario?" << std::endl;
  std::cin >> fator_rh_;
  std::cin.ignore();

  while(fator_rh_ != '-' &&
  fator_rh_ != '+')
  {
    system("clear");
    std::cout << "Entrada invalida, digite novamente\n";
    std::cout << "Qual o fator rh do funcionario?" << std::endl;
    std::cin >> fator_rh_; std::cin.ignore();
  }
}
void System::DefNivSecurityFunc(int &nivel_de_seguranca_){
  system("clear");
  std::cout << " Qual o nivel de segurança do funcionario" << std::endl;
  std::cin >> nivel_de_seguranca_;
  std::cin.ignore();

  while(nivel_de_seguranca_ != 0 &&
    nivel_de_seguranca_ != 1 &&
    nivel_de_seguranca_ != 2)
    {
      system("clear");
      std::cout << "Entrada invalida, digite novamente\n";
      std::cout << " Qual o nivel de segurança do funcionario" << std::endl;
      std::cin >> nivel_de_seguranca_;
      std::cin.ignore();
    }
  }


//Metodos com os tratamentos utilizados p/ "set" atributos  de animais
void System::DefAnimalId(int &id_){

  //Pergunta o ID do animal
  std::cout << " Qual o número idenficador do animal a ser inserido? " << std::endl;
  std::cin >> id_; std::cin.ignore();

  // Testando se Id existencia no mymapA
  while(this->mymapA.find(id_) != this->mymapA.end()){
    system("clear");
    std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
    << " Qual o número idenficador do animal a ser inserido?" << std::endl;
    std::cin  >> id_;
    std::cin.ignore();
  }
  system("clear");
}
void System::DefAnimalClasse(std::string &classe_){

  std::cout << "Qual a classe do animal Ave, Reptil, Mamifero ou Anfibio?"
  << std::endl;
  std::cin  >> classe_;
  std::cin.ignore();

  while(classe_ != "Ave" && classe_ != "Anfibio"  &&
  classe_ != "Mamifero" && classe_ != "Reptil")
  {
    system("clear");
    std::cout << "++++++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
    << "Qual a classe do animal Ave, Reptil, Mamifero ou Anfibio?"
    << std::endl;
    std::cin  >> classe_;
    std::cin.ignore();
  }
  system("clear");
}
void System::DefAnimalNaturalidade(std::string &naturalidade_){
  std::cout << "Qual a naturalidade do animal ? Exotico ou Nativo"
  << std::endl;
  std::cin  >> naturalidade_;
  std::cin.ignore();

  while(naturalidade_ != "Exotico" && naturalidade_ != "Nativo")
  {
    system("clear");
    std::cout << "++++++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
    << "Qual a naturalidade do animal ? Exotico ou Nativo"
    << std::endl;
    std::cin  >> naturalidade_;
    std::cin.ignore();
  }
  system("clear");
}
void System::DefAnimalNomeCientifico(string &nome_cientifico_){
  //Pergunta nome Cientifico
  std::cout << " Qual o nome científico do animal? " << std::endl;
  std::cin >> nome_cientifico_; std::cin.ignore();
  system("clear");
}
void System::DefAnimalSexo(char &sexo_){
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
    system("clear");
  }

//Metodo expecifico de tratamento na instanciação da classe Reptil
void System::boolReptilVenenoso(bool &venenoso_){
    //Pergunta se o animal é venenoso ou não
    int aux;
    std::cout << " O animal é venenoso ? Digite 1 para sim e 0 para não"
    << std::endl;
    std::cin  >> aux;
    std::cin.ignore();

    while(aux != 1 && aux != 0)
    {
      system("clear");
      std::cout << "++++++++++++ ENTRADA INVALIDA, TENTE NOVAMENTE ++++++++++++++++\n"
      << " O animal é venenoso ? Digite 1 para sim e 0 para não"
      << std::endl;
      std::cin >> aux;
      std::cin.ignore();
    }

    venenoso_ = aux;
    system("clear");
  }


//Metodos usados para instanciação de atributos sem restrição
//Pode ser implementado em template depois
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
void System::infoMaiorQZero(short &generico, std::string os){
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
  //Função generica que recebe dois parametros string
  // onde "os" esta com a pergunta a ser respondida no
  // genericos
  std::cout <<  os << std::endl;
  std::cin >> generico;
  std::cin.ignore();

  system("clear");
}

//Consulta -> pode dar erro
Tratador * System::consultaTratador(int Id){
  return (dynamic_cast<Tratador*>(mymapF.find(Id)->second));
}
Veterinario * System::consultaVeterinario(int Id){
  return (dynamic_cast<Veterinario*>(mymapF.find(Id)->second));
}






//Não Implementados

void System::listarAnimaisEmArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n "<< endl;
}
void System::listarAnimaisComFiltroNaTela(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}
void System::listarAnimaisComFiltroEmArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
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
void System::inserirAnimalViaArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}
void System::inserirFuncionarioViaArquivoCSV(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
}


//Menus que controlam as opções do usuario
void System::MenuInicial(){
  int alternativa = -1;
  do{
      PrintMenuPrincipal();
      std::cout << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          MenuListar1(); // Menu Inicial >> Listar
          break;
        case 2 :
          MenuInserir1(); // Menu Inicial >> Inserir
          break;
        case 3 :
          MenuRemover1(); // Menu Inicial >> Remover
          break;
        case 4 :
    //      MenuPesquisar1(); // Menu Inicial >> Pesquisar
          break;
        case 5 :
    //      MenuEditar1(); // Menu Inicial >> Editar
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
void System::MenuListar1(){
  int alternativa = -1;
  do{
      PrintListar1();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          MenuListar1_1(); // Menu Inicial >> Listar >> Animais
          break;
        case 2 :
          MenuListar1_2(); // Menu Inicial >> Listar >> Funcionários
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}
void System::MenuListar1_1(){
  int alternativa = -1;
  do{
      PrintListar1_1();
      std::cout << " Alternativa escolhida: ";
      std::cin  >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          Print_MyMapA_Tela(); // Menu Inicial >> Listar >> Animais >> Tela
          break;
        case 2 :
          //listarAnimaisEmArquivoCSV(); // Menu Inicial >> Listar >> Animais >> Arquivo CSV
          break;
        case 3 :
          //listarAnimaisComFiltroNaTela(); // Menu Inicial >> Listar >> Animais >> Tela & Filtro
          break;
        case 4 :
          //listarAnimaisComFiltroEmArquivoCSV(); // Menu Inicial >> Listar >> Animais >> Arquivo CSV & Filtro
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}
void System::MenuListar1_2(){
  int alternativa = -1;
  do{
      PrintListar1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          Print_MyMapF_Tela(); // Menu Inicial >> Listar >> Funcionários >> Tela
          break;
        case 2 :
        //  listarFuncionariosEmArquivoCSV(); // Menu Inicial >> Listar >> Funcionários >> Arquivo CSV
          break;
        case 3 :
    //      listarFuncionariosComFiltroNaTela(); // Menu Inicial >> Listar >> Funcionários >> Tela & Filtro
          break;
        case 4 :
  //        listarFuncionariosComFiltroEmArquivoCSV(); // Menu Inicial >> Listar >> Funcionários >> Arquivo CSV & Filtro
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}
void System::MenuInserir1(){

    int alternativa = -1;
    do{
        PrintInserir1();
        std::cout  << " Alternativa escolhida: ";
        std::cin   >> alternativa; std::cin.ignore();
        switch(alternativa){
          case 1 :
            MenuInserir1_1(); // Menu Inicial >> Inserir >> Animais
            break;
          case 2 :
            MenuInserir1_2(); // Menu Inicial >> Inserir >> Funcionários
            break;
          case 0: // Nenhuma ação. Somente sai do menu.
            break;
          default:
            system("clear");
            std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
        }
    } while (alternativa != 0);
}
void System::MenuInserir1_1(){
  int alternativa = -1;
  do{
      PrintInserir1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          Inserir_Animal_MyMapA(); // Menu Inicial >> Inserir >> Animais >> Digitando
          break;
        case 2 :
      //    inserirAnimalViaArquivoCSV(); // Menu Inicial >> Inserir >> Animais >> Arquivo CSV
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
    } while (alternativa != 0);
}
void System::MenuInserir1_2(){
  int alternativa = -1;
  do{
      PrintInserir1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 :
          Inserir_Func_MyMapF(); // Menu Inicial >> Inserir >> Funcionário >> Digitando
          break;
        case 2 :
        //  inserirFuncionarioViaArquivoCSV(); // Menu Inicial >> Listar >> Funcionário >> Arquivo CSV
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}
void System::MenuRemover1(){
  int alternativa = -1;
  do{
      PrintRemover1();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      switch(alternativa){
        case 1 :
          MenuRemover1_1(); // Menu Inicial >> Remover >> Animais
          break;
        case 2 :
          MenuRemover1_2(); // Menu Inicial >> Remover >> Funcionários
          break;
        case 0 : // Nenhuma ação. Somente sai do menu.
          break;
        default:
          system("clear");
          std::cout << " \n\n Alternativa inválida! Tente outra vez.\n\n" << std::endl;
      }
  } while (alternativa != 0);
}
void System::MenuRemover1_1(){
  int alternativa = -1;
  do{
      PrintRemover1_1();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      RemoverAnimal(alternativa);

      system("clear");
      std::cout << "Caso deseje excluir outro animal -> digite\" 1\""
                << "Caso deseje voltar ao menu anterior digite \"0\"" << std::endl;
      std::cin   >> alternativa; std::cin.ignore();

  } while (alternativa != 0);
}
void System::MenuRemover1_2(){
  int alternativa = -1;
  do{
      PrintRemover1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      RemoverFuncionario(alternativa);

      system("clear");

      std::cout << "Caso deseje excluir outro funcionario -> digite\" 1\""
                << "Caso deseje voltar ao menu anterior digite \"0\"" << std::endl;
      std::cin   >> alternativa; std::cin.ignore();

  } while (alternativa != 0);
}

//Cout's das opções dos menus
void System::PrintMenuPrincipal(){
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
             << std::endl;
}
void System::PrintListar1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Listar Dados no Banco \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Listar Dados dos Animais\n"
             << " Digite '2' para: Listar Dados dos Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}
void System::PrintListar1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Listar Dados de Animais \n"
             << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Listar todos os animais na tela\n"
      //       << " Digite '2' para: Listar todos os animais em um arquivo csv\n"
      //       << " Digite '3' para: Listar animais na tela por Filtro\n"
      //       << " Digite '4' para: Listar animais em um arquivo csv por Filtro\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}
void System::PrintListar1_2(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Listar Dados de Funcionários \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Listar todos os funcionários na tela\n"
  //           << " Digite '2' para: Listar todos os funcionários em arquivo csv\n"
  //           << " Digite '3' para: Listar todos os funcionários na tela com Filtro\n"
  //           << " Digite '4' para: Listar todos os funcionários em arquivo csv com Filtro\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void System::PrintInserir1(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Inserir Dados no Banco \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Inserir Dados de Animais\n"
             << " Digite '2' para: Inserir Dados de Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}
void System::PrintInserir1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Inserir Dados de Animal \n"
             << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Inserir Dados de Animal Item a Item (Digitando)\n"
          //   << " Digite '2' para: Inserir um Arquivo CSV de animais\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}
void System::PrintInserir1_2(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Inserir Dados de Funcionário \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Inserir Dados de Funcionário Item a Item (Digitando)\n"
             << " Digite '2' para: Inserir Dados de Funcionário Via Arquivo CSV\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void System::PrintRemover1(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Remover Dados no Banco \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Remover um Animais\n"
             << " Digite '2' para: Remover um Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}
void System::PrintRemover1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Remover um Animal \n"
             << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite o ID do animal"
             << " ou digite '0' para voltar ao menu anterior \n"
             << std::endl;
}
void System::PrintRemover1_2(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Remover Dados de Funcionário \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite o ID do funcionário"
             << " ou digite '0' para voltar ao menu anterior \n"
             << std::endl;
}

/*

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
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Editar Dados do Banco \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Editar Dados dos Animais\n"
                 << " Digite '2' para: Editar Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          printMenuEditar1_1(); // Edita >> Animais
          break;
        case 2 :
          printMenuEditar1_2(); // Editar >> Funcionarios
          break;
        case 0 :
          break;
        default:
          system("clear");
          std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
      }
    } while (alternativa != 0);

}

void System::printMenuEditar1_1(){
  std::cout << " \n FALTA IMPLEMENTAR!\n " << endl;
  /*
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Editar Dados dos Animais \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Editar Dados dos Animais\n"
                 << " Digite '2' para: Editar Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          printMenuEditar1_1(); // Edita >> Animais
          break;
        case 2 :
          printMenuEditar1_2(); // Editar >> Funcionarios
          break;
        case 0 :
          break;
        default:
          system("clear");
          std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
      }
    } while (alternativa != 0);
*/
//}
/*
void System::printMenuEditar1_2(){
  int alternativa = -1;
  do{
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Editar Dados dos Funcionario \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Editar Dados dos Animais\n"
                 << " Digite '2' para: Editar Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl
                 << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          printMenuEditar1_1(); // Edita >> Animais
          break;
        case 2 :
          printMenuEditar1_2(); // Editar >> Funcionarios
          break;
        case 0 :
          break;
        default:
          system("clear");
          std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
      }
    } while (alternativa != 0);
}
*/
