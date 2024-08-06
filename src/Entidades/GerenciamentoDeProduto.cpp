#include "../../includes/Produto.h"
#include "../../includes/GerenciamentoDeProduto.h"
#include <iostream>

using namespace std;

GerenciamentoDeProduto::GerenciamentoDeProduto(Produto& produto_) : produto(produto_) {
}

void GerenciamentoDeProduto::AdicionarEstoque() {
    string nome_;
    int quantidade_;

    cout << "Digite o nome do produto: ";
    cin >> nome_;

    cout << "Digite a quantidade a ser adicionada: ";
    cin >> quantidade_;

    if(quantidade_ > 0){
    produto.AdicionarQuantidade(nome_, quantidade_);
    } else {
        cout << "Quantidade invalida, digite um número maior do que zero" << endl;
    }
    cout << quantidade_ << "unidades de " << nome_ << " adicionados ao estoque!" << endl;
}

void GerenciamentoDeProduto::RemoverEstoque() {
    string nome_;
    int quantidade_;

    cout << "Digite o nome do produto: ";
    cin >> nome_;

    cout << "Digite a quantidade a ser removida: ";
    cin >> quantidade_;

    produto.RemoverQuantidade(nome_, quantidade_);

    cout << quantidade_ << "unidades de " << nome_ << " removidos do estoque!" << endl;
}

int GerenciamentoDeProduto::TotalEntradas(const string& produto_) {
        return entradas_[produto_];
}

int GerenciamentoDeProduto::TotalSaidas(const string& produto_) {
    return saidas_[produto_];
}