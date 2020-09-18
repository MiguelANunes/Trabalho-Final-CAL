#include"main_header.h"
#include"chaves.h"
#include"cripto.h"
#include"bruta.h"

using namespace std;
/*
####################
Ideias:
    
####################
*/
int main(int argc, char const *argv[]){
    if(argc == 2){
        TOTALBITS = atoi(argv[1]);
    }else{
        cout << "Digite o total de bits:" << endl;
        cin >> TOTALBITS;
    }
    
    mpz_t E, N, D;
    mpz_init2(E,TOTALBITS);
    mpz_init2(N,TOTALBITS);
    mpz_init2(D,TOTALBITS);

    chave_publica(E,N);
    // chave_privada(E,N,D);

    return 0;
}
