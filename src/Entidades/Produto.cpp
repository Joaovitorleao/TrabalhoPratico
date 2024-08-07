#include <iostream>
#include <string>
#include <map>
#include <random>
#include <algorithm>
#include "../../includes/Produto.h"

using namespace std;

Produto::Produto(){}

void Produto::AdicionarProduto(string prod, float valor_compra, float valor_venda){

    Produtos novoProduto;
    novoProduto.idProduto = gerarIdUnico();
    novoProduto.nome = prod;
    novoProduto.valorDeCompra = valor_compra;
    novoProduto.valorDeVenda = valor_venda;

    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        if(it->first.nome == novoProduto.nome){
            mapProdutos.erase(it);
            break;
        }
    }
    
    mapProdutos[novoProduto] = novoProduto.quantidade;
}

void Produto::EditarProduto(string idProduto, string novo_nome, float novo_valor_compra, float novo_valor_venda){

    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        if(it->first.idProduto == idProduto){
            Produtos novoProduto = it->first;
            novoProduto.nome = novo_nome;
            novoProduto.valorDeCompra = novo_valor_compra;
            novoProduto.valorDeVenda = novo_valor_venda;
            mapProdutos.erase(it);
            mapProdutos[novoProduto] = novoProduto.quantidade;
            return;
        }
    }
}

void Produto::ExcluirProduto(string idProduto){
    
    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        if(it->first.idProduto == idProduto){
            mapProdutos.erase(it);
            return;
        }
    }
}

void Produto::NomeMaiusculo(){
    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        Produtos novoProduto = it->first;
        string novoNome = novoProduto.nome;
        transform(novoNome.begin(), novoNome.end(), novoNome.begin(), ::toupper);
        novoProduto.nome = novoNome;
        mapProdutos.erase(it);
        mapProdutos[novoProduto] = novoProduto.quantidade;
    }
}

string Produto::gerarIdUnico(){
    static const char caracteres[] = 
        "123456789"
        "abcdefghij";
    
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


bool Produto::ProdutoPertence(const string idProduto){

    for(const auto& produto : mapProdutos){
        if(produto.first.idProduto == idProduto)
            return true;
    }
}