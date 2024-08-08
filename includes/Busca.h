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
    void PesquisarProduto(string& pesquisa_);
    
	// Mostra todos os produtos contidos na lista	
	void MostraProdutos();	
	
	// Busca o Valor da Compra
	float BuscaValorDeCompra(string idProduto);   
		
	// Busca o Valor da Venda
	float BuscaValorDeVenda(string idProduto); 

	
private:
    Produto& produto;
    string pesquisa_;
};


#endif
