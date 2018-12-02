#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "substr.c"

typedef struct ContaBancaria
{ 
  int codigo;
  // char codigo[6];
  char nome[36];
  float valorPagar;
  char banco[4];
  int agencia;
  int contaCorrente;
  char cnpj[15];
} ContaBancaria;

int main()
{
    // Armazena o arquivo
    FILE * arquivo;
    FILE * error;

    ContaBancaria contas[10];

    // Armazena a cadeia de caracteres do arquivo
    char cadeia[80];

    // Valor temporário do valor a pagar
    double tmpValorPagar;

    int i = 0;

    // Abre no modo leitura
    arquivo = fopen("pagamento.txt", "r");
    
    // Abre o arquivo de erro em modo leitura
    // e escrita
    error = fopen("error.txt", "r+");

    if(error == NULL) {

        // Cria um arquivo para escrita
        error = fopen("error.txt", "w");
    } else {
        fflush(error);
    }
    
    // Recebe o texto por linha
    for(i = 0; i < 10; i++) {
        fgets(cadeia, 79, arquivo);

        if(cadeia != NULL || cadeia != "") {
            (contas+i)->codigo = atoi(substr(cadeia, 1, 5));
            strcpy((contas+i)->nome, substr(cadeia, 6, 40));
            (contas+i)->valorPagar = atof(substr(cadeia, 41, 49)) / 100;
            strcpy((contas+i)->banco, substr(cadeia, 50, 52));
            (contas+i)->agencia = atoi(substr(cadeia, 53, 56));
            (contas+i)->contaCorrente = atoi(substr(cadeia, 57, 62));
            strcpy((contas+i)->cnpj, substr(cadeia, 63, 76));

            // Validação do campo
            if(strcmp((contas+i)->banco, "001") != 0) {
                if(strcmp((contas+i)->cnpj, "00000000000000") == 0) {
                    fputs(cadeia, error);
                    continue;
                }
            }

            printf("Conta:%d %s %.2f %s %d %d %s.%s.%s/%s-%s\n", (contas+i)->codigo, (contas+i)->nome, (contas+i)->valorPagar, 
                (contas+i)->banco, (contas+i)->agencia, (contas+i)->contaCorrente, substr((contas+i)->cnpj, 1, 2), 
                substr((contas+i)->cnpj, 3, 5), substr((contas+i)->cnpj, 5, 7), substr((contas+i)->cnpj, 8, 11), substr((contas+i)->cnpj, 13, 14));
        }
    }

    fclose(arquivo);
    fclose(error);

    return 0;
}