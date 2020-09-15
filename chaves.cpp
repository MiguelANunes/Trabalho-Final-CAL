#include"chaves.h"
// geração das chaves publica e privada

// primo relativo
// algoritmo de euclides estendido
// primos aleatorios
// verificação probabilistica de primalidade
// inverso modular

void fun1(){
    cout << "bbb";
}

// função para gerar números primos aleatórios

// função para verificar a primalidade de um número de maneira probabilistica
// ideia: gerar 100 números aleatórios entre 3 e sqrt(número gerado) e testar se são divisores deste número
// se nenhum deles for, repetir com mais 100 números, diferentes dos 100 originais
    // sub-ideia: colocar os 100 números gerados na primeira iteração num heap, quando for verificar
    // na segunda repetição, basta procurar pelo heap, que é mais eficiente que procurar por um array/lista
    // construir um (max/min)-heap leva tempo linear, o que é mais eficiente que qualquer algoritmo de busca em um array/lista
    // buscar num (max/min)-heap tbm é (log n) (confirmar)
// se ainda assim não achar nenhum divisor, assumir que esse número gerado é primo