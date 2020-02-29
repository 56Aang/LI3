CC = gcc -fopenmp
CFLAGS = -Wall -g

main : main.o clientes.o produtos.o vendas.o

clientes.o : clientes.c clientes.h

produtos.o : produtos.c produtos.h

vendas.o : vendas.c vendas.h

main.o : main.c

clean : 
	rm *.o
