#include "HistoricoDeTransacao.hpp"

Transacao::Transacao(int idProduto, Tipo tipo, int quantidade, double valor, const std::string& data)
    : idProduto(idProduto), tipo(tipo), quantidade(quantidade), valor(valor), data(data) {}

int Transacao::getIdProduto() const { return idProduto; }
Transacao::Tipo Transacao::getTipo() const { return tipo; }
int Transacao::getQuantidade() const { return quantidade; }
double Transacao::getValor() const { return valor; }
std::string Transacao::getData() const { return data; }

void HistoricoDeTransacao::registrarTransacao(int idProduto, Transacao::Tipo tipo, int quantidade, double valor, const std::string& data) {
    historico.emplace_back(idProduto, tipo, quantidade, valor, data);
}

void HistoricoDeTransacao::mostrarHistorico() const {
    for (const auto& transacao : historico) {
        std::cout << "ID Produto: " << transacao.getIdProduto() << std::endl;
        std::cout << "Tipo: " << (transacao.getTipo() == Transacao::ENTRADA ? "Entrada" : "Saida") << std::endl;
        std::cout << "Quantidade: " << transacao.getQuantidade() << std::endl;
        std::cout << "Valor: " << transacao.getValor() << std::endl;
        std::cout << "Data: " << transacao.getData() << std::endl;
    }
}

void HistoricoDeTransacao::mostrarHistoricoProduto(int idProduto) const {
    for (const auto& transacao : historico) {
        if (transacao.getIdProduto() == idProduto) {
            std::cout << "ID Produto: " << transacao.getIdProduto() << std::endl;
            std::cout << "Tipo: " << (transacao.getTipo() == Transacao::ENTRADA ? "Entrada" : "Saida") << std::endl;
            std::cout << "Quantidade: " << transacao.getQuantidade() << std::endl;
            std::cout << "Valor: " << transacao.getValor() << std::endl;
            std::cout << "Data: " << transacao.getData() << std::endl;
        }
    }
}
