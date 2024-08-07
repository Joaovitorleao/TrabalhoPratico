#include "../../includes/RelatorioVenda.h"
#include <iostream>
#include <limits>

using namespace std;

RelatorioVenda::RelatorioVenda(GerenciamentoDeProduto& gerenciamento)
    : gerenciamento(gerenciamento) {
}

void RelatorioVenda::getDespesas() {
    despesas = 0.0;

    for (const auto& it : gerenciamento.entradas_) {
        const string& produtoId = it.first;
        int totalEntradas = gerenciamento.TotalEntradas(produtoId);
        float valorCompra = gerenciamento.BuscaValorDeCompra(produtoId);

        despesas += totalEntradas * valorCompra;
    }

    cout << "As despesas totais foram de: R$ " << despesas << endl;
}

void RelatorioVenda::getLucro() {
    getDespesas();

    lucro = 0.0;
    float receita = 0.0;

    for (const auto& it : gerenciamento.saidas_) {
        const string& produtoId = it.first;
        int totalSaidas = gerenciamento.TotalSaidas(produtoId);
        float valorVenda = gerenciamento.BuscaValorDeVenda(produtoId);

        receita += totalSaidas * valorVenda;
    }

    lucro = receita - despesas;
    cout << "O lucro foi de: R$ " << lucro << endl;
}

void RelatorioVenda::getProdutoMaisVendido() {
    quantidadeMaisVendido = 0;
    produtoMaisVendido = "";

    for (const auto& it : gerenciamento.saidas_) {
        const string& produtoId = it.first;
        int VendasProduto = gerenciamento.TotalSaidas(produtoId);

        if (VendasProduto > quantidadeMaisVendido) {
            quantidadeMaisVendido = VendasProduto;
            produtoMaisVendido = produtoId;
        }
    }

    cout << "O produto mais vendido foi: " << produtoMaisVendido << endl;
}

void RelatorioVenda::getProdutoMenosVendido() {
    quantidadeMenosVendido = numeric_limits<int>::max();
    produtoMenosVendido = "";

    for (const auto& it : gerenciamento.saidas_) {
        const string& produtoId = it.first;
        int VendasProduto = gerenciamento.TotalSaidas(produtoId);

        if (VendasProduto < quantidadeMenosVendido) {
            quantidadeMenosVendido = VendasProduto;
            produtoMenosVendido = produtoId;
        }
    }

    cout << "O produto menos vendido foi: " << produtoMenosVendido << endl;
}

void RelatorioVenda::getQuantidadeMaisVendido() {
    getProdutoMaisVendido();
    cout << "A quantidade do mais vendido foi: " << quantidadeMaisVendido << endl;
}

void RelatorioVenda::getQuantidadeMenosVendido() {
    getProdutoMenosVendido();
    cout << "A quantidade do menos vendido foi: " << quantidadeMenosVendido << endl;
}