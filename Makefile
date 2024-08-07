all: build/Produto.o build/GerenciamentoDeProduto.o build/Busca.o build/HistoricoDeTransacao.o build/RelatorioVenda.o build/main.o
	g++ build/Produto.o build/GerenciamentoDeProduto.o build/Busca.o build/HistoricoDeTransacao.o build/RelatorioVenda.o build/main.o -o executar

build/Produto.o: src/Entidades/Produto.cpp includes/Produto.h 
	g++ src/Entidades/Produto.cpp -c -I include -o build/Produto.o

build/GerenciamentoDeProduto.o: src/Entidades/GerenciamentoDeProduto.cpp includes/Produto.h includes/GerenciamentoDeProduto.h
	g++ src/Entidades/GerenciamentoDeProduto.cpp -c -I include -o build/GerenciamentoDeProduto.o

build/Busca.o: src/Entidades/Busca.cpp includes/Produto.h includes/GerenciamentoDeProduto.h includes/Busca.h
	g++ src/Entidades/Busca.cpp -c -I include -o build/Busca.o

build/HistoricoDeTransacao: src/Entidades/HistoricoDeTransacao.cpp includes/Produto.h includes/HistoricoDeTransacao.hpp 
	g++ src/Entidades/HistoricoDeTransacao.cpp -c -I include -o build/HistoricoDeTransacao.o

build/RelatorioVenda.o: src/Entidades/RelatorioVenda.cpp includes/Produto.h includes/GerenciamentoDeProduto.h includes/RelatorioVenda.h
	g++ src/Entidades/RelatorioVenda.cpp -c -I include -o build/RelatorioVenda.o

build/main.o: src/main.cpp
	g++ src/main.cpp -c -I include -o build/main.o





