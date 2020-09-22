#pragma once
#include"main_header.h"
#include<time.h>
#include<utility>
#include<vector>

using namespace std;

void chave_publica(mpz_t E, mpz_t N, mpz_t PQ);
void chave_privada(mpz_t D, mpz_t E, mpz_t PQ);
void primo_aleatorio(mpz_t resultado);
bool provavelmente_primo(mpz_t possivel_primo, gmp_randstate_t estado_aleatorio);
void primo_relativo(mpz_t resultado, mpz_t primo1, mpz_t primo2);
void inverso_modular(mpz_t D, mpz_t E, mpz_t PQ);