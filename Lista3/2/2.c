#include <stdio.h>
#include <string.h>
#include <math.h>

int ConverterParaInteiro(char * stringNumero, int stringLength);

int main()
{
    // String para armazenar os números
    char stringNumero[5];

    // Recebo o número a ser convertido

    printf("Digite o a string númerica a ser convertida: \n(Até 5 caracteres)\n");
    scanf("%s", &stringNumero);

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
	int multiplicador = pow(10, stringLength - 1);

	int tmpNumero = 0;

	for (int i = 0; i < stringLength; ++i)
	{

        tmpNumero += (*(stringNumero + i) - '0') * multiplicador;
        multiplicador = multiplicador / 10;
	}

	return tmpNumero;
}