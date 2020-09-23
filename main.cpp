#include"main_header.h"
#include"chaves.h"
#include"cripto.h"
#include"bruta.h"

using namespace std;

int main(int argc, char const *argv[]){ // arrumar, ver aula 31/08

	TOTALBITS = -1;
	FILENAME = "-";

	if(argc == 3){
		TOTALBITS = atoi(argv[1]);
		FILENAME.assign(argv[2]);
	}else if(argc == 2){
		TOTALBITS = atoi(argv[1]);
	}

	int opcao = 0;
	mpz_t E, N, D, PQ;


	while(true){
		cout << "Selecione a operação: " << endl;
		cout << "\t[1] Gerar Chave Pública " << endl;
		cout << "\t[2] Gerar Chave Privada " << endl;
		cout << "\t[3] Criptografar um Arquivo " << endl;
		cout << "\t[4] Descriptografar um Arquivo " << endl;
		cout << "\t[5] Quebra de Chave por Força Bruta " << endl;
		cout << "\t[6] Sair " << endl;
		cin >> opcao;

		switch(opcao){
			case 1:
				if(TOTALBITS == -1){
					cout << "Digite o número de bits:" << endl;
					cin >> TOTALBITS;
					mpz_init2(E,TOTALBITS);
					mpz_init2(N,TOTALBITS);
					mpz_init2(D,TOTALBITS);
					mpz_init2(PQ, TOTALBITS);
				}
				chave_publica(E,N,PQ); // chave publica = <E,N>
				gmp_printf("Chave Pública (E,N): <%Zd, %Zd>\n",E,N);
			break;

			case 2:
				if(TOTALBITS == -1){
					cout << "Digite o número de bits:" << endl;
					cin >> TOTALBITS;
					mpz_init2(E,TOTALBITS);
					mpz_init2(N,TOTALBITS);
					mpz_init2(D,TOTALBITS);
					mpz_init2(PQ, TOTALBITS);
				}
				if(mpz_cmp_ui(E,0) == 0){
					cout << "Gerando a chave pública..." << endl;
					chave_publica(E,N,PQ); // chave publica = <E,N>
					gmp_printf("Chave Pública (E,N): <%Zd, %Zd>\n",E,N);
				}
				chave_privada(D,E,PQ); // chave privada = <D,N>
				gmp_printf("Chave Privada (D,N): <%Zd, %Zd>\n",D,N);
			break;

			case 3:
				if(FILENAME == "-"){
					cout << "Digite o nome do arquivo sem a extensão .txt:" << endl;
					cin >> FILENAME;
				}
				FILENAME += ".txt";
				cout << "Criptografando arquivo " << FILENAME << " ..." << endl;
				criptografar_arquivo(E,N);
			break;

			case 4:
				cout << "Descriptografando arquivo CRIPTO-" << FILENAME << " ..." << endl;
				descriptografar_arquivo(D,N);
			break;

			case 6:
				return 0;
			break;
		}
	}

	//gmp_printf("(P-1)(Q-1): %Zd\n",PQ);


    return 0;
}
