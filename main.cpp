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
int main(int argc, char const *argv[]){ // arrumar, ver aula 31/08
    if(argc == 3){
		TOTALBITS = atoi(argv[1]);
    }else if(argc == 2){
		TOTALBITS = atoi(argv[1]);
	}else{
        cout << "Digite o número de bits:" << endl;
        cin >> TOTALBITS;
    }
    
	string Filename;
    mpz_t E, N, D, PQ;//, inverso;
    mpz_init2(E,TOTALBITS);
    mpz_init2(N,TOTALBITS);
    mpz_init2(D,TOTALBITS);
	mpz_init2(PQ, TOTALBITS);
	//mpz_init2(inverso, TOTALBITS);

	Filename = "file.txt";

    chave_publica(E,N,PQ); // chave publica = <E,N>
    chave_privada(D,E,PQ); // chave privada = <D,N>

	//if(mpz_invert(inverso, E, PQ) != 0){
	//	gmp_printf("Inverso Modular de E: %Zd\n",inverso);	
	//}
	//if(mpz_invert(inverso, D, PQ) != 0){
	//	gmp_printf("Inverso Modular de D: %Zd\n",inverso);	
	//} 
	// sanity check

	gmp_printf("Chave Pública (E,N): <%Zd, %Zd>\n",E,N);
	gmp_printf("Chave Privada (D,N): <%Zd, %Zd>\n",D,N);
	gmp_printf("(P-1)(Q-1): %Zd\n",PQ);

	criptografar_arquivo(E,N,Filename);
	descriptografar_arquivo(D,N,Filename);

    return 0;
}
