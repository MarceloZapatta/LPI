#include <stdio.h>
#include <string.h>
#include <math.h>

int ConverterParaInteiro(char * stringNumero, int stringLength);

int main()
{
    // String para armazenar os números
    char stringNumero[5];

    printf("Digite o a string númerica a ser convertida: \n");
    scanf("%s", &stringNumero);

    while(strcmp(stringNumero, "FIM") != 0) {
        // Recebo o número a ser convertido


        // Inteiro para armazenar a 
        // string transformada em número
        int intNumero;

        if(strlen(stringNumero) > 10) {
            printf("Valor muito grande para caber em um inteiro.\n");
            return 0;
        } else if(strlen(stringNumero) == 10) {
            if((stringNumero[9] - '0') > 2) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[9] - '0') == 2 && (stringNumero[8] - '0') > 1) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[8] - '0') == 1 && (stringNumero[7] - '0') > 4) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[7] - '0') == 4 && (stringNumero[6] - '0') > 7) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[6] - '0') == 7 && (stringNumero[5] - '0') > 4) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[5] - '0') == 4 && (stringNumero[4] - '0') > 8) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[4] - '0') == 8 && (stringNumero[3] - '0') > 3) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[3] - '0') == 3 && (stringNumero[2] - '0') > 6) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[2] - '0') == 6 && (stringNumero[1] - '0') > 4) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            } else if((stringNumero[1] - '0') == 4 && (stringNumero[0] - '0') > 7) {
                printf("Valor muito grande para caber em um inteiro.\n");
                return 0;
            }
        }

        // Converte a string para o número inteiro 
        // e retorna um inteiro
        intNumero = ConverterParaInteiro(stringNumero, strlen(stringNumero));

        // Imprime o inteiro
        printf("O inteiro convertido: %d\n", intNumero);

        printf("Digite o a string númerica a ser convertida: \n");
        scanf("%s", &stringNumero);
    }
}

int ConverterParaInteiro(char * stringNumero, int stringLength) {

    int multiplicador = 1;

	// Multiplicador das casas decimais
    for (int i = 0; i < stringLength - 1; ++i)
    {
        multiplicador = multiplicador * 10;
    }
	int tmpNumero = 0;

	for (int i = 0; i < stringLength; ++i)
	{
        tmpNumero += (*(stringNumero + i) - '0') * multiplicador;
        multiplicador = multiplicador / 10;
	}

	return tmpNumero;
}