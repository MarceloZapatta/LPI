#include <stdio.h>

int ConverterParaInteiro(char * stringNumero);

int main()
{
    // String para armazenar os números
    char stringNumero[5] = "1234";

    // Inteiro para armazenar a 
    // string transformada em número
    int intNumero;

    // Converte a string para o número inteiro 
    // e retorna um inteiro
    intNumero = ConverterParaInteiro(stringNumero);

    // Imprime o inteiro
    printf("O inteiro convertido: %d\n", intNumero);
}

int ConverterParaInteiro(char * stringNumero) {
	// Multiplicador das casas decimais
	int multiplicador = 1;

	int tmpNumero = 0;

	for (int i = 0; i < 5; ++i)
	{
		tmpNumero += *(stringNumero + i) * (i + 1);
	}

	return tmpNumero;
}