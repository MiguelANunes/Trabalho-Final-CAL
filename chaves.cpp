#include"chaves.h"
// geração das chaves publica e privada
// primo relativo
// algoritmo de euclides estendido
// primos aleatorios  [ok]
// verificação probabilistica de primalidade [ok]
// inverso modular

int TOTALBITS; // necessário definir aqui tbm pq no header "main_header" a variável esta definida como extern
// isto é, o valor dela é definida em algum lugar e o linker descobre onde é isso
// nesse caso, é definida na main
// para acessar o valor dela em outros arquivos, tenho que declarar essa variável neste arquivo

pair<mpz_t, mpz_t> chave_publica(void){
    mpz_t PrimeiroPrimo, SegundoPrimo, ProdutoPrimos;
    pair<mpz_t, mpz_t> chave;

    mpz_init2(PrimeiroPrimo, TOTALBITS); // P
    mpz_init2(SegundoPrimo, TOTALBITS); // Q
    mpz_init2(ProdutoPrimos, TOTALBITS); // N
    // mpz_init2(primo1menos1, TOTALBITS); // P-1
    // mpz_init2(primo2menos1, TOTALBITS); // Q-1

    primo_aleatorio(PrimeiroPrimo);
    primo_aleatorio(SegundoPrimo);
    mpz_mul(ProdutoPrimos, PrimeiroPrimo, SegundoPrimo); // N = P*Q
    // mpz_sub_ui(primo1menos1,primeiro_primo,1); // Calculando P-1
    // mpz_sub_ui(primo2menos1,segundo_primo,1); // Calculando Q-1



}

void primo_relativo(mpz_t resultado, mpz_t primo1, mpz_t primo2){
    mpz_t primo1menos1, primo2menos1;

    mpz_init2(primo1menos1, TOTALBITS); // P-1
    mpz_init2(primo2menos1, TOTALBITS); // Q-1
}

void primo_aleatorio(mpz_t resultado){ 
    // retorna um número primo aleatório com <TOTALBITS> bits

    gmp_randstate_t estado; // estado aleatório necessário para gerar números aleatórios
    mpz_t primo;

    mpz_init2(primo,TOTALBITS); // inicializando a variável, como recomendado pelo manual da biblioteca
    gmp_randinit_default(estado); // inicializando o estado aleatório

    gmp_randseed_ui(estado,time(NULL)); // define a seed do gerador aleatório
    mpz_urandomb(primo,estado,TOTALBITS); // gera um número aleatório de até <TOTALBITS> bits

    while(!(provavelmente_primo(primo, estado)))
        mpz_urandomb(primo,estado,TOTALBITS);

    mpz_set(resultado,primo); // atribuindo o número gerado ao resultado da função
    mpz_clear(primo); // limpando a variável, como recomendado pelo manual
    gmp_randclear(estado);
    // todas as variáveis de tipo mpz são passadas para funções como referência automátiamente
    // logo, não é necessário retorno
}

// função para verificar a primalidade de um número de maneira probabilistica
bool provavelmente_primo(mpz_t possivel_primo, gmp_randstate_t estado_aleatorio){
    // teste de Fermat

    if(mpz_divisible_ui_p(possivel_primo,3) != 0 || mpz_divisible_ui_p(possivel_primo,5) != 0 ||
    mpz_divisible_ui_p(possivel_primo,7) != 0 || mpz_divisible_ui_p(possivel_primo,11) != 0 || 
    mpz_divisible_ui_p(possivel_primo,13) != 0 || mpz_divisible_ui_p(possivel_primo,17) != 0 || 
    mpz_even_p(possivel_primo) != 0){
        return false;
    }// verificando se é divisivel por 3, 5, 7, 11, 13, 17 ou se é par

    mpz_t testemunha, limite, um;
    mpz_init2(testemunha,TOTALBITS);
    mpz_init2(limite,TOTALBITS);
    mpz_init_set_ui(um,1);
    // função de verificar congruência não aceita int's como argumento
    // por causa disso, esse work around é necessário

    for(int i = 0; i < 25000; i++){
        mpz_sub_ui(limite,possivel_primo,1);
        mpz_urandomm(testemunha, estado_aleatorio, possivel_primo);
        //  gera um número aleatório entre 0 e (possivel_primo)-1

        mpz_powm(testemunha, testemunha, limite, possivel_primo);
        // se a testemunha de Fermat não é congruente à um (mod primo_testado), então primo_testado não é primo
        if(mpz_congruent_p(testemunha, um, possivel_primo) == 0 && (mpz_cmp_ui(testemunha, 1) > 0))
            return false; // foi encontrado um número que divide o primo que esta sendo testado e este não é 1 nem 0
    }
    return true; // não foi encontrado nenhum divisor
}
