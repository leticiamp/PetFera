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
#include <iostream>
#include <sstream>


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
        std::cout << "Funcionario : " <<  it->first << " \n" << *it->second << "\n";
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

void System::Print_MyMapA_CSV(std::string nomeArquivo){
  ofstream file; // Cria arquivo.
	file.open(nomeArquivo);

  if(file.bad()){
    std::cerr << "Arquivo não foi aberto" << std::endl;
    exit(1);
  }

	for (std::map<int,Animal*>::iterator it = this->mymapA.begin();it!= this->mymapA.end(); ++it){
      file <<  *it->second;
  }

	file.close();

  std::cout <<"Arquivo modificado com sucesso" << std::endl;
}

void System::Print_MyMapF_CSV(std::string nomeArquivo){

  ofstream file; // Cria arquivo.
	file.open(nomeArquivo);

  if(file.bad()){
    std::cerr << "Arquivo não foi aberto" << std::endl;
    exit(1);
  }

	for (std::map<int,Funcionario*>::iterator it = this->mymapF.begin();
      it!= this->mymapF.end();
      ++it){
      file <<  *it->second;
  }
	file.close();

  std::cout <<"Arquivo modificado com sucesso" << std::endl;
}

/* Lê dados de funcionários de arquivo CSV - quase pronto. */
void System::Import_CSV_To_MyMapA(std::string nomeArquivo){
  /*
  ifstream file(nomeArquivo);
  if(file.bad()){
    std::cerr << "Arquivo não foi aberto." << std::endl;
    exit(1);
  }
  std::string id_, classe_, nome_cientifico_, sexo_;
  std::string tamanho_, dieta_, veterinario_, tratador_;
  std::string nome_batismo_, naturalidade_, p11, p12, p13, p14, p15;
  std::string line;
  while(std::getline(file, line)){
    std::istringstream ss(line);
    std::getline(ss, id_, ';');
    int id_ = const_cast<int>(id_);
    std::getline(ss, classe_, ';');
    std::getline(ss, nome_cientifico_, ';');
    std::getline(ss, sexo_, ';');
    std::getline(ss, tamanho_, ';');
    int tamanho_ = const_cast<int>(tamanho_);
    std::getline(ss, dieta_, ';');
    std::getline(ss, veterinario_, ';');
    std::getline(ss, tratador_, ';');
    std::getline(ss, nome_batismo_, ';');
    std::getline(ss, naturalidade_, ';');
    std::getline(ss, p11, ';');
    std::getline(ss, p12, ';');

  if( classe_ == "Ave" && naturalidade_ == "Exotico"){
    std::getline(ss, p13, ';');
    std::getline(ss, p14, ';');
    std::getline(ss, p15, '\n');
    int tamanho_do_bico_cm_ = const_cast<int>(p11);
    int envergadura_das_asas_ = const_cast<int>(p12);
    std::string pais_origem_ = p13;
    std::string cidade_origem_ = p14;
    std::string auto_ibama_ = p15;
    AveExo * animal = new AveExo(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  naturalidade_,
                                  tamanho_do_bico_cm_,
                                  envergadura_das_asas_,
                                  pais_origem_,
                                  cidade_origem_,
                                  auto_ibama_);
    inserirAnimalMyMapA(animal);
  }
  if(classe_ == "Mamifero" && naturalidade_ == "Exotico"){
    std::getline(ss, p13, ';');
    std::getline(ss, p14, '\n');
    std::string cor_pelo_ = p11;
    std::string pais_origem_ = p12;
    std::string cidade_origem_ = p13;
    std::string auto_ibama_ = p14;
    MamiferoExo * animal = new MamiferoExo(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  naturalidade_,
                                  cor_pelo_,
                                  pais_origem_,
                                  cidade_origem_,
                                  auto_ibama_);
    inserirAnimalMyMapA(animal);
  }
  if(classe_ == "Reptil" && naturalidade_ == "Exotico"){
    std::getline(ss, p13, ';');
    std::getline(ss, p14, ';');
    std::getline(ss, p15, '\n');
    bool venenoso_ = const_cast<bool>(p11);
    std::string tipo_veneno_ = p12;
    std::string pais_origem_ = p13;
    std::string cidade_origem_ = p14;
    std::string auto_ibama_ = p15;
    ReptilExo * animal = new ReptilExo(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  naturalidade_,
                                  venenoso_,
                                  tipo_veneno_,
                                  pais_origem_,
                                  cidade_origem_,
                                  auto_ibama_);
    inserirAnimalMyMapA(animal);
  }
  if(classe_ == "Anfibio" && naturalidade_ == "Exotico"){
    std::getline(ss, p13, ';');
    std::getline(ss, p14, '\n');
    int mudas_ = const_cast<int>(p11);
    std::string pais_origem_ = p12;
    std::string cidade_origem_ = p13;
    std::string auto_ibama_ = p14;
    AnfibioExo * animal = new AnfibioExo(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  naturalidade_,
                                  mudas_,
                                  pais_origem_,
                                  cidade_origem_,
                                  auto_ibama_);
    inserirAnimalMyMapA(animal);
  }
  if(classe_ == "Ave" && naturalidade_ == "Nativo"){
    std::getline(ss, p13, ';');
    std::getline(ss, p14, '\n');
    int tamanho_do_bico_cm_ = const_cast<int>(p11);
    int envergadura_das_asas_ = const_cast<int>(p12);
    std::string uf_origem_ = p13;
    std::string auto_ibama_ = p14;
    AveNat * animal = new AveNat  (id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  naturalidade_,
                                  tamanho_do_bico_cm_,
                                  envergadura_das_asas_,
                                  uf_origem_,
                                  auto_ibama_);
    inserirAnimalMyMapA(animal);
  }
  if(classe_ == "Mamifero" && naturalidade_ == "Nativo"){
    std::getline(ss, p13, '\n');
    std::string cor_pelo_ = p11;
    std::string uf_origem_ = p12;
    std::string auto_ibama_ = p13;
    MamiferoNat * animal = new MamiferoNat(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  naturalidade_,
                                  cor_pelo_,
                                  uf_origem_,
                                  auto_ibama_);
    inserirAnimalMyMapA(animal);
  }
  if(classe_ == "Reptil" && naturalidade_ == "Nativo"){
    std::getline(ss, p13, ';');
    std::getline(ss, p14, '\n');
    bool venenoso_ = const_cast<bool>(p11);
    std::string tipo_veneno_ = p12;
    std::string uf_origem_ = p13;
    std::string auto_ibama_ = p14;
    ReptilNat * animal = new ReptilNat(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  naturalidade_,
                                  venenoso_,
                                  tipo_veneno_,
                                  uf_origem_,
                                  auto_ibama_);
    inserirAnimalMyMapA(animal);
  }
  if(classe_ == "Anfibio" && naturalidade_ == "Nativo"){
    std::getline(ss, p13, '\n');
    int mudas_ = const_cast<int>(p11);
    std::string uf_origem_ = p12;
    std::string auto_ibama_ = p13;
    AnfibioNat * animal = new AnfibioNat(id_,
                                  classe_,
                                  nome_cientifico_,
                                  sexo_,
                                  tamanho_,
                                  dieta_,
                                  veterinario_,
                                  tratador_,
                                  nome_batismo_,
                                  naturalidade_,
                                  mudas_,
                                  uf_origem_,
                                  auto_ibama_);
    inserirAnimalMyMapA(animal);
  }

  }
  file.close();
  std::cout << "Pronto! Os animais acima foram salvos no banco de dados." << std::endl;
*/
}
/* Lê dados de funcionários de arquivo CSV - quase pronto. */
void System::Import_CSV_To_MyMapF(std::string nomeArquivo){

  ifstream file(nomeArquivo);
  if(file.bad()){
    std::cerr << "Arquivo não foi aberto." << std::endl;
    exit(1);
  }
  std::string line;
  std::string coluna;

  int id_;
  std::string funcao_;
  std::string nome_;
  std::string cpf_;
  short idade_;
  std::string tipo_sanguineo_;
  char fator_rh_;
  std::string especialidade_;

  while(std::getline(file, line)){
    std::istringstream ss(line);
    std::getline(ss, coluna, ';');
    id_ = std::stoi(coluna);
    std::getline(ss, funcao_, ';');
    std::getline(ss, nome_, ';');
    std::getline(ss, cpf_, ';');
    std::getline(ss, coluna, ';');
    idade_ = std::stoi(coluna);
    std::getline(ss, tipo_sanguineo_, ';');
    std::getline(ss, coluna, ';');
    fator_rh_ = coluna[0];
    std::getline(ss, especialidade_, ';');
    std::getline(ss, coluna, '\n');

    if(funcao_ == "Veterinario" ){
      Veterinario * funcionario = new Veterinario(  id_,
                                                    funcao_,
                                                    nome_,
                                                    cpf_,
                                                    idade_,
                                                    tipo_sanguineo_,
                                                    fator_rh_,
                                                    especialidade_,
                                                    coluna);
      inserirFuncionarioMyMapF(funcionario);
    }

    if(funcao_ == "Tratador"){
      int nivel_de_seguranca_ = std::stoi(coluna);
      Tratador * funcionario = new Tratador(  id_,
                                              funcao_,
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

  file.close();
}

//Metodos de instanciação de objetos

void System::Inserir_Func_MyMapF(){

  std::string funcao_;
  DefFuncaoFunc(funcao_);

  if(funcao_ == "Veterinario"){
    inserirFuncionarioMyMapF(NewVeterinario());
  }
  else if(funcao_ == "Tratador"){
    inserirFuncionarioMyMapF(NewTratador());
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

  if( classe_ == "Ave" && naturalidade_ == "Exotico"){
    inserirAnimalMyMapA(NewAveExo());
  }

  else if( classe_ == "Ave" && naturalidade_ == "Nativo"){
    inserirAnimalMyMapA(NewAveNat());
  }

  else if( classe_ == "Reptil" && naturalidade_ == "Exotico"){
    inserirAnimalMyMapA(NewReptilExo());
  }

  else if( classe_ == "Reptil" && naturalidade_ == "Nativo"){
    inserirAnimalMyMapA(NewReptilNat());
  }

  else if( classe_ == "Mamifero" && naturalidade_ == "Exotico"){
    inserirAnimalMyMapA(NewMamiferoExo());
  }

  else if( classe_ == "Mamifero" && naturalidade_ == "Nativo"){
    inserirAnimalMyMapA(NewMamiferoNat());
  }

  else if( classe_ == "Anfibio" && naturalidade_ == "Exotico"){
    inserirAnimalMyMapA(NewAnfibioExo());
  }

  else if( classe_ == "Anfibio" && naturalidade_ == "Nativo"){
    inserirAnimalMyMapA(NewAnfibioNat());
  }

  /*

  //Condição de parada sem funcionario cuidador
  if(veterinario_ == nullptr && tratador_ == nullptr){
    std::cout << "Erro: Não foram atrelados funcionarios para cuidar dos animais\n" << std::endl;
    delete veterinario_;
    delete tratador_;
    return;
  }

  */
}

Tratador * System::NewTratador(){
  Tratador * funcionario = new Tratador();
  setFuncId(funcionario);
  setFuncNome(funcionario);
  setFuncCpf(funcionario);
  setFuncIdade(funcionario);
  setFuncTipoSanguineo(funcionario);
  setFuncFatorRh(funcionario);
  setFuncEspecialidade(funcionario);
  setFuncNivDeSeguranca(funcionario);
  return funcionario;
}
Veterinario * System::NewVeterinario(){
  Veterinario * funcionario = new Veterinario();
  setFuncId(funcionario);
  setFuncNome(funcionario);
  setFuncCpf(funcionario);
  setFuncIdade(funcionario);
  setFuncTipoSanguineo(funcionario);
  setFuncFatorRh(funcionario);
  setFuncEspecialidade(funcionario);
  setFuncCrmv(funcionario);
  return funcionario;
}

AveExo * System::NewAveExo(){

  AveExo * animal = new AveExo();
  //Já é instanciado com a classe  = "Ave" e naturalidade = "Exotico"
  setAnimalId(animal);
  setAnimalNomeCientifico(animal);
  setAnimalSexo(animal);
  setAnimalTamanho(animal);
  setAnimalDieta(animal);
  setAnimalVeterinario(animal);
  setAnimalTratador(animal);
  setAnimalNomeBatismo(animal);
  setAnimalTamanhoDoBico(animal);
  setAnimalEnvergaduraAsas(animal);
  setAnimalPaisOrigem(animal);
  setAnimalCidadeOrigem(animal);
  setAnimalAutoIbama(animal);

  return animal;
}
AveNat * System::NewAveNat(){

  AveNat * animal = new AveNat();
  //Já é instanciado com a classe  = "Ave" e naturalidade = "Nativo"
  setAnimalId(animal);
  setAnimalNomeCientifico(animal);
  setAnimalSexo(animal);
  setAnimalTamanho(animal);
  setAnimalDieta(animal);
  setAnimalVeterinario(animal);
  setAnimalTratador(animal);
  setAnimalNomeBatismo(animal);
  setAnimalTamanhoDoBico(animal);
  setAnimalEnvergaduraAsas(animal);
  setAnimalUfOrigem(animal);
  setAnimalAutoIbama(animal);

  return animal;
}
ReptilExo * System::NewReptilExo(){

  ReptilExo * animal = new ReptilExo();
  //Já é instanciado com a classe  = "Reptil" e naturalidade = "Exotico"
  setAnimalId(animal);
  setAnimalNomeCientifico(animal);
  setAnimalSexo(animal);
  setAnimalTamanho(animal);
  setAnimalDieta(animal);
  setAnimalVeterinario(animal);
  setAnimalTratador(animal);
  setAnimalNomeBatismo(animal);
  setAnimalVenenoso(animal);
  setAnimalTipoVeneno(animal);
  setAnimalPaisOrigem(animal);
  setAnimalCidadeOrigem(animal);
  setAnimalAutoIbama(animal);

  return animal;
}
ReptilNat * System::NewReptilNat(){

  ReptilNat * animal = new ReptilNat();
  //Já é instanciado com a classe  = "Reptil" e naturalidade = "Nativo"
  setAnimalId(animal);
  setAnimalNomeCientifico(animal);
  setAnimalSexo(animal);
  setAnimalTamanho(animal);
  setAnimalDieta(animal);
  setAnimalVeterinario(animal);
  setAnimalTratador(animal);
  setAnimalNomeBatismo(animal);
  setAnimalVenenoso(animal);
  setAnimalTipoVeneno(animal);
  setAnimalUfOrigem(animal);
  setAnimalAutoIbama(animal);

  return animal;
}
MamiferoExo * System::NewMamiferoExo(){

  MamiferoExo * animal = new MamiferoExo();
  //Já é instanciado com a classe  = "Mamifero" e naturalidade = "Exotico"
  setAnimalId(animal);
  setAnimalNomeCientifico(animal);
  setAnimalSexo(animal);
  setAnimalTamanho(animal);
  setAnimalDieta(animal);
  setAnimalVeterinario(animal);
  setAnimalTratador(animal);
  setAnimalNomeBatismo(animal);
  setAnimalCorDoPelo(animal);
  setAnimalPaisOrigem(animal);
  setAnimalCidadeOrigem(animal);
  setAnimalAutoIbama(animal);

  return animal;
}
MamiferoNat * System::NewMamiferoNat(){

  MamiferoNat * animal = new MamiferoNat();
  //Já é instanciado com a classe  = "Mamifero" e naturalidade = "Nativo"
  setAnimalId(animal);
  setAnimalNomeCientifico(animal);
  setAnimalSexo(animal);
  setAnimalTamanho(animal);
  setAnimalDieta(animal);
  setAnimalVeterinario(animal);
  setAnimalTratador(animal);
  setAnimalNomeBatismo(animal);
  setAnimalCorDoPelo(animal);
  setAnimalUfOrigem(animal);
  setAnimalAutoIbama(animal);

  return animal;
}
AnfibioExo * System::NewAnfibioExo(){

  AnfibioExo * animal = new AnfibioExo();
  //Já é instanciado com a classe  = "Anfibio" e naturalidade = "Exotico"
  setAnimalId(animal);
  setAnimalNomeCientifico(animal);
  setAnimalSexo(animal);
  setAnimalTamanho(animal);
  setAnimalDieta(animal);
  setAnimalVeterinario(animal);
  setAnimalTratador(animal);
  setAnimalNomeBatismo(animal);
  setAnimalNumMudas(animal);
  setAnimalPaisOrigem(animal);
  setAnimalCidadeOrigem(animal);
  setAnimalAutoIbama(animal);

  return animal;
}
AnfibioNat * System::NewAnfibioNat(){

  AnfibioNat * animal = new AnfibioNat();
  //Já é instanciado com a classe  = "Anfibio" e naturalidade = "Nativo"
  setAnimalId(animal);
  setAnimalNomeCientifico(animal);
  setAnimalSexo(animal);
  setAnimalTamanho(animal);
  setAnimalDieta(animal);
  setAnimalVeterinario(animal);
  setAnimalTratador(animal);
  setAnimalNomeBatismo(animal);
  setAnimalNumMudas(animal);
  setAnimalUfOrigem(animal);
  setAnimalAutoIbama(animal);

  return animal;
}




//Metodos de remoção do MyMap
void System::RemoverAnimal(int &id_){
  delete this->mymapA.find(id_)->second;
  this->mymapA.erase(id_);
  std::cout << "Animal deletado" << std::endl;
}

void System::RemoverFuncionario(int &id_){
  //se não existir nenhum animal
  if(this->mymapA.size() == 0){
    delete this->mymapF.find(id_)->second;
    this->mymapF.erase(id_);
    std::cout << "Funcionario deletado" << std::endl;
    return;
  }

  //Se existir animais

    //verifica a funcao do funcionario
  std::string funcao_ = this->mymapF.find(id_)->second->getFuncao();

  if(funcao_ == "Veterinario")
  {
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it)
    {
      Veterinario * vet = it->second->getVeterinario();
      Tratador * trat = it->second->getTratador();
        if(vet!= nullptr){
          if(vet->getId() == id_ && trat == nullptr){
            std::cout << "Erro, existem animais que só possuem esse Veterinario\n"
            << "ação abortada\n";
            return;
          }
        }
    }

    //Deletando do local dos animais
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it)
    {
        Veterinario * vet = it->second->getVeterinario();
          if(vet!= nullptr){
            if(vet->getId() == id_){
             it->second->setVeterinario(nullptr);
            }
          }
    }

    //Deletando o funcionario
    delete this->mymapF.find(id_)->second;
    this->mymapF.erase(id_);

    std::cout << "Funcionario deletado" << std::endl;
    return;
  }

  if(funcao_ == "Tratador")
  {
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it)
    {
      Veterinario * vet = it->second->getVeterinario();
      Tratador * trat = it->second->getTratador();
        if(trat!= nullptr){
          if(trat->getId() == id_ && vet == nullptr){
            std::cout << "Erro, existem animais que só possuem esse Tratador\n"
            << "ação abortada\n";
            return;
          }
        }
    }

    //Deletando do local dos animais
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it)
    {
        Tratador * trat = it->second->getTratador();
          if(trat!= nullptr){
            if(trat->getId() == id_){
             it->second->setTratador(nullptr);
            }
          }
    }

    //Deletando o funcionario
    delete this->mymapF.find(id_)->second;
    this->mymapF.erase(id_);

    std::cout << "Funcionario deletado" << std::endl;
    return;
  }
}



