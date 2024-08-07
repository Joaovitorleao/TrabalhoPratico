#include "RelatorioVenda.h"
#include <iostream>
#include <limits>

RelatorioVenda::RelatorioVenda(GerenciamentoDeProduto& gerenciamento)
    : gerenciamento(gerenciamento) {
}

void RelatorioVenda::getDespesas() {
    despesas = 0.0;

    for (const auto& it : gerenciamento.entradas_) {
        const std::string& produtoId = it.first;
        int totalEntradas = gerenciamento.TotalEntradas(produtoId);
        float valorCompra = gerenciamento.BuscaValorDeCompra(produtoId);

        despesas += totalEntradas * valorCompra;
    }

    std::cout << "As despesas totais foram de: R$ " << despesas << std::endl;
}

void RelatorioVenda::getLucro() {
    getDespesas();

    lucro = 0.0;
    float receita = 0.0;

    for (const auto& it : gerenciamento.saidas_) {
        const std::string& produtoId = it.first;
        int totalSaidas = gerenciamento.TotalSaidas(produtoId);
        float valorVenda = gerenciamento.BuscaValorDeVenda(produtoId);

        receita += totalSaidas * valorVenda;
    }

    lucro = receita - despesas;
    std::cout << "O lucro foi de: R$ " << lucro << std::endl;
}

void RelatorioVenda::getProdutoMaisVendido() {
    quantidadeMaisVendido = 0;
    produtoMaisVendido = "";

    for (const auto& it : gerenciamento.saidas_) {
        const std::string& produtoId = it.first;
        int VendasProduto = gerenciamento.TotalSaidas(produtoId);

        if (VendasProduto > quantidadeMaisVendido) {
            quantidadeMaisVendido = VendasProduto;
            produtoMaisVendido = produtoId;
        }
    }

    std::cout << "O produto mais vendido foi: " << produtoMaisVendido << std::endl;
}

void RelatorioVenda::getProdutoMenosVendido() {
    quantidadeMenosVendido = std::numeric_limits<int>::max();
    produtoMenosVendido = "";

    for (const auto& it : gerenciamento.saidas_) {
        const std::string& produtoId = it.first;
        int VendasProduto = gerenciamento.TotalSaidas(produtoId);

        if (VendasProduto < quantidadeMenosVendido) {
            quantidadeMenosVendido = VendasProduto;
            produtoMenosVendido = produtoId;
        }
    }

    std::cout << "O produto menos vendido foi: " << produtoMenosVendido << std::endl;
}

void RelatorioVenda::getQuantidadeMaisVendido() {
    getProdutoMaisVendido();
    std::cout << "A quantidade do mais vendido foi: " << quantidadeMaisVendido << std::endl;
}

void RelatorioVenda::getQuantidadeMenosVendido() {
    getProdutoMenosVendido();
    std::cout << "A quantidade do menos vendido foi: " << quantidadeMenosVendido << std::endl;
}
