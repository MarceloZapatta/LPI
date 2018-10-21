#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int qtdClientes, qtdCpf = 0, pontoValor = 0, pot = 0, tamanhoString;
    char cpf[11], string[500];
    float valor;

    printf("Entre com a quantidade de clientes:\n");
    scanf("%i", &qtdClientes);

    printf("Entre com a string:\n");
    scanf("%s", string);
    tamanhoString = strlen(string);

    // Repete a quantidade para imprimir cada
    // cpf e valor de cada cliente
    for(int i = 0; i < qtdClientes; i++)
    {
        
        // Percorre a string entrada pelo usuário
        for(int j = 0; j < tamanhoString; j++)
        {
            // Verifica se é um número (tabela ASCII)
            if(*(string + j) >= 48 && *(string + j) <= 57) {

                // Se a quantidade de caracteres
                // do CPF não atingiu 11
                if(qtdCpf < 11) {

                    // Insere o proximo digito do cpf na string
                    *(cpf + qtdCpf) = *(string + j);
                    qtdCpf++;
                } else {
                    
                    // Caso ainda não tenha aparecido 
                    // o ponto do valor preenche as casas iniciais
                    if(pontoValor == 0) {
                        if(pot == 0) {

                            // Primeira posição do valor
                            // Tratado como número
                            valor = *(string + j) - '0';
                            pot = 1;
                        } else {

                            // Trata as casas decimais
                            // Tratado como número
                            valor = (valor * 10) + (*(string + j) - '0');
                        }
                    } else if(pontoValor <= 2) {
                        // Caso esteja preenchendo as casas depois da virgula

                        // Primeira casa depois da vírgula
                        if(pontoValor == 1) {

                            // Multiplica para liberar uma casa decimal
                            // soma o número e divide por 10 para andar a virgula
                            valor = valor + ((*(string + j) - '0') * 0.1);
                            pontoValor++;
                        } else {

                            // Segunda casa depois do ponto divide por 100
                            valor = valor + ((*(string + j) - '0') * 0.01);

                            // Printa os valores

                            // Print do cpf
                            printf("CPF: %s", cpf);

                            // Print da soma
                            printf(" Soma: %.2f\n", valor);

                            // Zera tudo para reinicar a rotininha
                            qtdCpf = 0;
                            pot = 0;
                            pontoValor = 0;
                        }
                    }
                }
            } else if(*(string + j) == '.' && qtdCpf == 11 && pontoValor == 0) {
                pontoValor = 1;
            }
        }
    }
}