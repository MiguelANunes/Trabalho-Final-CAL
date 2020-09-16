# https://opensource.com/article/18/8/what-how-makefile
# https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html#Overall-Options
# https://www.cs.colostate.edu/~cs157/LectureMakefile.pdf
# http://story-of-a-programmer.blogspot.com/2015/04/makefile-tutorial.html <- Melhor


# To Do: Criar comandos para as funções específicas
# Isto é, um comando para: calcular as chaves, criptografar, descriptografar, tentar o brute-force e um geral

CC = g++   # compilador 

all: link # mudar

run: 
	./main

link: main
	${CC} -o main chaves.o cripto.o bruta.o main.o -lgmpxx -lgmp

main: chaves cripto bruta  main.cpp
	${CC} -Wall main.cpp -c

chaves:
	${CC} -c chaves.cpp  

cripto:
	${CC} -Wall cripto.cpp -c

bruta:
	${CC} -Wall bruta.cpp -c 

clean:
	rm *.o
	rm main
