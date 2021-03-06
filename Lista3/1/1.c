#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "substr.c"

typedef struct ContaBancaria
{ 
  int codigo;
  char nome[36];
  float valorPagar;
  char banco[4];
  int agencia;
  int contaCorrente;
  char cnpj[15];
} ContaBancaria;

char * limpaFimString(char * string);
char * stringEspacos(int stringLength);
void pesquisaBinaria(char * stringPesquisa, ContaBancaria * contasBancarias, int numeroContas);

int main()
{
    // Armazena o arquivo
    FILE * arquivo;
    FILE * error;

    unsigned int numeroLinhasArquivo = 0;
    unsigned int numeroContas = 0;
    int chLinhaArquivo;

    // Abre no modo leitura
    arquivo = fopen("pagamento.txt", "r");

    // Contagem quantas linhas o arquivo possui
    while (EOF != (chLinhaArquivo=getc(arquivo))) {
        if ('\n' == chLinhaArquivo) {
            ++numeroLinhasArquivo;
        }
    }

    // Fecho arquivo e abro novamente
    fclose(arquivo);
    arquivo = fopen("pagamento.txt", "r");

    ContaBancaria contas[numeroLinhasArquivo];

    // Armazena a cadeia de caracteres do arquivo
    char cadeia[80];

    // String da pesquisa
    char stringPesquisa[36];

    // Valor temporário do valor a pagar
    double tmpValorPagar;
    double valorTotalPagar = 0;

    int i = 0;
    
    
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
    while(fgets(cadeia, 79, arquivo)) {

        if(cadeia != NULL || cadeia != "") {
            (contas+i)->codigo = atoi(substr(cadeia, 1, 5));
            strcpy((contas+i)->nome, limpaFimString(substr(cadeia, 6, 40)));
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

            printf("Conta:%d %s %s %.2f %s %d %d %s.%s.%s/%s-%s\n", (contas+i)->codigo, stringEspacos(strlen((contas+i)->nome)), (contas+i)->nome, (contas+i)->valorPagar, 
                (contas+i)->banco, (contas+i)->agencia, (contas+i)->contaCorrente, substr((contas+i)->cnpj, 1, 2), 
                substr((contas+i)->cnpj, 3, 5), substr((contas+i)->cnpj, 5, 7), substr((contas+i)->cnpj, 8, 11), 
                substr((contas+i)->cnpj, 13, 14));

            // Soma o valor total
            valorTotalPagar += (contas+i)->valorPagar;
            i++;
        }
    }

    // Printa o valor total
    printf("\nTotal: %.2f\n", valorTotalPagar);

    numeroContas = i;

    ContaBancaria tmpConta;

    // Bubble sort
    for (i = 0; i < numeroContas; ++i)
    {
        for (int j = i + 1; j < numeroContas; ++j)
        {
            if(strcmp((contas+j)->nome, (contas+i)->nome) < 0) {
                tmpConta.codigo = (contas+j)->codigo;
                strcpy(tmpConta.nome, (contas+j)->nome);
                tmpConta.valorPagar = (contas+j)->valorPagar;
                strcpy(tmpConta.banco, (contas+j)->banco);
                tmpConta.agencia = (contas+j)->agencia;
                tmpConta.contaCorrente = (contas+j)->contaCorrente;
                strcpy(tmpConta.cnpj, (contas+j)->cnpj);

                (contas+j)->codigo = (contas+i)->codigo;
                strcpy((contas+j)->nome, (contas+i)->nome);
                (contas+j)->valorPagar = (contas+i)->valorPagar;
                strcpy((contas+j)->banco, (contas+i)->banco);
                (contas+j)->agencia = (contas+i)->agencia;
                (contas+j)->contaCorrente = (contas+i)->contaCorrente;
                strcpy((contas+j)->cnpj, (contas+i)->cnpj);

                (contas+i)->codigo = tmpConta.codigo;
                strcpy((contas+i)->nome, tmpConta.nome);
                (contas+i)->valorPagar = tmpConta.valorPagar;
                strcpy((contas+i)->banco, tmpConta.banco);
                (contas+i)->agencia = tmpConta.agencia;
                (contas+i)->contaCorrente = tmpConta.contaCorrente;
                strcpy((contas+i)->cnpj, tmpConta.cnpj);
            }
        }
    }

    fclose(arquivo);
    fclose(error);

    // Realiza a pesquisa binária
    do {
        printf("\nPesquise pelo nome do fornecedor:\n");
        fgets(stringPesquisa, 36, stdin);

        // Remove o \n criado
        if ((strlen(stringPesquisa) > 0) && (stringPesquisa[strlen (stringPesquisa) - 1] == '\n')){
            stringPesquisa[strlen (stringPesquisa) - 1] = '\0';
        }
        pesquisaBinaria(stringPesquisa, contas, numeroContas);
    } while(1);


    return 0;
}

