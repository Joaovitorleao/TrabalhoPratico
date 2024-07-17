#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <iostream>
#include <string>
#include <list>

class Produto {
    public:
        Produto();
        //só adiciona um produto que ainda não existe na lista de produtos
        void AdicionarProduto(string produto);

        //Garante que só consegue editar um produto que esteja na lista de produtos
        void EditarProduto(string id);

        //Garante que só consegue excluir um produto que esteja na lista de produtos
        void ExcluirProduto(string id);

        //Verifica se o produto pertence à lista de produtos
        bool ProdutoPertence(string p);
    
    private:
        list<string> Produtos;
        string nomeProduto;
        float valorDeCompra;
        float valorDeVenda;
}

#endif
