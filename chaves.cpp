#include"chaves.h"

// struct CustomCompare {
//     bool operator()(const mpz_t lhs, const mpz_t rhs) {
//         if(mpz_cmp(lhs,rhs) >= 0){
//             return true;
//         }else{
//             return false;
//         }
//     }
// };

// geração das chaves publica e privada

// primo relativo
// algoritmo de euclides estendido
// primos aleatorios
// verificação probabilistica de primalidade
// inverso modular

void primo_aleatorio(mpz_t resultado, int total_bits){ 
    // retorna um número primo aleatório com <total_bits> bits

    gmp_randstate_t estado; // estado aleatório necessário para gerar números aleatórios
    mpz_t primo;

    mpz_init2(primo,total_bits); // inicializando a variável, como recomendado pelo manual da biblioteca
    gmp_randinit_default(estado); // inicializando o estado aleatório

    gmp_randseed_ui(estado,time(NULL)); // define a seed do gerador aleatório
    for(int i = 0; i < 10; i++){
        mpz_urandomb(primo,estado,total_bits); // gera um número aleatório de até <total_bits> bits

    // cout << "entrou no loop" << endl;
        while(provavelmente_primo(primo, estado, total_bits)){
            // cout << "falhou um teste" << endl;
            if(mpz_even_p(primo) != 0){ // verifica se o número é par
                mpz_add_ui(primo,primo,1);
            }

            else{
                mpz_add_ui(primo,primo,2);
                // cout << "somou 2" << endl;
            }
            
        }
        mpz_out_str(NULL,10,primo);
        cout << endl;
    }

    mpz_set(resultado,primo); // atribuindo o número gerado ao resultado da função
    mpz_clear(primo); // limpando a variável, como recomendado pelo manual
    gmp_randclear(estado);
    // todas as variáveis de tipo mpz são passadas para funções como referência automátiamente
    // logo, não é necessário retorno
}

// função para verificar a primalidade de um número de maneira probabilistica
bool provavelmente_primo(mpz_t possivel_primo, gmp_randstate_t estado_aleatorio, int total_bits){
    // verificar se não gerou 1 ou 2
    // cout << "entou na função de verificação" << endl;

    if(mpz_even_p(possivel_primo) != 0){
        // cout << "saiu um certamente não primo" << endl;
        return true;
    }

    mpz_t multiplo_testado;
    mpz_t raiz;
    // priority_queue<mpz_t, vector<mpz_t>, CustomCompare> multiplos_testados;
    mpz_init2(multiplo_testado,total_bits);
    mpz_init2(raiz,total_bits);

    for(int i = 0; i < 10; i++){ // i repetições de ...
        for(int j = 0; j < 2000; j++){ // mil testes

            mpz_sqrt(raiz,possivel_primo);
            mpz_urandomm(multiplo_testado, estado_aleatorio, raiz);
            // gera um número aleatório entre 0 e a (raiz quadrada de possivel_primo, arredondada p/ baixo)-1

            // if(){ // verificar se o multiplo selecionado já foi testado
            //     continue;
            // }

            if(mpz_divisible_p(possivel_primo, multiplo_testado) != 0 && (mpz_cmp_ui(multiplo_testado, 1) != 0)){
                // cout << "saiu um certamente não primo" << endl;
                return true; // foi encontrado um número que divide o primo que esta sendo testado e este não é 1
            }
            // multiplos_testados.push(multiplo_testado);
        }
    }
    // cout << "saiu um possível primo" << endl;
    return false; // não foi encontrado nenhum divisor
}

// bool busca_binaria(priority_queue<mpz_t, vector<mpz_t>, CustomCompare> min_heap, mpz_t termo_procurado, int index){
//     if(min_heap[index] == )
// }

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
