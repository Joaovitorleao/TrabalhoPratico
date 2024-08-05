all: build/Produto.o build/GerenciamentoDeProduto.o build/Busca.o build/HistoricoDeTransacao.o build/RelatorioVenda.o build/main.o
	g++ build/Produto.o build/GerenciamentoDeProduto.o build/Busca.o build/HistoricoDeTransacao build/RelatorioVenda.o build/main.o -o executar

build/main.o: src/main.cpp
	g++ src/main.cpp -c -I include -o build/main.o

build/Produto.o: src/entidades/Produto.cpp include/Produto.h 
	g++ src/entidades/Produto.cpp -c -I include -o build/Produto.o

build/GerenciamentoDeProduto.o: src/entidades/GerenciamentoDeProduto.cpp include/Produto.h include/GerenciamentoDeProduto.h
	g++ src/entidades/GerenciamentoDeProduto.cpp -c -I include -o build/GerenciamentoDeProduto.o

build/Busca.o: src/entidades/Busca.cpp include/Produto.h include/GerenciamentoDeProduto.h include/Busca.h
	g++ src/entidades/Busca.cpp -c -I include -o build/Busca.o

build/HistoricoDeTransacao: src/entidades/HistoricoDeTransacao.cpp include/Produto.h include/HistoricoDeTransacao.hpp 
	g++ src/entidades/HistoricoDeTransacao.cpp -c -I include -o build/HistoricoDeTransacao.o

build/RelatorioVenda.o: //Esperando implementação da class




