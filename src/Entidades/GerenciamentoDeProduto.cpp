#include "../../includes/Produto.h"
#include "../../includes/GerenciamentoDeProduto.h"
#include <iostream>

using namespace std;

GerenciamentoDeProduto::GerenciamentoDeProduto(Produto& produto_) : produto(produto_) {
}

void GerenciamentoDeProduto::AdicionarEstoque(const string& produto_, int quantidade_) {
    if (quantidade_ <= 0) {
        cout << "Quantidade inválida. Por favor, insira um valor maior que zero." << endl;
        return;
    }
    
    if (produto.ProdutoPertence(produto_)) {
        estoque_[produto_] += quantidade_;
        if(quantidade_ == 1){
            cout << "Adicionado " << quantidade_ << " unidade de " << produto_ << " ao estoque." << endl;
        } else {
            cout << "Adicionado " << quantidade_ << " unidades de " << produto_ << " ao estoque." << endl;
        }
    } else {
        cout << "Produto " << produto_ << " não encontrado." << endl;
    }
}

void GerenciamentoDeProduto::RemoverEstoque(const string& produto_, int quantidade_) {
    if (quantidade_ <= 0) {
        cout << "Quantidade inválida. Por favor, insira um valor maior que zero." << endl;
        return;
    }
    
    if (produto.ProdutoPertence(produto_)) {
        if (estoque_[produto_] >= quantidade_) {
            estoque_[produto_] -= quantidade_;
            if(quantidade_ == 1){
                cout << "Removido " << quantidade_ << " unidade de " << produto_ << " do estoque."  << endl;
            } else {
                cout << "Removido " << quantidade_ << " unidades de " << produto_ << " do estoque."  << endl; 
                }
        } else {
            cout << "Quantidade insuficiente em estoque para " << produto_ << "."  << endl;
        }
    } else {
        cout << "Produto " << produto_ << " não encontrado." << endl;
    }
}

int GerenciamentoDeProduto::TotalEntradas(const string& produto_) {
        return entradas_[produto_];
}

int GerenciamentoDeProduto::TotalSaidas(const string& produto_) {
    return saidas_[produto_];
}