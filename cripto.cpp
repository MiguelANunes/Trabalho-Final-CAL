// criptografa e descriptografa dados em um arquivo
#include"cripto.h"
#include"chaves.h"

int TOTALARQ;

void criptografar_arquivo(mpz_t E, mpz_t N){
	// os arquivos a serem criptografados deverão ter o nome 
	// criptografarN onde N é um número inteiro >= 0
	// exemplo: criptografar0, criptografar1, criptografar2, ...
	// os arquivo criptografados terão o nome 
	// criptografadoN, onde N é o número do arquivo original
	string SourceFilename, OutFilename, TextoLido;
	fstream ArquivoCifrar;
	ofstream ArquivoCifrado;

	char Letra;
	mpz_t LetraCifrada, Aux;
	mpz_init2(LetraCifrada,TOTALBITS);
	mpz_init2(Aux,TOTALBITS); // auxiliar p/ a função de codificação

	vector<int> LinhaASCII; // cada termo desse vector é o código ascii de uma letra de uma palavra da linha lida
	vector<vector<int>> TextoASCII; // códigos ascii de todo o texto lido

	vector<string> LinhaCifrada; // linha do texto depois de ser cifrada
	vector<vector<string>> TextoCifrado; // texto inteiro cifrado
	// não da pra fazer vector de mpz_t, mas da pra converter um mpz_t pra char*
	// este que por sua vez pode ser convertido em string e colocado num vector

	for(int i = 0; i < TOTALARQ ; i++){
		SourceFilename = "criptografar"+to_string(i)+".txt";
		OutFilename = "criptografado"+to_string(i)+".txt";

		ArquivoCifrar.open(SourceFilename);

		if(!ArquivoCifrar.is_open()){
			cerr << "Não conseguiu abrir arquivo: " << SourceFilename << endl;
			continue;
		}

		while(getline(ArquivoCifrar,TextoLido)){
			// lendo o texto do arquivo
			for(unsigned int j = 0; j < TextoLido.length(); j++){
				Letra = TextoLido[j];
				if(Letra != ' ')
					LinhaASCII.push_back(int(Letra));
				else
					LinhaASCII.push_back(-1);
			}
			TextoASCII.push_back(LinhaASCII);
			LinhaASCII.clear();
		}

//		for(unsigned int j = 0; j < TextoASCII.size(); j++)
//			for(unsigned int k = 0; k < TextoASCII[j].size(); k++)
//				cout << TextoASCII[j][k] << endl;

		for(unsigned int j = 0; j < TextoASCII.size(); j++){
			for(unsigned int k = 0; k < TextoASCII[j].size(); k++){
				// cifrando o texto lido
				if(TextoASCII[j][k] == -1){
					LinhaCifrada.push_back("-");
					continue;
				}
				mpz_set_ui(Aux, TextoASCII[j][k]);
				cout << Aux << endl;
				mpz_powm(LetraCifrada,Aux,E,N);
				gmp_printf("%Zd \n",LetraCifrada);

				string AuxString(mpz_get_str(NULL,10,LetraCifrada));
				LinhaCifrada.push_back(AuxString);
			}
			TextoCifrado.push_back(LinhaCifrada);
			LinhaCifrada.clear();
		}

		TextoASCII.clear();
		ArquivoCifrar.close();

		ArquivoCifrado.open(OutFilename);
		for(unsigned int j = 0; j < TextoCifrado.size(); j++){
			for(unsigned int k = 0; k < TextoCifrado[j].size(); k++){
				if(TextoCifrado[j][k] == "-"){
					ArquivoCifrado << endl; // uma palavra criptografada por linha
					continue;
				}
				ArquivoCifrado << TextoCifrado[j][k] << " ";
			}
			ArquivoCifrado << endl << "x" << endl; // indicador de nova linha
		}

		TextoCifrado.clear();
		ArquivoCifrado.close();
	}
}

void descriptografar_arquivo(mpz_t D, mpz_t N){
	// decifra o texto em um arquivo cifrado
	// lê de um arquivo chamado criptografadoN, onde N é um int
	// põe o resultado num arquivo chamada decifradoN

	// cada linha é uma palavra, após cada palavra tem um espaço em branco
	// x é uma nova linha

	mpz_t LetraCifrada;
	mpz_init2(LetraCifrada, TOTALBITS);
	//char LetraDecifrada;
	string SourceFilename, OutFilename, TextoLido, PalavraDecifrada, StringAuxiliar;

	fstream ArquivoCifrado; // lê do arquivo cifrado
	ofstream ArquivoDecifrar; // escreve no arquivo decifrado

	for(int i = 0; i < TOTALARQ ; i++){
		SourceFilename = "criptografado"+to_string(i)+".txt";
		OutFilename = "descriptografado"+to_string(i)+".txt";

		ArquivoCifrado.open(SourceFilename);
		PalavraDecifrada = "";

		if(!ArquivoCifrado.is_open()){
			cerr << "Não conseguiu abrir arquivo: " << SourceFilename << endl;
			continue;
		}

		while(getline(ArquivoCifrado,TextoLido)){ // vai ler uma linha inteira, isso é, uma palavra
			// TextoLido tem uma linha inteira de números
			stringstream Auxiliar(TextoLido); 
			do{
				Auxiliar >> StringAuxiliar; // ao fazer isso, já quebro a string nos espaços em branco
				if(StringAuxiliar == "x"){
					break; // chegou ao final da linha
				}
				cout << StringAuxiliar << endl;

				mpz_set_str(LetraCifrada,StringAuxiliar.c_str(),10);
				mpz_powm(LetraCifrada,LetraCifrada,D,N);
				//cout << mpz_get_str(NULL,10,LetraCifrada) << endl;
				//cout << "------------------------------" << endl;
				//PalavraDecifrada += mpz_get_str(NULL,10,LetraCifrada);
			}while(Auxiliar);
		}
		//cout << PalavraDecifrada << endl;

	}
}