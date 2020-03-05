CC = gcc -fopenmp
### Makefile ###

objects = clientes.o produtos.o faturacao.o



CFLAGS = -Wall -O2

all:
			make clean
			make produtos
			make clientes
			make faturacao
			make main

main: main.c clientes.o produtos.o faturacao.o
		gcc main.c clientes.o produtos.o faturacao.o $(CFLAGS) -o prog

clientes: clientes.c headers/clientes.h
		gcc clientes.c -c $(CFLAGS)

produtos: produtos.c headers/produtos.h
		gcc produtos.c -c $(CFLAGS)

faturacao: faturacao.c headers/faturacao.h
		gcc faturacao.c -c $(CFLAGS)



clean : 
	rm -f prog
	rm -f $(objects)
	rm -f gesval
