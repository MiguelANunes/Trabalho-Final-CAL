#include<iostream>
#include<time.h>
#include<stdio.h> // necessário p/ IO de números da GMP
#include<gmp.h>

using namespace std;

// void fun1(void);
void primo_aleatorio(mpz_t resultado, int total_bits); // manual estabelece essa convenção para parametros
bool primo_probabilistico(mpz_t possivel_primo);