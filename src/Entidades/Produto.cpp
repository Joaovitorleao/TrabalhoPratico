#include <iostream>
#include <string>
#include <map>
#include <random>
#include <algorithm>
#include "../../includes/Produto.h"

using namespace std;

Produto::Produto(){}

void Produto::AdicionarProduto(string prod, float valor_compra, float valor_venda){
<<<<<<< HEAD
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [&prod](const Produtos& p){
        return p.nome == prod;
    });

    if(it != listaProdutos.end()){
        it->quantidade += 1;
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
=======

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

bool Produto::ProdutoPertence(const string idProduto){

    for(const auto& produto : mapProdutos){
        if(produto.first.idProduto == idProduto)
            return true;
    }
}

void Produto::AdicionarQuantidade(const string& nome, int quantidade) {
    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        if (it->first.nome == nome) {
            Produtos novoProduto = it->first;
            novoProduto.quantidade += quantidade;
            mapProdutos.erase(it);
            mapProdutos[novoProduto] = novoProduto.quantidade;
            return;
        }
    }
    cout << "Produto não encontrado. Por favor, verifique o nome do produto e tente novamente." << endl;
}

void Produto::RemoverQuantidade(const string& nome, int quantidade) {
    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        if (it->first.nome == nome) {
            if (it->first.quantidade >= quantidade) {
                Produtos novoProduto = it->first;
                novoProduto.quantidade -= quantidade;
                mapProdutos.erase(it);
                mapProdutos[novoProduto] = novoProduto.quantidade;
            } else {
                cout << "Quantidade de itens insuficientes para remoção. Por favor, verifique a quantidades de itens no estoque e tente novamente." << endl;
                return;
            }
            return;
        }
    }
    cout << "Produto não encontrado. Por favor, verifique o nome do produto e tente novamente." << endl;
}
>>>>>>> d9128eb05da0721a96644e439ca6114af7babaea
