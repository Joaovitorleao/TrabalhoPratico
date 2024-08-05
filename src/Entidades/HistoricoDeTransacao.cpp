#include "HistoricoDeTransacao.hpp" 
#include <iostream>

using namespace std;

Transacao::Transacao(int idProduto, Tipo tipo, int quantidade, double valorDeCompra, double valorDeVenda, const string& data)
    : idProduto(idProduto), tipo(tipo), quantidade(quantidade), valorDeCompra(valorDeCompra), valorDeVenda(valorDeVenda), data(data) {}

int Transacao::getIdProduto() const { return idProduto; }
Transacao::Tipo Transacao::getTipo() const { return tipo; }
int Transacao::getQuantidade() const { return quantidade; }
double Transacao::getValorDeCompra() const { return valorDeCompra; }
double Transacao::getValorDeVenda() const { return valorDeVenda; }
string Transacao::getData() const { return data; }

void HistoricoDeTransacao::registrarTransacao(int idProduto, Transacao::Tipo tipo, int quantidade, double valorDeCompra, double valorDeVenda, const string& data) {
    historico.emplace_back(idProduto, tipo, quantidade, valorDeCompra, valorDeVenda, data);
}

void HistoricoDeTransacao::mostrarHistorico() const {
    for (const auto& transacao : historico) {
        cout << "ID Produto: " << transacao.getIdProduto() << endl;
        cout << "Tipo: " << (transacao.getTipo() == Transacao::ENTRADA ? "Entrada" : "Saida") << endl;
        cout << "Quantidade: " << transacao.getQuantidade() << endl;
           if (transacao.getTipo() == Transacao::ENTRADA) {
            cout << "Valor de Compra: " << transacao.getValorDeCompra() << endl;
        } else {
            cout << "Valor de Venda: " << transacao.getValorDeVenda() << endl;
        }
        cout << "Data: " << transacao.getData() << endl;
    }
}

void HistoricoDeTransacao::mostrarHistoricoProduto(int idProduto) const {
    for (const auto& transacao : historico) {
        if (transacao.getIdProduto() == idProduto) {
            cout << "ID Produto: " << transacao.getIdProduto() << endl;
            cout << "Tipo: " << (transacao.getTipo() == Transacao::ENTRADA ? "Entrada" : "Saida") << endl;
            cout << "Quantidade: " << transacao.getQuantidade() << endl;
              if (transacao.getTipo() == Transacao::ENTRADA) {
            cout << "Valor de Compra: " << transacao.getValorDeCompra() << endl;
        } else {
            cout << "Valor de Venda: " << transacao.getValorDeVenda() << endl;
        }
            cout << "Data: " << transacao.getData() << endl;
        }
    }
}
