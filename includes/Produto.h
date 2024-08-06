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
        void EditarProduto(string idProduto, string novo_nome, float novo_valor_compra, float novo_valor_venda);

        //Garante que só consegue excluir um produto que esteja na lista de produtos
        void ExcluirProduto(string idProduto);

        //Mostra todos os produtos da lista de produtos
        void MostraProdutos();

        //Verifica se o produto pertence à lista de produtos
        bool ProdutoPertence(string p); 
		
		// Busca o Valor da Compra
		int BuscaValorDeCompra(string idProduto);   
		
		// Busca o Valor da Venda
		int BuscaValorDeVenda(string idProduto);  
   
    private:
        struct Produtos {
            string idProduto;
            string nome;
            float valorDeCompra;
            float valorDeVenda;
            int quantidade;
        };

        list<Produtos> listaProdutos;
        string gerarIdUnico();
};

#endif
