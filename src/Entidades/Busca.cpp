#include "../../includes/Produto.h"
#include "../../includes/GerenciamentoDeProduto.h"
#include "../../includes/Busca.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

Busca::Busca(Produto& produto_) : produto(produto_) {
}

int Produto::BuscaValorDeCompra(string idProduto){
    
    for(const auto& produto : mapProdutos){
        if(produto.first.idProduto == idProduto){
            return produto.first.valorDeCompra;
        }
    }
}

int Produto::BuscaValorDeVenda(string idProduto){
    
    for(const auto& produto : mapProdutos){
        if(produto.first.idProduto == idProduto){
            return produto.first.valorDeVenda;
        }
    }
}


void Busca::PesquisarProduto(string& pesquisa_, float valor_compra, float valor_venda, int quantidade){
	
	
    if (produto.ProdutoPertence(pesquisa_)) {
    	    	        
        valor_compra = produto.BuscaValorDeCompra(pesquisa_);
        valor_venda = produto.BuscaValorDeVenda(pesquisa_);
        if (produto.ProdutoPertence(pesquisa_)) {
           quantidade = estoque_[pesquisa_];
         }
        
		cout << "Produto                : " << pesquisa_  << endl; 
        cout << "Valor de Compra        : " << valor_compra  << endl; 
        cout << "Valor de Venda         : " << valor_venda  << endl; 
        cout << "Quantidade em Estoque  : " << quantidade  << endl; 
    }    
    else{
    	cout << "Produto " << pesquisa_ << " não encontrado." << endl;
        valor_compra = 0;
        valor_venda = 0;
        quantidade = 0;
    }
}

void Busca::MostraProdutos(){
    cout << endl;
    cout << "-------------------------------------";
    cout << "*Lista de produtos: ***" << endl;
    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        cout << endl;
        Produtos produto = it->first;
        cout << "Id: " << produto.idProduto << endl;
        cout << "Nome: " << produto.nome << endl;
        cout << "Valor de compra: R$" << produto.valorDeCompra << endl;
        cout << "Valor de venda: R$" << produto.valorDeVenda << endl;
        cout << "Quantidade: " << produto.quantidade << endl;
        cout << endl;
    }
}