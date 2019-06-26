/**
* @file system.cpp
* @brief Sistema central que controla as principais ações do SuperFera.
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santosos
* @since 25/04/2019
* @date 23/06/2019
*/

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "system.h"
#include "arquivoNaoAberto.h"

/** @brief Métodos construtor e destrutor da classe system.h. */
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

/** @brief Métodos de saída ou impressão. */
void
System::Print_MyMapA_Tela(){
  if(this->mymapA.size() == 0){
    std::cout << "Não há animais no banco de dados. \n" << std::endl;
    return;
  }
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
    std::cout << "Animal : " <<  it->first << " \n" << *it->second << "\n\n";
  }
}

void
System::Print_MyMapF_Tela(){
  if(this->mymapF.size() == 0){
    std::cout << "Não há funcionários no banco de dados. \n" << std::endl;
    return;
  }

  for (std::map<int,Funcionario*>::iterator it = this->mymapF.begin();
        it!= this->mymapF.end();
        ++it){
        std::cout << "Funcionário : " <<  it->first << " \n" << *it->second << "\n";
    }
}

void
System::Print_MyMapA_Func_Tela(int Id){
  for (std::map<int,Animal*>::iterator it = this->mymapA.begin();
  it!= this->mymapA.end();
  ++it){
    if( it->second->getTratador()->getId() == Id){
      std::cout << "Animal " << *it->second;
    }

  }
}

void
System::Print_MyMapA_CSV(std::string nomeArquivo){
  ofstream file; // Cria arquivo.
	file.open(nomeArquivo);
  /** @brief Trata a exceção, caso o arquivo não abra. */
  try{
    if(file.bad()) throw ArquivoNaoAberto();
  }
  catch (ArquivoNaoAberto &err){
      std::cerr << err.what() << std::endl;
      file.close();
      return;
  }
  catch (...) {
      std::cerr << "Erro desconhecido ao tentar abrir o arquivo." << std::endl;
  }

  for (std::map<int,Animal*>::iterator it = this->mymapA.begin();
       it!= this->mymapA.end(); ++it){
    file <<  *it->second;
  }

	file.close();

  std::cout << "Arquivo modificado com sucesso" << std::endl;
}

void
System::Print_MyMapF_CSV(std::string nomeArquivo){

  ofstream file; // Cria arquivo.
	file.open(nomeArquivo);

  /** @brief Trata a exceção, caso o arquivo não abra. */
  try{
    if(file.bad()) throw ArquivoNaoAberto();
  }
  catch (ArquivoNaoAberto &err){
      std::cerr << err.what() << std::endl;
      file.close();
      return;
  }
  catch (...) {
      std::cerr << "Erro desconhecido ao tentar abrir o arquivo." << std::endl;
  }

  for (std::map<int,Funcionario*>::iterator it = this->mymapF.begin();
  it!= this->mymapF.end();++it){
  file << *it->second;
  }

	file.close();

  std::cout <<"Arquivo modificado com sucesso." << std::endl;
}

