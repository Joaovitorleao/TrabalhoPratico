#include "../../includes/Produto.h"
#include "../../includes/GerenciamentoDeProduto.h"
#include "../../includes/Busca.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

Busca::Busca(Produto& produto_) : produto(produto_) {
}

float Busca::BuscaValorDeCompra(string idProduto){
    float valor_;
    for(const auto& produto : mapProdutos){
        if(produto.first.idProduto == idProduto){
            valor_ = produto.first.valorDeCompra;
        }
    }
    return valor_;
}

float Busca::BuscaValorDeVenda(string idProduto){
    float valor_;
    for(const auto& produto : mapProdutos){
        if(produto.first.idProduto == idProduto){
            valor_ = produto.first.valorDeVenda;
        }
    }
    return valor_;
}


void Busca::PesquisarProduto(string& pesquisa_){
	bool encontrado = false;

    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        Produtos produto = it->first;
        if(produto.nome == pesquisa_){ 
            cout << "Id: " << produto.idProduto << endl;
            cout << "Nome: " << produto.nome << endl;
            cout << "Valor de compra: R$" << produto.valorDeCompra << endl;
            cout << "Valor de venda: R$" << produto.valorDeVenda << endl;
            cout << "Quantidade: " << produto.quantidade << endl;
            cout << endl;  
            encontrado = true;  	        
        }   
    }
    if(!encontrado){
    cout << "Produto " << pesquisa_ << " não encontrado." << endl;
    }
}


void Busca::MostraProdutos(){
    cout << endl;
    cout << "Lista de produtos: " << endl;
    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        Produtos produto = it->first;
        cout << endl;
        cout << "Id: " << produto.idProduto << endl;
        cout << "Nome: " << produto.nome << endl;
        cout << "Valor de compra: R$" << produto.valorDeCompra << endl;
        cout << "Valor de venda: R$" << produto.valorDeVenda << endl;
        cout << "Quantidade: " << produto.quantidade << endl;
        cout << endl;
    }
}