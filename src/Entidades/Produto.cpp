#include <iostream>
#include <string>
#include <algorithm>
#include <random>

#include "../../includes/Produto.h"

using namespace std;

Produto::Produto(){}

void Produto::AdicionarProduto(string prod, float valor_compra, float valor_venda){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&prod](const Produtos& p){
        return p.nome == prod;
    });

    if(it != listaProdutos.end()){
        it->quantidade++;
    }
    
    else{
        Produtos novoProduto;
        novoProduto.idProduto = gerarIdUnico();
        novoProduto.nome = prod;
        novoProduto.valorDeCompra = valor_compra;
        novoProduto.valorDeVenda = valor_venda;
        novoProduto.quantidade = 1;
        listaProdutos.push_back(novoProduto);
    }
}

void Produto::EditarProduto(string idProduto, string novo_nome, float novo_valor_compra, float novo_valor_venda){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&idProduto](const Produtos p){
        return p.idProduto == idProduto;
    });

    if(it != listaProdutos.end()){
        it->nome = novo_nome;
        it->valorDeCompra = novo_valor_compra;
        it->valorDeVenda = novo_valor_venda;
    }  
}

void Produto::ExcluirProduto(string idProduto){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&idProduto](const Produtos p){
        return p.idProduto == idProduto;
    });

    if(it != listaProdutos.end()){
        if(it->quantidade > 1)
            it->quantidade--;
        else
            listaProdutos.erase(it);
    }
        
}

void Produto::MostraProdutos(){
    cout << "Lista de produtos: " << endl;
    for(const auto& produto : listaProdutos){
        cout << "Id: " << produto.idProduto << endl;
        cout << "Nome: " << produto.nome << endl;
        cout << "Valor de compra: R$" << produto.valorDeCompra << endl;
        cout << "Valor de venda: R$" << produto.valorDeVenda << endl;
        cout << "Quantidade: " << produto.quantidade << endl;
    }
}

string Produto::gerarIdUnico(){
    static const char caracteres[] = 
        "123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHJKLMNOPQRSTUVWXYZ";
    
    const int tamanhoId_ = 10;
    string idProduto_;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, sizeof(caracteres) - 2);

    for(int i=0; i<10; i++){
        idProduto_ += caracteres[dis(gen)];
    }

    return idProduto_;
}

int Produto::BuscaValorDeCompra(string idProduto){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&idProduto](const Produtos p){
        return p.nome == idProduto;
    });

    if(it != listaProdutos.end())
        return it->valorDeCompra;
}

int Produto::BuscaValorDeVenda(string idProduto){
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&idProduto](const Produtos p){
        return p.nome == idProduto;
    });

    if(it != listaProdutos.end())
        return it->valorDeVenda;
}

bool Produto::ProdutoPertence(const string idProduto){
    return any_of(listaProdutos.begin(), listaProdutos.end(), [&idProduto](const Produtos prod){
        return prod.idProduto == idProduto;
    });
}
