// header "geral" p/ ser incluso em todos os outros arquivos
#pragma once
#include<stdio.h> // necessário p/ IO de números da GMP
#include<gmp.h>
#include<iostream> // para fins de debugging

extern int TOTALBITS; 
// "constante" que determina o tamnho de bits para serem usados durante a execução
// não é do tipo const pq é necessário definir esse valor dentro da main