#pragma once
#include"main_header.h"
using namespace std;

void fun3(void); // não foi usada, pode apagar (?)

bool forcabruta(mpz_t possivelPrimo);   // checa de 3 até a raiz do número
                                        // retorna true se for primo
                                        // retorna false se nao for primo

bool forcabruta_ruim(mpz_t possivelPrimo);  // checa de 3 até a metade do número
                                            // retorna true se for primo
                                            // retorna false se nao for primo
