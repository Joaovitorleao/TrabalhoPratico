#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Produto {
    public:
        Produto();
        //Adiciona um produto inexistente. Caso ele exista, acrescenta uma unidade
        void AdicionarProduto(string prod, float valor_compra, float valor_venda);

        //Garante que só consegue editar um produto que esteja na lista de produtos
        void EditarProduto(string id, string novo_nome, float novo_valor_compra, float novo_valor_venda);

        //Garante que só consegue excluir um produto que esteja na lista de produtos
        void ExcluirProduto(string id);

        //Mostra todos os produtos da lista de produtos
        void MostraProdutos();

        //Verifica se o produto pertence à lista de produtos
        bool ProdutoPertence(string p);
    
    private:
        struct Produtos {
            string id;
            string nome;
            float valorDeCompra;
            float valorDeVenda;
        };

        list<Produtos> listaProdutos;
        string gerarIdUnico();
};

#endif
