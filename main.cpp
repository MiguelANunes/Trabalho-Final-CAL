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
    if(argc == 3){
		TOTALBITS = atoi(argv[1]);
		TOTALARQ = atoi(argv[2]);
    }else if(argc == 2){
		TOTALBITS = atoi(argv[1]);
		cout << "Digite o número de arquivos p/ cifrar:" << endl;
        cin >> TOTALARQ;
	}else{
        cout << "Digite o número de bits:" << endl;
        cin >> TOTALBITS;
		cout << "Digite o número de arquivos p/ cifrar:" << endl;
        cin >> TOTALARQ;
    }
    
    mpz_t E, N, D, PQ;
    mpz_init2(E,TOTALBITS);
    mpz_init2(N,TOTALBITS);
    mpz_init2(D,TOTALBITS);
	mpz_init2(PQ, TOTALBITS);

    chave_publica(E,N,PQ); // chave publica = <E,N>
    chave_privada(D,E,PQ); // chave privada = <D,N>

	gmp_printf("Chave Pública: <%Zd, %Zd>\n",E,N);
	gmp_printf("Chave Privada: <%Zd, %Zd>\n",D,N);
	gmp_printf("(P-1)(Q-1): %Zd\n",PQ);

	criptografar_arquivo(E,N);
	descriptografar_arquivo(D,N);

    return 0;
}
