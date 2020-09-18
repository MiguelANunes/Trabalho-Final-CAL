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

void chave_publica(mpz_t E, mpz_t N){
    mpz_t PrimeiroPrimo, SegundoPrimo, ProdutoPrimos, PrimoRelativoProduto;

    mpz_init2(PrimeiroPrimo, TOTALBITS); // P
    mpz_init2(SegundoPrimo, TOTALBITS); // Q
    mpz_init2(ProdutoPrimos, TOTALBITS); // N

    primo_aleatorio(PrimeiroPrimo);
    primo_aleatorio(SegundoPrimo);
    mpz_mul(ProdutoPrimos, PrimeiroPrimo, SegundoPrimo); // N = P*Q
    primo_relativo(PrimoRelativoProduto, PrimeiroPrimo, SegundoPrimo); // E

    mpz_set(E,PrimoRelativoProduto);
    mpz_set(N,ProdutoPrimos);
}

void chave_privada(mpz_t E, mpz_t N, mpz_t D){

}

void primo_relativo(mpz_t Resultado, mpz_t PrimeiroPrimo, mpz_t SegundoPrimo){
    // calcula um primo relativo de (PrimeiroPrimo-1)(SegundoPrimo-1)
    mpz_t Primo1, Primo2, PR, MDC, E;
    gmp_randstate_t Estado;

    gmp_randinit_default(Estado);
    mpz_init2(Primo1, TOTALBITS);
    mpz_init2(Primo2, TOTALBITS);
    mpz_init2(PR, TOTALBITS);
    mpz_init2(MDC, TOTALBITS);
    mpz_init2(E, TOTALBITS);
    gmp_randseed_ui(Estado,time(NULL));

    mpz_sub_ui(Primo1,PrimeiroPrimo,1); //  P-1
    mpz_sub_ui(Primo2,SegundoPrimo,1); //  Q-1
    mpz_mul(PR,Primo1,Primo2); // (P-1)(Q-1)
    mpz_urandomm(E,Estado,PR); // Gerando um _e_ aleatório
    mpz_gcd(MDC,E,PR); // Calculando o MDC de e com (P-1)(Q-1)1

    while(mpz_cmp_ui(MDC,1) != 0){ // enquanto o MDC não for 1, procure por outro e
        mpz_urandomm(E,Estado,PR);
        mpz_gcd(MDC,E,PR);
    }

    // cout << "(P-1)(Q-1): " << endl;
    // mpz_out_str(NULL,10,PR);
    // cout << endl << "e: " << endl;
    // mpz_out_str(NULL,10,E);
    // cout << endl;

    mpz_set(Resultado,E);
    gmp_randclear(Estado);
    // mpz_clears(Primo1,Primo2,PR,MDC,E);
}

void primo_aleatorio(mpz_t Resultado){ 
    // retorna um número primo aleatório com <TOTALBITS> bits
    gmp_randstate_t Estado; 
    mpz_t PrimoGerado;

    mpz_init2(PrimoGerado,TOTALBITS); 
    gmp_randinit_default(Estado); 

    gmp_randseed_ui(Estado,time(NULL)); 
    mpz_urandomb(PrimoGerado,Estado,TOTALBITS); 
    // gera um número aleatório de até <TOTALBITS> bits

    while(!(provavelmente_primo(PrimoGerado, Estado)))
        mpz_urandomb(PrimoGerado,Estado,TOTALBITS);

    mpz_set(Resultado,PrimoGerado); 
    mpz_clear(PrimoGerado);
    gmp_randclear(Estado);
}

bool provavelmente_primo(mpz_t PossivelPrimo, gmp_randstate_t EstadoAleatorio){
// verifica a primalidade de um número de maneira probabilistica usando o teste de Fermat

    if(mpz_divisible_ui_p(PossivelPrimo,3) != 0 || mpz_divisible_ui_p(PossivelPrimo,5)  != 0 ||
       mpz_divisible_ui_p(PossivelPrimo,7) != 0 || mpz_divisible_ui_p(PossivelPrimo,11) != 0 || 
       mpz_divisible_ui_p(PossivelPrimo,13)!= 0 || mpz_divisible_ui_p(PossivelPrimo,17) != 0 || 
    mpz_even_p(PossivelPrimo) != 0){
        return false;
    }// verificando se é divisivel por 3, 5, 7, 11, 13, 17 ou se é par

    mpz_t Testemunha, Limite, um;
    mpz_init2(Testemunha,TOTALBITS);
    mpz_init2(Limite,TOTALBITS);
    mpz_init_set_ui(um,1);
    // função de verificar congruência não aceita int's como argumento
    // por causa disso, esse work around é necessário

    for(int i = 0; i < 25000; i++){
        mpz_sub_ui(Limite,PossivelPrimo,1);
        mpz_urandomm(Testemunha, EstadoAleatorio, PossivelPrimo);
        //  gera um número aleatório entre 0 e (PossivelPrimo)-1

        mpz_powm(Testemunha, Testemunha, Limite, PossivelPrimo);
        // se a Testemunha de Fermat não é congruente à 1 (mod PossivelPrimo), então PossivelPrimo não é primo
        if(mpz_congruent_p(Testemunha, um, PossivelPrimo) == 0 && (mpz_cmp_ui(Testemunha, 1) > 0))
            return false; 
    }
    return true; 
}
