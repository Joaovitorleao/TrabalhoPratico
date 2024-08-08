# SISTEMA DE GERENCIAMENTO DE ESTOQUE

# User stories

Como gerente de loja, eu quero adicionar, excluir e alterar produtos no estoque, para mantê-lo
organizado e correto.

Como funcionário da loja, eu quero adicionar entradas e saídas de itens, para manter as quantidades
de itens corretas e nunca haver faltas.

Como funcionário da loja, eu quero buscar produtos por nome, preço e ID, para encontrar produtos
rapidamente para clientes.

Como gerente da loja, eu quero alterar os valores de compra e venda dos itens quando necessário,
para que os valores fiquem corrigidos, minimizar os prejuízos e maximizar os lucros.

Como gerente de loja, eu quero gerar relatórios de vendas e estatísticas, para analisar o desempenho
das vendas e tomar decisões assertivas.

Como gerente da loja, eu quero acessar o histórico de vendas e calcular lucros, para manter o
controle financeiro da loja.

Como gerente da loja, eu quero acessar o histórico de transação do estoque, para verificar a
integridade das movimentações de estoque.

# Cartões CRC

![Imagem 1 - Cartões CRC](<Cartões CRC's (Atualizados).png>)

# Descrição do projeto e aplicação

Gerenciar e organizar um estoque de uma loja de forma eficiente, é uma tarefa difícil, uma vez que
demanda de múltiplos fatores que influenciam diretamente no funcionamento organizacional do
empreendimento. O controle inadequado do estoque pode levar a problemas como falta de
produtos, excesso de estoque, e dificuldades na tomada de decisões estratégicas. Este projeto se
propõe a resolver esses problemas fornecendo um sistema de gerenciamento de estoque que facilita
o controle e a visualização dos produtos disponíveis na loja.

Este projeto é um sistema de gerenciamento de estoque para uma loja. O sistema oferece
funcionalidades para adicionar, excluir e alterar produtos, buscar e filtrar produtos, gerar relatórios
de vendas e estatísticas, acessar o histórico de vendas e calcular lucros, e registrar transações do
estoque.

A interface principal do sistema é composta por cinco módulos:
1. Manipulação do produto: adicionar, excluir e alterar produtos no estoque.
2. Gerenciamento de quantidade de produtos: indicar entradas, saídas.
3. Busca: buscar produtos por nome, e conseguir visualizar preço de compra, preço de venda, ID e quantidade de itens do produto no estoque, além de conseguir ver essas informações de todos os produtos de uma só vez.
4. Relatório e estatística de venda: gerar relatórios e estatísticas, de vendas, lucros e despesas.
5. Histórico de transação: registrar transações do estoque.

# Estrutura do projeto

O projeto é organizado da seguinte forma:\
/projeto-gerenciamento-estoque \
│\
├── /src/\
│├── /Entidades/\
││├── Produto.cpp\
││├── GerenciamentoDeProduto.cpp\
││├── Busca.cpp\
││├── RelatorioVenda.cpp\
││├── HistoricoDeTransacao.cpp\
│├── main.cpp\
│\
├── /include/\
│├── Produto.hpp\
│├── GerenciamentoDeProduto.hpp\
│├── Busca.hpp\
│├── RelatorioVenda.hpp\
│├── HistoricoDeTransacao.hpp\
│\
├── /build/\
│├── Produto.o\
│├── GerenciamentoDeProduto.o\
│├── Busca.o\
│├── RelatorioVenda.o\
│├── HistoricoDeTransacao.o\
│├── main.o\
├── executar.exe\
├── Makefile\
├── README.md\
│\

# Instruções de instalação e uso

Clone o repositório do projeto em um arquivo pessoal;\
Disponível em: https://github.com/Joaovitorleao/TrabalhoPratico.git ;\
Navegue até o diretório do projeto;\
Compile o código, com o comando "make";\
Execute o programa, dando o comando "./executar";\
Selecione qual será a ação que se deseja realizar;

Ao executar o programa, você terá acesso às funcionalidades:

1. Adicionar produto:
- Adicionar um produto no estoque, com nome, preço de compra, preço de venda e um ID será gerado para ele automaticamente.
2. Editar produto:
- Editar um produto existente no estoque, podendo ser nome, preço de compra e/ou preço de venda.
3. Excluir produto:
- Exclui um produto do estoque.
4. Adicionar quantidade de itens ao estoque:
- Adiciona unidades de itens do produto ao estoque.
5. Remover quantidade de itens do estoque:
- Remove unidades de itens do produto do estoque.
6. Mostrar todos os produtos:
- Imprime todos os produtos.
7. Histórico de transações:
- Imprime todas as transações realizadas no estoque.
8. Histórico de produtos:
-Imprime o histórico do produto dado o seu ID.
9. Relatorio de vendas:
- Imprime o relatório de vendas.
10. Pesquisar produto:
- Pesquisa o produto pelo seu nome e retorna seu ID, valor de compra, valor de venda e a quantidade de itens no estoque.
11. Sair:
- Encerra o programa.

# Principais dificuldades

Durante o desenvolvimento do projeto, algumas dificuldades foram encontradas, tais como:

1. Desafios técnicos:
- Implementação de uma estrutura eficiente para armazenar e acessar rapidamente as
informações do produto;
- Garantir que as operações de busca sejam rápidas e precisas.

2. Obstáculos de design:
- Definir uma arquitetura de classe e fácil de manter;
- Integrar os diferentes módulos do sistema de forma coesa.

3. Integração:
- Assegurar que as alterações no gerenciamento de produtos estão refletidas corretamente nos
relatórios e históricos;
- Garantir a integridade dos dados durante as operações de transação de estoque.

4. Gerenciamento de Conflitos:
- Lidar com conflitos ao integrar contribuições de diferentes membros da equipe no 
repositório de código;
- Assegurar que as mudanças feitas em uma parte do código não afetem negativamente 
outras partes do sistema.

# Desenvolvedores

João Vitor Araújo Leão;\
Luís Fernando Farias;\
Miguel Dias Andrade;\
Pedro Henrique Mendonça Almeida Magalhães;\
Vinicius Santos Rodrigues.
