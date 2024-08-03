#include "../../includes/Produto.h"
#include "../../includes/GerenciamentoDeProduto.h"
#include "../../includes/Busca.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

Busca::Busca(Produto& produto_) : produto(produto_) {
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


