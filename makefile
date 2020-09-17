# https://opensource.com/article/18/8/what-how-makefile
# https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html#Overall-Options
# https://www.cs.colostate.edu/~cs157/LectureMakefile.pdf
# http://story-of-a-programmer.blogspot.com/2015/04/makefile-tutorial.html <- Melhor


# To Do: Criar comandos para as funções específicas
# Isto é, um comando para: calcular as chaves, criptografar, descriptografar, tentar o brute-force e um geral

CC = g++   # compilador 
FLAGS = -Wall -c

all: link # mudar

run: 
	./main

link: main
	${CC} -o main chaves.o cripto.o bruta.o main.o -lgmpxx -lgmp

main: chaves cripto bruta  main.cpp
	${CC} ${FLAGS} main.cpp

chaves:
	${CC} ${FLAGS} chaves.cpp  

cripto:
	${CC} ${FLAGS} cripto.cpp 

bruta:
	${CC} ${FLAGS} bruta.cpp

clean:
	rm *.o main 
 
