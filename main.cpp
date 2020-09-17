#include"main_header.h"
#include"chaves.h"
#include"cripto.h"
#include"bruta.h"

using namespace std;
/*
####################
Ideias:
    Definir a variável de total de bits como global ?
####################
*/
int main(int argc, char const *argv[]){
    if(argc == 2){
        TOTALBITS = atoi(argv[1]);
    }else{
        cout << "Digite o total de bits:" << endl;
        cin >> TOTALBITS;
    }
    mpz_t teste;
    mpz_init2(teste,TOTALBITS);
    primo_aleatorio(teste);
    

    return 0;
}
