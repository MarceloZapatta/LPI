#include <stdio.h>
#include <string.h>

int ConverterParaInteiro(char * stringNumero, int stringLength);

int main()
{
    // String para armazenar os números
    char stringNumero[5] = "1234";

    // Inteiro para armazenar a 
    // string transformada em número
    int intNumero;

    // Converte a string para o número inteiro 
    // e retorna um inteiro
    intNumero = ConverterParaInteiro(stringNumero, strlen(stringNumero));

    // Imprime o inteiro
    printf("O inteiro convertido: %d\n", intNumero);
}

int ConverterParaInteiro(char * stringNumero, int stringLength) {
	// Multiplicador das casas decimais
	int multiplicador = 10;

	int tmpNumero = 0;

	for (int i = 0; i < stringLength; ++i)
	{
        printf("numero: %d \n", (*(stringNumero + i) - '0'));

        if(i != 0) {
		    tmpNumero += (*(stringNumero + i) - '0');
        } else {
            tmpNumero += (*(stringNumero + i) - '0') * multiplicador;
            multiplicador *= 10;
        }

        printf("tmpnumero: %d \n", tmpNumero);
	}

	return tmpNumero;
}