/** @brief Importa dados de animais de arquivo CSV para o banco. */
void
System::Import_CSV_To_MyMapA(std::string nomeArquivo){

  ifstream file(nomeArquivo);
  /** @brief Trata a exceção, caso o arquivo não abra. */
  try{
    if(file.bad()) throw ArquivoNaoAberto();
  }
  catch (ArquivoNaoAberto &err){
      std::cerr << err.what() << std::endl;
  }
  catch (...) {
      std::cerr << "Erro desconhecido ao tentar abrir o arquivo." << std::endl;
  }

  std::string line;
  std::string coluna;

  int id_;
  std::string classe_;
  std::string nome_cientifico_;
  char sexo_;
  double tamanho_;
  std::string dieta_;
  Veterinario * veterinario_ = nullptr;
  Tratador * tratador_ = nullptr;
  std::string nome_batismo_;
  std::string naturalidade_;

  while(std::getline(file, line)){
        std::istringstream ss(line);
        std::getline(ss, coluna, ';');
        id_ = std::stoi(coluna);
        std::getline(ss, classe_, ';');
        std::getline(ss, nome_cientifico_, ';');
        std::getline(ss, coluna, ';');
        sexo_ = coluna[0];
        std::getline(ss, coluna, ';');
        tamanho_ = std::stod(coluna);
        std::getline(ss, dieta_, ';');
        std::getline(ss, coluna, ';');

        //Veterinario
        int aux = std::stoi(coluna);
        if(aux == 0){
          veterinario_ = nullptr;
        }else{
          auto it = this->mymapF.find(aux);
          if( it != this->mymapF.end()){
            if(it->second->getFuncao() != "Veterinario"){
              veterinario_ = nullptr;
              std::cout << "Tentativa de inserção de Id funcionario em posição errada" << std::endl;
            }else{
              veterinario_ = dynamic_cast<Veterinario*> (it->second);
            }
          }else{
            std::cout << "Veterinario não existe" << std::endl;
            veterinario_ = nullptr;
          }
        }

        //Tratador
        std::getline(ss, coluna, ';');
        aux = std::stoi(coluna);
        if(aux == 0){
          tratador_ = nullptr;
        }else{
          auto it = this->mymapF.find(aux);
          if( it != this->mymapF.end()){
            if(it->second->getFuncao() != "Tratador"){
              tratador_ = nullptr;
              std::cerr << "Tentativa de inserção de Id funcionario em posição errada" << std::endl;
            }else{
              tratador_ = dynamic_cast<Tratador*> (it->second);;
            }
          }else{
            std::cout << "Tratador não existe" << std::endl;
            tratador_ = nullptr;
          }
        }

        std::getline(ss, nome_batismo_, ';');
        std::getline(ss, naturalidade_, ';');

        if( classe_ == "Ave" && naturalidade_ == "Exotico"){
          std::getline(ss, coluna, ';');
          double tamanho_do_bico_cm_ = std::stod(coluna);
          std::getline(ss, coluna, ';');
          double envergadura_das_asas_ = std::stod(coluna);

          std::string pais_origem_;
          std::string cidade_origem_;
          std::string auto_ibama_;

          std::getline(ss, pais_origem_, ';');
          std::getline(ss, cidade_origem_, ';');
          std::getline(ss, auto_ibama_, ';');
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
          std::string cor_pelo_;
          std::getline(ss, cor_pelo_, ';');

          std::string pais_origem_;
          std::getline(ss, pais_origem_, ';');

          std::string cidade_origem_;
          std::getline(ss, cidade_origem_, ';');

          std::string auto_ibama_;
          std::getline(ss, auto_ibama_, ';');

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
          std::getline(ss, coluna, ';');
          bool venenoso_ = std::stoi(coluna);

          std::string tipo_veneno_;
          std::getline(ss,tipo_veneno_,';');

          std::string pais_origem_;
          std::getline(ss, pais_origem_, ';');

          std::string cidade_origem_;
          std::getline(ss, cidade_origem_, ';');

          std::string auto_ibama_;
          std::getline(ss, auto_ibama_, ';');

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
          std::getline(ss, coluna, ';');
          int mudas_ = std::stoi(coluna);
          std::string pais_origem_;
          std::getline(ss, pais_origem_, ';');
          std::string cidade_origem_;
          std::getline(ss, cidade_origem_, ';');
          std::string auto_ibama_;
          std::getline(ss, auto_ibama_,';');

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
          std::getline(ss, coluna, ';');
          double tamanho_do_bico_cm_ = std::stod(coluna);
          std::getline(ss, coluna, ';');
          double envergadura_das_asas_ = std::stod(coluna);

          std::string uf_origem_;
          std::getline(ss, uf_origem_, ';');
          std::string auto_ibama_;
          std::getline(ss, auto_ibama_,';');

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
          std::string cor_pelo_;
          std::getline(ss, cor_pelo_, ';');

          std::string uf_origem_;
          std::getline(ss, uf_origem_, ';');
          std::string auto_ibama_;
          std::getline(ss, auto_ibama_,';');

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
          std::getline(ss, coluna, ';');
          bool venenoso_ = std::stoi(coluna);

          std::string tipo_veneno_;
          std::getline(ss,tipo_veneno_,';');

          std::string uf_origem_;
          std::getline(ss, uf_origem_, ';');
          std::string auto_ibama_;
          std::getline(ss, auto_ibama_,';');

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
          std::getline(ss, coluna, ';');
          int mudas_ = std::stoi(coluna);

          std::string uf_origem_;
          std::getline(ss, uf_origem_, ';');
          std::string auto_ibama_;
          std::getline(ss, auto_ibama_,';');

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
  std::cout << "Pronto! Os animais do arquivo foram salvos no banco de dados." << std::endl;

}

/** @brief Importa dados de funcionários de arquivo CSV para o banco.  */
void
System::Import_CSV_To_MyMapF(std::string nomeArquivo){

  ifstream file(nomeArquivo);
  /** @brief Trata a exceção, caso o arquivo não abra. */
  try{
    if(file.bad()) throw ArquivoNaoAberto();
  }
  catch (ArquivoNaoAberto &err){
      std::cerr << err.what() << std::endl;
      file.close();
      return;
  }
  catch (...) {
      std::cerr << "Erro desconhecido ao tentar abrir o arquivo." << std::endl;
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
  std::cout << "Pronto! Os funcionários do arquivo foram salvos no banco de dados." << std::endl;
}

/** Métodos de instanciação de objetos das Classes Animal e Funcionario. */
void
System::Inserir_Func_MyMapF(){

  std::string funcao_;
  DefFuncaoFunc(funcao_);

  if(funcao_ == "Veterinario"){
    inserirFuncionarioMyMapF(NewVeterinario());
  }
  else if(funcao_ == "Tratador"){
    inserirFuncionarioMyMapF(NewTratador());
  }
}

void
System::Inserir_Animal_MyMapA(){
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

Tratador *
System::NewTratador(){
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

Veterinario *
System::NewVeterinario(){
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

AveExo *
System::NewAveExo(){
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
AveNat *
System::NewAveNat(){
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
ReptilExo *
System::NewReptilExo(){
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
ReptilNat *
System::NewReptilNat(){
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
MamiferoExo *
System::NewMamiferoExo(){
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
MamiferoNat *
System::NewMamiferoNat(){
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
AnfibioExo *
System::NewAnfibioExo(){
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
AnfibioNat *
System::NewAnfibioNat(){
  AnfibioNat * animal = new AnfibioNat();
  /** @brief Já é instanciado com a classe  = "Anfibio" e naturalidade = "Nativo" */
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

/** @brief Métodos de remoção do MyMap.*/
void
System::RemoverAnimal(int &id_){
  delete this->mymapA.find(id_)->second;
  this->mymapA.erase(id_);
  std::cout << "Animal removido com sucesso." << std::endl;
}

void
System::RemoverFuncionario(int &id_){
  /**@brief Caso não exista animal instanciado. */
  if(this->mymapA.size() == 0){
    delete this->mymapF.find(id_)->second;
    this->mymapF.erase(id_);
    std::cout << "Funcionário removido com sucesso." << std::endl;
    return;
  }

  /**@brief Caso exista animal instanciado. */

  /**@brief Verifica a função do funcionário. */
  std::string funcao_ = this->mymapF.find(id_)->second->getFuncao();

  if(funcao_ == "Veterinario"){
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
      Veterinario * vet = it->second->getVeterinario();
      Tratador * trat = it->second->getTratador();
      if(vet!= nullptr){
        if(vet->getId() == id_ && trat == nullptr){
          std::cout << "Erro: existem animais que só possuem esse Veterinário.\n"
                    << "Ação abortada. \n";
          return;
        }
      }
    }
    /** @brief Removendo o local dos animais. */
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
      Veterinario * vet = it->second->getVeterinario();
      if(vet!= nullptr){
        if(vet->getId() == id_){
          it->second->setVeterinario(nullptr);
        }
      }
    }
    /** @brief Removendo o funcionário. */
    delete this->mymapF.find(id_)->second;
    this->mymapF.erase(id_);

    std::cout << "Funcionário removido." << std::endl;
    return;
  }

  if(funcao_ == "Tratador"){
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
      Veterinario * vet = it->second->getVeterinario();
      Tratador * trat = it->second->getTratador();
      if(trat!= nullptr){
        if(trat->getId() == id_ && vet == nullptr){
          std::cout << "Erro: existem animais que só possuem esse Tratador.\n"
                    << "Ação abortada. \n";
          return;
        }
      }
    }

    /** @brief Removendo o local dos animais. */
    for (std::map<int,Animal*>::iterator it = this->mymapA.begin(); it!= this->mymapA.end(); ++it){
      Tratador * trat = it->second->getTratador();
      if(trat!= nullptr){
        if(trat->getId() == id_){
          it->second->setTratador(nullptr);
        }
      }
    }

    /** @brief Removendo o funcionário. */
    delete this->mymapF.find(id_)->second;
    this->mymapF.erase(id_);

    std::cout << "Funcionário removido." << std::endl;
    return;
  }
}

/** @brief Métodos com tratamentos para os atributos da Classe Funcionário.*/
void
System::DefFuncaoFunc(std::string &funcao_){
  system("clear");
  std::cout << "Qual a função do funcionário? Opções: Veterinario ou Tratador." << std::endl;
  std::cin >> funcao_;
  std::cin.ignore();

  while(funcao_ != "Veterinario" && funcao_ != "Tratador"){
    system("clear");
    std::cout << "Entrada inválida. Digite novamente.\n";
    std::cout << "Qual a função do funcionário? Opções: Veterinario ou Tratador." << std::endl;
    std::cin >> funcao_;
    std::cin.ignore();
  }
}

void
System::DefAnimalClasse(std::string &classe_){

  std::cout << "Qual a classe do animal? Opções: Ave, Reptil, Mamifero ou Anfibio." << std::endl;
  std::cin  >> classe_;
  std::cin.ignore();

  while(classe_ != "Ave" && classe_ != "Anfibio"  &&
  classe_ != "Mamifero" && classe_ != "Reptil")
  {
    system("clear");
    std::cout << "++++++++++++++++ ENTRADA INVÁLIDA. TENTE NOVAMENTE. ++++++++++++++++\n"
    << "Qual a classe do animal? Opções: Ave, Reptil, Mamífero ou Anfibio." << std::endl;
    std::cin  >> classe_;
    std::cin.ignore();
  }
  system("clear");
}

void
System::DefAnimalNaturalidade(std::string &naturalidade_){
  std::cout << "Qual a naturalidade do animal? Opções: Exotico ou Nativo." << std::endl;
  std::cin  >> naturalidade_;
  std::cin.ignore();

  while(naturalidade_ != "Exotico" && naturalidade_ != "Nativo")
  {
    system("clear");
    std::cout << "++++++++++++++++ ENTRADA INVÁLIDA. TENTE NOVAMENTE ++++++++++++++++\n"
    << "Qual a naturalidade do animal? Opções: Exotico ou Nativo." << std::endl;
    std::cin  >> naturalidade_;
    std::cin.ignore();
  }
  system("clear");
}

/** @details Função genérica que recebe dois parâmetros do tipo string,
 * onde "os" está com a com a pergunta a ser respondida no "genérico".
*/
void
System::infoString(std::string &generico, std::string os){
  std::cout <<  os << std::endl;
  std::cin >> generico;
  std::cin.ignore();

  system("clear");
}

/** @brief Consulta ou pesquisa o determinado funcionário. */
Tratador *
System::consultaTratador(int Id){
  return (dynamic_cast<Tratador*>(mymapF.find(Id)->second));
}

Veterinario *
System::consultaVeterinario(int Id){
  return (dynamic_cast<Veterinario*>(mymapF.find(Id)->second));
}

/** @brief Menus que controlam as ações definidas pelo usuário.*/
void
System::MenuInicial(){
  Import_CSV_To_MyMapF("funcionarios.csv");
  Import_CSV_To_MyMapA("animais.csv");
  int alternativa = -1;
  do{
      PrintMenuPrincipal();
      std::cout << " Alternativa escolhida: ";
      std::cin >> alternativa;
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

void
System::MenuListar1(){
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

void
System::MenuListar1_1(){
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

void
System::MenuListar1_2(){
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

void
System::MenuInserir1(){

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

void
System::MenuInserir1_1(){
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

void
System::MenuInserir1_2(){
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

void
System::MenuRemover1(){
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

void
System::MenuRemover1_1(){
  int alternativa = -1;
  do{
      PrintRemover1_1();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      system("clear");
      RemoverAnimal(alternativa);

  } while (alternativa != 0);
}

void
System::MenuRemover1_2(){
  int alternativa = -1;
  do{
      PrintRemover1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa; std::cin.ignore();
      system("clear");
      RemoverFuncionario(alternativa);

  } while (alternativa != 0);
}

void
System::MenuPesquisar1(){
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

void
System::MenuPesquisar1_1(){
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

void
System::MenuPesquisar1_2(){
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

void
System::MenuEditar1(){
  int alternativa = -1;
  do{
      PrintEditar1();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      switch(alternativa){
        case 1 :
          MenuEditar1_1(); // Editar >> Animais
          break;
        case 2 :
          MenuEditar1_2(); // Editar >> Funcionarios
          break;
        case 0 :
          break;
        default:
          system("clear");
          std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
      }
    } while (alternativa != 0);
}

void
System::MenuEditar1_1(){
  int id_;
  int alternativa;
  do{
      PrintEditar1_1();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      if(alternativa != 0){
        std::cout  << "Digite o Id do animal :";
        std::cin   >> id_;
        std::cin.ignore();

        if(mymapA.count(id_) == 1){
          switch(alternativa){
            case 1 :
              setAnimalNomeCientifico(mymapA.find(id_)->second); // Editar >> Animais
              break;
            case 2 :
              setAnimalSexo(mymapA.find(id_)->second);
              break;
            case 3 :
              setAnimalTamanho(mymapA.find(id_)->second);
              break;
            case 4:
              setAnimalDieta(mymapA.find(id_)->second);
              break;
            case 5:
              setAnimalVeterinario(mymapA.find(id_)->second);
              break;
            case 6:
              setAnimalTratador(mymapA.find(id_)->second);
              break;
            case 7:
              setAnimalNomeBatismo(mymapA.find(id_)->second);
              break;
            case 8:
              if(FlagNumMudas(mymapA.find(id_)->second) == true){
                setAnimalNumMudas(dynamic_cast<Anfibio*>(mymapA.find(id_)->second));
              }
              break;
            case 9:
              if(FlagCorDoPelo(mymapA.find(id_)->second) == true){
                setAnimalCorDoPelo(dynamic_cast<Mamifero*>(mymapA.find(id_)->second));
              }
              break;
            case 10:
              if(FlagVenenoso(mymapA.find(id_)->second) == true){
                setAnimalVenenoso(dynamic_cast<Reptil*>(mymapA.find(id_)->second));
              }
              break;
            case 11 :
              if(FlagTipoVeneno(mymapA.find(id_)->second) == true){
                setAnimalTipoVeneno(dynamic_cast<Reptil*>(mymapA.find(id_)->second));
              }
              break;
            case 12 :
              if(FlagEnvergaduraAsas(mymapA.find(id_)->second) == true){
                setAnimalEnvergaduraAsas(dynamic_cast<Ave*>(mymapA.find(id_)->second));
              }
              break;
            case 13 :
              if(FlagTamanhoDoBico(mymapA.find(id_)->second) == true){
                setAnimalTamanhoDoBico(dynamic_cast<Ave*>(mymapA.find(id_)->second));
              }
              break;
            case 14:
              if(FlagUfOrigem(mymapA.find(id_)->second) == true){
                setAnimalUfOrigem(dynamic_cast<AnimalNat*>(mymapA.find(id_)->second));
              }
              break;
            case 15:
              if(FlagPaisOrigem(mymapA.find(id_)->second) == true){
                setAnimalPaisOrigem(dynamic_cast<AnimalExo*>(mymapA.find(id_)->second));
              }
              break;
            case 16:
              if(FlagCidadeOrigem(mymapA.find(id_)->second) == true){
                setAnimalCidadeOrigem(dynamic_cast<AnimalExo*>(mymapA.find(id_)->second));
              }
              break;
            case 17:
              if(FlagAutoIbama(mymapA.find(id_)->second) == true){
                setAnimalAutoIbama(dynamic_cast<AnimalSilv*>(mymapA.find(id_)->second));
              }
              break;
            case 0 :
              break;
            default:
            system("clear");
            std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
          }
        }else{
          std::cout << "\n\nId invalido! Animal não existe.\n\n";
        }

      }
    } while (alternativa != 0);
}

void
System::MenuEditar1_2(){
  int id_;
  int alternativa;
  do{
      PrintEditar1_2();
      std::cout  << " Alternativa escolhida: ";
      std::cin   >> alternativa;
      std::cin.ignore();

      if(alternativa != 0){
        std::cout  << "Digite o Id do animal :";
        std::cin   >> id_;
        std::cin.ignore();

        if(mymapA.count(id_) == 1){
          switch(alternativa){
            case 1 :
              setFuncNome(mymapF.find(id_)->second); // Editar >> Animais
              break;
            case 2 :
              setFuncCpf(mymapF.find(id_)->second);
              break;
            case 3 :
              setFuncIdade(mymapF.find(id_)->second);
              break;
            case 4:
              setFuncTipoSanguineo(mymapF.find(id_)->second);
              break;
            case 5:
              setFuncFatorRh(mymapF.find(id_)->second);
              break;
            case 6:
              setFuncEspecialidade(mymapF.find(id_)->second);
              break;
            case 7:
              if(FlagCrmv(mymapF.find(id_)->second) == true){
                setFuncCrmv(dynamic_cast<Veterinario*>(mymapF.find(id_)->second));
              }
              break;
            case 8:
              if(FlagNivDeSeguranca(mymapF.find(id_)->second) == true){
                setFuncNivDeSeguranca(dynamic_cast<Tratador*>(mymapF.find(id_)->second));
              }
              break;
            case 0 :
              break;
            default:
            system("clear");
            std::cout << "\n\nAlternativa inválida! Tente outra vez.\n\n";
          }
        }else{
          std::cout << "\n\nId invalido! Animal não existe.\n\n";
        }

      }
    } while (alternativa != 0);
}

/** @brief Caixas de diálogos (cout's) apresentadas ao usuário. */
void
System::PrintMenuPrincipal(){
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

void
System::PrintListar1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Listar Dados no Banco \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Listar Dados dos Animais\n"
             << " Digite '2' para: Listar Dados dos Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintListar1_1(){
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

void
System::PrintListar1_2(){
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

void
System::PrintInserir1(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Inserir Dados no Banco \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Inserir Dados de Animais\n"
             << " Digite '2' para: Inserir Dados de Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintInserir1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Inserir Dados de Animal \n"
             << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Inserir Dados de Animal Item a Item (Digitando)\n"
          //   << " Digite '2' para: Inserir um Arquivo CSV de animais\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintInserir1_2(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Inserir Dados de Funcionário \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Inserir Dados de Funcionário Item a Item (Digitando)\n"
             << " Digite '2' para: Inserir Dados de Funcionário Via Arquivo CSV\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintRemover1(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Remover Dados no Banco \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Remover um Animais\n"
             << " Digite '2' para: Remover um Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintRemover1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Remover um Animal \n"
             << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite o ID do animal"
             << " ou digite '0' para voltar ao menu anterior \n"
             << std::endl;
}

void
System::PrintRemover1_2(){
  std::cout  << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Remover Dados de Funcionário \n"
             << " \n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite o ID do funcionário"
             << " ou digite '0' para voltar ao menu anterior \n"
             << std::endl;
}

void
System::PrintPesquisar1(){
      std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
                 << " \n Você escolheu a alternativa: Pesquisar Dados do Banco \n"
                 << " \n Escolha uma das seguintes alternativas abaixo: \n"
                 << " Digite '1' para: Pesquisar Dados dos Animais\n"
                 << " Digite '2' para: Pesquisar Dados dos Funcionarios\n"
                 << " Digite '0' para: Voltar ao Menu Anterior \n"
                 << std::endl;
}

void
System::PrintPesquisar1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Pesquisar dados dos animais \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Pesquisar por Id\n"
             //<< " Digite '2' para: \n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintPesquisar1_2(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Pesquisar dados dos funcionario \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Pesquisar por Id\n"
             //<< " Digite '2' para: \n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintEditar1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Editar Dados dos Banco \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1' para: Editar Dados dos Animais\n"
             << " Digite '2' para: Editar Dados dos Funcionarios\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintEditar1_1(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Editar Dados dos Animais \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1'  para: Editar Nome Cientifico\n"
             << " Digite '2'  para: Editar Sexo\n"
             << " Digite '3'  para: Editar Tamanho\n"
             << " Digite '4'  para: Editar Dieta\n"
             << " Digite '5'  para: Editar Veterinario\n"
             << " Digite '6'  para: Editar Tratador\n"
             << " Digite '7'  para: Editar Nome de Batismo\n"
             << " Digite '8'  para: Editar mudas\n"
             << " Digite '9'  para: Editar Cor do pelo\n"
             << " Digite '10' para: Editar Venenoso\n"
             << " Digite '11' para: Editar Tipo do Veneno\n"
             << " Digite '12' para: Editar Envergadura das Asas\n"
             << " Digite '13' para: Editar Tamanho do Bico\n"
             << " Digite '14' para: Editar Uf Origem\n"
             << " Digite '15' para: Editar Pais de origem\n"
             << " Digite '16' para: Editar Cidade de origem\n"
             << " Digite '17' para: Editar Autorização do ibama\n"
             << " Digite '0' para: Voltar ao Menu Anterior \n"
             << std::endl;
}

void
System::PrintEditar1_2(){
  std::cout  << " \n ++++++++++++++++++++++++++++++++++++++++++++++++++ \n"
             << " \n Você escolheu a alternativa: Editar Dados dos funcionarios \n"
             << " \n Escolha uma das seguintes alternativas abaixo: \n"
             << " Digite '1'  para: Editar Nome\n"
             << " Digite '2'  para: Editar Cpf\n"
             << " Digite '3'  para: Editar Idade\n"
             << " Digite '4'  para: Editar Tipo Sanguineo\n"
             << " Digite '5'  para: Editar Fator Rh\n"
             << " Digite '6'  para: Editar especialidade\n"
             << " Digite '7'  para: Editar Crmv\n"
             << " Digite '8'  para: Editar Nivel de segurança\n"
             << std::endl;
}
