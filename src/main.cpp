#include "../includes/Busca.h"
#include "../includes/GerenciamentoDeProduto.h"
#include "../includes/Produto.h"
//#include "../includes/RelatorioVenda.h" DESCOMENTAR QUANDO IMPLEMENTAR RELATORIOVENDA
#include "../includes/HistoricoDeTransacao.hpp"

#include <iostream>
#include <string>

using namespace std;

void Menu() {
    cout << "====== Menu de gerenciamento de estoque ======" << endl;
    cout << "1. Adicionar produto" << endl;
    cout << "2. Editar produto" << endl;
    cout << "3. Excluir produto" << endl;
    cout << "4. Mostrar todos os produtos" << endl;
    cout << "5. Histórico de transações" << endl;
    cout << "6. Histórico de produtos" << endl;
    cout << "7. Relatorio de vendas" << endl;
    cout << "8. Sair" << endl;
    cout << endl << "Escolha uma opção: ";
}

int main(){
    Produto produto;
    GerenciamentoDeProduto gerenciamento(produto);
    HistoricoDeTransacao historico;
    int opcao;

    do {
        Menu();
        cin >> opcao;

        switch(opcao){
            case 1: {
                string nome;
                float valorCompra, valorVenda;
                cout << "Digite o nome do produto: ";
                cin >> nome;
                cout << "Digite o valor de compra do produto: ";
                cin >> valorCompra;
                cout << "Digite o valor de venda do produto: ";
                cin >> valorVenda;
                produto.AdicionarProduto(nome, valorCompra, valorVenda);
                break;
            }
            case 2: {
                string id, novoNome;
                float novoValorCompra, novoValorVenda;
                cout << "Digite o id do produto a ser editado: ";
                cin >> id;
                cout << "Digite o novo nome do produto: ";
                cin >> novoNome;
                cout << "Digite o novo valor de compra do produto: ";
                cin >> novoValorCompra;
                cout << "Digite o novo valor de venda do produto: ";
                cin >> novoValorVenda;
                produto.EditarProduto(id, novoNome, novoValorCompra, novoValorVenda);
                break;
            }
            case 3: {
                string id;
                int quantidade;
                cout << "Digite o valor do id do produto a ser excluido: ";
                cin >> id;
                produto.ExcluirProduto(id);
                break;
            }
            case 4: {
                produto.MostraProdutos();
                break;
            }
            case 5: {
                cout << "Histórico de Transações:" << endl;
                historico.mostrarHistorico();
                break; 
            }
            case 6: {
                int idProduto;
                cout << "Digite o ID do produto para visualizar o histórico: " << endl;
                cin >> idProduto;
                
                cout << "Histórico de para o Produto ID " << idProduto << ":" << endl;
                historico.mostrarHistoricoProduto(idProduto);
                break; 
            }
            case 7: {
                //implementar relatorio de vendas
            }
            case 8: {
                cout << "Saindo do programa. Obrigado por utilizar nosso sistema!" << endl;
                break; 
            }
            default: {
                cout << "Opção inválida. Tente novamente" << endl;
                break;
            }
        }
        if(opcao == 8)
            break;
    } while(opcao != 7);

    return 0;
}
