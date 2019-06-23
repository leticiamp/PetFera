/**
* @file arquivoNaoAberto.h
* @brief Classe padrão para a exceção de arquivo não aberto.
* @author André Vitor Macedo Soares, Letícia Moura Pinheiro e Odilon Julio dos Santos
* @since 25/04/2019
* @date 23/06/2019
*/

#ifndef _ARQUIVO_NAO_ABERTO_H_
#define _ARQUIVO_NAO_ABERTO_H_

#include <stdexcept>
#include <exception>

/** 
* @details Esta classe verifica se foi possível abrir ou não um arquivo, e informa ao usuário
*/

using std::exception;
using std::invalid_argument;

class ArquivoNaoAberto : public exception, public invalid_argument {
    public:
        const char * what() {
            return "Operação inválida: O arquivo NÃO foi aberto!";
        }
        ArquivoNaoAberto() : invalid_argument("Operação inválida: O arquivo NÃO foi aberto!"){};
};


#endif
