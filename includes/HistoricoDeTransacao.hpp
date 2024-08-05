#ifndef HISTORICODETRANSACAO_H
#define HISTORICODETRANSACAO_H

#include "Produto.h"
#include "Transacao.h"
#include <vector>

class HistoricoDeTransacao {
public:
    // Construtor
    HistoricoDeTransacao();

    // Métodos de Transação
    //Soma ao contador que imprime historico
    void adicionarTransacao(const Transacao& transacao);
    void imprimirHistorico();

    // Métodos de Produto
    void adicionarProduto(const Produto& produto);
    
    //Método para imprimir o historico de cada produto individualmente
    void imprimirHistoricoIndividual();

private:
    std::vector<Transacao> historico_;
    std::vector<Produto> produtos_;
};

#endif  // HISTORICODETRANSACAO_H