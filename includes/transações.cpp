#include "HistoricoDeTransacao.h"
#include "Produto.h"
#include "Transacao.h"
#include <iostream>
#include <vector>

void HistoricoDeTransacao::adicionarTransacao(const Transacao& transacao) {
    historico_.push_back(transacao);
}

void HistoricoDeTransacao::imprimirHistorico() {
    std::cout << "Histórico de transações:" << std::endl;
    for (const auto& descricao : historico_) {
        std::cout << "Produto: " << descricao.getProduto().getNome() << std::endl;
        std::cout << "  Tipo: " << (descricao.getTipo() == TipoTransacao::ENTRADA ? "Entrada" : "Saída") << std::endl;
        std::cout << "  Quantidade: " << descricao.getQuantidade() << std::endl;
        std::cout << std::endl;
    }
}

void HistoricoDeTransacao::imprimirHistoricoIndividual() {
    for (const auto& produto : produtos_) {
        int totalEntradas = 0;
        int totalSaidas = 0;
        for (const auto& descricao : historico_) {
            if (descricao.getProduto() == produto) {
                if (descricao.getTipo() == TipoTransacao::ENTRADA) {
                    totalEntradas += descricao.getQuantidade();
                } else if (descricao.getTipo() == TipoTransacao::SAIDA) {
                    totalSaidas += descricao.getQuantidade();
                }
            }
        }
        std::cout << "Produto: " << produto.getNome() << std::endl;
        std::cout << "  Total de entradas: " << totalEntradas << std::endl;
        std::cout << "  Total de saídas: " << totalSaidas << std::endl;
        std::cout << std::endl;
    }
}

void HistoricoDeTransacao::adicionarProduto(const Produto& produto) {
    produtos_.push_back(produto);
}