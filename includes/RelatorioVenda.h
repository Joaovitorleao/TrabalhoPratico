#ifndef RELATORIOVENDA_H_
#define RELATORIOVENDA_H_

#include "GerenciamentoDeProduto.h"
#include <string>

class RelatorioVenda {
    public:
        RelatorioVenda(GerenciamentoDeProduto& gerenciamento);

        //Calcula e informa as despesas pelo número de entradas e o preço de compra de cada produto
        void getDespesas();
        //Calcula e informa o lucro pelo número de saídas e o preço de venda de cada produto
        void getLucro();
        //Encontra e informa o produto mais vendido a partir do número de saídas
        void getProdutoMaisVendido();
        //Encontra e informa o produto menos vendido a partir do número de saídas
        void getProdutoMenosVendido();
        //Informa a quantidade vendida do mais vendido
        void getQuantidadeMaisVendido();
        //Informa a quantidade vendida do menos vendido
        void getQuantidadeMenosVendido();

    private:
        GerenciamentoDeProduto& gerenciamento;
        float lucro;
        float despesas;
        std::string produtoMaisVendido;
        std::string produtoMenosVendido;
        int quantidadeMaisVendido;
        int quantidadeMenosVendido;
};

#endif // RELATORIOVENDA_H_
