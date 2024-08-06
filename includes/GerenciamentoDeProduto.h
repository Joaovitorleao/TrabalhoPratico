#ifndef GERENCIAMENTODEPRODUTO_H_
#define GERENCIAMENTODEPRODUTO_H_

#include "Produto.h"
#include <map>

class GerenciamentoDeProduto {
    public:

        GerenciamentoDeProduto();

        GerenciamentoDeProduto(Produto& produto_);

        // Adiciona uma quantidade ao estoque do produto especificado
        void AdicionarEstoque(const string& produto_, int quantidade_);

        // Remove uma quantidade do estoque do produto especificado
        void RemoverEstoque(const string& produto_, int quantidade_);

        // Contabiliza o total de entradas de um produto
        int TotalEntradas(const string& produto_);

        // Contabiliza o total de saídas de um produto
        int TotalSaidas(const string& produto_);

    private:
        Produto& produto;
        map<string, int> estoque_; // Mapeia o nome do produto à quantidade em estoque
        map<string, int> entradas_; // Mapeia o nome do produto à quantidade de entradas
        map<string, int> saidas_; // Mapeia o nome do produto à quantidade de saídas
};

#endif