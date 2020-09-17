#include<iostream>
#include<time.h>
#include<stdio.h> // necessário p/ IO de números da GMP
#include<gmp.h>
#include<vector>
#include<queue>


using namespace std;

// void fun1(void);
void primo_aleatorio(mpz_t resultado, int total_bits); // manual estabelece essa convenção para parametros
bool provavelmente_primo(mpz_t possivel_primo, gmp_randstate_t estado_aleatorio, int total_bits);
// bool busca_binaria(priority_queue<mpz_t, vector<mpz_t>, CustomCompare> max_heap, mpz_t termo_procurado, int index);