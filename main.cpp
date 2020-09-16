#include<gmp.h>
#include<iostream>
#include<stdlib.h>
#include"chaves.h"
#include"cripto.h"
#include"bruta.h"

using namespace std;

int main(int argc, char const *argv[]){
    // cout << "aaa";
    // fun2();
    // fun3();

    mpz_t teste;

    mpz_init2(teste,128); // inicializando a variável, como recomendado pelo manual da biblioteca
    primo_aleatorio(teste,128);

    cout << endl;
    return 0;
}
