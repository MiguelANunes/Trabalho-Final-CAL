# Instruções


## Básicas
Baixar os arquivos .cpp e .h assim como o arquivo `makefile`.


## Compilação
`make` ou `make all` na pasta onde estão os arquivos baixados.

## Execução
`make run` ou `./main` na mesma pasta. Adicionalmente pode-se passar dois argumentos adicionais quando executar esses comandos:
- `make run BITS=x` ou `./main x` roda o programa gerando chaves de x bits e pula o prompt para entrar com o número de bits
- `make run BITS=x ARQ=nome` ou `./main x nome` roda o programa gerando chaves de x bits e operando sobre o arquivo cujo nome é "nome", pulando o prompt para entrar com o número de bits e nome do arquivo.

## Pós Execução
`make clean` apaga os aquivos `.o` o executável `main` e os arquivos criptografados e descriptografados.
