#include"chaves.h"
// geração das chaves publica e privada

// primo relativo
// algoritmo de euclides estendido
// primos aleatorios
// verificação probabilistica de primalidade
// inverso modular

void primo_aleatorio(mpz_t resultado){ 
    // retorna um número primo aleatório de tamanho
    gmp_randstate_t estado; // estado aleatório necessário para gerar números aleatórios
    mpz_t primo; // ver no manual sobre alocação de tamanho específico (sec. 5.6 acho)

    mpz_init(primo); // inicializando a variável, como recomendado pelo manual da biblioteca
    gmp_randinit_default(estado); // inicializando o estado aleatório


    // para geração de números, usar o método do Cristiano

    mpz_set(resultado,primo); // atribuição
    mpz_clear(primo); // limpando a variável, como recomendado pelo manual
    gmp_randclear(estado);
}

// função para verificar a primalidade de um número de maneira probabilistica
bool primo_probabilistico(mpz_t possivel_primo){
    return true;
}

// ideia: gerar 10 números aleatórios entre 3 e sqrt(número gerado) e testar se são divisores deste número 100 vezes
// onde após cada teste, os números gerados são colocados numa lista e ao gerar novos números, são comparados aos que
// estão na lista para evitar repetições.
// se nenhum deles for, fazer isso de novo, novamente comparando com os números que já foram gerados
    // sub-ideia: colocar os números gerados num heap, quando for verificar por repetições
    // para verificar, basta procurar pelo heap, que é mais eficiente que procurar por um array/lista
    // construir um (max/min)-heap leva tempo linear, o que é mais eficiente que qualquer algoritmo de busca em um array/lista
    // buscar num (max/min)-heap tbm é linear tbm
// se ainda assim não achar nenhum divisor, assumir que esse número gerado é primo
// fazer um contador para o total de vezes que um número gerado repete, se ultrapassar algum limite a definir (100 ?) consideramos
// que todos os possíveis divisores do número já foram testados e ele é tomado como um primo.
