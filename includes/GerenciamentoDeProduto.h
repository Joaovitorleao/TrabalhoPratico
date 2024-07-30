#ifndef GERENCIAMENTODEPRODUTO_H_
#define GERENCIAMENTODEPRODUTO_H_

#include "Produto.h"
#include <map>

class GerenciamentoDeProduto {
public:
    GerenciamentoDeProduto(Produto& produto_);

    // Adiciona uma quantidade ao estoque do produto especificado
    void AdicionarEstoque(const string& produto_, int quantidade_);

    // Remove uma quantidade do estoque do produto especificado
    void RemoverEstoque(const string& produto_, int quantidade_);

private:
    Produto& produto;
    map<string, int> estoque_; // Mapeia o nome do produto à quantidade em estoque
};

#endif