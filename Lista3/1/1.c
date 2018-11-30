#include <stdio.h>
#include "substr.c"

int main()
{
    // Armazena o arquivo
    FILE * arquivo;

    // Armazena 80 caracteres
    char cadeia[77];
    char teste[12] = "substringtop";
    char destino[12];
    substr(teste, destino, 4, 9);
    printf("Resultado: %s\n", destino);
    return 0;
    // Abre no modo leitura
    arquivo = fopen("pagamento.txt", "r");
    
    // Recebe o texto por linha
    while(fgets(cadeia, 76, arquivo)) {

        printf("%s", cadeia);
    }

    fclose(arquivo);

    return 0;
}