//Metodos com os tratamentos utilizados p/ "set" atributos  de funcionaris

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


//Menus que controlam as opções do usuario
void System::MenuInicial(){
  Import_CSV_To_MyMapF("funcionarios.csv");
  Import_CSV_To_MyMapA("animais.csv");
  int alternativa = -1;
  do{
      PrintMenuPrincipal();
      std::cout << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          system("clear");
          MenuListar1(); // Menu Inicial >> Listar
          break;
        case 2 :
          system("clear");
          MenuInserir1(); // Menu Inicial >> Inserir
          break;
        case 3 :
          system("clear");
          MenuRemover1(); // Menu Inicial >> Remover
          break;
        case 4 :
          system("clear");
          MenuPesquisar1(); // Menu Inicial >> Pesquisar
          break;
        case 5 :
          system("clear");
          MenuEditar1(); // Menu Inicial >> Editar
          break;
        case 0 : // Salva em arquivo CSV e sai do menu.
          Print_MyMapA_CSV("animais.csv");
          Print_MyMapF_CSV("funcionarios.csv");
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
          system("clear");
          MenuListar1_1(); // Menu Inicial >> Listar >> Animais
          break;
        case 2 :
          system("clear");
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
  std::string nomeArquivo;
  do{
      PrintListar1_1();
      std::cout << " Alternativa escolhida: ";
      std::cin  >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          system("clear");
          Print_MyMapA_Tela(); // Menu Inicial >> Listar >> Animais >> Tela
          break;
        case 2 :
          system("clear");
          infoString(nomeArquivo, "Qual o nome do arquivo a ser salvo?");
          Print_MyMapA_CSV(nomeArquivo); // Menu Inicial >> Listar >> Animais >> Arquivo CSV
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
  std::string nomeArquivo;
  do{
      PrintListar1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();

      switch(alternativa){
        case 1 :
          system("clear");
          Print_MyMapF_Tela(); // Menu Inicial >> Listar >> Funcionários >> Tela
          break;
        case 2 :
          system("clear");
          infoString(nomeArquivo, "Qual o nome do arquivo a ser salvo?");
          Print_MyMapF_CSV(nomeArquivo); // Menu Inicial >> Listar >> Funcionários >> Arquivo CSV
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
            system("clear");
            MenuInserir1_1(); // Menu Inicial >> Inserir >> Animais
            break;
          case 2 :
            system("clear");
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
      PrintInserir1_1();
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
          system("clear");
          MenuRemover1_1(); // Menu Inicial >> Remover >> Animais
          break;
        case 2 :
          system("clear");
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
      system("clear");
      RemoverAnimal(alternativa);

  } while (alternativa != 0);
}

void System::MenuRemover1_2(){
  int alternativa = -1;
  do{
      PrintRemover1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      system("clear");
      RemoverFuncionario(alternativa);

  } while (alternativa != 0);
}

void System::MenuPesquisar1(){
  int alternativa = -1;
  do{
    PrintPesquisar1();
    std::cout  << " Alternativa escolhida: ";
    std::cin   >> alternativa;
    std::cin.ignore();

    switch(alternativa){
      case 1 :
      //      MenuPesquisar1_1(); // Pesquisar >> Animais
      break;
      case 2 :
      //      MenuPesquisar1_2(); // Pesquisar >> Funcionarios
      break;
      case 0 :
      break;
      default:
      system("clear");
      std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
    }
  } while (alternativa != 0);

}

void System::MenuPesquisar1_1(){
  int id;
  int alternativa = -1;
  do{
      PrintPesquisar1_1();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          system("clear");
          std::cout  << " Digite o Id ";
          std::cin   >> id;
          std::cin.ignore();
          if( this->mymapA.find(id) != this->mymapA.end()){
            std::cout << this->mymapA.find(id)->second;
          }else{
            std::cout << "Animal com esse identificador não existe";
          }
          break;
        case 0 :
          break;
        default:
          system("clear");
          std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
      }
    } while (alternativa != 0);
}

void System::MenuPesquisar1_2(){
  int id;
  int alternativa = -1;
  do{
      PrintPesquisar1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          system("clear");
          std::cout  << " Digite o Id ";
          std::cin   >> id;
          std::cin.ignore();
          if( this->mymapF.find(id) != this->mymapF.end()){
            std::cout << this->mymapF.find(id)->second;
          }else{
            std::cout << "Funcionario com esse identificador não existe";
          }
          break;
        case 0 :
          break;
        default:
          system("clear");
          std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
      }
    } while (alternativa != 0);
}

void System::MenuEditar1(){
  int alternativa = -1;
  do{
      PrintEditar1();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          //MenuEditar1_1(); // Edita >> Animais
          break;
        case 2 :
          //MenuEditar1_2(); // Editar >> Funcionarios
          break;
        case 0 :
          break;
        default:
          system("clear");
          std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
      }
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
             << " Digite '2' para: Listar todos os animais em um arquivo csv\n"
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
             << " Digite '2' para: Listar todos os funcionários em arquivo csv\n"
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

void System::PrintPesquisar1(){
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Pesquisar Dados do Banco \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Pesquisar Dados dos Animais\n"
                 << " Digite '2' para: Pesquisar Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl;
}

void System::PrintPesquisar1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Pesquisar dados dos animais \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Pesquisar por Id\n"
             //<< " Digite '2' para: \n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void System::PrintPesquisar1_2(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Pesquisar dados dos funcionario \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Pesquisar por Id\n"
             //<< " Digite '2' para: \n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void System::PrintEditar1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Editar Dados dos Banco \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Editar Dados dos Animais\n"
             << " Digite '2' para: Editar Dados dos Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void System::PrintEditar1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Editar Dados dos Animais \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Editar Dados dos Animais\n"
             << " Digite '2' para: Editar Dados dos Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}
