#ifndef HISTORICODETRANSACAO_H
#define HISTORICODETRANSACAO_H

#include <vector>
#include "Produto.hpp"

class HistoricoDeTransacao {
public:
    //método para registrar uma entrada de produto no estoque
    void registrarEntrada(const Produto& produto, int quantidade);
    
    //método para registrar uma saída de produto do estoque
    void registrarSaida(const Produto& produto, int quantidade);
    
    //método para imprimir o histórico de transações
    void imprimirHistorico() const;

private:
    std::vector<std::string> historico_;
    //Armazena total de entradas
    int  HistoricoDeTransacao::getTotalEntradas()
    //Armazena total de saidas
    int  HistoricoDeTransacao::getTotalSaidas()
};

#endif  // HISTORICODETRANSAÇAO_H