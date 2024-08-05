#include "HistoricoDeTransacao.hpp"
#include <iostream>

using namespace std;

Transacao::Transacao(int idProduto, Tipo tipo, int quantidade, double valor, const string& data)
    : idProduto(idProduto), tipo(tipo), quantidade(quantidade), valor(valor), data(data) {}

int Transacao::getIdProduto() const { return idProduto; }
Transacao::Tipo Transacao::getTipo() const { return tipo; }
int Transacao::getQuantidade() const { return quantidade; }
double Transacao::getValor() const { return valor; }
string Transacao::getData() const { return data; }

void HistoricoDeTransacao::registrarTransacao(int idProduto, Transacao::Tipo tipo, int quantidade, double valor, const string& data) {
    historico.emplace_back(idProduto, tipo, quantidade, valor, data);
}

void HistoricoDeTransacao::mostrarHistorico() const {
    for (const auto& transacao : historico) {
        cout << "ID Produto: " << transacao.getIdProduto() << endl;
        cout << "Tipo: " << (transacao.getTipo() == Transacao::ENTRADA ? "Entrada" : "Saida") << endl;
        cout << "Quantidade: " << transacao.getQuantidade() << endl;
        cout << "Valor: " << transacao.getValor() << endl;
        cout << "Data: " << transacao.getData() << endl;
    }
}

void HistoricoDeTransacao::mostrarHistoricoProduto(int idProduto) const {
    for (const auto& transacao : historico) {
        if (transacao.getIdProduto() == idProduto) {
            cout << "ID Produto: " << transacao.getIdProduto() << endl;
            cout << "Tipo: " << (transacao.getTipo() == Transacao::ENTRADA ? "Entrada" : "Saida") << endl;
            cout << "Quantidade: " << transacao.getQuantidade() << endl;
            cout << "Valor: " << transacao.getValor() << endl;
            cout << "Data: " << transacao.getData() << endl;
        }
    }
}
