#include "../../includes/Produto.h"
#include "../../includes/GerenciamentoDeProduto.h"
#include <iostream>

using namespace std;

GerenciamentoDeProduto::GerenciamentoDeProduto(Produto& produto_) : produto(produto_) {
}

void GerenciamentoDeProduto::AdicionarEstoque(const string& nome, int quantidade) {
    for(auto it = mapProdutos.begin(); it != mapProdutos.end(); it++){
        if (it->first.nome == nome) {
            Produtos novoProduto = it->first;
            novoProduto.quantidade += quantidade;
            mapProdutos.erase(it);
            mapProdutos[novoProduto] = novoProduto.quantidade;
            
            entradas_[nome] += quantidade;
            return;
        }
    }
    cout << "Produto não encontrado. Por favor, verifique o nome do produto e tente novamente." << endl;
}

void GerenciamentoDeProduto::RemoverEstoque(const string& nome, int quantidade) {
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
            saidas_[nome] += quantidade;
            return;
        }
    }
    cout << "Produto não encontrado. Por favor, verifique o nome do produto e tente novamente." << endl;
}

int GerenciamentoDeProduto::TotalEntradas(const string& produto_) {
        return entradas_[produto_];
}

int GerenciamentoDeProduto::TotalSaidas(const string& produto_) {
    return saidas_[produto_];
}