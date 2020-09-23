#include"bruta.h"
#include"chaves.h"
// fatora por força bruta as chaves

void fun3(){ // não foi usada, pode apagar (?)
    cout << "ddd";
}
//MAIN UTILIZADO PARA TESTES: (pode apagar dps) https://medium.com/swlh/the-prime-number-test-a-brute-force-approach-a25b9d6b231
/*
#include"main_header.h"
#include"chaves.h"
#include"cripto.h"
#include"bruta.h"


using namespace std;

int main(int argc, char const *argv[]){
//    cout << "aaa" << endl;
    //cout << "totalbits = " << TOTALBITS << endl;
    TOTALBITS = 64;
    cout << "totalbits = " << TOTALBITS << endl;

    mpz_t x;
    //cout << "x = " << x << endl;
    primo_aleatorio(x);
    cout << "x = " << x << endl;

    //mpz_set_si(x,7832112136286693); // usado pra testar um numero especifico 
    cout << "\nusando forcabruta:" << endl;
    cout << x;
    if(forcabruta(x) == true)
        cout << " e primo" << endl;
    else
        cout << " nao e primo" << endl;

    cout << "-----------------" << endl;
    cout << "usando forcabruta_ruim:" << endl;
    cout << x; 
    if (forcabruta_ruim(x) == true)
        cout << " e primo" << endl;
    else
        cout << " nao e primo" << endl;
    
    

    return 0;
}
*/

bool forcabruta(mpz_t possivelPrimo){ // checa de 3 até a raiz do número
    if(mpz_cmp_si (possivelPrimo, 0) < 0){ // caso possivelPrimo < 0, retorna false
        return false;
    }
    if(mpz_cmp_si (possivelPrimo, 3) < 0 || mpz_cmp_si (possivelPrimo, 3) == 0 ){ // caso possivelPrimo <= 3, retorna true
        return true;
    }

    mpz_t r;
    mpz_init2(r, TOTALBITS);
    mpz_mod_ui(r, possivelPrimo, 2);

    if(mpz_cmp_si(r, 0)==0){
        return false;
    }
    
    mpz_t q, i, resto;
    mpz_init2(q, TOTALBITS); 
    mpz_init2(i, TOTALBITS);
    mpz_init2(r, TOTALBITS);
    mpz_init2(resto, TOTALBITS);
    mpz_set_si(i, 3); // i=3
    mpz_sqrt(q,possivelPrimo); // q = sqrt(possivelPrimo)

    int condicaofor; //para ser utilizado para adquirir o parâmetro a ser usado na função for
    bool continua;   //parametro de parada do for
    condicaofor = mpz_cmp (i, q);   // retorna 1 se i>q
                                    // retorna 0 se i==q
                                    // retorna -1 se i<q

    if(condicaofor < 0)
        continua = true;
    if(condicaofor == 0)
        continua = false;
    if(condicaofor > 0)
        continua = false;

    for( ; continua; mpz_add_ui(i, i, 1)){ // for( ; i<sqrt(possivelPrimo); i = i + 1)
        mpz_cdiv_r(resto,possivelPrimo, i); // resto da divisão de possivelPrimo por i
        if(mpz_cmp_si(resto, 0)==0) //if(possivelPrimo % i == 0)
            return false;

        condicaofor = mpz_cmp (i, q);
        if(condicaofor < 0)
            continua = true;
        if(condicaofor == 0)
            continua = false;
        if(condicaofor > 0)
            continua = false;   
    }

    return true;
}





bool forcabruta_ruim(mpz_t possivelPrimo){
    if(mpz_cmp_si (possivelPrimo, 0) < 0){ // caso possivelPrimo < 0, retorna false
        return false;
    }
    if(mpz_cmp_si (possivelPrimo, 3) < 0 || mpz_cmp_si (possivelPrimo, 3) == 0 ){ // caso possivelPrimo <= 3, retorna true
        return true;
    }

    mpz_t r;
    mpz_init2(r, TOTALBITS);
    mpz_mod_ui(r, possivelPrimo, 2);

    if(mpz_cmp_si(r, 0)==0){
        return false;
    }
    
    mpz_t q, i, resto;
    mpz_init2(q, TOTALBITS);
    mpz_init2(i, TOTALBITS);
    mpz_init2(r, TOTALBITS);
    mpz_init2(resto, TOTALBITS);
    mpz_set_si(i, 3); // i=3
    mpz_cdiv_q_ui(q,possivelPrimo,2); // q=possivelPrimo/2

//cout << "x = " << possivelPrimo << endl;
//cout << "q = " << q << endl;
//cout << "i = " << i << endl;

    int condicaofor;//para ser utilizado para adquirir o parâmetro a ser usado na função for
    bool continua; //parametro de parada do for
    condicaofor = mpz_cmp (i, q);   // retorna 1 se i>q
                                    // retorna 0 se i==q
                                    // retorna -1 se i<q
                                    
//cout << "condicaofor = " << condicaofor << endl;

    if(condicaofor < 0)
        continua = true;
    if(condicaofor == 0)
        continua = false;
    if(condicaofor > 0)
        continua = false;

    for( ; continua; mpz_add_ui(i, i, 1)){ // for( ; i<possivelPrimo/2; i = i + 1)

//cout << "for = " << i << endl;
//cout << "entrou no for" << endl;
        mpz_cdiv_r(resto,possivelPrimo, i);// resto da divisão de possivelPrimo por i
//cout << "resto = " << resto << endl;
        if(mpz_cmp_si(resto, 0)==0) //if(possivelPrimo % i == 0)
            return false;
            
//cout << "teste 1 " << endl;
        condicaofor = mpz_cmp (i, q);
        if(condicaofor < 0)
            continua = true;
        if(condicaofor == 0)
            continua = false;
        if(condicaofor > 0)
            continua = false;   
//cout << "condicaofor = " << condicaofor << endl;   
    }
    return true;
}

