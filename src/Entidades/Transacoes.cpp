#include "../../includes/HistoricoDeTransacao.h"
#include "../../includes/Produto.h"
#include "../../includes/Transacoes.h"

#include <iostream>
#include <vector>

using namespace std;

void HistoricoDeTransacao::adicionarTransacao(const Transacao& transacao) {
    historico_.push_back(transacao);
}

void HistoricoDeTransacao::imprimirHistorico() {
    cout << "Histórico de transações:" << endl;
    for (const auto& descricao : historico_) {
        cout << "Produto: " << descricao.getProduto().getNome() << endl;
        cout << "  Tipo: " << (descricao.getTipo() == TipoTransacao::ENTRADA ? "Entrada" : "Saída") endl;
        cout << "  Quantidade: " << descricao.getQuantidade() << endl;
        cout << endl;
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
        cout << "Produto: " << produto.getNome() << endl;
        cout << "  Total de entradas: " << totalEntradas << endl;
        cout << "  Total de saídas: " << totalSaidas << endl;
        cout << endl;
    }
}

void HistoricoDeTransacao::adicionarProduto(const Produto& produto) {
    produtos_.push_back(produto);
}