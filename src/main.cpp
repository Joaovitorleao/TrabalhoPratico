#include "../includes/Busca.h"
#include "../includes/GerenciamentoDeProduto.h"
#include "../includes/Produto.h"
#include "../includes/RelatorioVenda.h"
#include "../includes/HistoricoDeTransacao.hpp"

#include <iostream>
#include <string>

using namespace std;

void Menu() {
    cout << "====== Menu de gerenciamento de estoque ======" << endl;
    cout << "1. Adicionar produto" << endl;
    cout << "2. Editar produto" << endl;
    cout << "3. Excluir produto" << endl;
    cout << "4. Adicionar quantidade de itens ao estoque" << endl;
    cout << "5. Remover quantidade de itens do estoque" << endl;
    cout << "6. Mostrar todos os produtos" << endl;
    cout << "7. Histórico de transações" << endl;
    cout << "8. Histórico de produtos" << endl;
    cout << "9. Relatorio de vendas" << endl;
    cout << "10. Sair" << endl;
    cout << endl << "Escolha uma opção: ";
}

int main(){
    Produto produto;
    GerenciamentoDeProduto gerenciamento(produto);
    Busca busca(produto);
    HistoricoDeTransacao historico;
    RelatorioVenda relatorio(gerenciamento);
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
                string nome;
                int quantidade;
                cout << "Digite o nome do produto: ";
                cin >> nome;
                while (true) {
                    cout << "Digite a quantidade de itens para adicionar ao estoque: ";
                    cin >> quantidade;
                    if (quantidade > 0) {
                        gerenciamento.AdicionarEstoque(nome, quantidade);
                        break;
                        } else {
                        cout << "Quantidade inválida! Por favor, digite um número maior que zero." << endl;
                        }
                    }
                break;
            }
            case 5: {
                string nome;
                int quantidade;
                cout << "Digite o nome do produto: ";
                cin >> nome;
                while (true) {
                    cout << "Digite a quantidade de itens para remover do estoque: ";
                    cin >> quantidade;
                    if (quantidade > 0) {
                        gerenciamento.RemoverEstoque(nome, quantidade);
                        break;
                        } else {
                        cout << "Quantidade inválida! Por favor, digite um número maior que zero." << endl;
                        }
                    }
                break;
            }
            case 6: {
                busca.MostraProdutos();
                break;
            }
            case 7: {
                cout << "Histórico de Transações:" << endl;
                historico.mostrarHistorico();
                break; 
            }
            case 8: {
                int idProduto;
                cout << "Digite o ID do produto para visualizar o histórico: " << endl;
                cin >> idProduto;
                
                cout << "Histórico de para o Produto ID " << idProduto << ":" << endl;
                historico.mostrarHistoricoProduto(idProduto);
                break; 
            }
            case 9: {
                cout << "Relatório de Vendas:" << endl;
                relatorio.getDespesas();
                relatorio.getLucro();
                relatorio.getProdutoMaisVendido();
                relatorio.getQuantidadeMaisVendido();
                relatorio.getProdutoMenosVendido();
                relatorio.getQuantidadeMenosVendido();
            }
            case 10: {
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
