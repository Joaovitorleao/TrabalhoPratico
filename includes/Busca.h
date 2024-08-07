#ifndef BUSCA_H_
#define BUSCA_H_

#include <iostream>
#include <string>
#include <list>
#include "Produto.h"
#include <map>
#include "GerenciamentoDeProduto.h"

class Busca : public Produto{
public:
    Busca(Produto& produto_);

    // Pesquisa o produto e a quantidade em estoque pelo nome do produtoi
    void PesquisarProduto(string& pesquisa_, string& id, float valor_compra, float valor_venda, int quantidade);
    
	// Mostra todos os produtos contidos na lista	
	void MostraProdutos();	
	
	// Busca o Valor da Compra
	int BuscaValorDeCompra(string idProduto);   
		
	// Busca o Valor da Venda
	int BuscaValorDeVenda(string idProduto); 

	
private:
    Produto& produto;
    map<string, int> estoque_; // Mapeia o nome do produto à quantidade em estoque
    string pesquisa_;
};


#endif
