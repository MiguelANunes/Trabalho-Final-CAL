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
    
    mpz_t E, N, D, PQ;
    mpz_init2(E,TOTALBITS);
    mpz_init2(N,TOTALBITS);
    mpz_init2(D,TOTALBITS);
	mpz_init2(PQ, TOTALBITS);

    chave_publica(E,N,PQ);
    chave_privada(D,E,PQ);

	// chave publica = <E,N>
	// chave privada = <D,N>

    return 0;
}