/**
 * Função para limpar os espaços em brancos da string
 */
char * limpaFimString(char * string) {
    char * stringLimpa = (char *) malloc(sizeof(char *) * 36);

    // Armazena a posição do ultimo caracter na string
    // para remover os espaços em branco
    int posChar;

    for (int i = 0; i < 36; ++i)
    {
        // Range da tabela ASCII de caracteres
        // Corresponde a um texto e não a vazio ou espaços, etc...
        if(*(string + i) >= 33 && *(string + i) <= 126) {
            posChar = i;
        }
    }

    // Copia a quantia de caracteres necessários
    strncpy(stringLimpa, string, (posChar + 1));

    // Marca o fim da string
    *(stringLimpa + (posChar + 1)) = '\0';

    return stringLimpa;
}

/**
 * Função para exibir espaços de acordo com o nome dos fornecedores
 */
char * stringEspacos(int stringLength) {
    char * stringEspacos = (char *) malloc(sizeof(char *) * 36);
    int diff = 36 - stringLength;

    for (int i = 0; i < diff; ++i)
    {
        *(stringEspacos + i) = ' ';
    }

    *(stringEspacos + diff) = '\0';

    return stringEspacos;
}

/**
 * Faz a pesquisa do array
 */
void pesquisaBinaria(char * stringPesquisa, ContaBancaria * contasBancarias, int numeroContas) {
    
    int inicio = 0;
    int fim = numeroContas - 1;
    int meio = (inicio + fim) / 2;
    int encontrado = 0;

    while (inicio <= fim) {
        if (strcmp((contasBancarias + meio)->nome, stringPesquisa) < 0) {
            inicio = meio + 1;    
        } else if (strcmp((contasBancarias + meio)->nome, stringPesquisa) == 0) {
            printf("\nEncontrado o fornecedor:\n\n");
            printf("Conta:%d %s %s %.2f %s %d %d %s.%s.%s/%s-%s\n", (contasBancarias + meio)->codigo, stringEspacos(strlen((contasBancarias + meio)->nome)), (contasBancarias + meio)->nome, (contasBancarias + meio)->valorPagar, 
                (contasBancarias + meio)->banco, (contasBancarias + meio)->agencia, (contasBancarias + meio)->contaCorrente, substr((contasBancarias + meio)->cnpj, 1, 2), 
                substr((contasBancarias + meio)->cnpj, 3, 5), substr((contasBancarias + meio)->cnpj, 5, 7), substr((contasBancarias + meio)->cnpj, 8, 11), 
                substr((contasBancarias + meio)->cnpj, 13, 14));
            encontrado = 1;
            break;
        } else {
            fim = meio - 1;
        }
 
        meio = (inicio + fim) / 2;
   }

    if(!encontrado) {
        printf("\nNão encontrado! O fornecedor: %s não está presente na lista.\n", stringPesquisa);
    }
}