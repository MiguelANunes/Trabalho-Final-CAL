#include<gmp.h>
#include<iostream>
#include<stdlib.h>
#include"chaves.h"
#include"cripto.h"
#include"bruta.h"

using namespace std;

int main(int argc, char const *argv[]){
    mpz_t teste;
    int bits;

    bits = 64;
    mpz_init2(teste,bits);

    primo_aleatorio(teste,bits);
    

    return 0;
}
