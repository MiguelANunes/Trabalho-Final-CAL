# https://opensource.com/article/18/8/what-how-makefile
# https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html#Overall-Options
# https://www.cs.colostate.edu/~cs157/LectureMakefile.pdf
# http://story-of-a-programmer.blogspot.com/2015/04/makefile-tutorial.html <- Melhor


# To Do: Criar comandos para as funções específicas
# Isto é, um comando para: calcular as chaves, criptografar, descriptografar, tentar o brute-force e um geral

CC = g++   # compilador 

all: link

run: 
	./main

main: chaves cripto bruta  main.cpp
	${CC} main.cpp -c -lgmpxx -lgmp 

chaves:
	${CC} chaves.cpp -c -lgmpxx -lgmp

cripto:
	${CC} cripto.cpp -c -lgmpxx -lgmp

bruta:
	${CC} bruta.cpp -c -lgmpxx -lgmp

link: main
	${CC} -o main chaves.o cripto.o bruta.o main.o

clean:
	rm *.o
	rm main
