#ifndef GERENCIAMENTODEPRODUTO_H_
#define GERENCIAMENTODEPRODUTO_H_

#include "Produto.h"
#include <map>

class GerenciamentoDeProduto : public Produto {
    public:

        GerenciamentoDeProduto(Produto& produto);

        // Adiciona uma quantidade ao estoque do produto especificado
        void AdicionarEstoque(const string& nome, int quantidade);

        // Remove uma quantidade do estoque do produto especificado
        void RemoverEstoque(const string& nome, int quantidade);

        // Contabiliza o total de entradas de um produto
        int TotalEntradas(const string& produto_);

        // Contabiliza o total de saídas de um produto
        int TotalSaidas(const string& produto_);

        map<string, int> entradas_; // Mapeia o nome do produto à quantidade de entradas
        map<string, int> saidas_; // Mapeia o nome do produto à quantidade de saídas

    private:
        Produto& produto;

};

#endif