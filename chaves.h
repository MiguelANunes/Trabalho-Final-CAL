#pragma once
#include"main_header.h"
#include<time.h>
#include<utility>

using namespace std;

pair<mpz_t, mpz_t> chave_publica(void);
void primo_aleatorio(mpz_t resultado); // manual estabelece essa convenção para parametros
bool provavelmente_primo(mpz_t possivel_primo, gmp_randstate_t estado_aleatorio);
void primo_relativo(mpz_t resultado, mpz_t primo1, mpz_t primo2);