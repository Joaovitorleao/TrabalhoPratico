#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <iostream>
#include <string>
#include <map>
using namespace std;

 struct Produtos {
            string idProduto;
            string nome;
            float valorDeCompra;
            float valorDeVenda;
            int quantidade = 0;
            bool operator<(const Produtos& outro) const {
                return idProduto < outro.idProduto;
            }
};

class Produto {
    public:
        Produto();
        //Adiciona um produto inexistente. Caso ele exista, acrescenta uma unidade
        void AdicionarProduto(string prod, float valor_compra, float valor_venda);

        //Garante que só consegue editar um produto que esteja na lista de produtos
        void EditarProduto(string idProduto, string novo_nome, float novo_valor_compra, float novo_valor_venda);

        //Garante que só consegue excluir um produto que esteja na lista de produtos
        void ExcluirProduto(string idProduto);

        //Deixa o nome dos produtos em letra maiúscula
        void NomeMaiusculo();

        //Verifica se o produto pertence à lista de produtos
        bool ProdutoPertence(string idProduto); 
		
		// Busca o Valor da Compra
		int BuscaValorDeCompra(string idProduto);   
		
		// Busca o Valor da Venda
		int BuscaValorDeVenda(string idProduto);  

        map<Produtos, int> mapProdutos; //map de struct de produtos e um int de quantidade
        string gerarIdUnico();
};

#endif