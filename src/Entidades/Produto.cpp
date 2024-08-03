Produto.cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <random>

#include "../../includes/Produto.h"

using namespace std;

Produto::Produto(){}

string Produto::gerarIdUnico(){
    static const char caracteres[] = 
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";
    
    int tamanhoId_ = 8;
    string id;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, sizeof(caracteres) - 2);

    for(int i=0; i<tamanhoId_; i++){
        id += caracteres[dis(gen)];
    }

    return id;
}

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
        novoProduto.id = gerarIdUnico();
        novoProduto.nome = prod;
        novoProduto.valorDeCompra = valor_compra;
        novoProduto.valorDeVenda = valor_venda;
        listaProdutos.push_back(novoProduto);
    }
}

void Produto::EditarProduto(string id, string novo_nome, float novo_valor_compra, float novo_valor_venda){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&id](const Produtos p){
        return p.id == id;
    });

    if(it != listaProdutos.end()){
        it->nome = novo_nome;
        it->valorDeCompra = novo_valor_compra;
        it->valorDeVenda = novo_valor_venda;
    }  
}

void Produto::ExcluirProduto(string id){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&id](const Produtos p){
        return p.id == id;
    });

    if(it != listaProdutos.end())
        listaProdutos.erase(it);
}

bool Produto::ProdutoPertence(const string id){
    return any_of(listaProdutos.begin(), listaProdutos.end(), [&id](const Produtos prod){
        return prod.id == id;
    });
}

void Produto::MostraProdutos(){
    cout << "Lista de produtos: " << endl;
    for(const auto& produto : listaProdutos){
        cout << "Id: " << produto.id << endl;
        cout << "Nome: " << produto.nome << endl;
        cout << "Valor de compra: " << produto.valorDeCompra << endl;
        cout << "Valor de venda: " << produto.valorDeVenda << endl;
        cout << "-------------------" << endl;
    }
}