#include <iostream>
#include <string>
#include <algorithm>

#include "../../includes/Produto.h"

using namespace std;

Produto::Produto(){}

void Produto::AdicionarProduto(string prod, float valor_compra, float valor_venda){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&prod](const Produtos& p){
        return p.nome == prod;
    })

    if(it != listaProdutos.end()){
        it->valorDeCompra = valor_compra;
        it->valorDeVenda = valor_venda;
    }
    
    else{
        Produtos novoProduto;
        novoProduto.nome = prod;
        novoProduto.valorDeCompra = valor_compra;
        novoProduto.valorDeVenda = valor_venda;
        listaProdutos.push_back(novoProduto);
    }
}

void Produto::EditarProduto(string id, string novo_nome, float novo_valor_compra, float novo_valor_venda){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&id](const Produtos p){
        return p.nome == id;
    });

    if(it != listaProdutos.end()){
        it->nome = novo_nome;
        it->valorDeCompra = novo_valor_compra;
        it->valorDeVenda = novo_valor_venda;
    }  
}

void Produto::ExcluirProduto(string id){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&id](const Produtos p){
        return p.nome == id;
    });

    if(it != listaProdutos.end())
        listaProdutos.erase(it);
}

bool Produto::ProdutoPertence(const string p){
    return any_of(listaProdutos.begin(), listaProdutos.end(), [&p](const Produtos prod){
        return prod.nome == p;
    });
}