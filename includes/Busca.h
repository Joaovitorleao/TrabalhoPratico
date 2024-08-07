#ifndef BUSCA_H_
#define BUSCA_H_

#include <iostream>
#include <string>
#include <list>
#include "Produto.h"
#include <map>
#include "GerenciamentoDeProduto.h"

class Busca {
public:
    Busca(Produto& produto_);

    // Pesquisa o produto e a quantidade em estoque pelo nome do produtoi
<<<<<<< HEAD
    void PesquisarProduto(string& pesquisa_, float valor_compra, float valor_venda, int quantidade, string id);
=======
    void PesquisarProduto(string& pesquisa_, float valor_compra, float valor_venda, int quantidade);
>>>>>>> d9128eb05da0721a96644e439ca6114af7babaea
    

private:
    Produto& produto;
    map<string, int> estoque_; // Mapeia o nome do produto à quantidade em estoque
    string pesquisa_;
};


<<<<<<< HEAD


=======
>>>>>>> d9128eb05da0721a96644e439ca6114af7babaea
#endif
