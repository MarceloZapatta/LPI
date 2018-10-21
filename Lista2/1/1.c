#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // String para armazenar os dígitos ISBN
    // 11 caracteres por que conta o '-'
    char isbn[11];
    
    while (strcmp(isbn, "FIM") != 0) {

        scanf("%s", &isbn);
        
        // Verifica se o usuário digitou FIM
        if(strcmp(isbn, "FIM") == 0) {
            return 0;
        }

        // Acumuladores
        int s1[10] = {0}, s2 = 0;
        int k = 0, j = 0, resto;
        
        // Percorre o ISBN
        for(int i = 0; i < 11; i++) {

            // Primeiro caracter
            if(i == 0) {
                *s1 = *(isbn + i) - '0';
                k++;
            } else if(i != 9 && i != 10) {

                // Pega o digito com excecao das 2 ultimas casas
                *(s1 + k) += *(s1 + (k - 1)) + (*(isbn + i) - '0');
                k++;
            } else if(i == 10) {

                // Caso seja a ultima casa verifica se é X
                if(*(isbn + i) == 'X') {

                    // true soma 10 a ultima casa
                    *(s1 + k) += (*(s1 + (k - 1)) + 10);
                } else {

                    // se não soma com o respectivo número
                    *(s1 + k) += *(s1 + (k - 1)) + (*(isbn + i) - '0');
                }
            }
        }

        for(int i = 0; i < 10; i++)
        {
            // Preenche o segundo acumulador
            s2 += *(s1 + i);
        }

        resto = s2 % 11;

        // Valida o ISBN
        if(resto == 0) {
            printf("ISBN %s e' va'lido\n", isbn);
        } else {
            printf("ISBN inva'lido: %i\n", resto);
        }
        
    }
}