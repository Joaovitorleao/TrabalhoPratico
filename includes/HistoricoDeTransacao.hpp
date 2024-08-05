#ifndef HISTORICO_DE_TRANSACAO_HPP
#define HISTORICO_DE_TRANSACAO_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Produto.h"

// Classe que representa uma transação no estoque (entrada ou saída de produtos).
class Transacao {
public:
    // Enum para definir o tipo de transação: entrada ou saída.
    enum Tipo {ENTRADA, SAIDA};

    // Construtor da classe Transacao.
    Transacao(int idProduto, Tipo tipo, int quantidade, double valor, const std::string& data);
    
    // Métodos para acessar os atributos da transação.
    int getIdProduto() const;     
    Tipo getTipo() const;          
    int getQuantidade() const;     
    double getValor() const;      
    std::string getData() const;  

private:
    int idProduto;                 
    Tipo tipo;                     
    int quantidade;                
    double valor;                  
    std::string data;              
};

// Classe que gerencia o histórico de transações do estoque.
class HistoricoDeTransacao {
public:
    // Registra uma nova transação no histórico.
    void registrarTransacao(int idProduto, Transacao::Tipo tipo, int quantidade, double valor, const std::string& data);

    // Exibe todas as transações registradas no histórico.
    void mostrarHistorico() const;

    // Exibe o histórico de transações de um produto específico.
    void mostrarHistoricoProduto(int idProduto) const;

private:
    std::vector<Transacao> historico;  // Vetor que armazena todas as transações registradas.
};

#endif  
